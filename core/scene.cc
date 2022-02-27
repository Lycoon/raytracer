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

/*
Ray Scene::castRay(int x, int y)
{
    float w = cam_.getWidth();
    float h = cam_.getHeight();

    float d = 1.0 / tan(degToRad(cam_.getFovX() / 2.0));
    float aspectRatio = (float)cam_.getWidth() / (float)cam_.getHeight();

    float pX = x + 0.5;
    float pY = y + 0.5;

    float rayX = ((2.0 * pX / w) - 1.0) * aspectRatio;
    float rayY = 1.0 - (2.0 * pY / h);

    return Ray(cam_.getCenter(), Vector3(rayX, rayY, d));
}
*/

float computeDiffuse(Light *light, Vector3 lightToHit, Vector3 normal)
{
    float angle = max(0.0f, min(normal.dot(lightToHit), 1.0f));
    return angle * light->getIntensity();
}

Vector3 reflect(const Vector3 lightDir, Vector3 normal)
{
    float dot = 2.0f * lightDir.dot(normal);
    return lightDir * -1.0f + normal * dot;
}

Image Scene::draw()
{
    int w = cam_.getWidth();
    int h = cam_.getHeight();

    float padX = cam_.getFovX() / w;
    float padY = cam_.getFovY() / h;
    float fovXMax = cam_.getFovX() / 2;
    float fovYMax = cam_.getFovY() / 2;

    Vector3 forward = cam_.getForward();
    Point3 origin(0, 0, 0);
    Image image(w, h);

    for (float y = 0.0; y < h; y++)
    {
        Vector3 tmp = forward.rotate(cam_.getRight(), (y - h / 2) * padY);
        for (float x = 0.0; x < w; x++)
        {
            Vector3 pointing = tmp.rotate(cam_.getUp(), (x - w / 2) * padX);

            float minDst = INFINITY;
            SceneObject *closestObject = nullptr;
            Point3 hit;

            for (auto obj : objs_)
            {
                // Castray
                Ray ray(cam_.getCenter(), pointing);
                float dst = obj->doesIntersect(ray);

                if (dst > 0 && dst < minDst)
                {
                    minDst = dst;
                    closestObject = obj;
                    hit = ray.getOrigin()
                        + ray.getDirection().getPosition() * dst;
                }
            }

            if (closestObject != nullptr) // intersects
            {
                TextureMaterial *texture = closestObject->getTexture(origin);
                Vector3 normal = closestObject->getNormal(hit);

                float diffuse = 0;
                float specular = 0;
                for (auto light : lights_)
                {
                    Vector3 lightToHit = light->getPosition() - hit;
                    lightToHit.normalize();
                    normal.normalize();

                    diffuse += computeDiffuse(light, lightToHit, normal);

                    Vector3 reflected = reflect(lightToHit, normal);
                    specular += light->getIntensity()
                        * pow(max(0.0f, reflected.dot(hit * -1.0f)), 8.0f);
                }

                Color col = texture->getColor(origin) * diffuse * 0.9f
                    + specular * 0.1f;
                image.setPixel(x, y, col);
            }
            else // does not intersect
            {
                image.setPixel(x, y, Color(0, 0, 0));
            }
        }
    }

    return image;
}