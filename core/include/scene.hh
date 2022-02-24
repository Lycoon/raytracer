#pragma once

#include <vector>

#include "camera.hh"
#include "light.hh"
#include "scene-object.hh"

class Scene
{
public:
    Scene()
    {}

private:
    vector<SceneObject> objs_;
    vector<Light> lights_;
    Camera camera;
};