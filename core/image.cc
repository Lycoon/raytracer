#include "include/image.hh"

#include <iostream>

// Print
ostream &operator<<(ostream &out, Image &img)
{
    cout << "Image(w=" << img.getWidth() << ", h=" << img.getHeight() << ")"
         << endl;

    auto pixels = img.getPixels();
    for (int y = 0; y < img.getHeight(); y++)
    {
        for (int x = 0; x < img.getWidth(); x++)
        {
            cout << pixels[y][x] << " ";
        }
        cout << endl;
    }
}