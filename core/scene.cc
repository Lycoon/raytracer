#include "include/scene.hh"

#include "include/json.hpp"

const char *HIDE_CURSOR = "\e[?25l";
const char *SHOW_CURSOR = "\e[?25h";

const vector<SceneObject *> Scene::getObjects() const
{
    return objs_;
}

const vector<Light *> Scene::getLights() const
{
    return lights_;
}

Camera &Scene::getCamera() const
{
    return *cam_;
}

void Scene::addObject(SceneObject *object)
{
    objs_.push_back(object);
}

void Scene::addLight(Light *light)
{
    lights_.push_back(light);
}

void Scene::setCamera(Camera *camera)
{
    cam_ = camera;
}

Vector3 reflect(Vector3 camToHit, Vector3 normal)
{
    return camToHit - normal * (camToHit.dot(normal)) * 2.0f;
}

float diffuse(Vector3 hitToLight, Vector3 normal)
{
    return clamp(normal.dot(hitToLight), 0.0f, 1.0f);
}

float specular(Vector3 hitToLight, Vector3 reflected)
{
    float dot = reflected.dot(hitToLight);
    return pow(dot <= 0 ? 0 : dot, 40.0f) * 255;
}

Scene::CastRayResult *Scene::castRay(Ray ray)
{
    CastRayResult *res = new CastRayResult();

    float minDst = INFINITY;
    for (auto obj : objs_)
    {
        float dst = obj->doesIntersect(ray);

        if (dst > 0.001f && dst < minDst)
        {
            minDst = dst;
            res->object = obj;
            res->hit = ray.getOrigin() + ray.getDirection() * dst;
        }
    }

    return res;
}

Color Scene::castRayLight(SceneObject *object, Vector3 hit, int rec_ = 0)
{
    if (rec_ >= reflections_) // stopping reflection
        return *BLACK;

    TextureMaterial *texture = object->getTexture(*ORIGIN);
    Material mat = texture->getMaterial(*ORIGIN);
    Color objColor = texture->getColor(*ORIGIN);
    Color pixel = *BLACK;

    Vector3 normal = object->getNormal(hit);
    Vector3 hitToCamera = cam_->getCenter() - hit;
    hitToCamera.normalize();

    Vector3 reflected = reflect(hitToCamera * -1.0f, normal);

    float reflectLoss = 1.0f / (rec_ + 1);
    bool shadowed = false;
    for (auto light : lights_)
    {
        Vector3 hitToLight = light->getPosition() - hit;

        float lightLoss = 0.015;
        if (hasLightLoss_)
            lightLoss = 1.0 / pow(hitToLight.magnitude(), 2);

        hitToLight.normalize();

        Ray lightRay(hit, hitToLight);
        CastRayResult *res = castRay(lightRay);
        if (res->object != nullptr)
            shadowed = true;

        float shadowRatio = shadowed ? 0.4 : 1;
        float luminance = light->getIntensity() * shadowRatio * lightLoss;

        float i_d = mat.getKd() * diffuse(hitToLight, normal) * luminance;
        float i_s = mat.getKs() * specular(hitToLight, reflected) * luminance;

        pixel = objColor * i_d + Color(1, 1, 1) * i_s;
    }

    CastRayResult *rebound = castRay(Ray(hit, reflected));
    if (rebound->object == nullptr)
        return pixel + pixel * mat.getKa();

    Color reboundColor = castRayLight(rebound->object, rebound->hit, rec_ + 1);
    pixel += reboundColor * reflectLoss * mat.getKs();

    return pixel + pixel * mat.getKa();
}

void Scene::parse(string configFile)
{
    ifstream file("../" + configFile);
    nlohmann::json config;
    file >> config;

    hasLightLoss_ = config["lightLoss"];
    reflections_ = config["reflections"];

    // Materials
    auto mats_ = config["materials"];
    map<string, Material *> materials;
    for (auto &[key, val] : mats_.items())
    {
        auto mat =
            new Material(val["diffuse"], val["specular"], val["ambient"]);
        materials[val["name"]] = mat;
    }

    // Textures
    auto texts_ = config["textures"];
    map<string, UniformTexture *> textures;
    for (auto &[key, val] : texts_.items())
    {
        auto col_ = val["color"];
        auto color = new Color(col_[0], col_[1], col_[2]);
        auto material = materials[val["material"]];

        textures[val["name"]] = new UniformTexture(color, material);
    }

    // Objects
    auto objects = config["objects"];
    for (auto &[key, val] : objects.items())
    {
        string type = val["type"];

        auto pos_ = val["position"];
        auto position = new Vector3(pos_[0], pos_[1], pos_[2]);

        if (type.compare("camera") == 0)
        {
            auto dir_ = val["direction"];
            auto up_ = val["up"];

            auto dir = new Vector3(dir_[0], dir_[1], dir_[2]);
            auto up = new Vector3(up_[0], up_[1], up_[2]);

            cam_ = new Camera(position, dir, up, config["width"],
                              config["height"]);
        }
        else if (type.compare("light") == 0)
        {
            auto color = val["color"];
            auto intensity = val["intensity"];

            lights_.push_back(new PointLight(
                position, new Color(color[0], color[1], color[2]), intensity));
        }
        else if (type.compare("sphere") == 0)
        {
            auto texture = textures[val["texture"]];
            float radius = val["radius"];

            objs_.push_back(new Sphere(radius, position, texture));
        }
        else if (type.compare("plane") == 0)
        {
            auto texture = textures[val["texture"]];
            auto norm_ = val["normal"];
            auto normal = new Vector3(norm_[0], norm_[1], norm_[2]);

            objs_.push_back(new Plane(position, normal, texture));
        }
        else if (type.compare("triangle") == 0)
        {
            string textureName = val["texture"];
            auto texture = textures[textureName];

            auto v0_ = val["v0"];
            auto v1_ = val["v1"];
            auto v2_ = val["v2"];

            auto v0 = new Vector3(v0_[0], v0_[1], v0_[2]);
            auto v1 = new Vector3(v1_[0], v1_[1], v1_[2]);
            auto v2 = new Vector3(v2_[0], v2_[1], v2_[2]);

            objs_.push_back(new Triangle(v0, v1, v2, texture));
        }
    }
}

void updateProgress(int step, int total)
{
    int barLength = 30;

    float percent = ((float)step / (float)total);
    int scaledProgress = percent * barLength;

    cout << round(percent * 100) << "% [";
    string progress = string(scaledProgress, '.');
    string spaces = string(barLength - scaledProgress, ' ');
    cout << progress << spaces << "]" << '\r';
}

Image Scene::render()
{
    int w = cam_->getWidth();
    int h = cam_->getHeight();

    float padX = cam_->getFovX() / w;
    float padY = cam_->getFovY() / h;

    int size = w * h;
    int step = 0;

    Vector3 forward = cam_->getForward();
    Image image(w, h);

    cout << endl
         << "Rendering" << HIDE_CURSOR << endl;
    for (float y = 0.0; y < h; y++)
    {
        Vector3 tmp = forward.rotate(cam_->getRight(), (y - h / 2) * padY);
        for (float x = 0.0; x < w; x++)
        {
            /*
            if (x != 219 || y != 443)
                continue;
            */

            Vector3 pointing = tmp.rotate(cam_->getUp(), (x - w / 2) * padX);
            pointing.normalize();

            CastRayResult *res = castRay(Ray(cam_->getCenter(), pointing));
            SceneObject *object = res->object;

            Vector3 hit = res->hit;

            if (object != nullptr) // intersects
            {
                Color pixel = castRayLight(object, hit);
                image.setPixel(x, y, pixel);
            }
            else // does not intersect
            {
                image.setPixel(x, y, *BLACK);
            }

            updateProgress(++step, size);
        }
    }

    cout << endl
         << "Completed." << SHOW_CURSOR << endl;
    return image;
}