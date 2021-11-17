#ifndef MATHOBJS_H
#define MATHOBJS_H


class ScaleCoef
{
private:
    double kx, ky, kz;
public:
    ScaleCoef() = default;
    ScaleCoef(double x, double y, double z);

    double get_kx() const;
    double get_ky() const;
    double get_kz() const;
};

class Angle
{
private:
    double xy, yz, xz;
public:
    Angle() = default;
    Angle(double x, double y, double z);

    double get_xy() const;
    double get_yz() const;
    double get_xz() const;
};

#endif // MATHOBJS_H
