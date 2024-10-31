
/*
**    _________   ____.____       _____   
**   /     \   \ /   /|    |     /  _  \  
**  /  \ /  \   Y   / |    |    /  /_\  \ 
** /    Y    \     /  |    |___/    |    \
** \____|__  /\___/   |_______ \____|__  /
**         \/                 \/       \/ 
**
** @title:        MVLA (Matrix-Vector Linear Algebra)
**
** @author:       Walker Rout
**
** @contact:      walkerrout04@gmail.com
**
** @date_written: March 16th, 2022
**
** @description:  Simple, header-only 2/3/4D vectors and related functions
**
** @license:      MIT
*/

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef MVLA_H
#define MVLA_H

// -----------------------------------------

/*
** INCLUDES
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------

/*
** ACCESS MODIFIER DEFINES
*/

#ifndef MVLADEF
#define MVLADEF extern
#endif // MVLADEF

#ifndef MVLAIMPL
#define MVLAIMPL inline
#endif // MVLADEF

// -----------------------------------------

/*
** PREPROCESSOR DEFINTIONS
*/

#define V2_ARGS(v) (v).x, (v).y
#define V3_ARGS(v) (v).x, (v).y, (v).z
#define V4_ARGS(v) (v).x, (v).y, (v).z, (v).w

// -----------------------------------------

/*
** USEFUL CONSTANT DEFINTIONS
*/

// 20 decimal precision
#define MVLA_E      2.71828182845904523536
#define MVLA_PI     3.14159265358979323846
#define MVLA_2PI    6.28318530717958623200
#define MVLA_4PI    12.56637061435917246399
#define MVLA_HALFPI 1.57079632679489655800
#define MVLA_SQRTPI 1.77245385090551588192
#define MVLA_SQRT2  1.41421356237309514547
#define MVLA_SQRT3  1.73205080756887719318
#define MVLA_LN2    0.69314718055994528623
#define MVLA_LN10   2.30258509299404590109
#define MVLA_LNPI   1.14472988584940016388
#define MVLA_LOGE   0.43429448190325181667

// -----------------------------------------

/*
** 2D VECTOR DEFINITIONS
*/

typedef struct v2i {
  signed int x, y;
} v2i_t;

typedef struct v2u {
  unsigned int x, y;
} v2u_t;

typedef struct v2f {
  float x, y;
} v2f_t;

typedef struct v2d {
  double x, y;
} v2d_t;

// -----------------------------------------

/*
** 3D VECTOR DEFINITIONS
*/

typedef struct v3i {
  signed int x, y, z;
} v3i_t;

typedef struct v3u {
  unsigned int x, y, z;
} v3u_t;

typedef struct v3f {
  float x, y, z;
} v3f_t;

typedef struct v3d {
  double x, y, z;
} v3d_t;

// -----------------------------------------

/*
** 4D VECTOR DEFINITIONS
*/

typedef struct v4i {
  signed int x, y, z, w;
} v4i_t;

typedef struct v4u {
  unsigned int x, y, z, w;
} v4u_t;

typedef struct v4f {
  float x, y, z, w;
} v4f_t;

typedef struct v4d {
  double x, y, z, w;
} v4d_t;

// -----------------------------------------

/*
** MATH FUNCTION PROTOTYPES
*/

/*
** Generates a random float between 0 and 1
** @returns: A random float between 0 and 1
*/
MVLADEF float randf();

/*
** Generates a random double between 0 and 1
** @returns: A random double between 0 and 1
*/
MVLADEF double randd();

/*
** Linearly interpolates between two floats
** @param a: The lower bound
** @param b: The upper bound
** @param t: The interpolation factor
** @returns: The interpolated float value
*/
MVLADEF float lerpf(float a, float b, float t);

/*
** Linearly interpolates between two doubles
** @param a: The lower bound
** @param b: The upper bound
** @param t: The interpolation factor
** @returns: The interpolated double value
*/
MVLADEF double lerpd(double a, double b, double t);

/*
** Finds the smaller of two signed integers
** @param a: The first integer
** @param b: The second integer
** @returns: The smaller of a and b
*/
MVLADEF signed int mini(signed int a, signed int b);

/*
** Finds the larger of two signed integers
** @param a: The first integer
** @param b: The second integer
** @returns: The larger of a and b
*/
MVLADEF signed int maxi(signed int a, signed int b);

/*
** Finds the smaller of two unsigned integers
** @param a: The first unsigned integer
** @param b: The second unsigned integer
** @returns: The smaller of a and b
*/
MVLADEF unsigned int minu(unsigned int a, unsigned int b);

/*
** Finds the larger of two unsigned integers
** @param a: The first unsigned integer
** @param b: The second unsigned integer
** @returns: The larger of a and b
*/
MVLADEF unsigned int maxu(unsigned int a, unsigned int b);

// -----------------------------------------

/*
** 2D VECTOR FUNCTION PROTOTYPES
*/

// v2i_t

/*
** Creates a 2D integer vector with specified x and y components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @returns: A new 2D integer vector
*/
MVLADEF v2i_t v2i(signed int x, signed int y);

/*
** Creates a 2D integer vector with the same x and y components
** @param x: The value for both x and y components
** @returns: A new 2D integer vector with identical x and y values
*/
MVLADEF v2i_t v2ii(signed int x);

/*
** Adds two 2D integer vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v2i_t v2i_add(v2i_t a, v2i_t b);

/*
** Subtracts the second 2D integer vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v2i_t v2i_sub(v2i_t a, v2i_t b);

/*
** Multiplies two 2D integer vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v2i_t v2i_mul(v2i_t a, v2i_t b);

/*
** Divides the components of the first 2D integer vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v2i_t v2i_div(v2i_t a, v2i_t b);

/*
** Finds the component-wise minimum of two 2D integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v2i_t v2i_min(v2i_t a, v2i_t b);

/*
** Finds the component-wise maximum of two 2D integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v2i_t v2i_max(v2i_t a, v2i_t b);

/*
** Prints the components of a 2D integer vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v2i_print(v2i_t a);

// v2u_t

/*
** Creates a 2D unsigned integer vector with specified x and y components.
** @param x: The x component of the vector.
** @param y: The y component of the vector.
** @returns: A new 2D unsigned integer vector.
*/
MVLADEF v2u_t v2u(unsigned int x, unsigned int y);

/*
** Creates a 2D unsigned integer vector with identical x and y components.
** @param x: The value for both x and y components.
** @returns: A new 2D unsigned integer vector with identical components.
*/
MVLADEF v2u_t v2uu(unsigned int x);

/*
** Adds two 2D unsigned integer vectors.
** @param a: The first vector to add.
** @param b: The second vector to add.
** @returns: The vector sum of a and b.
*/
MVLADEF v2u_t v2u_add(v2u_t a, v2u_t b);

/*
** Subtracts the second 2D unsigned integer vector from the first.
** @param a: The vector to subtract from.
** @param b: The vector to subtract.
** @returns: The vector difference between a and b.
*/
MVLADEF v2u_t v2u_sub(v2u_t a, v2u_t b);

/*
** Multiplies two 2D unsigned integer vectors component-wise.
** @param a: The first vector.
** @param b: The second vector.
** @returns: The component-wise product of a and b.
*/
MVLADEF v2u_t v2u_mul(v2u_t a, v2u_t b);

/*
** Divides the components of the first 2D unsigned integer vector by the second, component-wise.
** @param a: The vector to be divided.
** @param b: The vector to divide by.
** @returns: The component-wise quotient of a and b.
*/
MVLADEF v2u_t v2u_div(v2u_t a, v2u_t b);

/*
** Finds the component-wise minimum of two 2D unsigned integer vectors.
** @param a: The first vector.
** @param b: The second vector.
** @returns: A vector containing the minimum components of a and b.
*/
MVLADEF v2u_t v2u_min(v2u_t a, v2u_t b);

/*
** Finds the component-wise maximum of two 2D unsigned integer vectors.
** @param a: The first vector.
** @param b: The second vector.
** @returns: A vector containing the maximum components of a and b.
*/
MVLADEF v2u_t v2u_max(v2u_t a, v2u_t b);

/*
** Prints the components of a 2D unsigned integer vector.
** @param a: The vector to print.
** @returns: N/A
*/
MVLADEF void v2u_print(v2u_t a);

// v2f_t

/*
** Creates a 2D float vector with specified x and y components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @returns: A new 2D float vector
*/
MVLADEF v2f_t v2f(float x, float y);

/*
** Creates a 2D float vector with identical x and y components
** @param x: The value for both x and y components
** @returns: A new 2D float vector with identical components
*/
MVLADEF v2f_t v2ff(float x);

/*
** Adds two 2D float vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v2f_t v2f_add(v2f_t a, v2f_t b);

/*
** Subtracts the second 2D float vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v2f_t v2f_sub(v2f_t a, v2f_t b);

/*
** Multiplies two 2D float vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v2f_t v2f_mul(v2f_t a, v2f_t b);

/*
** Divides the components of the first 2D float vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v2f_t v2f_div(v2f_t a, v2f_t b);

/*
** Finds the component-wise minimum of two 2D float vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v2f_t v2f_min(v2f_t a, v2f_t b);

/*
** Finds the component-wise maximum of two 2D float vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v2f_t v2f_max(v2f_t a, v2f_t b);

/*
** Calculates the component-wise square root of a 2D float vector
** @param a: The vector to calculate the square root for
** @returns: The component-wise square root of a
*/
MVLADEF v2f_t v2f_sqrt(v2f_t a);

/*
** Raises each component of a 2D float vector to a specified exponent
** @param a: The vector to raise to the power
** @param exp: The exponent to apply to each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v2f_t v2f_poww(v2f_t a, float exp);

/*
** Raises each component of a 2D float vector to the power of the corresponding component in another vector
** @param a: The vector to raise to the power
** @param exp: The vector containing the exponents for each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v2f_t v2f_pow(v2f_t a, v2f_t exp);

/*
** Calculates the component-wise exponential of a 2D float vector
** @param a: The vector to exponentiate
** @returns: The component-wise exponential of a
*/
MVLADEF v2f_t v2f_exp(v2f_t a);

/*
** Calculates the component-wise sine of a 2D float vector
** @param a: The vector to apply sine to
** @returns: The component-wise sine of a
*/
MVLADEF v2f_t v2f_sin(v2f_t a);

/*
** Calculates the component-wise cosine of a 2D float vector
** @param a: The vector to apply cosine to
** @returns: The component-wise cosine of a
*/
MVLADEF v2f_t v2f_cos(v2f_t a);

/*
** Calculates the component-wise tangent of a 2D float vector
** @param a: The vector to apply tangent to
** @returns: The component-wise tangent of a
*/
MVLADEF v2f_t v2f_tan(v2f_t a);

/*
** Calculates the magnitude (length) of a 2D float vector
** @param a: The vector to find the length of
** @returns: The magnitude of the vector a
*/
MVLADEF float v2f_len(v2f_t a);

/*
** Calculates the squared magnitude of a 2D float vector
** @param a: The vector to find the squared length of
** @returns: The squared magnitude of the vector a
*/
MVLADEF float v2f_sqr_len(v2f_t a);

/*
** Prints the components of a 2D float vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v2f_print(v2f_t a);

// v2d_t

/*
** Creates a 2D double vector with specified x and y components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @returns: A new 2D double vector
*/
MVLADEF v2d_t v2d(double x, double y);

/*
** Creates a 2D double vector with identical x and y components
** @param x: The value for both x and y components
** @returns: A new 2D double vector with identical components
*/
MVLADEF v2d_t v2dd(double x);

/*
** Adds two 2D double vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v2d_t v2d_add(v2d_t a, v2d_t b);

/*
** Subtracts the second 2D double vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v2d_t v2d_sub(v2d_t a, v2d_t b);

/*
** Multiplies two 2D double vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v2d_t v2d_mul(v2d_t a, v2d_t b);

/*
** Divides the components of the first 2D double vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v2d_t v2d_div(v2d_t a, v2d_t b);

/*
** Finds the component-wise minimum of two 2D double vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v2d_t v2d_min(v2d_t a, v2d_t b);

/*
** Finds the component-wise maximum of two 2D double vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v2d_t v2d_max(v2d_t a, v2d_t b);

/*
** Calculates the component-wise square root of a 2D double vector
** @param a: The vector to calculate the square root for
** @returns: The component-wise square root of a
*/
MVLADEF v2d_t v2d_sqrt(v2d_t a);

/*
** Raises each component of a 2D double vector to a specified exponent
** @param a: The vector to raise to the power
** @param exp: The exponent to apply to each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v2d_t v2d_poww(v2d_t a, double exp);

/*
** Raises each component of a 2D double vector to the power of the corresponding component in another vector
** @param a: The vector to raise to the power
** @param exp: The vector containing the exponents for each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v2d_t v2d_pow(v2d_t a, v2d_t exp);

/*
** Calculates the component-wise exponential of a 2D double vector
** @param a: The vector to exponentiate
** @returns: The component-wise exponential of a
*/
MVLADEF v2d_t v2d_exp(v2d_t a);

/*
** Calculates the component-wise sine of a 2D double vector
** @param a: The vector to apply sine to
** @returns: The component-wise sine of a
*/
MVLADEF v2d_t v2d_sin(v2d_t a);

/*
** Calculates the component-wise cosine of a 2D double vector
** @param a: The vector to apply cosine to
** @returns: The component-wise cosine of a
*/
MVLADEF v2d_t v2d_cos(v2d_t a);

/*
** Calculates the component-wise tangent of a 2D double vector
** @param a: The vector to apply tangent to
** @returns: The component-wise tangent of a
*/
MVLADEF v2d_t v2d_tan(v2d_t a);

/*
** Calculates the magnitude (length) of a 2D double vector
** @param a: The vector to find the length of
** @returns: The magnitude of the vector a
*/
MVLADEF double v2d_len(v2d_t a);

/*
** Calculates the squared magnitude of a 2D double vector
** @param a: The vector to find the squared length of
** @returns: The squared magnitude of the vector a
*/
MVLADEF double v2d_sqr_len(v2d_t a);

/*
** Prints the components of a 2D double vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v2d_print(v2d_t a);

// -----------------------------------------

/*
** 3D VECTOR FUNCTION PROTOTYPES
*/

// v3i_t

/*
** Creates a 3D signed integer vector with specified x, y, and z components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @returns: A new 3D signed integer vector
*/
MVLADEF v3i_t v3i(signed int x, signed int y, signed int z);

/*
** Creates a 3D signed integer vector with identical x, y, and z components
** @param x: The value for all components
** @returns: A new 3D signed integer vector with identical components
*/
MVLADEF v3i_t v3ii(signed int x);

/*
** Adds two 3D signed integer vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v3i_t v3i_add(v3i_t a, v3i_t b);

/*
** Subtracts the second 3D signed integer vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v3i_t v3i_sub(v3i_t a, v3i_t b);

/*
** Multiplies two 3D signed integer vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v3i_t v3i_mul(v3i_t a, v3i_t b);

/*
** Divides the components of the first 3D signed integer vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v3i_t v3i_div(v3i_t a, v3i_t b);

/*
** Finds the component-wise minimum of two 3D signed integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v3i_t v3i_min(v3i_t a, v3i_t b);

/*
** Finds the component-wise maximum of two 3D signed integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v3i_t v3i_max(v3i_t a, v3i_t b);

/*
** Prints the components of a 3D signed integer vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v3i_print(v3i_t a);

// v3u_t

/*
** Creates a 3D unsigned integer vector with specified x, y, and z components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @returns: A new 3D unsigned integer vector
*/
MVLADEF v3u_t v3u(unsigned int x, unsigned int y, unsigned int z);

/*
** Creates a 3D unsigned integer vector with identical x, y, and z components
** @param x: The value for all components
** @returns: A new 3D unsigned integer vector with identical components
*/
MVLADEF v3u_t v3uu(unsigned int x);

/*
** Adds two 3D unsigned integer vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v3u_t v3u_add(v3u_t a, v3u_t b);

/*
** Subtracts the second 3D unsigned integer vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v3u_t v3u_sub(v3u_t a, v3u_t b);

/*
** Multiplies two 3D unsigned integer vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v3u_t v3u_mul(v3u_t a, v3u_t b);

/*
** Divides the components of the first 3D unsigned integer vector by the second, 
** component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v3u_t v3u_div(v3u_t a, v3u_t b);

/*
** Finds the component-wise minimum of two 3D unsigned integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v3u_t v3u_min(v3u_t a, v3u_t b);

/*
** Finds the component-wise maximum of two 3D unsigned integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v3u_t v3u_max(v3u_t a, v3u_t b);

/*
** Prints the components of a 3D unsigned integer vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v3u_print(v3u_t a);

// v3f_t

/*
** Creates a 3D float vector with specified x, y, and z components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @returns: A new 3D float vector
*/
MVLADEF v3f_t v3f(float x, float y, float z);

/*
** Creates a 3D float vector with identical x, y, and z components
** @param x: The value for all components
** @returns: A new 3D float vector with identical components
*/
MVLADEF v3f_t v3ff(float x);

/*
** Adds two 3D float vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v3f_t v3f_add(v3f_t a, v3f_t b);

/*
** Subtracts the second 3D float vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v3f_t v3f_sub(v3f_t a, v3f_t b);

/*
** Multiplies two 3D float vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v3f_t v3f_mul(v3f_t a, v3f_t b);

/*
** Divides the components of the first 3D float vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v3f_t v3f_div(v3f_t a, v3f_t b);

/*
** Finds the component-wise minimum of two 3D float vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v3f_t v3f_min(v3f_t a, v3f_t b);

/*
** Finds the component-wise maximum of two 3D float vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v3f_t v3f_max(v3f_t a, v3f_t b);

/*
** Calculates the component-wise square root of a 3D float vector
** @param a: The vector to calculate the square root for
** @returns: The component-wise square root of a
*/
MVLADEF v3f_t v3f_sqrt(v3f_t a);

/*
** Raises each component of a 3D float vector to a specified exponent
** @param a: The vector to raise to the power
** @param exp: The exponent to apply to each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v3f_t v3f_poww(v3f_t a, float exp);

/*
** Raises each component of a 3D float vector to the power of the corresponding component in another vector
** @param a: The vector to raise to the power
** @param exp: The vector containing the exponents for each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v3f_t v3f_pow(v3f_t a, v3f_t exp);

/*
** Calculates the component-wise exponential of a 3D float vector
** @param a: The vector to exponentiate
** @returns: The component-wise exponential of a
*/
MVLADEF v3f_t v3f_exp(v3f_t a);

/*
** Calculates the component-wise sine of a 3D float vector
** @param a: The vector to apply sine to
** @returns: The component-wise sine of a
*/
MVLADEF v3f_t v3f_sin(v3f_t a);

/*
** Calculates the component-wise cosine of a 3D float vector
** @param a: The vector to apply cosine to
** @returns: The component-wise cosine of a
*/
MVLADEF v3f_t v3f_cos(v3f_t a);

/*
** Calculates the component-wise tangent of a 3D float vector
** @param a: The vector to apply tangent to
** @returns: The component-wise tangent of a
*/
MVLADEF v3f_t v3f_tan(v3f_t a);

/*
** Calculates the magnitude (length) of a 3D float vector
** @param a: The vector to find the length of
** @returns: The magnitude of the vector a
*/
MVLADEF float v3f_len(v3f_t a);

/*
** Calculates the squared magnitude of a 3D float vector
** @param a: The vector to find the squared length of
** @returns: The squared magnitude of the vector a
*/
MVLADEF float v3f_sqr_len(v3f_t a);

/*
** Prints the components of a 3D float vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v3f_print(v3f_t a);

// v3d_t

/*
** Creates a 3D double vector with specified x, y, and z components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @returns: A new 3D double vector
*/
MVLADEF v3d_t v3d(double x, double y, double z);

/*
** Creates a 3D double vector with identical x, y, and z components
** @param x: The value for all components
** @returns: A new 3D double vector with identical components
*/
MVLADEF v3d_t v3dd(double x);

/*
** Adds two 3D double vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v3d_t v3d_add(v3d_t a, v3d_t b);

/*
** Subtracts the second 3D double vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v3d_t v3d_sub(v3d_t a, v3d_t b);

/*
** Multiplies two 3D double vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v3d_t v3d_mul(v3d_t a, v3d_t b);

/*
** Divides the components of the first 3D double vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v3d_t v3d_div(v3d_t a, v3d_t b);

/*
** Finds the component-wise minimum of two 3D double vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v3d_t v3d_min(v3d_t a, v3d_t b);

/*
** Finds the component-wise maximum of two 3D double vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v3d_t v3d_max(v3d_t a, v3d_t b);

/*
** Calculates the component-wise square root of a 3D double vector
** @param a: The vector to calculate the square root for
** @returns: The component-wise square root of a
*/
MVLADEF v3d_t v3d_sqrt(v3d_t a);

/*
** Raises each component of a 3D double vector to a specified exponent
** @param a: The vector to raise to the power
** @param exp: The exponent to apply to each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v3d_t v3d_poww(v3d_t a, double exp);

/*
** Raises each component of a 3D double vector to the power of the corresponding component in another vector
** @param a: The vector to raise to the power
** @param exp: The vector containing the exponents for each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v3d_t v3d_pow(v3d_t a, v3d_t exp);

/*
** Calculates the component-wise exponential of a 3D double vector
** @param a: The vector to exponentiate
** @returns: The component-wise exponential of a
*/
MVLADEF v3d_t v3d_exp(v3d_t a);

/*
** Calculates the component-wise sine of a 3D double vector
** @param a: The vector to apply sine to
** @returns: The component-wise sine of a
*/
MVLADEF v3d_t v3d_sin(v3d_t a);

/*
** Calculates the component-wise cosine of a 3D double vector
** @param a: The vector to apply cosine to
** @returns: The component-wise cosine of a
*/
MVLADEF v3d_t v3d_cos(v3d_t a);

/*
** Calculates the component-wise tangent of a 3D double vector
** @param a: The vector to apply tangent to
** @returns: The component-wise tangent of a
*/
MVLADEF v3d_t v3d_tan(v3d_t a);

/*
** Calculates the magnitude (length) of a 3D double vector
** @param a: The vector to find the length of
** @returns: The magnitude of the vector a
*/
MVLADEF double v3d_len(v3d_t a);

/*
** Calculates the squared magnitude of a 3D double vector
** @param a: The vector to find the squared length of
** @returns: The squared magnitude of the vector a
*/
MVLADEF double v3d_sqr_len(v3d_t a);

/*
** Prints the components of a 3D double vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v3d_print(v3d_t a);

// -----------------------------------------

/*
** 4D VECTOR FUNCTION PROTOTYPES
*/

// v4i_t

/*
** Creates a 4D signed integer vector with specified x, y, z, and w components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @param w: The w component of the vector
** @returns: A new 4D signed integer vector
*/
MVLADEF v4i_t v4i(signed int x, signed int y, signed int z, signed int w);

/*
** Creates a 4D signed integer vector with identical x, y, z, and w components
** @param x: The value for all components
** @returns: A new 4D signed integer vector with identical components
*/
MVLADEF v4i_t v4ii(signed int x);

/*
** Adds two 4D signed integer vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v4i_t v4i_add(v4i_t a, v4i_t b);

/*
** Subtracts the second 4D signed integer vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v4i_t v4i_sub(v4i_t a, v4i_t b);

/*
** Multiplies two 4D signed integer vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v4i_t v4i_mul(v4i_t a, v4i_t b);

/*
** Divides the components of the first 4D signed integer vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v4i_t v4i_div(v4i_t a, v4i_t b);

/*
** Finds the component-wise minimum of two 4D signed integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v4i_t v4i_min(v4i_t a, v4i_t b);

/*
** Finds the component-wise maximum of two 4D signed integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v4i_t v4i_max(v4i_t a, v4i_t b);

/*
** Prints the components of a 4D signed integer vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v4i_print(v4i_t a);

// v4u_t

/*
** Creates a 4D unsigned integer vector with specified x, y, z, and w components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @param w: The w component of the vector
** @returns: A new 4D unsigned integer vector
*/
MVLADEF v4u_t v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w);

/*
** Creates a 4D unsigned integer vector with identical x, y, z, and w components
** @param x: The value for all components
** @returns: A new 4D unsigned integer vector with identical components
*/
MVLADEF v4u_t v4uu(unsigned int x);

/*
** Adds two 4D unsigned integer vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v4u_t v4u_add(v4u_t a, v4u_t b);

/*
** Subtracts the second 4D unsigned integer vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v4u_t v4u_sub(v4u_t a, v4u_t b);

/*
** Multiplies two 4D unsigned integer vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v4u_t v4u_mul(v4u_t a, v4u_t b);

/*
** Divides the components of the first 4D unsigned integer vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v4u_t v4u_div(v4u_t a, v4u_t b);

/*
** Finds the component-wise minimum of two 4D unsigned integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v4u_t v4u_min(v4u_t a, v4u_t b);

/*
** Finds the component-wise maximum of two 4D unsigned integer vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v4u_t v4u_max(v4u_t a, v4u_t b);

/*
** Prints the components of a 4D unsigned integer vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v4u_print(v4u_t a);

// v4f_t

/*
** Creates a 4D float vector with specified x, y, z, and w components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @param w: The w component of the vector
** @returns: A new 4D float vector
*/
MVLADEF v4f_t v4f(float x, float y, float z, float w);

/*
** Creates a 4D float vector with identical x, y, z, and w components
** @param x: The value for all components
** @returns: A new 4D float vector with identical components
*/
MVLADEF v4f_t v4ff(float x);

/*
** Adds two 4D float vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v4f_t v4f_add(v4f_t a, v4f_t b);

/*
** Subtracts the second 4D float vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v4f_t v4f_sub(v4f_t a, v4f_t b);

/*
** Multiplies two 4D float vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v4f_t v4f_mul(v4f_t a, v4f_t b);

/*
** Divides the components of the first 4D float vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v4f_t v4f_div(v4f_t a, v4f_t b);

/*
** Finds the component-wise minimum of two 4D float vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v4f_t v4f_min(v4f_t a, v4f_t b);

/*
** Finds the component-wise maximum of two 4D float vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v4f_t v4f_max(v4f_t a, v4f_t b);

/*
** Calculates the component-wise square root of a 4D float vector
** @param a: The vector to calculate the square root for
** @returns: The component-wise square root of a
*/
MVLADEF v4f_t v4f_sqrt(v4f_t a);

/*
** Raises each component of a 4D float vector to a specified exponent
** @param a: The vector to raise to the power
** @param exp: The exponent to apply to each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v4f_t v4f_poww(v4f_t a, float exp);

/*
** Raises each component of a 4D float vector to the power of the corresponding component in another vector
** @param a: The vector to raise to the power
** @param exp: The vector containing the exponents for each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v4f_t v4f_pow(v4f_t a, v4f_t exp);

/*
** Calculates the component-wise exponential of a 4D float vector
** @param a: The vector to exponentiate
** @returns: The component-wise exponential of a
*/
MVLADEF v4f_t v4f_exp(v4f_t a);

/*
** Calculates the component-wise sine of a 4D float vector
** @param a: The vector to apply sine to
** @returns: The component-wise sine of a
*/
MVLADEF v4f_t v4f_sin(v4f_t a);

/*
** Calculates the component-wise cosine of a 4D float vector
** @param a: The vector to apply cosine to
** @returns: The component-wise cosine of a
*/
MVLADEF v4f_t v4f_cos(v4f_t a);

/*
** Calculates the component-wise tangent of a 4D float vector
** @param a: The vector to apply tangent to
** @returns: The component-wise tangent of a
*/
MVLADEF v4f_t v4f_tan(v4f_t a);

/*
** Calculates the magnitude (length) of a 4D float vector
** @param a: The vector to find the length of
** @returns: The magnitude of the vector a
*/
MVLADEF float v4f_len(v4f_t a);

/*
** Calculates the squared magnitude of a 4D float vector
** @param a: The vector to find the squared length of
** @returns: The squared magnitude of the vector a
*/
MVLADEF float v4f_sqr_len(v4f_t a);

/*
** Prints the components of a 4D float vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v4f_print(v4f_t a);

// v4d_t

/*
** Creates a 4D double vector with specified x, y, z, and w components
** @param x: The x component of the vector
** @param y: The y component of the vector
** @param z: The z component of the vector
** @param w: The w component of the vector
** @returns: A new 4D double vector
*/
MVLADEF v4d_t v4d(double x, double y, double z, double w);

/*
** Creates a 4D double vector with identical x, y, z, and w components
** @param x: The value for all components
** @returns: A new 4D double vector with identical components
*/
MVLADEF v4d_t v4dd(double x);

/*
** Adds two 4D double vectors
** @param a: The first vector to add
** @param b: The second vector to add
** @returns: The vector sum of a and b
*/
MVLADEF v4d_t v4d_add(v4d_t a, v4d_t b);

/*
** Subtracts the second 4D double vector from the first
** @param a: The vector to subtract from
** @param b: The vector to subtract
** @returns: The vector difference between a and b
*/
MVLADEF v4d_t v4d_sub(v4d_t a, v4d_t b);

/*
** Multiplies two 4D double vectors component-wise
** @param a: The first vector
** @param b: The second vector
** @returns: The component-wise product of a and b
*/
MVLADEF v4d_t v4d_mul(v4d_t a, v4d_t b);

/*
** Divides the components of the first 4D double vector by the second, component-wise
** @param a: The vector to be divided
** @param b: The vector to divide by
** @returns: The component-wise quotient of a and b
*/
MVLADEF v4d_t v4d_div(v4d_t a, v4d_t b);

/*
** Finds the component-wise minimum of two 4D double vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the minimum components of a and b
*/
MVLADEF v4d_t v4d_min(v4d_t a, v4d_t b);

/*
** Finds the component-wise maximum of two 4D double vectors
** @param a: The first vector
** @param b: The second vector
** @returns: A vector containing the maximum components of a and b
*/
MVLADEF v4d_t v4d_max(v4d_t a, v4d_t b);

/*
** Calculates the component-wise square root of a 4D double vector
** @param a: The vector to calculate the square root for
** @returns: The component-wise square root of a
*/
MVLADEF v4d_t v4d_sqrt(v4d_t a);

/*
** Raises each component of a 4D double vector to a specified exponent
** @param a: The vector to raise to the power
** @param exp: The exponent to apply to each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v4d_t v4d_poww(v4d_t a, double exp);

/*
** Raises each component of a 4D double vector to the power of the corresponding component in another vector
** @param a: The vector to raise to the power
** @param exp: The vector containing the exponents for each component
** @returns: The component-wise power of a raised to exp
*/
MVLADEF v4d_t v4d_pow(v4d_t a, v4d_t exp);

/*
** Calculates the component-wise exponential of a 4D double vector
** @param a: The vector to exponentiate
** @returns: The component-wise exponential of a
*/
MVLADEF v4d_t v4d_exp(v4d_t a);

/*
** Calculates the component-wise sine of a 4D double vector
** @param a: The vector to apply sine to
** @returns: The component-wise sine of a
*/
MVLADEF v4d_t v4d_sin(v4d_t a);

/*
** Calculates the component-wise cosine of a 4D double vector
** @param a: The vector to apply cosine to
** @returns: The component-wise cosine of a
*/
MVLADEF v4d_t v4d_cos(v4d_t a);

/*
** Calculates the component-wise tangent of a 4D double vector
** @param a: The vector to apply tangent to
** @returns: The component-wise tangent of a
*/
MVLADEF v4d_t v4d_tan(v4d_t a);

/*
** Calculates the magnitude (length) of a 4D double vector
** @param a: The vector to find the length of
** @returns: The magnitude of the vector a
*/
MVLADEF double v4d_len(v4d_t a);

/*
** Calculates the squared magnitude of a 4D double vector
** @param a: The vector to find the squared length of
** @returns: The squared magnitude of the vector a
*/
MVLADEF double v4d_sqr_len(v4d_t a);

/*
** Prints the components of a 4D double vector
** @param a: The vector to print
** @returns: N/A
*/
MVLADEF void v4d_print(v4d_t a);

// -----------------------------------------

#endif // MVLA_H

/*
** HEADER ONLY IMPLEMENTATION
*/

#ifdef MVLA_IMPLEMENTATION

// -----------------------------------------

MVLAIMPL float randf() {
  // assume we have seeded srand first to use rand
  return ((float) rand()) /
         ((float) RAND_MAX);
}

MVLAIMPL double randd() {
  return ((double) rand()) /
         ((double) RAND_MAX);
}

MVLAIMPL float lerpf(float a, float b, float t) {
  return a + ((b - a) * t);
}

MVLAIMPL double lerpd(double a, double b, double t) {
  return a + ((b - a) * t);
}

MVLAIMPL signed int mini(signed int a, signed int b) {
  return (a < b) ? a : b;
}

MVLAIMPL signed int maxi(signed int a, signed int b) {
  return (a < b) ? b : a;
}

MVLAIMPL unsigned int minu(unsigned int a, unsigned int b) {
  return (a < b) ? a : b;
}

MVLAIMPL unsigned int maxu(unsigned int a, unsigned int b) {
  return (a < b) ? b : a;
}

// -----------------------------------------

MVLAIMPL v2i_t v2i(signed int x, signed int y) {
  v2i_t vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLAIMPL v2i_t v2ii(signed int x) { 
  return v2i(x, x); 
}

MVLAIMPL v2i_t v2i_add(v2i_t a, v2i_t b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLAIMPL v2i_t v2i_sub(v2i_t a, v2i_t b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLAIMPL v2i_t v2i_mul(v2i_t a, v2i_t b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLAIMPL v2i_t v2i_div(v2i_t a, v2i_t b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLAIMPL v2i_t v2i_min(v2i_t a, v2i_t b) {
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  return a;
}

MVLAIMPL v2i_t v2i_max(v2i_t a, v2i_t b) {
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  return a;
}

MVLAIMPL void v2i_print(v2i_t a) {
  printf("v2i_t(%d, %d)\n", V2_ARGS(a));
}

MVLAIMPL v2u_t v2u(unsigned int x, unsigned int y) {
  v2u_t vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLAIMPL v2u_t v2uu(unsigned int x) { 
  return v2u(x, x); 
}

MVLAIMPL v2u_t v2u_add(v2u_t a, v2u_t b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLAIMPL v2u_t v2u_sub(v2u_t a, v2u_t b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLAIMPL v2u_t v2u_mul(v2u_t a, v2u_t b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLAIMPL v2u_t v2u_div(v2u_t a, v2u_t b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLAIMPL v2u_t v2u_min(v2u_t a, v2u_t b) {
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  return a;
}

MVLAIMPL v2u_t v2u_max(v2u_t a, v2u_t b) {
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  return a;
}

MVLAIMPL void v2u_print(v2u_t a) {
  printf("v2u_t(%u, %u)\n", V2_ARGS(a));
}

MVLAIMPL v2f_t v2f(float x, float y) {
  v2f_t vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLAIMPL v2f_t v2ff(float x) { 
  return v2f(x, x); 
}

MVLAIMPL v2f_t v2f_add(v2f_t a, v2f_t b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLAIMPL v2f_t v2f_sub(v2f_t a, v2f_t b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLAIMPL v2f_t v2f_mul(v2f_t a, v2f_t b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLAIMPL v2f_t v2f_div(v2f_t a, v2f_t b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLAIMPL v2f_t v2f_min(v2f_t a, v2f_t b) {
  a.x = fminf(a.x, b.x);
  a.y = fminf(a.y, b.y);
  return a;
}

MVLAIMPL v2f_t v2f_max(v2f_t a, v2f_t b) {
  a.x = fmaxf(a.x, b.x);
  a.y = fmaxf(a.y, b.y);
  return a;
}

MVLAIMPL v2f_t v2f_sqrt(v2f_t a) {
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  return a;
}

MVLAIMPL v2f_t v2f_poww(v2f_t a, float exp) {
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  return a;
}

MVLAIMPL v2f_t v2f_pow(v2f_t a, v2f_t exp) {
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  return a;
}

MVLAIMPL v2f_t v2f_exp(v2f_t a) {
  a.x = powf(MVLA_E, a.x);
  a.y = powf(MVLA_E, a.y);
  return a;
}

MVLAIMPL v2f_t v2f_sin(v2f_t a) {
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  return a;
}

MVLAIMPL v2f_t v2f_cos(v2f_t a) {
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  return a;
}

MVLAIMPL v2f_t v2f_tan(v2f_t a) {
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  return a;
}

MVLAIMPL float v2f_len(v2f_t a) {
  return sqrtf(v2f_sqr_len(a));
}

MVLAIMPL float v2f_sqr_len(v2f_t a) {
  return a.x * a.x + a.y * a.y;
}

MVLAIMPL void v2f_print(v2f_t a) {
  printf("v2f_t(%f, %f)\n", V2_ARGS(a));
}

MVLAIMPL v2d_t v2d(double x, double y) {
  v2d_t vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLAIMPL v2d_t v2dd(double x) {
  return v2d(x, x);
}

MVLAIMPL v2d_t v2d_add(v2d_t a, v2d_t b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLAIMPL v2d_t v2d_sub(v2d_t a, v2d_t b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLAIMPL v2d_t v2d_mul(v2d_t a, v2d_t b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLAIMPL v2d_t v2d_div(v2d_t a, v2d_t b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLAIMPL v2d_t v2d_min(v2d_t a, v2d_t b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  return a;
}

MVLAIMPL v2d_t v2d_max(v2d_t a, v2d_t b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  return a;
}

MVLAIMPL v2d_t v2d_sqrt(v2d_t a) {
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  return a;
}

MVLAIMPL v2d_t v2d_poww(v2d_t a, double exp) {
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  return a;
}

MVLAIMPL v2d_t v2d_pow(v2d_t a, v2d_t exp) {
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  return a;
}

MVLAIMPL v2d_t v2d_exp(v2d_t a) {
  a.x = pow(MVLA_E, a.x);
  a.y = pow(MVLA_E, a.y);
  return a;
}

MVLAIMPL v2d_t v2d_sin(v2d_t a) {
  a.x = sin(a.x);
  a.y = sin(a.y);
  return a;
}

MVLAIMPL v2d_t v2d_cos(v2d_t a) {
  a.x = cos(a.x);
  a.y = cos(a.y);
  return a;
}

MVLAIMPL v2d_t v2d_tan(v2d_t a) {
  a.x = tan(a.x);
  a.y = tan(a.y);
  return a;
}

MVLAIMPL double v2d_len(v2d_t a) {
  return sqrt(v2d_sqr_len(a));
}

MVLAIMPL double v2d_sqr_len(v2d_t a) {
  return a.x * a.x + a.y * a.y;
}

MVLAIMPL void v2d_print(v2d_t a) {
  printf("v2d_t(%lf, %lf)\n", V2_ARGS(a));
}

// -----------------------------------------

MVLAIMPL v3i_t v3i(signed int x, signed int y, signed int z) {
  v3i_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLAIMPL v3i_t v3ii(signed int x) {
  return v3i(x, x, x);
}

MVLAIMPL v3i_t v3i_add(v3i_t a, v3i_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLAIMPL v3i_t v3i_sub(v3i_t a, v3i_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLAIMPL v3i_t v3i_mul(v3i_t a, v3i_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLAIMPL v3i_t v3i_div(v3i_t a, v3i_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLAIMPL v3i_t v3i_min(v3i_t a, v3i_t b) {
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  a.z = mini(a.z, b.z);
  return a;
}

MVLAIMPL v3i_t v3i_max(v3i_t a, v3i_t b) {
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  a.z = maxi(a.z, b.z);
  return a;
}

MVLAIMPL void v3i_print(v3i_t a) {
  printf("v3i_t(%d, %d, %d)\n", V3_ARGS(a));
}

MVLAIMPL v3u_t v3u(unsigned int x, unsigned int y, unsigned int z) {
  v3u_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLAIMPL v3u_t v3uu(unsigned int x) {
  return v3u(x, x, x);
}

MVLAIMPL v3u_t v3u_add(v3u_t a, v3u_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLAIMPL v3u_t v3u_sub(v3u_t a, v3u_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLAIMPL v3u_t v3u_mul(v3u_t a, v3u_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLAIMPL v3u_t v3u_div(v3u_t a, v3u_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLAIMPL v3u_t v3u_min(v3u_t a, v3u_t b) {
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  a.z = minu(a.z, b.z);
  return a;
}

MVLAIMPL v3u_t v3u_max(v3u_t a, v3u_t b) {
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  a.z = maxu(a.z, b.z);
  return a;
}

MVLAIMPL void v3u_print(v3u_t a) {
  printf("v3u_t(%u, %u, %u)\n", V3_ARGS(a));
}

MVLAIMPL v3f_t v3f(float x, float y, float z) {
  v3f_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLAIMPL v3f_t v3ff(float x) {
  return v3f(x, x, x);
}

MVLAIMPL v3f_t v3f_add(v3f_t a, v3f_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLAIMPL v3f_t v3f_sub(v3f_t a, v3f_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLAIMPL v3f_t v3f_mul(v3f_t a, v3f_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLAIMPL v3f_t v3f_div(v3f_t a, v3f_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLAIMPL v3f_t v3f_min(v3f_t a, v3f_t b) {
  a.x = fminf(a.x, b.x);
  a.y = fminf(a.y, b.y);
  a.z = fminf(a.z, b.z);
  return a;
}

MVLAIMPL v3f_t v3f_max(v3f_t a, v3f_t b) {
  a.x = fmaxf(a.x, b.x);
  a.y = fmaxf(a.y, b.y);
  a.z = fmaxf(a.z, b.z);
  return a;
}

MVLAIMPL v3f_t v3f_sqrt(v3f_t a) {
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  a.z = sqrtf(a.z);
  return a;
}

MVLAIMPL v3f_t v3f_poww(v3f_t a, float exp) {
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  a.z = powf(a.z, exp);
  return a;
}

MVLAIMPL v3f_t v3f_pow(v3f_t a, v3f_t exp) {
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  a.z = powf(a.z, exp.z);
  return a;
}

MVLAIMPL v3f_t v3f_exp(v3f_t a) {
  a.x = powf(MVLA_E, a.x);
  a.y = powf(MVLA_E, a.y);
  a.z = powf(MVLA_E, a.z);
  return a;
}

MVLAIMPL v3f_t v3f_sin(v3f_t a) {
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  a.z = sinf(a.z);
  return a;
}

MVLAIMPL v3f_t v3f_cos(v3f_t a) {
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  a.z = cosf(a.z);
  return a;
}

MVLAIMPL v3f_t v3f_tan(v3f_t a) {
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  a.z = tanf(a.z);
  return a;
}

MVLAIMPL float v3f_len(v3f_t a) {
  return sqrtf(v3f_sqr_len(a));
}

MVLAIMPL float v3f_sqr_len(v3f_t a) {
  return a.x * a.x + a.y * a.y + a.z * a.z;
}

MVLAIMPL void v3f_print(v3f_t a) {
  printf("v3f_t(%f, %f, %f)\n", V3_ARGS(a));
}

MVLAIMPL v3d_t v3d(double x, double y, double z) {
  v3d_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLAIMPL v3d_t v3dd(double x) {
  return v3d(x, x, x);
}

MVLAIMPL v3d_t v3d_add(v3d_t a, v3d_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLAIMPL v3d_t v3d_sub(v3d_t a, v3d_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLAIMPL v3d_t v3d_mul(v3d_t a, v3d_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLAIMPL v3d_t v3d_div(v3d_t a, v3d_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLAIMPL v3d_t v3d_min(v3d_t a, v3d_t b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  return a;
}

MVLAIMPL v3d_t v3d_max(v3d_t a, v3d_t b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  return a;
}

MVLAIMPL v3d_t v3d_sqrt(v3d_t a) {
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  a.z = sqrt(a.z);
  return a;
}

MVLAIMPL v3d_t v3d_poww(v3d_t a, double exp) {
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  a.z = pow(a.z, exp);
  return a;
}

MVLAIMPL v3d_t v3d_pow(v3d_t a, v3d_t exp) {
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  a.z = pow(a.z, exp.z);
  return a;
}

MVLAIMPL v3d_t v3d_exp(v3d_t a) {
  a.x = pow(MVLA_E, a.x);
  a.y = pow(MVLA_E, a.y);
  a.z = pow(MVLA_E, a.z);
  return a;
}

MVLAIMPL v3d_t v3d_sin(v3d_t a) {
  a.x = sin(a.x);
  a.y = sin(a.y);
  a.z = sin(a.z);
  return a;
}

MVLAIMPL v3d_t v3d_cos(v3d_t a) {
  a.x = cos(a.x);
  a.y = cos(a.y);
  a.z = cos(a.z);
  return a;
}

MVLAIMPL v3d_t v3d_tan(v3d_t a) {
  a.x = tan(a.x);
  a.y = tan(a.y);
  a.z = tan(a.z);
  return a;
}

MVLAIMPL double v3d_len(v3d_t a) {
  return sqrt(v3d_sqr_len(a));
}

MVLAIMPL double v3d_sqr_len(v3d_t a) {
  return a.x * a.x + a.y * a.y + a.z * a.z;
}

MVLAIMPL void v3d_print(v3d_t a) {
  printf("v3d_t(%lf, %lf, %lf)\n", V3_ARGS(a));
}

// -----------------------------------------

MVLAIMPL v4i_t v4i(signed int x, signed int y, signed int z, signed int w) {
  v4i_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLAIMPL v4i_t v4ii(signed int x) {
  return v4i(x, x, x, x);
}

MVLAIMPL v4i_t v4i_add(v4i_t a, v4i_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLAIMPL v4i_t v4i_sub(v4i_t a, v4i_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLAIMPL v4i_t v4i_mul(v4i_t a, v4i_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLAIMPL v4i_t v4i_div(v4i_t a, v4i_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLAIMPL v4i_t v4i_min(v4i_t a, v4i_t b) {
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  a.z = mini(a.z, b.z);
  a.w = mini(a.w, b.w);
  return a;
}

MVLAIMPL v4i_t v4i_max(v4i_t a, v4i_t b) {
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  a.z = maxi(a.z, b.z);
  a.w = maxi(a.w, b.w);
  return a;
}

MVLAIMPL void v4i_print(v4i_t a) {
  printf("v4i_t(%d, %d, %d, %d)\n", V4_ARGS(a));
}

MVLAIMPL v4u_t v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w) {
  v4u_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLAIMPL v4u_t v4uu(unsigned int x) {
  return v4u(x, x, x, x);
}

MVLAIMPL v4u_t v4u_add(v4u_t a, v4u_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLAIMPL v4u_t v4u_sub(v4u_t a, v4u_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLAIMPL v4u_t v4u_mul(v4u_t a, v4u_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLAIMPL v4u_t v4u_div(v4u_t a, v4u_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLAIMPL v4u_t v4u_min(v4u_t a, v4u_t b) {
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  a.z = minu(a.z, b.z);
  a.w = minu(a.w, b.w);
  return a;
}

MVLAIMPL v4u_t v4u_max(v4u_t a, v4u_t b) {
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  a.z = maxu(a.z, b.z);
  a.w = maxu(a.w, b.w);
  return a;
}

MVLAIMPL void v4u_print(v4u_t a) {
  printf("v4u_t(%u, %u, %u, %u)\n", V4_ARGS(a));
}

MVLAIMPL v4f_t v4f(float x, float y, float z, float w) {
  v4f_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLAIMPL v4f_t v4ff(float x) { return v4f(x, x, x, x); }

MVLAIMPL v4f_t v4f_add(v4f_t a, v4f_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLAIMPL v4f_t v4f_sub(v4f_t a, v4f_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLAIMPL v4f_t v4f_mul(v4f_t a, v4f_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLAIMPL v4f_t v4f_div(v4f_t a, v4f_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLAIMPL v4f_t v4f_min(v4f_t a, v4f_t b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  a.w = fmin(a.w, b.w);
  return a;
}

MVLAIMPL v4f_t v4f_max(v4f_t a, v4f_t b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  a.w = fmax(a.w, b.w);
  return a;
}

MVLAIMPL v4f_t v4f_sqrt(v4f_t a) {
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  a.z = sqrtf(a.z);
  a.w = sqrtf(a.w);
  return a;
}

MVLAIMPL v4f_t v4f_poww(v4f_t a, float exp) {
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  a.z = powf(a.z, exp);
  a.w = powf(a.w, exp);
  return a;
}

MVLAIMPL v4f_t v4f_pow(v4f_t a, v4f_t exp) {
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  a.z = powf(a.z, exp.z);
  a.w = powf(a.w, exp.w);
  return a;
}

MVLAIMPL v4f_t v4f_exp(v4f_t a) {
  a.x = powf(MVLA_E, a.x);
  a.y = powf(MVLA_E, a.y);
  a.z = powf(MVLA_E, a.z);
  a.w = powf(MVLA_E, a.w);
  return a;
}

MVLAIMPL v4f_t v4f_sin(v4f_t a) {
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  a.z = sinf(a.z);
  a.w = sinf(a.w);
  return a;
}

MVLAIMPL v4f_t v4f_cos(v4f_t a) {
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  a.z = cosf(a.z);
  a.w = cosf(a.w);
  return a;
}

MVLAIMPL v4f_t v4f_tan(v4f_t a) {
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  a.z = tanf(a.z);
  a.w = tanf(a.w);
  return a;
}

MVLAIMPL float v4f_len(v4f_t a) {
  return sqrtf(v4f_sqr_len(a));
}

MVLAIMPL float v4f_sqr_len(v4f_t a) {
  return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

MVLAIMPL void v4f_print(v4f_t a) {
  printf("v4f_t(%f, %f, %f, %f)\n", V4_ARGS(a));
}

MVLAIMPL v4d_t v4d(double x, double y, double z, double w) {
  v4d_t vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLAIMPL v4d_t v4dd(double x) {
  return v4d(x, x, x, x);
}

MVLAIMPL v4d_t v4d_add(v4d_t a, v4d_t b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLAIMPL v4d_t v4d_sub(v4d_t a, v4d_t b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLAIMPL v4d_t v4d_mul(v4d_t a, v4d_t b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLAIMPL v4d_t v4d_div(v4d_t a, v4d_t b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLAIMPL v4d_t v4d_min(v4d_t a, v4d_t b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  a.w = fmin(a.w, b.w);
  return a;
}

MVLAIMPL v4d_t v4d_max(v4d_t a, v4d_t b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  a.w = fmax(a.w, b.w);
  return a;
}

MVLAIMPL v4d_t v4d_sqrt(v4d_t a) {
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  a.z = sqrt(a.z);
  a.w = sqrt(a.w);
  return a;
}

MVLAIMPL v4d_t v4d_poww(v4d_t a, double exp) {
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  a.z = pow(a.z, exp);
  a.w = pow(a.w, exp);
  return a;
}

MVLAIMPL v4d_t v4d_pow(v4d_t a, v4d_t exp) {
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  a.z = pow(a.z, exp.z);
  a.w = pow(a.w, exp.w);
  return a;
}

MVLAIMPL v4d_t v4d_exp(v4d_t a) {
  a.x = pow(MVLA_E, a.x);
  a.y = pow(MVLA_E, a.y);
  a.z = pow(MVLA_E, a.z);
  a.w = pow(MVLA_E, a.w);
  return a;
}

MVLAIMPL v4d_t v4d_sin(v4d_t a) {
  a.x = sin(a.x);
  a.y = sin(a.y);
  a.z = sin(a.z);
  a.w = sin(a.w);
  return a;
}

MVLAIMPL v4d_t v4d_cos(v4d_t a) {
  a.x = cos(a.x);
  a.y = cos(a.y);
  a.z = cos(a.z);
  a.w = cos(a.w);
  return a;
}

MVLAIMPL v4d_t v4d_tan(v4d_t a) {
  a.x = tan(a.x);
  a.y = tan(a.y);
  a.z = tan(a.z);
  a.w = tan(a.w);
  return a;
}

MVLAIMPL double v4d_len(v4d_t a) {
  return sqrt(v4d_sqr_len(a));
}

MVLAIMPL double v4d_sqr_len(v4d_t a) {
  return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

MVLAIMPL void v4d_print(v4d_t a) {
  printf("v4d_t(%lf, %lf, %lf, %lf)\n", V4_ARGS(a));
}

// -----------------------------------------

#endif // MVLA_IMPLEMENTATION

#ifdef __cplusplus
}
#endif // __cplusplus

/*
** TODO:
** - still missing the M (matrix) in MVLA... should implement mat2x2f_t, etc
** - implement a way to choose an allocator (ie... preprocessor defs to pick a 
**   malloc definition)
*/
