#include <stdio.h>
#include <math.h>

typedef enum { RECT, POLAR, ERROR } CoordType;

typedef struct {
    CoordType t;
    double a;
    double b;
} Complex;

typedef double (*ComplexGet)(Complex);

static double rect_real(Complex z) { return z.a; };
static double rect_img(Complex z) { return z.b; };
static double rect_magnitude(Complex z) { return sqrt(z.a * z.a + z.b * z.b); };
static double rect_angle(Complex z) { return atan2(z.b, z.a); };
static double pol_real(Complex z) { return z.a * cos(z.b); };
static double pol_img(Complex z) { return z.a * sin(z.b); };
static double pol_magnitude(Complex z) { return z.a; }; 
static double pol_angle(Complex z) { return z.b; };

static ComplexGet real[] = {rect_real, pol_real};
static ComplexGet img[] = {rect_img, pol_img};
static ComplexGet magnitude[] = {rect_magnitude, pol_magnitude};
static ComplexGet angle[] = {rect_angle, pol_angle};

#define REAL(z) real[(z).t](z)
#define IMG(z) img[(z).t](z)
#define MAGNITUDE(z) magnitude[(z).t](z)
#define ANGLE(z) angle[(z).t](z)

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

int main()
{
    Complex z = {RECT, 3.0, 4.0};

    printf("%.2f\n", REAL(z));
    printf("%.2f\n", IMG(z));
    printf("%.2f\n", MAGNITUDE(z));
    printf("%.2f\n", ANGLE(z));

    Complex z1 = {RECT, 3.0, 4.0};
    Complex z2 = {RECT, 8.0, 2.0};
    Complex z3 = {POLAR, 8.0, 45.0};
    Complex z4 = {POLAR, 4.5, 66.0};

    Complex sum1 = zadd(z1, z2);
    Complex sum2 = zadd(z1, z3);
    Complex sum3 = zadd(z3, z4);

    printf("%d, %.2f, %.2f\n", sum1.t, sum1.a, sum1.b);
    printf("%d, %.2f, %.2f\n", sum2.t, sum2.a, sum2.b);
    printf("%d, %.2f, %.2f\n", sum3.t, sum3.a, sum3.b);

    return 0;
}

