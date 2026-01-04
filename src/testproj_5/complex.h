#ifndef COMPLEX_H
#define COMPLEX_H

typedef enum { RECT, POLAR, ERROR } CoordType;

typedef struct {
    CoordType t;
    double a;
    double b;
} Complex;

double real(Complex z);
double img(Complex z);
double mag(Complex z);
double angle(Complex z);

Complex zadd(Complex z1, Complex z2);
Complex zsub(Complex z1, Complex z2);
Complex zmul(Complex z1, Complex z2);
Complex zdiv(Complex z1, Complex z2);

#endif