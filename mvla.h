
/*
** @title:        MVLA (Matrix-Vector Linear Algebra)
**
** @author:       Walker Rout
**
** @contact:      walkerrout04@gmail.com
**
** @date_written: March 16th, 2022
**
** @description:  This library implements matrices and vectors for use in
**                scripts and mathematical computations
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
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// -----------------------------------------

// -----------------------------------------
/*
** ACCESS MODIFIER DEFINES
*/
#ifndef MVLADEF
#define MVLADEF static inline
#endif // MVLADEF
// -----------------------------------------

// -----------------------------------------
/*
** PREPROCESSOR DEFINTIONS
*/
#define V2Args(v) (v).x, (v).y
#define V3Args(v) (v).x, (v).y, (v).z
#define V4Args(v) (v).x, (v).y, (v).z, (v).w
// -----------------------------------------

// -----------------------------------------
/*
** USEFUL CONSTANT DEFINTIONS
*/
#define C_E 2.71828182845
#define C_PI 3.14159265359
#define C_2PI 6.28318530718
#define C_4PI 12.5663706144
#define C_HALFPI 1.57079632679
#define C_SQRTPI 1.77245385091
#define C_SQRT2 1.41421356237
#define C_SQRT3 1.73205080757
#define C_LN2 0.69314718056
#define C_LN10 2.30258509299
#define C_LNPI 1.14472988585
#define C_LOGE 0.43429448190
// -----------------------------------------

// -----------------------------------------
/*
** 2D VECTOR DEFINITIONS
*/
typedef struct {
  signed int x, y;
} V2i;
typedef struct {
  unsigned int x, y;
} V2u;
typedef struct {
  float x, y;
} V2f;
typedef struct {
  double x, y;
} V2d;
/*
** 3D VECTOR DEFINITIONS
*/
typedef struct {
  signed int x, y, z;
} V3i;
typedef struct {
  unsigned int x, y, z;
} V3u;
typedef struct {
  float x, y, z;
} V3f;
typedef struct {
  double x, y, z;
} V3d;
/*
** 4D VECTOR DEFINITIONS
*/
typedef struct {
  signed int x, y, z, w;
} V4i;
typedef struct {
  unsigned int x, y, z, w;
} V4u;
typedef struct {
  float x, y, z, w;
} V4f;
typedef struct {
  double x, y, z, w;
} V4d;
// -----------------------------------------

// -----------------------------------------
/*
** UNSPECIFIED VECTOR DEFINITIONS
*/
typedef struct {
  unsigned int length;
  float *data;
} Vec;
// -----------------------------------------

// -----------------------------------------
/*
** UNSPECIFIED MATRIX DEFINITIONS
*/
typedef struct {
  unsigned int rows;
  unsigned int cols;
  float *data; // rows * cols
} Mat;
// -----------------------------------------

// -----------------------------------------
/*
** MATH FUNCTION PROTOTYPES
*/
MVLADEF unsigned int pot(unsigned int x);
MVLADEF float rand_f();
MVLADEF double rand_d();
MVLADEF float lerpf(float a, float b, float t);
MVLADEF double lerp(double a, double b, double t);
MVLADEF signed int mini(signed int a, signed int b);
MVLADEF signed int maxi(signed int a, signed int b);
MVLADEF unsigned int minu(unsigned int a, unsigned int b);
MVLADEF unsigned int maxu(unsigned int a, unsigned int b);
// -----------------------------------------

// -----------------------------------------
/*
** 2D VECTOR FUNCTION PROTOTYPES
*/
MVLADEF V2i v2i(signed int x, signed int y);
MVLADEF V2i v2ii(signed int x);
MVLADEF V2i v2i_add(V2i a, V2i b);
MVLADEF V2i v2i_sub(V2i a, V2i b);
MVLADEF V2i v2i_mul(V2i a, V2i b);
MVLADEF V2i v2i_div(V2i a, V2i b);
MVLADEF V2i v2i_min(V2i a, V2i b);
MVLADEF V2i v2i_max(V2i a, V2i b);
MVLADEF void v2i_print(V2i a);

MVLADEF V2u v2u(unsigned int x, unsigned int y);
MVLADEF V2u v2uu(unsigned int x);
MVLADEF V2u v2u_add(V2u a, V2u b);
MVLADEF V2u v2u_sub(V2u a, V2u b);
MVLADEF V2u v2u_mul(V2u a, V2u b);
MVLADEF V2u v2u_div(V2u a, V2u b);
MVLADEF V2u v2u_min(V2u a, V2u b);
MVLADEF V2u v2u_max(V2u a, V2u b);
MVLADEF void v2u_print(V2u a);

MVLADEF V2f v2f(float x, float y);
MVLADEF V2f v2ff(float x);
MVLADEF V2f v2f_add(V2f a, V2f b);
MVLADEF V2f v2f_sub(V2f a, V2f b);
MVLADEF V2f v2f_mul(V2f a, V2f b);
MVLADEF V2f v2f_div(V2f a, V2f b);
MVLADEF V2f v2f_min(V2f a, V2f b);
MVLADEF V2f v2f_max(V2f a, V2f b);
MVLADEF V2f v2f_sqrt(V2f a);
MVLADEF V2f v2f_poww(V2f a, float exp);
MVLADEF V2f v2f_pow(V2f a, V2f exp);
MVLADEF V2f v2f_exp(V2f a);
MVLADEF V2f v2f_sin(V2f a);
MVLADEF V2f v2f_cos(V2f a);
MVLADEF V2f v2f_tan(V2f a);
MVLADEF float v2f_len(V2f a);
MVLADEF void v2f_print(V2f a);

MVLADEF V2d v2d(double x, double y);
MVLADEF V2d v2dd(double x);
MVLADEF V2d v2d_add(V2d a, V2d b);
MVLADEF V2d v2d_sub(V2d a, V2d b);
MVLADEF V2d v2d_mul(V2d a, V2d b);
MVLADEF V2d v2d_div(V2d a, V2d b);
MVLADEF V2d v2d_min(V2d a, V2d b);
MVLADEF V2d v2d_max(V2d a, V2d b);
MVLADEF V2d v2d_sqrt(V2d a);
MVLADEF V2d v2d_poww(V2d a, double exp);
MVLADEF V2d v2d_pow(V2d a, V2d exp);
MVLADEF V2d v2d_exp(V2d a);
MVLADEF V2d v2d_sin(V2d a);
MVLADEF V2d v2d_cos(V2d a);
MVLADEF V2d v2d_tan(V2d a);
MVLADEF double v2d_len(V2d a);
MVLADEF void v2d_print(V2d a);
// -----------------------------------------

// -----------------------------------------
/*
** 3D VECTOR FUNCTION PROTOTYPES
*/
MVLADEF V3i v3i(signed int x, signed int y, signed int z);
MVLADEF V3i v3ii(signed int x);
MVLADEF V3i v3i_add(V3i a, V3i b);
MVLADEF V3i v3i_sub(V3i a, V3i b);
MVLADEF V3i v3i_mul(V3i a, V3i b);
MVLADEF V3i v3i_div(V3i a, V3i b);
MVLADEF V3i v3i_min(V3i a, V3i b);
MVLADEF V3i v3i_max(V3i a, V3i b);
MVLADEF void v3i_print(V3i a);

MVLADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z);
MVLADEF V3u v3uu(unsigned int x);
MVLADEF V3u v3u_add(V3u a, V3u b);
MVLADEF V3u v3u_sub(V3u a, V3u b);
MVLADEF V3u v3u_mul(V3u a, V3u b);
MVLADEF V3u v3u_div(V3u a, V3u b);
MVLADEF V3u v3u_min(V3u a, V3u b);
MVLADEF V3u v3u_max(V3u a, V3u b);
MVLADEF void v3u_print(V3u a);

MVLADEF V3f v3f(float x, float y, float z);
MVLADEF V3f v3ff(float x);
MVLADEF V3f v3f_add(V3f a, V3f b);
MVLADEF V3f v3f_sub(V3f a, V3f b);
MVLADEF V3f v3f_mul(V3f a, V3f b);
MVLADEF V3f v3f_div(V3f a, V3f b);
MVLADEF V3f v3f_min(V3f a, V3f b);
MVLADEF V3f v3fMax(V3f a, V3f b);
MVLADEF V3f v3f_sqrt(V3f a);
MVLADEF V3f v3f_poww(V3f a, float exp);
MVLADEF V3f v3f_pow(V3f a, V3f exp);
MVLADEF V3f v3f_exp(V3f a);
MVLADEF V3f v3f_sin(V3f a);
MVLADEF V3f v3f_cos(V3f a);
MVLADEF V3f v3f_tan(V3f a);
MVLADEF float v3f_len(V3f a);
MVLADEF void v3f_print(V3f a);

MVLADEF V3d v3d(double x, double y, double z);
MVLADEF V3d v3dd(double x);
MVLADEF V3d v3d_add(V3d a, V3d b);
MVLADEF V3d v3d_sub(V3d a, V3d b);
MVLADEF V3d v3d_mul(V3d a, V3d b);
MVLADEF V3d v3d_div(V3d a, V3d b);
MVLADEF V3d v3d_min(V3d a, V3d b);
MVLADEF V3d v3d_max(V3d a, V3d b);
MVLADEF V3d v3d_sqrt(V3d a);
MVLADEF V3d v3d_poww(V3d a, double exp);
MVLADEF V3d v3d_pow(V3d a, V3d exp);
MVLADEF V3d v3d_exp(V3d a);
MVLADEF V3d v3d_sin(V3d a);
MVLADEF V3d v3d_cos(V3d a);
MVLADEF V3d v3d_tan(V3d a);
MVLADEF double v3d_len(V3d a);
MVLADEF void v3d_print(V3d a);
// -----------------------------------------

// -----------------------------------------
/*
** 3D VECTOR FUNCTION PROTOTYPES
*/
MVLADEF V4i v4i(signed int x, signed int y, signed int z, signed int w);
MVLADEF V4i v4ii(signed int x);
MVLADEF V4i v4i_add(V4i a, V4i b);
MVLADEF V4i v4i_sub(V4i a, V4i b);
MVLADEF V4i v4i_mul(V4i a, V4i b);
MVLADEF V4i v4i_div(V4i a, V4i b);
MVLADEF V4i v4i_min(V4i a, V4i b);
MVLADEF V4i v4i_max(V4i a, V4i b);
MVLADEF void v4i_print(V4i a);

MVLADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w);
MVLADEF V4u v4uu(unsigned int x);
MVLADEF V4u v4u_add(V4u a, V4u b);
MVLADEF V4u v4u_sub(V4u a, V4u b);
MVLADEF V4u v4u_mul(V4u a, V4u b);
MVLADEF V4u v4u_div(V4u a, V4u b);
MVLADEF V4u v4u_min(V4u a, V4u b);
MVLADEF V4u v4u_max(V4u a, V4u b);
MVLADEF void v4u_print(V4u a);

MVLADEF V4f v4f(float x, float y, float z, float w);
MVLADEF V4f v4ff(float x);
MVLADEF V4f v4f_add(V4f a, V4f b);
MVLADEF V4f v4f_sub(V4f a, V4f b);
MVLADEF V4f v4f_mul(V4f a, V4f b);
MVLADEF V4f v4f_div(V4f a, V4f b);
MVLADEF V4f v4f_min(V4f a, V4f b);
MVLADEF V4f v4f_max(V4f a, V4f b);
MVLADEF V4f v4f_sqrt(V4f a);
MVLADEF V4f v4f_poww(V4f a, float exp);
MVLADEF V4f v4f_pow(V4f a, V4f exp);
MVLADEF V4f v4f_exp(V4f a);
MVLADEF V4f v4f_sin(V4f a);
MVLADEF V4f v4f_cos(V4f a);
MVLADEF V4f v4f_tan(V4f a);
MVLADEF float v4f_len(V4f a);
MVLADEF void v4f_print(V4f a);

MVLADEF V4d v4d(double x, double y, double z, double w);
MVLADEF V4d v4dd(double x);
MVLADEF V4d v4d_add(V4d a, V4d b);
MVLADEF V4d v4d_sub(V4d a, V4d b);
MVLADEF V4d v4d_mul(V4d a, V4d b);
MVLADEF V4d v4d_div(V4d a, V4d b);
MVLADEF V4d v4d_min(V4d a, V4d b);
MVLADEF V4d v4d_max(V4d a, V4d b);
MVLADEF V4d v4d_sqrt(V4d a);
MVLADEF V4d v4d_poww(V4d a, double exp);
MVLADEF V4d v4d_pow(V4d a, V4d exp);
MVLADEF V4d v4d_exp(V4d a);
MVLADEF V4d v4d_sin(V4d a);
MVLADEF V4d v4d_cos(V4d a);
MVLADEF V4d v4d_tan(V4d a);
MVLADEF double v4d_len(V4d a);
MVLADEF void v4d_print(V4d a);
// -----------------------------------------

// -----------------------------------------
/*
** UNSPECIFIED VECTOR FUNCTION PROTOTYPES
*/
MVLADEF Vec vec(unsigned int length);
MVLADEF float vec_get(const Vec a, unsigned int index);
MVLADEF float *vec_get_ptr(const Vec *a, unsigned int index);
MVLADEF Vec vec_clone(Vec a);
MVLADEF void vec_copy_data(Vec *dest, Vec *src);
MVLADEF Vec vec_add(Vec a, Vec b);
MVLADEF Vec vec_sub(Vec a, Vec b);
MVLADEF Vec vec_mul(Vec a, Vec b);
MVLADEF Vec vec_mull(Vec a, float b);
MVLADEF Vec vec_dot(Vec a, Vec b);
MVLADEF Vec vec_div(Vec a, Vec b);
MVLADEF Vec vec_map(Vec a, float (*func)(float));
MVLADEF Vec vec_from_mat_row(Mat a, int row);
MVLADEF Vec vec_from_mat_col(Mat a, int col);
MVLADEF Vec vec_from_f_ptr(float *a, unsigned int length);
MVLADEF float vec_length(const Vec a);
MVLADEF void vec_resize(Vec *a, unsigned int newLength); // *
MVLADEF void vec_fill_rand(Vec *a);
MVLADEF void vec_free(Vec *a);
MVLADEF void vec_print(const Vec a);
MVLADEF void vec_print_length(const Vec a);
// -----------------------------------------

// -----------------------------------------
/*
** UNSPECIFIED MATRIX FUNCTION PROTOTYPES
*/
MVLADEF Mat mat(unsigned int rows, unsigned int cols);
MVLADEF Mat matt(unsigned int dim);
MVLADEF Mat mat_null(void);
MVLADEF Mat mat_id(unsigned int dim);
MVLADEF float mat_get(Mat a, unsigned int i, unsigned int j);
MVLADEF float *mat_get_ptr(Mat *a, unsigned int i, unsigned int j);
MVLADEF Mat mat_clone(Mat a);
MVLADEF void mat_copy_data(Mat *dest, Mat *src);
MVLADEF Mat mat_add(Mat a, Mat b);
MVLADEF Mat mat_sub(Mat a, Mat b);
MVLADEF Mat mat_mul(Mat a, Mat b);
MVLADEF Mat mat_mull(Mat a, float b);
MVLADEF Mat mat_dot(Mat a, Mat b);
MVLADEF Mat mat_div(Mat a, Mat b);
MVLADEF Mat mat_transpose(Mat a);
MVLADEF Mat mat_map(Mat a, float (*func)(float));
MVLADEF Mat mat_from_vec(Vec a);
MVLADEF V2u mat_dims(const Mat a);
MVLADEF void mat_fill_rand(Mat *a);
MVLADEF void mat_free(Mat *a);
MVLADEF void mat_print(const Mat a);
MVLADEF void mat_print_rows_cols(const Mat a);
// -----------------------------------------

#endif // MVLA_H

/*
** HEADER ONLY IMPLEMENTATION
*/
#ifdef MVLA_IMPLEMENTATION

/*
** @brief:   Generate a random float between 0 and 1
** @params:  N/A
** @returns: N/A
*/
MVLADEF float rand_f() {
  return ((float)rand()) /
         ((float)RAND_MAX); // initialize srand first: srand(time(NULL))
}

/*
** @brief:   Generate a random double between 0 and 1
** @params:  N/A
** @returns: N/A
*/
MVLADEF double rand_d() {
  return ((double)rand()) /
         ((double)RAND_MAX); // initialize srand first: srand(time(NULL))
}

/*
** @brief:   Linearly interpolate between two floats
** @params:  a {float} - lower bound, b {float} - upper bound, c {float} - value to interpolate
** @returns: N/A
*/
MVLADEF float lerpf(float a, float b, float t) { return a + ((b - a) * t); }

/*
** @brief:   Linearly interpolate between two doubles
** @params:  a {double} - lower bound, b {double} - upper bound, c {double} - value to interpolate
** @returns: N/A
*/
MVLADEF double lerp(double a, double b, double t) { return a + ((b - a) * t); }

/*
** @brief:   Find the smaller of two integers
** @params:  a {signed int} - first number, b {signed int} - second number
** @returns: {signed int} - the smaller between a and b
*/
MVLADEF signed int mini(signed int a, signed int b) { return (a < b) ? a : b; }

/*
** @brief:   Find the larger of two integers
** @params:  a {signed int} - first number, b {signed int} - second number
** @returns: {signed int} - the larger between a and b
*/
MVLADEF signed int maxi(signed int a, signed int b) { return (a < b) ? b : a; }

/*
** @brief:   Find the smaller of two unsigned integers
** @params:  a {unsigned int} - first number, b {unsigned int} - second number
** @returns: {unsigned int} - the smaller between a and b
*/
MVLADEF unsigned int minu(unsigned int a, unsigned int b) {
  return (a < b) ? a : b;
}

/*
** @brief:   Find the larger of two unsigned integers
** @params:  a {unsigned int} - first number, b {unsigned int} - second number
** @returns: {unsigned int} - the larger between a and b
*/
MVLADEF unsigned int maxu(unsigned int a, unsigned int b) {
  return (a < b) ? b : a;
}

// -----------------------------------------

/*
** @brief:   Create a 2D integer vector with differing x and y components
** @params:  x {signed int} - x component, y {signed int} - y component
** @returns: vec {V2i} - new 2D integer vector
*/
MVLADEF V2i v2i(signed int x, signed int y) {
  V2i vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

/*
** @brief:   Create a 2D integer vector with the same x and y components
** @params:  x {signed int} - all components
** @returns: vec {V2i} - new 2D integer vector
*/
MVLADEF V2i v2ii(signed int x) { return v2i(x, x); }

/*
** @brief:   Add two 2D integer vectors
** @params:  a {V2i} - first vector, b {V2i} - second vector
** @returns: a {V2i} - sum of a and b
*/
MVLADEF V2i v2i_add(V2i a, V2i b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

/*
** @brief:   Subtract two 2D integer vectors
** @params:  a {V2i} - first vector, b {V2i} - second vector
** @returns: a {V2i} - difference between a and b
*/
MVLADEF V2i v2i_sub(V2i a, V2i b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

/*
** @brief:   Multiply two 2D integer vectors
** @params:  a {V2i} - first vector, b {V2i} - second vector
** @returns: a {V2i} - product of a and b
*/
MVLADEF V2i v2i_mul(V2i a, V2i b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

/*
** @brief:   Divide two 2D integer vectors
** @params:  a {V2i} - first vector, b {V2i} - second vector
** @returns: a {V2i} - quotient of a and b
*/
MVLADEF V2i v2i_div(V2i a, V2i b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

/*
** @brief:   Find the minimum of two 2D integer vectors
** @params:  a {V2i} - first vector, b {V2i} - second vector
** @returns: a {V2i} - minimum of a and b
*/
MVLADEF V2i v2i_min(V2i a, V2i b) {
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  return a;
}

/*
** @brief:   Find the maximum of two 2D integer vectors
** @params:  a {V2i} - first vector, b {V2i} - second vector
** @returns: a {V2i} - maximum of a and b
*/
MVLADEF V2i v2i_max(V2i a, V2i b) {
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  return a;
}

/*
** @brief:   Print a 2D integer vector
** @params:  a {V2i} - vector to print
** @returns: N/A
*/
MVLADEF void v2i_print(V2i a) { printf("V2i(%d, %d)\n", a.x, a.y); }

/*
** @brief:   Create a 2D unsigned integer vector with differing x and y components
** @params:  x {unsigned int} - x component, y {unsigned int} - y component
** @returns: vec {V2u} - new 2D unsigned integer vector
*/
MVLADEF V2u v2u(unsigned int x, unsigned int y) {
  V2u vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

/*
** @brief:   Create a 2D unsigned integer vector with the same x and y components
** @params:  x {unsigned int} - all components
** @returns: vec {V2u} - new 2D unsigned integer vector
*/
MVLADEF V2u v2uu(unsigned int x) { return v2u(x, x); }

/*
** @brief:   Add two 2D unsigned integer vectors
** @params:  a {V2u} - first vector, b {V2u} - second vector
** @returns: a {V2u} - sum of a and b
*/
MVLADEF V2u v2u_add(V2u a, V2u b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

/*
** @brief:   Subtract two 2D unsigned integer vectors
** @params:  a {V2u} - first vector, b {V2u} - second vector
** @returns: a {V2u} - difference between a and b
*/
MVLADEF V2u v2u_sub(V2u a, V2u b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

/*
** @brief:   Multiply two 2D unsigned integer vectors
** @params:  a {V2u} - first vector, b {V2u} - second vector
** @returns: a {V2u} - product of a and b
*/
MVLADEF V2u v2u_mul(V2u a, V2u b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

/*
** @brief:   Divide two 2D unsigned integer vectors
** @params:  a {V2u} - first vector, b {V2u} - second vector
** @returns: a {V2u} - quotient of a and b
*/
MVLADEF V2u v2u_div(V2u a, V2u b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

/*
** @brief:   Find the minimum of two 2D unsigned integer vectors
** @params:  a {V2u} - first vector, b {V2u} - second vector
** @returns: a {V2u} - minimum of a and b
*/
MVLADEF V2u v2u_min(V2u a, V2u b) {
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  return a;
}

/*
** @brief:   Find the maximum of two 2D unsigned integer vectors
** @params:  a {V2u} - first vector, b {V2u} - second vector
** @returns: a {V2u} - maximum of a and b
*/
MVLADEF V2u v2u_max(V2u a, V2u b) {
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  return a;
}

/*
** @brief:   Print a 2D unsigned integer vector
** @params:  a {V2u} - vector to print
** @returns: N/A
*/
MVLADEF void v2u_print(V2u a) { printf("V2u(%u, %u)\n", a.x, a.y); }

MVLADEF V2f v2f(float x, float y) {
  V2f vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLADEF V2f v2ff(float x) { return v2f(x, x); }

MVLADEF V2f v2f_add(V2f a, V2f b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLADEF V2f v2f_sub(V2f a, V2f b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLADEF V2f v2f_mul(V2f a, V2f b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLADEF V2f v2f_div(V2f a, V2f b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLADEF V2f v2f_min(V2f a, V2f b) {
  a.x = fminf(a.x, b.x);
  a.y = fminf(a.y, b.y);
  return a;
}

MVLADEF V2f v2f_max(V2f a, V2f b) {
  a.x = fmaxf(a.x, b.x);
  a.y = fmaxf(a.y, b.y);
  return a;
}

MVLADEF V2f v2f_sqrt(V2f a) {
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  return a;
}

MVLADEF V2f v2f_poww(V2f a, float exp) {
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  return a;
}

MVLADEF V2f v2f_pow(V2f a, V2f exp) {
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  return a;
}

MVLADEF V2f v2f_exp(V2f a) {
  a.x = powf(C_E, a.x);
  a.y = powf(C_E, a.y);
  return a;
}

MVLADEF V2f v2f_sin(V2f a) {
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  return a;
}

MVLADEF V2f v2f_cos(V2f a) {
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  return a;
}

MVLADEF V2f v2f_tan(V2f a) {
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  return a;
}

MVLADEF float v2f_len(V2f a) {
  float sqr = a.x * a.x + a.y * a.y;
  return sqrtf(sqr);
}

MVLADEF void v2f_print(V2f a) { printf("V2f(%f, %f)\n", a.x, a.y); }

MVLADEF V2d v2d(double x, double y) {
  V2d vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLADEF V2d v2dd(double x) { return v2d(x, x); }

MVLADEF V2d v2d_add(V2d a, V2d b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLADEF V2d v2d_sub(V2d a, V2d b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLADEF V2d v2d_mul(V2d a, V2d b) {
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLADEF V2d v2d_div(V2d a, V2d b) {
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLADEF V2d v2d_min(V2d a, V2d b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  return a;
}

MVLADEF V2d v2d_max(V2d a, V2d b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  return a;
}

MVLADEF V2d v2d_sqrt(V2d a) {
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  return a;
}

MVLADEF V2d v2d_poww(V2d a, double exp) {
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  return a;
}

MVLADEF V2d v2d_pow(V2d a, V2d exp) {
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  return a;
}

MVLADEF V2d v2d_exp(V2d a) {
  a.x = pow(C_E, a.x);
  a.y = pow(C_E, a.y);
  return a;
}

MVLADEF V2d v2d_sin(V2d a) {
  a.x = sin(a.x);
  a.y = sin(a.y);
  return a;
}

MVLADEF V2d v2d_cos(V2d a) {
  a.x = cos(a.x);
  a.y = cos(a.y);
  return a;
}

MVLADEF V2d v2d_tan(V2d a) {
  a.x = tan(a.x);
  a.y = tan(a.y);
  return a;
}

MVLADEF double v2d_len(V2d a) {
  double sqr = a.x * a.x + a.y * a.y;
  return sqrt(sqr);
}

MVLADEF void v2d_print(V2d a) { printf("V2d(%lf, %lf)\n", a.x, a.y); }

// -----------------------------------------

MVLADEF V3i v3i(signed int x, signed int y, signed int z) {
  V3i vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3i v3ii(signed int x) { return v3i(x, x, x); }

MVLADEF V3i v3i_add(V3i a, V3i b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3i v3i_sub(V3i a, V3i b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3i v3i_mul(V3i a, V3i b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3i v3i_div(V3i a, V3i b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3i v3i_min(V3i a, V3i b) {
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  a.z = mini(a.z, b.z);
  return a;
}

MVLADEF V3i v3i_max(V3i a, V3i b) {
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  a.z = maxi(a.z, b.z);
  return a;
}

MVLADEF void v3i_print(V3i a) { printf("V3i(%d, %d, %d)\n", a.x, a.y, a.z); }

MVLADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z) {
  V3u vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3u v3uu(unsigned int x) { return v3u(x, x, x); }

MVLADEF V3u v3u_add(V3u a, V3u b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3u v3u_sub(V3u a, V3u b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3u v3u_mul(V3u a, V3u b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3u v3u_div(V3u a, V3u b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3u v3u_min(V3u a, V3u b) {
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  a.z = minu(a.z, b.z);
  return a;
}

MVLADEF V3u v3u_max(V3u a, V3u b) {
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  a.z = maxu(a.z, b.z);
  return a;
}

MVLADEF void v3u_print(V3u a) { printf("V3u(%u, %u, %u)\n", a.x, a.y, a.z); }

MVLADEF V3f v3f(float x, float y, float z) {
  V3f vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3f v3ff(float x) { return v3f(x, x, x); }

MVLADEF V3f v3f_add(V3f a, V3f b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3f v3f_sub(V3f a, V3f b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3f v3f_mul(V3f a, V3f b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3f v3f_div(V3f a, V3f b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3f v3f_min(V3f a, V3f b) {
  a.x = fminf(a.x, b.x);
  a.y = fminf(a.y, b.y);
  a.z = fminf(a.z, b.z);
  return a;
}

MVLADEF V3f v3fMax(V3f a, V3f b) {
  a.x = fmaxf(a.x, b.x);
  a.y = fmaxf(a.y, b.y);
  a.z = fmaxf(a.z, b.z);
  return a;
}

MVLADEF V3f v3f_sqrt(V3f a) {
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  a.z = sqrtf(a.z);
  return a;
}

MVLADEF V3f v3f_poww(V3f a, float exp) {
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  a.z = powf(a.z, exp);
  return a;
}

MVLADEF V3f v3f_pow(V3f a, V3f exp) {
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  a.z = powf(a.z, exp.z);
  return a;
}

MVLADEF V3f v3f_exp(V3f a) {
  a.x = powf(C_E, a.x);
  a.y = powf(C_E, a.y);
  a.z = powf(C_E, a.z);
  return a;
}

MVLADEF V3f v3f_sin(V3f a) {
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  a.z = sinf(a.z);
  return a;
}

MVLADEF V3f v3f_cos(V3f a) {
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  a.z = cosf(a.z);
  return a;
}

MVLADEF V3f v3f_tan(V3f a) {
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  a.z = tanf(a.z);
  return a;
}

MVLADEF float v3f_len(V3f a) {
  float sqr = a.x * a.x + a.y * a.y + a.z * a.z;
  return sqrtf(sqr);
}

MVLADEF void v3f_print(V3f a) { printf("V3f(%f, %f, %f)\n", a.x, a.y, a.z); }

MVLADEF V3d v3d(double x, double y, double z) {
  V3d vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3d v3dd(double x) { return v3d(x, x, x); }

MVLADEF V3d v3d_add(V3d a, V3d b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3d v3d_sub(V3d a, V3d b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3d v3d_mul(V3d a, V3d b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3d v3d_div(V3d a, V3d b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3d v3d_min(V3d a, V3d b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  return a;
}

MVLADEF V3d v3d_max(V3d a, V3d b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  return a;
}

MVLADEF V3d v3d_sqrt(V3d a) {
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  a.z = sqrt(a.z);
  return a;
}

MVLADEF V3d v3d_poww(V3d a, double exp) {
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  a.z = pow(a.z, exp);
  return a;
}

MVLADEF V3d v3d_pow(V3d a, V3d exp) {
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  a.z = pow(a.z, exp.z);
  return a;
}

MVLADEF V3d v3d_exp(V3d a) {
  a.x = pow(C_E, a.x);
  a.y = pow(C_E, a.y);
  a.z = pow(C_E, a.z);
  return a;
}

MVLADEF V3d v3d_sin(V3d a) {
  a.x = sin(a.x);
  a.y = sin(a.y);
  a.z = sin(a.z);
  return a;
}

MVLADEF V3d v3d_cos(V3d a) {
  a.x = cos(a.x);
  a.y = cos(a.y);
  a.z = cos(a.z);
  return a;
}

MVLADEF V3d v3d_tan(V3d a) {
  a.x = tan(a.x);
  a.y = tan(a.y);
  a.z = tan(a.z);
  return a;
}

MVLADEF double v3d_len(V3d a) {
  double sqr = a.x * a.x + a.y * a.y + a.z * a.z;
  return sqrt(sqr);
}

MVLADEF void v3d_print(V3d a) { printf("V3d(%lf, %lf, %lf)\n", a.x, a.y, a.z); }

// -----------------------------------------

MVLADEF V4i v4i(signed int x, signed int y, signed int z, signed int w) {
  V4i vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4i v4ii(signed int x) { return v4i(x, x, x, x); }

MVLADEF V4i v4i_add(V4i a, V4i b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4i v4i_sub(V4i a, V4i b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4i v4i_mul(V4i a, V4i b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4i v4i_div(V4i a, V4i b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4i v4i_min(V4i a, V4i b) {
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  a.z = mini(a.z, b.z);
  a.w = mini(a.w, b.w);
  return a;
}

MVLADEF V4i v4i_max(V4i a, V4i b) {
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  a.z = maxi(a.z, b.z);
  a.w = maxi(a.w, b.w);
  return a;
}

MVLADEF void v4i_print(V4i a) {
  printf("V4i(%d, %d, %d, %d)\n", a.x, a.y, a.z, a.w);
}

MVLADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z,
                unsigned int w) {
  V4u vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4u v4uu(unsigned int x) { return v4u(x, x, x, x); }

MVLADEF V4u v4u_add(V4u a, V4u b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4u v4u_sub(V4u a, V4u b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4u v4u_mul(V4u a, V4u b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4u v4u_div(V4u a, V4u b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4u v4u_min(V4u a, V4u b) {
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  a.z = minu(a.z, b.z);
  a.w = minu(a.w, b.w);
  return a;
}

MVLADEF V4u v4u_max(V4u a, V4u b) {
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  a.z = maxu(a.z, b.z);
  a.w = maxu(a.w, b.w);
  return a;
}

MVLADEF void v4u_print(V4u a) {
  printf("V4u(%u, %u, %u, %u)\n", a.x, a.y, a.z, a.w);
}

MVLADEF V4f v4f(float x, float y, float z, float w) {
  V4f vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4f v4ff(float x) { return v4f(x, x, x, x); }

MVLADEF V4f v4f_add(V4f a, V4f b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4f v4f_sub(V4f a, V4f b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4f v4f_mul(V4f a, V4f b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4f v4f_div(V4f a, V4f b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4f v4f_min(V4f a, V4f b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  a.w = fmin(a.w, b.w);
  return a;
}

MVLADEF V4f v4f_max(V4f a, V4f b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  a.w = fmax(a.w, b.w);
  return a;
}

MVLADEF V4f v4f_sqrt(V4f a) {
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  a.z = sqrtf(a.z);
  a.w = sqrtf(a.w);
  return a;
}

MVLADEF V4f v4f_poww(V4f a, float exp) {
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  a.z = powf(a.z, exp);
  a.w = powf(a.w, exp);
  return a;
}

MVLADEF V4f v4f_pow(V4f a, V4f exp) {
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  a.z = powf(a.z, exp.z);
  a.w = powf(a.w, exp.w);
  return a;
}

MVLADEF V4f v4f_exp(V4f a) {
  a.x = powf(C_E, a.x);
  a.y = powf(C_E, a.y);
  a.z = powf(C_E, a.z);
  a.w = powf(C_E, a.w);
  return a;
}

MVLADEF V4f v4f_sin(V4f a) {
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  a.z = sinf(a.z);
  a.w = sinf(a.w);
  return a;
}

MVLADEF V4f v4f_cos(V4f a) {
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  a.z = cosf(a.z);
  a.w = cosf(a.w);
  return a;
}

MVLADEF V4f v4f_tan(V4f a) {
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  a.z = tanf(a.z);
  a.w = tanf(a.w);
  return a;
}

MVLADEF float v4f_len(V4f a) {
  float sqr = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
  return sqrtf(sqr);
}

MVLADEF void v4f_print(V4f a) {
  printf("V4f(%f, %f, %f, %f)\n", a.x, a.y, a.z, a.w);
}

MVLADEF V4d v4d(double x, double y, double z, double w) {
  V4d vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4d v4dd(double x) { return v4d(x, x, x, x); }

MVLADEF V4d v4d_add(V4d a, V4d b) {
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4d v4d_sub(V4d a, V4d b) {
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4d v4d_mul(V4d a, V4d b) {
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4d v4d_div(V4d a, V4d b) {
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4d v4d_min(V4d a, V4d b) {
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  a.w = fmin(a.w, b.w);
  return a;
}

MVLADEF V4d v4d_max(V4d a, V4d b) {
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  a.w = fmax(a.w, b.w);
  return a;
}

MVLADEF V4d v4d_sqrt(V4d a) {
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  a.z = sqrt(a.z);
  a.w = sqrt(a.w);
  return a;
}

MVLADEF V4d v4d_poww(V4d a, double exp) {
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  a.z = pow(a.z, exp);
  a.w = pow(a.w, exp);
  return a;
}

MVLADEF V4d v4d_pow(V4d a, V4d exp) {
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  a.z = pow(a.z, exp.z);
  a.w = pow(a.w, exp.w);
  return a;
}

MVLADEF V4d v4d_exp(V4d a) {
  a.x = pow(C_E, a.x);
  a.y = pow(C_E, a.y);
  a.z = pow(C_E, a.z);
  a.w = pow(C_E, a.w);
  return a;
}

MVLADEF V4d v4d_sin(V4d a) {
  a.x = sin(a.x);
  a.y = sin(a.y);
  a.z = sin(a.z);
  a.w = sin(a.w);
  return a;
}

MVLADEF V4d v4d_cos(V4d a) {
  a.x = cos(a.x);
  a.y = cos(a.y);
  a.z = cos(a.z);
  a.w = cos(a.w);
  return a;
}

MVLADEF V4d v4d_tan(V4d a) {
  a.x = tan(a.x);
  a.y = tan(a.y);
  a.z = tan(a.z);
  a.w = tan(a.w);
  return a;
}

MVLADEF double v4d_len(V4d a) {
  double sqr = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
  return sqrt(sqr);
}

MVLADEF void v4d_print(V4d a) {
  printf("V4d(%lf, %lf, %lf, %lf)\n", a.x, a.y, a.z, a.w);
}

// -----------------------------------------

/*
** @brief:   Create a vector with a specified length
** @params:  length {unsigned int} - length of vector
** @returns: vec {Vec} - new vec with specified length and initial values of 0
*/
MVLADEF Vec vec(unsigned int length) {
  Vec vec;
  vec.length = length;
  vec.data = calloc(length, sizeof(float));

  assert(vec.data);
  return vec;
}

/*
** @brief:   Get the element at a specific index in a vector
** @params:  a {const Vec} - vector with data, index {unsigned int} - the index of the requested data
** @returns: {float} - data at the specified index
*/
MVLADEF float vec_get(const Vec a, unsigned int index) {
  assert(index < a.length);
  return a.data[index];
}

/*
** @brief:   Get the pointer to an element out of a vector
** @params:  a {Vec *} - a vector (pointer for brevity), index {unsigned int} - element index
** @returns: {float *} - the pointer to the index'th element of the vector
*/
MVLADEF float *vec_get_ptr(const Vec *a, unsigned int index) {
  assert(index < a->length);
  return &a->data[index];
}

/*
** @brief:   Create a clone of a vector
** @params:  a {Vec} - vector to clone
** @returns: c {Vec} - cloned vector
*/
MVLADEF Vec vec_clone(Vec a) {
  assert(a.data);

  Vec c = vec(a.length);
  printf("%d\n", a.length);
  memcpy(c.data, a.data, a.length * sizeof(float));

  return c;
}

/*
** @brief:   Copy data from one vector to another with matching length
** @params:  dest {Vec *} - the destination vector, src {Vec *} - the source vector
** @returns: N/A
*/
MVLADEF void vec_copy_data(Vec *dest, Vec *src) {
  assert(src->data);
  assert(dest->data);
  assert(dest->length == src->length);

  memcpy(dest->data, src->data, src->length * sizeof(float));
}

/*
** @brief:   Adds a vector to another
** @params:  a {Vec} - first vector, b {Vec} - second vector
** @returns: c {Vec} - new vector equal to the i_th element of a plus the i_th element of b
*/
MVLADEF Vec vec_add(Vec a, Vec b) {
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);

  for (int i = 0; i < a.length; ++i)
    c.data[i] = a.data[i] + b.data[i];

  return c;
}

/*
** @brief:   Subtract a vector from another
** @params:  a {Vec} - first vector, b {Vec} - second vector
** @returns: c {Vec} - new vector equal to the i_th element of a minus the i_th element of b
*/
MVLADEF Vec vec_sub(Vec a, Vec b) {
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);

  for (int i = 0; i < a.length; ++i)
    c.data[i] = a.data[i] - b.data[i];

  return c;
}

/*
** @brief:   Multiplies the elements of two vectors together
** @params:  a {Vec} - first vector, b {Vec} - second vector
** @returns: c {Vec} - new vector with elements equal to i_th element of a multiplied with the i_th element of b
*/
MVLADEF Vec vec_mul(Vec a, Vec b) {
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);

  for (int i = 0; i < a.length; ++i)
    c.data[i] = a.data[i] * b.data[i];

  return c;
}

/*
** @brief:   Multiplies a vector with a scalar
** @params:  a {Vec} - vector to multiply, b {float} - scalar to multiply the vector by
** @returns: c {Vec} - new vector equal to a's elements multiplied by b
*/
MVLADEF Vec vec_mull(Vec a, float b) {
  assert(a.data);

  Vec c = vec(a.length);

  for (int i = 0; i < a.length; ++i)
    c.data[i] = a.data[i] * b;

  return c;
}

/*
** @brief:   Calculates dot product of two vectors
** @params:  a {Vec} - first vector (a length must equal b length), b {Vec} - second vector (b length must equal a length)
** @returns: c {Vec} - new vector equal to the vector product of a and b (length of 1)
*/
MVLADEF Vec vec_dot(Vec a, Vec b) {
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(1);

  for (int i = 0; i < a.length; ++i)
    c.data[0] += a.data[i] * b.data[i];

  return c;
}

/*
** @brief:   Divide the i_th element of the first vector by the i_th element of the second vector
** @params:  a {Vec} - vector to divide, b {Vec} - vector to divide a by
** @returns: c {Vec} - new vector with elements equal to a divided by b
*/
MVLADEF Vec vec_div(Vec a, Vec b) {
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);

  for (int i = 0; i < a.length; ++i) {
    if (b.data[i] == 0)
      continue;
    c.data[i] = (float)a.data[i] / b.data[i];
  }
  return c;
}

/*
** @brief:   Maps a function of type :: Float -> Float onto each element of a vector
** @params:  a {Vec} - vector to map, func {float (*ptr)(float)} - function to apply to each vector element
** @returns: c {Vec} - new vector with elements equal to mapped elements of a
*/
MVLADEF Vec vec_map(Vec a, float (*func)(float)) {
  assert(a.data);

  Vec c = vec(a.length);

  for (int i = 0; i < a.length; ++i)
    c.data[i] = func(a.data[i]);

  return c;
}

/*
** @brief:   Turn a row of a matrix into a vector
** @params:  a {Mat} - matrix to turn into a vector, row {int} - row of matrix to turn into vector
** @returns: c {Vec} - new vector that represents a single row of the matrix, a
*/
MVLADEF Vec vec_from_mat_row(Mat a, int row) {
  assert(a.data);
  assert(a.rows > row);

  Vec c = vec(a.cols);

  for (int i = 0; i < a.cols; ++i)
    c.data[i] = mat_get(a, row, i);

  return c;
}

/*
** @brief:   Turn a column of a matrix into a vector
** @params:  a {Mat} - matrix to turn into a vector, col {int} - the column of the matrix to turn into vector
** @returns: c {Vec} - new vector that represents a single column of the matrix, a
*/
MVLADEF Vec vec_from_mat_col(Mat a, int col) {
  assert(a.data);
  assert(a.cols > col);

  Vec c = vec(a.rows);

  for (int i = 0; i < a.rows; ++i)
    c.data[i] = mat_get(a, i, col);

  return c;
}

/*
** @brief:   Turn a float * into a vector
** @params:  a {float *} - float * to turn into a vector, length {unsigned int} - length of the vector
** @returns: c {Vec} - new vector that represents the float *, a
*/
MVLADEF Vec vec_from_f_ptr(float *a, unsigned int length) {
  assert(a);

  Vec c = vec(length);

  for (int i = 0; i < length; ++i)
    c.data[i] = a[i];

  return c;
}

/*
** @brief:   Get the length of a vector (square root of all elements squared and summed)
** @params:  a {const Vec} - vector to find the length of
** @returns: length {float} - the length of the vector
*/
MVLADEF float vec_length(const Vec a) {
  assert(a.data);

  float length = 0.0;

  for (int i = 0; i < a.length; ++i)
    length += a.data[i] * a.data[i];

  return sqrtf(length);
}

/*
** @brief:   Resize a vector
** @params:  a {Vec *} - vector to resize, newLength {unsigned int} - the new length of the vector
** @returns: N/A
*/
MVLADEF void vec_resize(Vec *a, unsigned int newLength) {
  assert(a->data);

  a->length = newLength;
  a->data = realloc(a->data, newLength * sizeof(float));
}

/*
** @brief:   Fill a vector with random numbers between 0 and 1
** @params:  a {Vec *} - vector to fill with random numbers
** @returns: N/A
*/
MVLADEF void vec_fill_rand(Vec *a) {
  assert(a->data);

  for (int i = 0; i < a->length; ++i)
    a->data[i] = rand_f();
}

/*
** @brief:   Free a vector's data property and set its length to -1
** @params:  a {Vec *} - vector to free
** @returns: N/A
*/
MVLADEF void vec_free(Vec *a) {
  free(a->data);
  a->data = NULL;
  a->length = -1;
}

/*
** @brief:   Prints the elements of a vector
** @params:  a {const Vec} - vector to print
** @returns: N/A
*/
MVLADEF void vec_print(const Vec a) {
  for (int i = 0; i < a.length; ++i)
    printf("%lf ", a.data[i]);
  printf("\n");
}

/*
** @brief:   Prints the length of a vector
** @params:  a {const Vec} - vector with length to print
** @returns: N/A
*/
MVLADEF void vec_print_length(const Vec a) {
  printf("Vector Length: %d\n", a.length);
}

// -----------------------------------------

/*
** @brief:   Create a matrix with varying row and column count
** @params:  rows {unsigned int} - row count, cols {unsigned int} - column count
** @returns: mat {Mat} - new matrix with size of rows*cols and initial values of 0
*/
MVLADEF Mat mat(unsigned int rows, unsigned int cols) {
  Mat mat;
  mat.rows = rows;
  mat.cols = cols;

  mat.data = calloc(rows * cols, sizeof(float));

  return mat;
}

/*
** @brief:   Create a matrix with equal row and column count
** @params:  dim {unsigned int} - row/column count
** @returns: mat {Mat} - new matrix with size dim*dim and initial values of 0
*/
MVLADEF Mat matt(unsigned int dim) {
  Mat mat;
  mat.rows = dim;
  mat.cols = dim;

  mat.data = calloc(dim * dim, sizeof(float));

  return mat;
}

/*
** @brief:   Create a completely empty matrix (NOT RECOMMENDED)
** @params:  N/A
** @returns: c {Mat} - new empty matrix 0x0 -> NULL
*/
MVLADEF Mat mat_null() {
  Mat c;

  c.rows = 0;
  c.cols = 0;
  c.data = NULL;

  return c;
}

/*
** @brief:   Create an identity matrix
** @params:  dim {unsigned int} - row/column count
** @returns: mat {Mat} - new identity matrix with size dim*dim
*/
MVLADEF Mat mat_id(unsigned int dim) {
  assert(dim > 0);

  Mat mat = matt(dim);

  for (int i = 0; i < dim; ++i)
    mat.data[i * mat.cols + i] = 1.0;

  return mat;
}

/*
** @brief:   Get the element out of a matrix
** @params:  a {Mat} - a matrix, i {unsigned int} - a row index, j {unsigned int} - a column index
** @returns: {float} - the element at [i][j] in a standard 2d matrix
*/
MVLADEF float mat_get(Mat a, unsigned int i, unsigned int j) {
  assert(a.data);
  return a.data[i * a.cols + j];
}

/*
** @brief:   Get the pointer to an element out of a matrix
** @params:  a {Mat *} - a matrix (pointer for brevity), i {unsigned int} - a row index, j {unsigned int} - a column index
** @returns: {float *} - the pointer to an element at [i][j] in a standard 2d matrix
*/
MVLADEF float *mat_get_ptr(Mat *a, unsigned int i, unsigned int j) {
  assert(a->data);
  return &a->data[i * a->cols + j];
}

/*
** @brief:   Create a clone of a matrix
** @params:  a {Mat} - matrix to clone
** @returns: c {Mat} - cloned matrix
*/
MVLADEF Mat mat_clone(Mat a) {
  assert(a.data);

  Mat c = mat(a.rows, a.cols);

  memcpy(c.data, a.data, a.rows * a.cols * sizeof(float));

  return c;
}

/*
** @brief:   Copy data from one matrix to another with matching dimensions
** @params:  dest {Mat *} - the destination matrix, src {Mat *} - the source matrix
** @returns: N/A
*/
MVLADEF void mat_copy_data(Mat *dest, Mat *src) {
  assert(src->data);
  assert(dest->data);
  assert(dest->rows == src->rows);
  assert(dest->cols == src->cols);

  memcpy(dest->data, src->data, src->rows * src->cols * sizeof(float));
}

/*
** @brief:   Adds a matrix to another
** @params:  a {Mat} - first matrix, b {Mat} - second matrix
** @returns: c {Mat} - new matrix equal to the i_th j_th element of a plus the i_th j_th element of b
*/
MVLADEF Mat mat_add(Mat a, Mat b) {
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < a.cols; ++j)
      *mat_get_ptr(&c, i, j) = mat_get(a, i, j) + mat_get(b, i, j);

  return c;
}

/*
** @brief:   Subtract a matrix from another
** @params:  a {Mat} - first matrix, b {Mat} - second matrix
** @returns: c {Mat} - new matrix equal to the i_th j_th element of a subtracting the i_th j_th element of b
*/
MVLADEF Mat mat_sub(Mat a, Mat b) {
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < a.cols; ++j)
      *mat_get_ptr(&c, i, j) = mat_get(a, i, j) - mat_get(b, i, j);

  return c;
}

/*
** @brief:   Multiplies the elements of two matrices together
** @params:  a {Mat} - first matrix, b {Mat} - second matrix
** @returns: c {Mat} - new matrix with elements equal to i_th j_th element of a multiplied with the i_th j_th element of b
*/
MVLADEF Mat mat_mul(Mat a, Mat b) {
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < a.cols; ++j)
      *mat_get_ptr(&c, i, j) = mat_get(a, i, j) * mat_get(b, i, j);

  return c;
}

/*
** @brief:   Multiplies a matrix with a scalar
** @params:  a {Mat} - matrix to multiply, b {float} - scalar to multiply the matrix by
** @returns: c {Mat} - new matrix equal to a's elements multiplied by b
*/
MVLADEF Mat mat_mull(Mat a, float b) {
  assert(a.data);

  Mat c = mat(a.rows, a.cols);

  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < a.cols; ++j)
      *mat_get_ptr(&c, i, j) = mat_get(a, i, j) * b;

  return c;
}

/*
** @brief:   Calculates dot product (matrix product) of two matrices
** @params:  a {Mat} - first matrix (a cols must equal b rows), b {Mat} - second matrix (b rows must equal a cols)
** @returns: c {Mat} - new matrix equal to the matrix product of a and b
*/
MVLADEF Mat mat_dot(Mat a, Mat b) {
  // m * p (dot) p * n = m * n
  assert(a.cols == b.rows);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, b.cols);

  // BUG! if b.cols > a.cols, it will segfault
  assert(b.cols <= a.cols && "Apparently a bug -> fix it soon");
  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < b.cols; ++j)
      for (int k = 0; k < b.rows; ++k)
        *mat_get_ptr(&c, i, j) += mat_get(a, i, k) * mat_get(b, k, j);

  return c;
}

/*
** @brief:   Divide the i_th j_th element of the first matrix by the i_th j_th element of the second matrix
** @params:  a {Mat} - matrix to divide, b {Mat} - matrix to divide a by
** @returns: c {Mat} - new matrix with elements equal to a divided by b
*/
MVLADEF Mat mat_div(Mat a, Mat b) {
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for (int i = 0; i < a.rows; ++i) {
    for (int j = 0; j < a.cols; ++j) {
      if (mat_get(b, i, j) == 0)
        continue;
      *mat_get_ptr(&c, i, j) = mat_get(a, i, j) / mat_get(b, i, j);
    }
  }

  return c;
}

/*
** @brief:   Transpose a matrix
** @params:  a {Mat} - matrix to transpose
** @returns: c {Mat} - new matrix equal to the transpose of a
*/
MVLADEF Mat mat_transpose(Mat a) {
  assert(a.data);

  Mat c = mat(a.cols, a.rows);

  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < a.cols; ++j)
      *mat_get_ptr(&c, j, i) = mat_get(a, i, j);

  return c;
}

/*
** @brief:   Maps a function of type :: Float -> Float onto each element of a matrix
** @params:  a {Mat} - matrix to map, func {float (*)(float)} - function to apply to each matrix element
** @returns: c {Mat} - new matrix with elements equal to mapped elements of a
*/
MVLADEF Mat mat_map(Mat a, float (*func)(float)) {
  assert(a.data);

  Mat c = mat(a.rows, a.cols);

  for (int i = 0; i < a.rows; ++i)
    for (int j = 0; j < a.cols; ++j)
      *mat_get_ptr(&c, i, j) = func(mat_get(a, i, j));

  return c;
}

/*
** @brief:   Turn a vector into a matrix (row vector into matrix)
** @params:  a {Vec} - vector to turn into a matrix
** @returns: c {Mat} - new matrix that represents the row vector, a
*/
MVLADEF Mat mat_from_vec(Vec a) {
  Mat c = mat(1, a.length);

  for (int i = 0; i < a.length; ++i)
    *mat_get_ptr(&c, 0, i) = a.data[i];

  return c;
}

/*
** @brief:   Get the dimensions of a matrix
** @params:  a {const Mat} - matrix with dimensions
** @returns: {V2u} - 2D unsigned int vector with x and y as row and column, respectively
*/
MVLADEF V2u mat_dims(const Mat a) { return (V2u){.x = a.rows, .y = a.cols}; }

/*
** @brief:   Fill a matrix with random numbers between 0 and 1
** @params:  a {Mat *} - matrix to fill with random numbers
** @returns: N/A
*/
MVLADEF void mat_fill_rand(Mat *a) {
  assert(a->data);

  for (int i = 0; i < a->rows; ++i)
    for (int j = 0; j < a->cols; ++j)
      *mat_get_ptr(a, i, j) = rand_f();
}

/*
** @brief:   Free a matrix's data property and set its row and column count to -1
** @params:  a {Mat *} - matrix to free
** @returns: N/A
*/
MVLADEF void mat_free(Mat *a) {
  free(a->data);
  a->data = NULL; // avoid double free
  a->rows = -1;
  a->cols = -1;
}

/*
** @brief:   Prints the elements of a matrix in order of rows and columns
** @params:  a {const Mat} - matrix to print
** @returns: N/A
*/
MVLADEF void mat_print(const Mat a) {
  for (int i = 0; i < a.rows; ++i) {
    for (int j = 0; j < a.cols; ++j)
      printf("%lf ", mat_get(a, i, j));
    printf("\n");
  }
}

/*
** @brief:   Prints the row and column count of a matrix
** @params:  a {const Mat} - matrix with row and column count to print
** @returns: N/A
*/
MVLADEF void mat_print_rows_cols(const Mat a) {
  printf("Matrix (Rows, Columns): (%d, %d)\n", a.rows, a.cols);
}

#endif // MVLA_IMPLEMENTATION

#ifdef __cplusplus
}
#endif // __cplusplus

/*
** TODO:
** - make all matrix and vector data fields constant (double **const data instead of double **data)
** - rewrite all matrix and vector functions as macros ***
** - implement quality-of-life functions in a separate block/file and remove PV__ macros
** - fix matrix product bug where b.cols must be greater than a.cols
** - add assert() for >=1 length, row, and column counts
** - add a function to map a function on the vectors (rows/cols) of a matrix -> for use with softmax
**
** - fvec_pop_front(); -> malloc and vector+sizeof(element) it in memcpy
** - fvec_remove(int index); -> delete the given index from the vector
** - fvec_clear(void *default_value) -> create a default value and pass its address to set everything to it
** - fvec_shrink_to(unsigned int new_length) -> drop all elements after new_length (easy with realloc)
** - ... more I can't think of right now
**
** - Implement a way to choose an allocator (ie... preprocessor defines to pick a malloc definition)
*/
