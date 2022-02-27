#include <iostream>

#include "core/include/image.hh"
#include "core/include/scene.hh"
#include "graphics/include/plane.hh"
#include "graphics/include/point-light.hh"
#include "graphics/include/sphere.hh"

using namespace std;

#define DEFAULT_WIDTH 512
#define DEFAULT_HEIGHT 512
#define DEFAULT_FOV 90
#define DEFAULT_OUTPUT_NAME "output"

void loadDefaultScene(int width, int height, int fov, string outputName)
{
    // Objects
    auto red = UniformTexture(Color(255, 0, 0));
    auto blue = UniformTexture(Color(0, 0, 255));
    auto green = UniformTexture(Color(0, 255, 0));
    auto orange = UniformTexture(Color(255, 153, 0));

    auto sphereRed = Sphere(1.2, Point3(2, -0.4, -3), &red);
    auto sphereBlue = Sphere(1, Point3(5, 3, 1), &blue);
    auto sphereGreen = Sphere(1.5, Point3(2, -3, -2), &green);
    auto plane = Plane(Point3(0, 0, 0), Vector3(0, 0, 0.05), &orange);
    auto objects =
        vector<SceneObject *>{ &sphereRed, &sphereBlue, &sphereGreen };

    // Lights
    auto pointLight = PointLight(Point3(-2, 0, 6), 0.7);
    auto lights = vector<Light *>{ &pointLight };

    // Camera
    Point3 cameraPos = Point3(-2, 0, 0);
    Vector3 cameraDir = Vector3(1, 0, 0);
    Vector3 cameraUp = Vector3(0, 0, 1);
    auto camera = Camera(cameraPos, cameraDir, cameraUp, width, height, fov);
    cout << camera << endl;

    // Creating scene
    Scene scene(objects, lights, camera);

    Image image = scene.draw();
    image.save(outputName);
}

int main(int argc, char const *argv[])
{
    cout << "\n[----------------- Raytracer -----------------]\n";
    cout << "./raytracer [width] [height] [fov] [outputName]\n\n";

    // Parsing options
    int width = argc >= 2 ? atoi(argv[1]) : DEFAULT_WIDTH;
    int height = argc >= 3 ? atoi(argv[2]) : DEFAULT_HEIGHT;
    int fov = argc >= 4 ? atoi(argv[3]) : DEFAULT_FOV;
    string outputName = argc >= 5 ? argv[4] : DEFAULT_OUTPUT_NAME;

    loadDefaultScene(width, height, fov, outputName);

    return 0;
}