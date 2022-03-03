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

void loadErwanScene(int width, int height, int fov, string outputName)
{
    // Objects
    auto matObj = Components(0.8f, 0.7f, 0.2f);
    auto matPlane = Components(0.85f, 0.3f, 0.4f);

    auto obj1_color = UniformTexture(Color(66, 135, 245), matObj);
    auto obj2_color = UniformTexture(Color(120, 180, 60), matObj);
    auto obj3_color = UniformTexture(Color(227, 15, 30), matObj);
    auto obj4_color = UniformTexture(Color(210, 40, 110), matObj);
    auto pla1_color = UniformTexture(Color(200, 150, 120), matPlane);

    auto obj1 = Sphere(0.5, Point3(-1, -1.5, 2.5), &obj1_color);
    auto obj2 = Sphere(2.5, Point3(7, 2, 1), &obj2_color);
    auto obj3 = Sphere(1, Point3(1, -1, -2.5), &obj3_color);
    auto obj4 = Sphere(0.5, Point3(-2, -1.5, 0.5), &obj4_color);
    auto plane1 = Plane(Point3(0, -2, 0), Vector3(0, 1, 0), &pla1_color);
    auto objects = vector<SceneObject *>{&plane1, &obj1, &obj2, &obj3, &obj4};

    // Lights
    auto pointLight = PointLight(Point3(0, 6, 3), 50.0f);
    auto lights = vector<Light *>{&pointLight};

    // Camera
    Point3 cameraPos = Point3(-5, 0, 0);
    Vector3 cameraDir = Vector3(1, 0, 0);
    Vector3 cameraUp = Vector3(0, 1, 0);
    auto camera = Camera(cameraPos, cameraDir, cameraUp, width, height, fov);
    cout << camera << endl;

    // Creating scene
    Scene scene(objects, lights, camera);

    Image image = scene.render();
    image.save(outputName);
}

void loadDefaultScene(int width, int height, int fov, string outputName)
{
    // Objects
    auto matObj = Components(1.0f, 0.3f, 1.0f);
    auto matPlane = Components(1.0f, 0.1f, 0);

    auto red = UniformTexture(Color(255, 0, 0), matObj);
    auto blue = UniformTexture(Color(0, 0, 255), matObj);
    auto green = UniformTexture(Color(0, 255, 0), matObj);
    auto orange = UniformTexture(Color(255, 153, 0), matPlane);

    auto sphereRed = Sphere(3, Point3(10, 3.5, 0), &red);
    auto sphereBlue = Sphere(2.5, Point3(10, -4, -3), &blue);
    auto sphereGreen = Sphere(1.5, Point3(6, -1, 2), &green);
    auto plane = Plane(Point3(0, -3, 0), Vector3(0, 1, 0), &orange);
    auto objects =
        vector<SceneObject *>{&sphereRed, &sphereBlue, &sphereGreen, &plane};

    // Lights
    auto pointLight = PointLight(Point3(0, 7, 4), 0.8);
    auto pointLight2 = PointLight(Point3(4, 5, -8), 0.5);
    auto lights = vector<Light *>{&pointLight};

    // Camera
    Point3 cameraPos = Point3(0, 0, 0);
    Vector3 cameraDir = Vector3(1, 0, 0);
    Vector3 cameraUp = Vector3(0, 1, 0);
    auto camera = Camera(cameraPos, cameraDir, cameraUp, width, height, fov);
    cout << camera << endl;

    // Creating scene
    Scene scene(objects, lights, camera);

    Image image = scene.render();
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

    // loadDefaultScene(width, height, fov, outputName);
    loadErwanScene(width, height, fov, outputName);

    return 0;
}