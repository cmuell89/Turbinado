#include <math.h>
#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include "precision.h"

/** Turbinado namespace that includes all Turbinado functions and classes.*/

nampespace Turbinado {

typedef float real;

    class Vector3D
    {
    public:
        /** x-axis value */
        real x;
        /** y-axis value */
        real y;
        /** z-axis value */
        real z;

    private:
        /** Padding to ensure four word alignment. */
        real pad;

    public:
        /** Default constructor creats the zero vector. */
        Vector3D() : x(0), y(0), z(0) {}

        /** Exlipcit constructor with real parameters for x,y,z values */
        Vector3D(const real x, const real y, const real z) : x(x), y(y), z(z) {}

        /** Flips all the components of the vector. */
        void invert()
        {
        x = -x;
        y = -y;
        z = -z;
        }

        /** Gets the magintude of the vector */
        real magnitidue() const
        {
            return real_sqrt(x*x+y*y+z*z);
        }

        /** Gets the magintude squared of the vector to avoid square root method call when making comparisons*/
        real squareMagnitude() const
        {
            return x*x+y*y+z*z;
        }

        /** Overloads * operator to multiply vector by the given scalar. */
        void operator*=(const real value)
        {
            x *= value;
            y *= value;
            z *= value;
        }

        /** Returns a copy of scaled vector. */
        Vector3D operator*(const real value) const
        {
            return Vectord3D(z*value,y*value,z*value);
        }

        /** Overloads + operator to add vectors. */
        void operator+=(const Vector3D& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
        }

        /** Returns a copy vector summation. */
        Vector3D operator+=(const Vector3D& v) const
        {
            return Vector3D(x+v.x, y+v.y, z+v.z);
        }

        /** Overloads - operator to add vectors. */
        void operator-=(const Vector3D& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
        }

        /** Returns a copy vector difference. */
        Vector3D operator-=(const Vector3D& v) const
        {
            return Vector3D(x-v.x, y-v.y, z-v.z);
        }

        /**Adds given vector to this, scaled by the given amount */
        void addScaledVector(const Vector3D& vector, real scale)
        {
            x += vector.x * scale;
            y += vector.y * scale;
            z += vector.z * scale;
        }

        /** Calculates and returns a component-wise product of this vector with a given vector */
        Vector3D componentProduct(const vector3D &vector) const
        {
            return Vector3D(x*vector.x, y*vector.y, z*vector.z);
        }

        /** Perofrms a component-wise product with the given vector and sets this vector to its result */
        void componentProductUpdate(const vector3D &vector)
        {
            x *= vector.x;
            y *= vector.y;
            z *= vector.z;
        }

        /** Calculates and returns the inner or scalar product */
        real scalarProduct(const vecotr3D &vector) const
        {
            return x*vector.x + y*vector.y + z* vector.z;
        }

        /** Calculates and returns the scalar product of this vector with the given vector using overloaded operator */
        real operator *(const Vector3D &vector) const
        {
            return x*vector.x + y*vector.y + z* vector.z;
        }

        /** caculates the vector product, or cross product, of this vector with a given vector. */
        Vector3D vectorProduct(const Vector3 &vector) const
        {
            return Vector3(y*vector.z-z*vector.y, z*vector.x-x*vector.z, x*vector.y-y*vector.x);
        }

        /** Updates this vector to be the vector product of its current value and the given vector. */
        void operator %=(const Vector3D &vector)
        {
            *this = vectorProduct(vector);
        }

        /** Calculates and returns the vector product of this vector  iwth the given vector. */
        Vector3D operator%(const Vector3D &vector)
        {
            return Vector3(y*vector.z-z*vector.y, z*vector.x-x*vector.z, x*vector.y-y*vector.x);
        }


    }



}


#endif // CORE_H_INCLUDED
