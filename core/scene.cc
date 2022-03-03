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
    objs_.emplace_back(object);
}

void Scene::addLight(Light *light)
{
    lights_.emplace_back(light);
}

void Scene::setCamera(Camera camera)
{
    cam_ = camera;
}

float degToRad(float angle)
{
    return angle * M_PI / 180;
}

Vector3 reflect(Vector3 camToHit, Vector3 normal)
{
    return camToHit - normal * (camToHit.dot(normal)) * 2.0f;
}

float getDiffuse(Light *light, Vector3 hitToLight, Vector3 normal)
{
    return clamp(normal.dot(hitToLight), 0.0f, 1.0f);
}

float getSpecular(Light *light, Vector3 hitToLight, Vector3 reflected)
{
    float dot = reflected.dot(hitToLight * -1.0f);
    return pow(dot, 40.0f) * 255;
}

Scene::CastRayResult* Scene::castRay(Ray ray)
{
    CastRayResult* res = new CastRayResult();
    
    float minDst = INFINITY;
    for (auto obj : objs_)
    {
        float dst = obj->doesIntersect(ray);

        if (dst > 0.001f && dst < minDst)
        {
            minDst = dst;
            res->object = obj;
            res->hit = ray.getOrigin() + ray.getDirection().getPosition() * dst;
        }
    }

    return res;
}

Color Scene::castRayLight(SceneObject *object, Point3 hit, int rec_)
{
    if (rec_ <= 0) // stopping reflection
        return BLACK;

    TextureMaterial *texture = object->getTexture(ORIGIN);
    Components c = texture->getComponents(ORIGIN);
    Color color = texture->getColor(ORIGIN);
    
    Vector3 normal = object->getNormal(hit);
    Vector3 hitToCamera = cam_.getCenter() - hit;
    hitToCamera.normalize();

    float diffuse = 0;
    float specular = 0;
    bool shadowed = false;
    for (auto light : lights_)
    {
        Vector3 hitToLight = light->getPosition() - hit;
        float lightDistance = hitToLight.magnitude();
        hitToLight.normalize();

        Ray lightRay(hit, hitToLight);
        CastRayResult* res = castRay(lightRay);
        if (res->object != nullptr)
            shadowed = true;

        float shadowRatio = shadowed ? 0.4f : 1.0f;
        float luminance = light->getIntensity() * (1.0f / pow(lightDistance, 2)) * shadowRatio;
        
        Vector3 reflected = reflect(hitToCamera * -1.0f, normal);
        diffuse += getDiffuse(light, hitToLight, normal) * luminance;
        specular += getSpecular(light, hitToLight, reflected) * luminance;
    }

    Color recColor = castRayLight(object, hit, rec_ - 1);

    Color pixel = color * diffuse * c.getKd() + specular * c.getKs();
    return pixel + color * c.getKa();
}

Image Scene::render()
{
    int w = cam_.getWidth();
    int h = cam_.getHeight();

    float padX = cam_.getFovX() / w;
    float padY = cam_.getFovY() / h;
    float fovXMax = cam_.getFovX() / 2;
    float fovYMax = cam_.getFovY() / 2;

    Vector3 forward = cam_.getForward();
    Image image(w, h);

    for (float y = 0.0; y < h; y++)
    {
        Vector3 tmp = forward.rotate(cam_.getRight(), (y - h / 2) * padY);
        for (float x = 0.0; x < w; x++)
        {
            Vector3 pointing = tmp.rotate(cam_.getUp(), (x - w / 2) * padX);
            pointing.normalize();

            CastRayResult* res = castRay(Ray(cam_.getCenter(), pointing));
            SceneObject *object = res->object;
            Point3 hit = res->hit;

            if (object != nullptr) // intersects
            {
                Color pixel = castRayLight(object, hit, 5);
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