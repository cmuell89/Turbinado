#ifndef PRECISION_H_INCLUDED
#define PRECISION_H_INCLUDED

#include <float.h>

namespace turbinado {
#if 0
    /**
     * Defines we're in single precision mode, for any code
     * that needs to be conditionally compiled.
     */
    #definte SINGLE_PRECISION

    /**
     * Defines a real number precision. Turbinado can be compiled in
     * single or double precision versions. By default single precision is
     * provided.
     */
    typedef float real

    /** Defines the precision of the power operator. */
    #define real_pow powf

    ;
#else
    #define DOUBLE_PRECISION
    typedef double real;


#endif
}

#endif // PRECISION_H_INCLUDED
