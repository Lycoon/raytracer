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

    const Color BLACK = Color(0, 0, 0);
    const Point3 ORIGIN = Point3(0, 0, 0);
    const int MAX_RECURSION_DEPTH = 5;

    struct CastRayResult {
        SceneObject *object;
        Point3 hit;
    };

    const vector<SceneObject *> getObjects() const;
    const vector<Light *> getLights() const;
    const Camera getCamera() const;
    CastRayResult* castRay(Ray ray);
    Color castRayLight(SceneObject *object, Point3 hit, int rec_);
    Image render();

    void addObject(SceneObject *object);
    void addLight(Light *light);
    void setCamera(Camera camera);

private:
    vector<SceneObject *> objs_;
    vector<Light *> lights_;
    Camera cam_;
};