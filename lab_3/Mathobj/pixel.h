#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    Pixel() = default;
    Pixel(int _x, int _y);

    int get_x() const;
    int get_y() const;

    void set_x(int _x);
    void set_y(int _y);
private:
    int x, y;
};

#endif // PIXEL_H
