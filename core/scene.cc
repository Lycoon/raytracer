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
    return camera_;
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
    camera_ = camera;
}

Image Scene::draw(int width, int height)
{
    Image image(width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Color pixel(128, 128, 128);
            image.setPixel(x, y, pixel);
        }
    }

    return image;
}