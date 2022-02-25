#include "include/image.hh"

#include <iostream>

const int Image::getWidth() const
{
    return width_;
}

const int Image::getHeight() const
{
    return height_;
}

const vector<vector<Color>> &Image::getPixels() const
{
    return pixels_;
}

// Print
ostream &operator<<(ostream &out, Image &img)
{
    out << "Image(w=" << img.getWidth() << ", h=" << img.getHeight() << ")"
        << endl;

    auto pixels = img.getPixels();
    for (int y = 0; y < img.getHeight(); y++)
    {
        for (int x = 0; x < img.getWidth(); x++)
        {
            out << pixels[y][x] << " ";
        }
        out << endl;
    }

    return out;
}