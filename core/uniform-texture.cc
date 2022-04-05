#include "include/uniform-texture.hh"

Color &UniformTexture::getColor(Vector3 p) const
{
    return *color_;
}