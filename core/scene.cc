#include "include/scene.hh"

const vector<SceneObject> Scene::getObjects() const
{
    return objs_;
}

const vector<Light> Scene::getLights() const
{
    return lights_;
}

const Camera Scene::getCamera() const
{
    return camera_;
}

void Scene::addObject(SceneObject object)
{
    objs_.emplace_back(object);
}

void Scene::addLight(Light light)
{
    lights_.emplace_back(light);
}

void Scene::setCamera(Camera camera)
{
    camera_ = camera;
}