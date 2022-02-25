#include <iostream>

#include "core/include/image.hh"
#include "core/include/scene.hh"
#include "graphics/include/point-light.hh"
#include "graphics/include/sphere.hh"

using namespace std;

void test()
{
    Sphere sphere(1, Point3(2, 2, 2));
    cout << sphere << "\n\n";

    Point3 rayOrigin(0, 0, 0);
    Vector3 rayDirection(1, 1, 1);
    Ray ray(rayOrigin, rayDirection);

    float dist = sphere.doesIntersect(ray);
    cout << "distance = " << dist << endl;

    Image img(800, 600);
    img.save("raytracer.ppm");
}

int main(int argc, char const *argv[])
{
    cout << "===== RAYTRACER =====\n\n";

    auto sphere = Sphere(5, Point3(15, 0, 0));
    auto pointLight = PointLight(Point3(0, 0, 0));

    auto objects = vector<SceneObject *>{ &sphere };
    auto lights = vector<Light *>{ &pointLight };
    auto camera = Camera();

    Scene scene(objects, lights, camera);

    Image image = scene.draw(800, 600);
    image.save("output.ppm");

    return 0;
}
