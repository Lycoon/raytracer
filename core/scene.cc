#include "include/scene.hh"

const vector<SceneObject *> Scene::getObjects() const
{
    return objs_;
}

const vector<Light *> Scene::getLights() const
{
    return lights_;
}

const Camera Scene::getCamera() const
{
    return cam_;
}

void Scene::addObject(SceneObject *object)
{
    objs_.push_back(object);
}

void Scene::addLight(Light *light)
{
    lights_.push_back(light);
}

void Scene::setCamera(Camera camera)
{
    cam_ = camera;
}

Vector3 reflect(Vector3 camToHit, Vector3 normal)
{
    return camToHit - normal * (camToHit.dot(normal)) * 2.0f;
}

float diffuse(Vector3 hitToLight, Vector3 normal)
{
    return clamp(normal.dot(hitToLight), 0.0f, 1.0f);
}

float specular(Vector3 hitToLight, Vector3 reflected)
{
    float dot = reflected.dot(hitToLight);
    return pow(dot <= 0 ? 0 : dot, 40.0f) * 255;
}

Scene::CastRayResult *Scene::castRay(Ray ray)
{
    CastRayResult *res = new CastRayResult();

    float minDst = INFINITY;
    for (auto obj : objs_)
    {
        float dst = obj->doesIntersect(ray);

        if (dst > 0.001f && dst < minDst)
        {
            minDst = dst;
            res->object = obj;
            res->hit = ray.getOrigin() + ray.getDirection() * dst;
        }
    }

    return res;
}

Color Scene::castRayLight(SceneObject *object, Vector3 hit, int rec_ = 0)
{
    if (rec_ >= MAX_RECURSION_DEPTH) // stopping reflection
        return BLACK;

    TextureMaterial *texture = object->getTexture(ORIGIN);
    Material mat = texture->getMaterial(ORIGIN);
    Color objColor = texture->getColor(ORIGIN);
    Color pixel = BLACK;

    Vector3 normal = object->getNormal(hit);
    Vector3 hitToCamera = cam_.getCenter() - hit;
    hitToCamera.normalize();

    Vector3 reflected = reflect(hitToCamera * -1.0f, normal);

    float reflectLoss = 1.0f / (rec_ + 1);
    bool shadowed = false;
    for (auto light : lights_)
    {
        Vector3 hitToLight = light->getPosition() - hit;
        float lightDistance = hitToLight.magnitude();
        hitToLight.normalize();

        Ray lightRay(hit, hitToLight);
        CastRayResult *res = castRay(lightRay);
        if (res->object != nullptr)
            shadowed = true;

        float shadowRatio = shadowed ? 0.4 : 1;
        float luminance =
            light->getIntensity() * (1.0 / pow(lightDistance, 2)) * shadowRatio;

        float i_d = mat.getKd() * diffuse(hitToLight, normal) * luminance;
        float i_s = mat.getKs() * specular(hitToLight, reflected) * luminance;

        pixel = objColor * i_d + Color(1, 1, 1) * i_s;
    }

    CastRayResult *rebound = castRay(Ray(hit, reflected));
    if (rebound->object == nullptr)
        return pixel + pixel * mat.getKa();

    Color reboundColor = castRayLight(rebound->object, rebound->hit, rec_ + 1);
    pixel += reboundColor * reflectLoss * mat.getKs();

    return pixel + pixel * mat.getKa();
}

Image Scene::render()
{
    int w = cam_.getWidth();
    int h = cam_.getHeight();

    float padX = cam_.getFovX() / w;
    float padY = cam_.getFovY() / h;

    Vector3 forward = cam_.getForward();
    Image image(w, h);

    for (float y = 0.0; y < h; y++)
    {
        Vector3 tmp = forward.rotate(cam_.getRight(), (y - h / 2) * padY);
        for (float x = 0.0; x < w; x++)
        {
            /*
            if (x != 219 || y != 443)
                continue;
            */

            Vector3 pointing = tmp.rotate(cam_.getUp(), (x - w / 2) * padX);
            pointing.normalize();

            CastRayResult *res = castRay(Ray(cam_.getCenter(), pointing));
            SceneObject *object = res->object;
            Vector3 hit = res->hit;

            if (object != nullptr) // intersects
            {
                Color pixel = castRayLight(object, hit);
                image.setPixel(x, y, pixel);
            }
            else // does not intersect
            {
                image.setPixel(x, y, BLACK);
            }
        }
    }

    return image;
}