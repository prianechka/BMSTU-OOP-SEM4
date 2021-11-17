#include "mathobjs.h"

ScaleCoef::ScaleCoef(double x, double y, double z)
{
    kx = x;
    ky = y;
    kz = z;
}

double ScaleCoef::get_kx() const
{
    return kx;
}

double ScaleCoef::get_ky() const
{
    return ky;
}

double ScaleCoef::get_kz() const
{
    return kz;
}

Angle::Angle(double x, double y, double z)
{
    xy = x;
    yz = y;
    yz = z;
};

double Angle::get_xy() const
{
    return xy;
}

double Angle::get_yz() const
{
    return yz;
}

double Angle::get_xz() const
{
    return xz;
}
