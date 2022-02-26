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

void Image::setPixel(int x, int y, Color color)
{
    pixels_[y][x] = color;
}

void Image::save(string name) const
{
    ofstream img(name + ".ppm");

    img << "P3" << endl;
    img << width_ << " " << height_ << endl;
    img << "255" << endl;

    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            Color px = pixels_[y][x];

            img << px.getRed() << " " << px.getGreen() << " " << px.getBlue()
                << "\n";
        }
    }

    img.close();
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