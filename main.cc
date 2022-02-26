#include <iostream>

#include "core/include/image.hh"
#include "core/include/scene.hh"
#include "graphics/include/point-light.hh"
#include "graphics/include/sphere.hh"

using namespace std;

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define DEFAULT_FOV 90
#define DEFAULT_OUTPUT_NAME "output"

int main(int argc, char const *argv[])
{
    cout << "\n[----------------- Raytracer -----------------]\n";
    cout << "./raytracer [width] [height] [fov] [outputName]\n\n";

    // Parsing options
    int width = argc >= 2 ? atoi(argv[1]) : DEFAULT_WIDTH;
    int height = argc >= 3 ? atoi(argv[2]) : DEFAULT_HEIGHT;
    int fov = argc >= 4 ? atoi(argv[3]) : DEFAULT_FOV;
    string outputName = argc >= 5 ? argv[4] : DEFAULT_OUTPUT_NAME;

    // Creating objects
    auto sphere = Sphere(5, Point3(15, 0, 0));
    auto pointLight = PointLight(Point3(0, 0, 0));

    auto objects = vector<SceneObject *>{ &sphere };
    auto lights = vector<Light *>{};

    Point3 cameraPos = Point3(0, 0, 0);
    Point3 cameraDir = Point3(0, 0, 1);
    Vector3 cameraUp = Vector3(1, 0, 0);
    auto camera = Camera(cameraPos, cameraDir, cameraUp, width, height, fov);

    // Creating scene
    Scene scene(objects, lights, camera);

    Image image = scene.draw();
    image.save(outputName);

    return 0;
}

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