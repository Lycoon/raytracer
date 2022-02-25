#pragma once

#include <vector>

#include "camera.hh"
#include "light.hh"
#include "scene-object.hh"

class Scene
{
public:
    Scene(vector<SceneObject> objects, vector<Light> lights, Camera camera) : objs_(objects), lights_(lights), camera_(camera)
    {
    }

    const vector<SceneObject> getObjects() const;
    const vector<Light> getLights() const;
    const Camera getCamera() const;

    void addObject(SceneObject object);
    void addLight(Light light);
    void setCamera(Camera camera);

private:
    vector<SceneObject> objs_;
    vector<Light> lights_;
    Camera camera_;
};