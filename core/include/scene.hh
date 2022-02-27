#pragma once

#include <vector>

#include "camera.hh"
#include "image.hh"
#include "light.hh"
#include "scene-object.hh"

class Scene
{
public:
    Scene(vector<SceneObject *> objects, vector<Light *> lights, Camera camera)
        : objs_(objects)
        , lights_(lights)
        , cam_(camera)
    {}

    const vector<SceneObject *> getObjects() const;
    const vector<Light *> getLights() const;
    const Camera getCamera() const;
    Ray castRay(int x, int y);
    Image draw();

    void addObject(SceneObject *object);
    void addLight(Light *light);
    void setCamera(Camera camera);

private:
    vector<SceneObject *> objs_;
    vector<Light *> lights_;
    Camera cam_;
};