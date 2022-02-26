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

void Scene::castRay()
{}

Image Scene::draw()
{
    int w = cam_.getWidth();
    int h = cam_.getHeight();

    float padX = cam_.getFovX() / w;
    float padY = cam_.getFovY() / h;
    float fovXMax = cam_.getFovX() / 2;
    float fovYMax = cam_.getFovY() / 2;

    Vector3 origin = cam_.getForward();
    origin = origin.rotate(cam_.getUp(), -fovXMax);
    origin = origin.rotate(cam_.getRight(), -fovYMax);

    Image image(w, h);
    Vector3 pointing = origin;
    for (float y = 0.0; y < h; y++)
    {
        Vector3 tmp =
            cam_.getForward().rotate(cam_.getRight(), (y - h / 2) * padY);
        for (float x = 0.0; x < w; x++)
        {
            Vector3 tmp2 = tmp.rotate(cam_.getUp(), (x - w / 2) * padX);

            float minDst = INFINITY;
            SceneObject *closestObject = nullptr;
            for (auto obj : objs_)
            {
                // Castray
                Ray ray(cam_.getCenter(), tmp2);

                float dst = obj->doesIntersect(ray);
                if (dst > 0 && dst < minDst)
                {
                    minDst = dst;
                    closestObject = obj;
                }

                Vector3 dir = ray.getDirection() * dst;
            }

            if (closestObject != nullptr)
            {
                // intersects
                // Point3 hit = ray.getOrigin() + dir.getPosition();

                image.setPixel(x, y,
                               closestObject->getTexture(Point3(0, 0, 0))
                                   ->getColor(Point3(0, 0, 0)));
            }
            else
            {
                // does not intersect
                image.setPixel(x, y, Color(255, 255, 255));
            }
        }
    }

    return image;
}