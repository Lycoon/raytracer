#include <iostream>

#include "core/include/image.hh"
#include "core/include/scene.hh"
#include "core/include/turtle.hh"
#include "graphics/include/box.hh"
#include "graphics/include/mengen-sponge.hh"
#include "graphics/include/plane.hh"
#include "graphics/include/point-light.hh"
#include "graphics/include/sphere.hh"
#include "graphics/include/triangle.hh"

using namespace std;

#define DEFAULT_WIDTH 512
#define DEFAULT_HEIGHT 512
#define DEFAULT_FOV 90
#define DEFAULT_OUTPUT_NAME "output"

void doTurtle(Scene *scene, UniformTexture *texture)
{
    Turtle turtle;
    turtle.rotateLeft(90);

    for (int i = 0; i < 150; i++)
    {
        Sphere *sphere = new Sphere(0.2, turtle.getPosition(), texture);
        scene->addObject(sphere);
        
        turtle.rotateUp(90);
        turtle.moveForward(i * 0.15);
    }
}

void loadDefaultScene(int width, int height, int fov, string outputName)
{
    // Objects
    auto matObj = Material(0.8f, 0.7f, 0.2f);
    auto matPlane = Material(0.85f, 0.3f, 0.4f);
    auto matBox = Material(0.8f, 0.1f, 0.4f);

    Color WHITE = Color(255, 255, 255);
    Color GREEN = Color(0, 255, 0);
    Color BLUE = Color(0, 0, 255);

    auto obj1_color = UniformTexture(Color(66, 135, 245), matObj);
    auto obj2_color = UniformTexture(Color(120, 180, 60), matObj);
    auto obj3_color = UniformTexture(Color(227, 15, 30), matObj);
    auto obj4_color = UniformTexture(Color(210, 40, 110), matObj);
    auto pla1_color = UniformTexture(Color(200, 150, 120), matPlane);
    auto box1_color = UniformTexture(Color(255, 255, 255), matBox);

    auto obj1 = Sphere(0.5, Vector3(-1, -1.5, 2.5), &obj1_color);
    auto obj2 = Sphere(2.5, Vector3(7, 4, 1), &obj2_color);
    auto obj3 = Sphere(1, Vector3(1, -1, -2.5), &obj3_color);
    auto obj4 = Sphere(0.5, Vector3(-2, -1.5, 0.5), &obj4_color);
    auto plane1 = Plane(Vector3(0, -2, 0), Vector3(0, 1, 0), &pla1_color);
    auto tri1 = Triangle(Vector3(2.0, -1, 3), Vector3(2.0, 2, 0),
                         Vector3(2.0, -1, -3), &obj1_color);
    // auto box1 = Box(Vector3(0, -0.5, -1), Vector3(-1, 0.5, 1), &box1_color);
    auto sponge = Sponge(2, { -2, -2, -2 }, { 2, 2, 2 }, &box1_color);

    auto objects =
        vector<SceneObject *>{ &plane1, &tri1 };

    // Lights
    auto pointLight = PointLight(Vector3(-3, 6, 3), WHITE, 50.0f);
    auto lights = vector<Light *>{ &pointLight };

    // Camera
    Vector3 cameraPos = Vector3(-5, 0, 0);
    Vector3 cameraDir = Vector3(1, 0, 0);
    Vector3 cameraUp = Vector3(0, 1, 0);
    auto camera = Camera(cameraPos, cameraDir, cameraUp, width, height, fov);
    cout << camera << endl;

    // Creating scene
    Scene *scene = new Scene(objects, lights, camera);
    doTurtle(scene, &obj1_color);

    /*
    for (auto obj : scene->getObjects())
    {
        if (obj->getId().compare("sphere") == 0)
            cout << *(Sphere*)obj << endl;
    }
    */

    Image image = scene->render();
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
