#include "ImageBMP.h"

// Simple Rectangle class
class Rectangle
{
private:
    unsigned int x;
    unsigned int y;
    unsigned int width;
    unsigned int height;
    Color color;

public:
    Rectangle(unsigned int x, unsigned int y,
        unsigned int width, unsigned int height,
        const Color& color)
        : x(x), y(y), width(width), height(height), color(color)
    {
    }

    void draw(ImageBMP& image) const
    {
        image.fillRectangleWithColor(x, y, width, height, color);
    }
};

int main()
{
    ImageBMP image(500, 500, Color(ColorEnum::Black));

    //purple rectangle
    Rectangle purpleRect
    (50, 50, 200, 150, Color(128, 0, 128));

    purpleRect.draw(image);

    //white diagonal line
    for (unsigned int i = 0; i < 500; ++i)
    {
        image.setPixelToColor_withThickness(i, i, Color(ColorEnum::White), 3);
    }

    image.writeImageFile("output.bmp");

    return 0;
};
