#pragma once

#include <vector>
#include <algorithm>

#include "camera.hh"
#include "image.hh"
#include "light.hh"
#include "scene-object.hh"

class Scene
{
public:
    Scene(vector<SceneObject *> objects, vector<Light *> lights, Camera camera)
        : objs_(objects), lights_(lights), cam_(camera)
    {
    }

    struct CastRayResult {
        SceneObject *object;
        Point3 hit;
    };

    const vector<SceneObject *> getObjects() const;
    const vector<Light *> getLights() const;
    const Camera getCamera() const;
    CastRayResult* castRay(Vector3 ray);
    Color castRayLight(SceneObject *object, Point3 hit, Point3 origin);
    Image draw();

    void addObject(SceneObject *object);
    void addLight(Light *light);
    void setCamera(Camera camera);


private:
    vector<SceneObject *> objs_;
    vector<Light *> lights_;
    Camera cam_;
};