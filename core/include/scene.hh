#pragma once

#include <algorithm>
#include <vector>

#include "../../math/include/utils.hh"
#include "../../graphics/include/point-light.hh"
#include "../../graphics/include/sphere.hh"
#include "../../graphics/include/plane.hh"
#include "../../graphics/include/triangle.hh"

#include "camera.hh"
#include "image.hh"
#include "light.hh"
#include "uniform-texture.hh"
#include "texture-material.hh"
#include "scene-object.hh"

class Scene
{
public:
    Scene(string configFile)
    {
        parse(configFile);
    }

    Color *BLACK = new Color(0, 0, 0);
    Vector3 *ORIGIN = new Vector3(0, 0, 0);

    struct CastRayResult
    {
        SceneObject *object;
        Vector3 hit;
    };

    void parse(string configFile);
    Image render();

    Camera &getCamera() const;
    void setCamera(Camera *camera);

    CastRayResult *castRay(Ray ray);
    Color castRayLight(SceneObject *object, Vector3 hit, int rec_);

    const vector<SceneObject *> getObjects() const;
    const vector<Light *> getLights() const;
    void addObject(SceneObject *object);
    void addLight(Light *light);

private:
    vector<SceneObject *> objs_;
    vector<Light *> lights_;
    Camera *cam_;

    bool hasLightLoss_ = true;
    int reflections_ = 1;
};