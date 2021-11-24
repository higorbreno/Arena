#include "Vector.h"

// ------------------------------------------------------------------------------

const double Vector::PI = 3.1415926535;

// ------------------------------------------------------------------------------

Vector::Vector()
{
    x = 0;
    y = 0;
    angle = 0;
    magnitude = 0;
}

// ------------------------------------------------------------------------------

void Vector::setXY(float x, float y)
{
    this->x = x;
    this->y = y;
    magnitude = sqrt((x * x) + y * y);
    angle = double(atan2(y, x)) * 180.0f / PI;

    while (angle < 0 || angle >= 360)
        angle += (angle >= 360 ? -360.0f : 360.0f);
}

void Vector::setPolar(float ang, float mag)
{
    this->magnitude = mag;
    this->angle = ang;

    while (angle < 0 || angle >= 360)
        angle += (angle >= 360 ? -360.0f : 360.0f);

    x = magnitude * cos(angle * PI / 180.0f);
    y = magnitude * sin(angle * PI / 180.0f);
}

void Vector::Rotate(float theta)
{
    angle -= theta;

    // mantém o ângulo entre 0 e 359 graus
    while (angle < 0 || angle >= 360)
        angle += (angle >= 360 ? -360.0f : 360.0f);
}

void Vector::RotateTo(float value)
{
    setPolar(value, magnitude);
}

// ------------------------------------------------------------------------------

void Vector::Scale(float factor)
{
    setXY(this->x * factor, this->y * factor);
}

void Vector::ScaleTo(float value)
{
    setPolar(angle, value);
}

// ------------------------------------------------------------------------------

Vector Vector::operator+(const Vector* vector)
{
    Vector result;
    result.setXY(this->x + vector->x, this->y + vector->y);
    return result;
}

// ------------------------------------------------------------------------------

Vector Vector::operator*(float scalar)
{
    Vector result;
    result.setXY(this->x * scalar, this->y * scalar);
    return result;
}

// ------------------------------------------------------------------------------

Vector Vector::operator=(const Vector* vector)
{
    this->setXY(vector->x, vector->y);
    return *this;
}