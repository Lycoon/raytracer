#include "include/uniform-texture.hh"

vector<float> UniformTexture::getComponents(Point3 p) const
{
    return vector<float>{ 0.5, 0.3, 1 };
}

Color UniformTexture::getColor(Point3 p) const
{
    return color_;
}