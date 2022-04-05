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

void loadDefaultScene(int width, int height, int fov, string outputName)
{
    // Creating scene
    Scene *scene = new Scene("config.json");

    // Turtle
    Turtle turtle;
    turtle.execute(scene, "grammars/little_plant.json");

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
