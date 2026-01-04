#include <stdio.h>
#include <math.h>
#include "complex.h"

typedef double (*ComplexGet)(Complex);

static double rect_real(Complex z) { return z.a; };
static double rect_img(Complex z) { return z.b; };
static double rect_magnitude(Complex z) { return sqrt(z.a * z.a + z.b * z.b); };
static double rect_angle(Complex z) { return atan2(z.b, z.a); };
static double pol_real(Complex z) { return z.a * cos(z.b); };
static double pol_img(Complex z) { return z.a * sin(z.b); };
static double pol_magnitude(Complex z) { return z.a; }; 
static double pol_angle(Complex z) { return z.b; };

static ComplexGet real_func[] = {rect_real, pol_real};
static ComplexGet img_func[] = {rect_img, pol_img};
static ComplexGet magnitude_func[] = {rect_magnitude, pol_magnitude};
static ComplexGet angle_func[] = {rect_angle, pol_angle};

#define REAL(z) real_func[(z).t](z)
#define IMG(z) img_func[(z).t](z)
#define MAGNITUDE(z) magnitude_func[(z).t](z)
#define ANGLE(z) angle_func[(z).t](z)

double real(Complex z) { return REAL(z); };
double img(Complex z) { return IMG(z); };
double mag(Complex z) { return MAGNITUDE(z); };
double angle(Complex z) { return ANGLE(z); };

static Complex Type(Complex z0, Complex z1, Complex z2)
{
    if (z1.t == POLAR && z2.t == POLAR)
    {
        Complex z = {POLAR, MAGNITUDE(z0), ANGLE(z0)};
        return z;
    } else {
        Complex z = {RECT, REAL(z0), IMG(z0)};
        return z;
    }
}

Complex zadd(Complex z1, Complex z2)
{
    Complex z = {RECT, REAL(z1) + REAL(z2), IMG(z1) + IMG(z2)};
    z = Type(z, z1, z2);
    return z;
}

Complex zsub(Complex z1, Complex z2)
{
    Complex z = {RECT, REAL(z1) - REAL(z2), IMG(z1) - IMG(z2)};
    z = Type(z, z1, z2);
    return z;
}

Complex zmul(Complex z1, Complex z2)
{
    Complex z = {POLAR, MAGNITUDE(z1) * MAGNITUDE(z2), ANGLE(z1) + ANGLE(z2)};
    z = Type(z, z1, z2);
    return z;
}

Complex zdiv(Complex z1, Complex z2)
{
    if (MAGNITUDE(z2) == 0)
    {
        printf("Error!");
        Complex z = {ERROR, 0, 0};
        return z;
    } else {
        Complex z = {POLAR, MAGNITUDE(z1) / MAGNITUDE(z2), ANGLE(z1) - ANGLE(z2)};
        z = Type(z, z1, z2);
        return z;
    }
}