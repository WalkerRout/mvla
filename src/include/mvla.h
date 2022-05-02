/*
** @title:        MVLA (Matrix Vector Linear Algebra)
**
** @author:       Walker Rout
**
** @contact:      walkerrout04@gmail.com
**
** @date_written: March 16th, 2022
**
** @description:  This library implements matrices and different types of vectors
**                for use in Machine Learning / Computer Graphics projects.
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
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

#define MALLOC(size, type) (type*) alloc((size) * sizeof(type))
// -----------------------------------------



// -----------------------------------------
/*
** USEFUL CONSTANT DEFINTIONS
*/
#define C_E      2.71828182845
#define C_PI     3.14159265359
#define C_2PI    6.28318530718
#define C_4PI    12.5663706144
#define C_HALFPI 1.57079632679
#define C_SQRTPI 1.77245385091
#define C_SQRT2  1.41421356237
#define C_SQRT3  1.73205080757
#define C_LN2    0.69314718056
#define C_LN10   2.30258509299
#define C_LNPI   1.14472988585
#define C_LOGE   0.43429448190
// -----------------------------------------



// -----------------------------------------
/*
** 2D VECTOR DEFINITIONS
*/
typedef struct { signed int   x, y; } V2i;
typedef struct { unsigned int x, y; } V2u;
typedef struct { float        x, y; } V2f;
typedef struct { double       x, y; } V2d;
/*
** 3D VECTOR DEFINITIONS
*/
typedef struct { signed int   x, y, z; } V3i;
typedef struct { unsigned int x, y, z; } V3u;
typedef struct { float        x, y, z; } V3f;
typedef struct { double       x, y, z; } V3d;
/*
** 4D VECTOR DEFINITIONS
*/
typedef struct { signed int   x, y, z, w; } V4i;
typedef struct { unsigned int x, y, z, w; } V4u;
typedef struct { float        x, y, z, w; } V4f;
typedef struct { double       x, y, z, w; } V4d;
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
  float **data;
} Mat;
// -----------------------------------------



// -----------------------------------------
/*
** MATH FUNCTION PROTOTYPES
*/
MVLADEF float randF();
MVLADEF double randD();
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
MVLADEF V2i v2iAdd(V2i a, V2i b);
MVLADEF V2i v2iSub(V2i a, V2i b);
MVLADEF V2i v2iMul(V2i a, V2i b);
MVLADEF V2i v2iDiv(V2i a, V2i b);
MVLADEF V2i v2iMin(V2i a, V2i b);
MVLADEF V2i v2iMax(V2i a, V2i b);
MVLADEF void printV2i(V2i a);

MVLADEF V2u v2u(unsigned int x, unsigned int y);
MVLADEF V2u v2uu(unsigned int x);
MVLADEF V2u v2uAdd(V2u a, V2u b);
MVLADEF V2u v2uSub(V2u a, V2u b);
MVLADEF V2u v2uMul(V2u a, V2u b);
MVLADEF V2u v2uDiv(V2u a, V2u b);
MVLADEF V2u v2uMin(V2u a, V2u b);
MVLADEF V2u v2uMax(V2u a, V2u b);
MVLADEF void printV2u(V2u a);

MVLADEF V2f v2f(float x, float y);
MVLADEF V2f v2ff(float x);
MVLADEF V2f v2fAdd(V2f a, V2f b);
MVLADEF V2f v2fSub(V2f a, V2f b);
MVLADEF V2f v2fMul(V2f a, V2f b);
MVLADEF V2f v2fDiv(V2f a, V2f b);
MVLADEF V2f v2fMin(V2f a, V2f b);
MVLADEF V2f v2fMax(V2f a, V2f b);
MVLADEF V2f v2fSqrt(V2f a);
MVLADEF V2f v2fPoww(V2f a, float exp);
MVLADEF V2f v2fPow(V2f a, V2f exp);
MVLADEF V2f v2fExp(V2f a);
MVLADEF V2f v2fSin(V2f a);
MVLADEF V2f v2fCos(V2f a);
MVLADEF V2f v2fTan(V2f a);
MVLADEF float v2fLen(V2f a);
MVLADEF void printV2f(V2f a);

MVLADEF V2d v2d(double x, double y);
MVLADEF V2d v2dd(double x);
MVLADEF V2d v2dAdd(V2d a, V2d b);
MVLADEF V2d v2dSub(V2d a, V2d b);
MVLADEF V2d v2dMul(V2d a, V2d b);
MVLADEF V2d v2dDiv(V2d a, V2d b);
MVLADEF V2d v2dMin(V2d a, V2d b);
MVLADEF V2d v2dMax(V2d a, V2d b);
MVLADEF V2d v2dSqrt(V2d a);
MVLADEF V2d v2dPoww(V2d a, double exp);
MVLADEF V2d v2dPow(V2d a, V2d exp);
MVLADEF V2d v2dExp(V2d a);
MVLADEF V2d v2dSin(V2d a);
MVLADEF V2d v2dCos(V2d a);
MVLADEF V2d v2dTan(V2d a);
MVLADEF double v2dLen(V2d a);
MVLADEF void printV2d(V2d a);
// -----------------------------------------



// -----------------------------------------
/*
** 3D VECTOR FUNCTION PROTOTYPES
*/
MVLADEF V3i v3i(signed int x, signed int y, signed int z);
MVLADEF V3i v3ii(signed int x);
MVLADEF V3i v3iAdd(V3i a, V3i b);
MVLADEF V3i v3iSub(V3i a, V3i b);
MVLADEF V3i v3iMul(V3i a, V3i b);
MVLADEF V3i v3iDiv(V3i a, V3i b);
MVLADEF V3i v3iMin(V3i a, V3i b);
MVLADEF V3i v3iMax(V3i a, V3i b);
MVLADEF void printV3i(V3i a);

MVLADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z);
MVLADEF V3u v3uu(unsigned int x);
MVLADEF V3u v3uAdd(V3u a, V3u b);
MVLADEF V3u v3uSub(V3u a, V3u b);
MVLADEF V3u v3uMul(V3u a, V3u b);
MVLADEF V3u v3uDiv(V3u a, V3u b);
MVLADEF V3u v3uMin(V3u a, V3u b);
MVLADEF V3u v3uMax(V3u a, V3u b);
MVLADEF void printV3u(V3u a);

MVLADEF V3f v3f(float x, float y, float z);
MVLADEF V3f v3ff(float x);
MVLADEF V3f v3fAdd(V3f a, V3f b);
MVLADEF V3f v3fSub(V3f a, V3f b);
MVLADEF V3f v3fMul(V3f a, V3f b);
MVLADEF V3f v3fDiv(V3f a, V3f b);
MVLADEF V3f v3fMin(V3f a, V3f b);
MVLADEF V3f v3fMax(V3f a, V3f b);
MVLADEF V3f v3fSqrt(V3f a);
MVLADEF V3f v3fPoww(V3f a, float exp);
MVLADEF V3f v3fPow(V3f a, V3f exp);
MVLADEF V3f v3fExp(V3f a);
MVLADEF V3f v3fSin(V3f a);
MVLADEF V3f v3fCos(V3f a);
MVLADEF V3f v3fTan(V3f a);
MVLADEF float v3fLen(V3f a);
MVLADEF void printV3f(V3f a);

MVLADEF V3d v3d(double x, double y, double z);
MVLADEF V3d v3dd(double x);
MVLADEF V3d v3dAdd(V3d a, V3d b);
MVLADEF V3d v3dSub(V3d a, V3d b);
MVLADEF V3d v3dMul(V3d a, V3d b);
MVLADEF V3d v3dDiv(V3d a, V3d b);
MVLADEF V3d v3dMin(V3d a, V3d b);
MVLADEF V3d v3dMax(V3d a, V3d b);
MVLADEF V3d v3dSqrt(V3d a);
MVLADEF V3d v3dPoww(V3d a, double exp);
MVLADEF V3d v3dPow(V3d a, V3d exp);
MVLADEF V3d v3dExp(V3d a);
MVLADEF V3d v3dSin(V3d a);
MVLADEF V3d v3dCos(V3d a);
MVLADEF V3d v3dTan(V3d a);
MVLADEF double v3dLen(V3d a);
MVLADEF void printV3d(V3d a);
// -----------------------------------------



// -----------------------------------------
/*
** 3D VECTOR FUNCTION PROTOTYPES
*/
MVLADEF V4i v4i(signed int x, signed int y, signed int z, signed int w);
MVLADEF V4i v4ii(signed int x);
MVLADEF V4i v4iAdd(V4i a, V4i b);
MVLADEF V4i v4iSub(V4i a, V4i b);
MVLADEF V4i v4iMul(V4i a, V4i b);
MVLADEF V4i v4iDiv(V4i a, V4i b);
MVLADEF V4i v4iMin(V4i a, V4i b);
MVLADEF V4i v4iMax(V4i a, V4i b);
MVLADEF void printV4i(V4i a);

MVLADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w);
MVLADEF V4u v4uu(unsigned int x);
MVLADEF V4u v4uAdd(V4u a, V4u b);
MVLADEF V4u v4uSub(V4u a, V4u b);
MVLADEF V4u v4uMul(V4u a, V4u b);
MVLADEF V4u v4uDiv(V4u a, V4u b);
MVLADEF V4u v4uMin(V4u a, V4u b);
MVLADEF V4u v4uMax(V4u a, V4u b);
MVLADEF void printV4u(V4u a);

MVLADEF V4f v4f(float x, float y, float z, float w);
MVLADEF V4f v4ff(float x);
MVLADEF V4f v4fAdd(V4f a, V4f b);
MVLADEF V4f v4fSub(V4f a, V4f b);
MVLADEF V4f v4fMul(V4f a, V4f b);
MVLADEF V4f v4fDiv(V4f a, V4f b);
MVLADEF V4f v4fMin(V4f a, V4f b);
MVLADEF V4f v4fMax(V4f a, V4f b);
MVLADEF V4f v4fSqrt(V4f a);
MVLADEF V4f v4fPoww(V4f a, float exp);
MVLADEF V4f v4fPow(V4f a, V4f exp);
MVLADEF V4f v4fExp(V4f a);
MVLADEF V4f v4fSin(V4f a);
MVLADEF V4f v4fCos(V4f a);
MVLADEF V4f v4fTan(V4f a);
MVLADEF float v4fLen(V4f a);
MVLADEF void printV4f(V4f a);

MVLADEF V4d v4d(double x, double y, double z, double w);
MVLADEF V4d v4dd(double x);
MVLADEF V4d v4dAdd(V4d a, V4d b);
MVLADEF V4d v4dSub(V4d a, V4d b);
MVLADEF V4d v4dMul(V4d a, V4d b);
MVLADEF V4d v4dDiv(V4d a, V4d b);
MVLADEF V4d v4dMin(V4d a, V4d b);
MVLADEF V4d v4dMax(V4d a, V4d b);
MVLADEF V4d v4dSqrt(V4d a);
MVLADEF V4d v4dPoww(V4d a, double exp);
MVLADEF V4d v4dPow(V4d a, V4d exp);
MVLADEF V4d v4dExp(V4d a);
MVLADEF V4d v4dSin(V4d a);
MVLADEF V4d v4dCos(V4d a);
MVLADEF V4d v4dTan(V4d a);
MVLADEF double v4dLen(V4d a);
MVLADEF void printV4d(V4d a);
// -----------------------------------------



// -----------------------------------------
/*
** UNSPECIFIED VECTOR FUNCTION PROTOTYPES
*/
MVLADEF Vec vec(unsigned int length);
MVLADEF Vec vecAdd(Vec a, Vec b);
MVLADEF Vec vecSub(Vec a, Vec b);
MVLADEF Vec vecMul(Vec a, Vec b);
MVLADEF Vec vecMull(Vec a, float b);
MVLADEF Vec vecDot(Vec a, Vec b);
MVLADEF Vec vecDiv(Vec a, Vec b);
MVLADEF Vec vecMap(Vec a, float (*func)(float));
MVLADEF Vec matRowToVec(Mat a, int row);
MVLADEF Vec matColToVec(Mat a, int col);
MVLADEF Vec fPtrToVec(float *a, unsigned int length);
MVLADEF float vecLength(const Vec a);
MVLADEF void vecFillRand(Vec *a);
MVLADEF void freeVec(Vec *a);
MVLADEF void printVec(const Vec a);
MVLADEF void printVecLength(const Vec a);
// -----------------------------------------



// -----------------------------------------
/*
** UNSPECIFIED MATRIX FUNCTION PROTOTYPES
*/
MVLADEF Mat mat(unsigned int rows, unsigned int cols);
MVLADEF Mat matt(unsigned int dim);
MVLADEF Mat matId(unsigned int dim);
MVLADEF Mat matAdd(Mat a, Mat b);
MVLADEF Mat matSub(Mat a, Mat b);
MVLADEF Mat matMul(Mat a, Mat b);
MVLADEF Mat matMull(Mat a, float b);
MVLADEF Mat matDot(Mat a, Mat b);
MVLADEF Mat matDiv(Mat a, Mat b);
MVLADEF Mat matTranspose(Mat a);
MVLADEF Mat matMap(Mat a, float (*func)(float));
MVLADEF Mat vecToMat(Vec a);
MVLADEF void matFillRand(Mat *a);
MVLADEF void freeMat(Mat *a);
MVLADEF void printMat(const Mat a);
MVLADEF void printMatRowsCols(const Mat a);
// -----------------------------------------



// -----------------------------------------
/*
** MISCELLANEOUS FUNCTIONS
*/
MVLADEF void *alloc(unsigned int size){
  void *mem;
  mem = malloc(size);
  if(mem == NULL){
    printf("Out of memory!\n");
    exit(1);
  }
  return mem;
}
// -----------------------------------------


#endif // MVLA_H






/*
** HEADER ONLY IMPLEMENTATION
*/
#ifdef MVLA_IMPLEMENTATION

  
MVLADEF float randF(){
  return ((float) rand()) / ((float) RAND_MAX); // initialize srand first: srand(time(NULL))
}

MVLADEF double randD(){
  return ((double) rand()) / ((double) RAND_MAX); // initialize srand first: srand(time(NULL))
}

MVLADEF float lerpf(float a, float b, float t){
  return a + ((b - a) * t);
}

MVLADEF double lerp(double a, double b, double t){
  return a + ((b - a) * t);
}

MVLADEF signed int mini(signed int a, signed int b){
  return (a < b) ? a : b;
}

MVLADEF signed int maxi(signed int a, signed int b){
  return (a < b) ? b : a;
}

MVLADEF unsigned int minu(unsigned int a, unsigned int b){
  return (a < b) ? a : b;
}

MVLADEF unsigned int maxu(unsigned int a, unsigned int b){
  return (a < b) ? b : a;
}



// -----------------------------------------



MVLADEF V2i v2i(signed int x, signed int y){
  V2i vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLADEF V2i v2ii(signed int x){
  return v2i(x, x);
}

MVLADEF V2i v2iAdd(V2i a, V2i b){
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLADEF V2i v2iSub(V2i a, V2i b){
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLADEF V2i v2iMul(V2i a, V2i b){
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLADEF V2i v2iDiv(V2i a, V2i b){
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLADEF V2i v2iMin(V2i a, V2i b){
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  return a;
}

MVLADEF V2i v2iMax(V2i a, V2i b){
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  return a;
}

MVLADEF void printV2i(V2i a){
  printf("V2i(%d, %d)\n", a.x, a.y);
}



MVLADEF V2u v2u(unsigned int x, unsigned int y){
  V2u vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLADEF V2u v2uu(unsigned int x){
  return v2u(x, x);
}

MVLADEF V2u v2uAdd(V2u a, V2u b){
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLADEF V2u v2uSub(V2u a, V2u b){
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLADEF V2u v2uMul(V2u a, V2u b){
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLADEF V2u v2uDiv(V2u a, V2u b){
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLADEF V2u v2uMin(V2u a, V2u b){
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  return a;
}

MVLADEF V2u v2uMax(V2u a, V2u b){
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  return a;
}

MVLADEF void printV2u(V2u a){
  printf("V2u(%u, %u)\n", a.x, a.y);
}



MVLADEF V2f v2f(float x, float y){
  V2f vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLADEF V2f v2ff(float x){
  return v2f(x, x);
}

MVLADEF V2f v2fAdd(V2f a, V2f b){
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLADEF V2f v2fSub(V2f a, V2f b){
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLADEF V2f v2fMul(V2f a, V2f b){
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLADEF V2f v2fDiv(V2f a, V2f b){
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLADEF V2f v2fMin(V2f a, V2f b){
  a.x = fminf(a.x, b.x);
  a.y = fminf(a.y, b.y);
  return a;
}

MVLADEF V2f v2fMax(V2f a, V2f b){
  a.x = fmaxf(a.x, b.x);
  a.y = fmaxf(a.y, b.y);
  return a;
}

MVLADEF V2f v2fSqrt(V2f a){
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  return a;
}

MVLADEF V2f v2fPoww(V2f a, float exp){
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  return a;
}

MVLADEF V2f v2fPow(V2f a, V2f exp){
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  return a;
}

MVLADEF V2f v2fExp(V2f a){
  a.x = powf(C_E, a.x);
  a.y = powf(C_E, a.y);
  return a;
}

MVLADEF V2f v2fSin(V2f a){
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  return a;
}

MVLADEF V2f v2fCos(V2f a){
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  return a;
}

MVLADEF V2f v2fTan(V2f a){
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  return a;
}

MVLADEF float v2fLen(V2f a){
  float sqr = a.x*a.x + a.y*a.y;
  return sqrtf(sqr);
}

MVLADEF void printV2f(V2f a){
  printf("V2f(%f, %f)\n", a.x, a.y);
}



MVLADEF V2d v2d(double x, double y){
  V2d vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

MVLADEF V2d v2dd(double x){
  return v2d(x, x);
}

MVLADEF V2d v2dAdd(V2d a, V2d b){
  a.x += b.x;
  a.y += b.y;
  return a;
}

MVLADEF V2d v2dSub(V2d a, V2d b){
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

MVLADEF V2d v2dMul(V2d a, V2d b){
  a.x *= b.x;
  a.y *= b.y;
  return a;
}

MVLADEF V2d v2dDiv(V2d a, V2d b){
  a.x /= b.x;
  a.y /= b.y;
  return a;
}

MVLADEF V2d v2dMin(V2d a, V2d b){
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  return a;
}

MVLADEF V2d v2dMax(V2d a, V2d b){
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  return a;
}

MVLADEF V2d v2dSqrt(V2d a){
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  return a;
}

MVLADEF V2d v2dPoww(V2d a, double exp){
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  return a;
}

MVLADEF V2d v2dPow(V2d a, V2d exp){
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  return a;
}

MVLADEF V2d v2dExp(V2d a){
  a.x = pow(C_E, a.x);
  a.y = pow(C_E, a.y);
  return a;
}

MVLADEF V2d v2dSin(V2d a){
  a.x = sin(a.x);
  a.y = sin(a.y);
  return a;
}

MVLADEF V2d v2dCos(V2d a){
  a.x = cos(a.x);
  a.y = cos(a.y);
  return a;
}

MVLADEF V2d v2dTan(V2d a){
  a.x = tan(a.x);
  a.y = tan(a.y);
  return a;
}

MVLADEF double v2dLen(V2d a){
  double sqr = a.x*a.x + a.y*a.y;
  return sqrt(sqr);
}

MVLADEF void printV2d(V2d a){
  printf("V2d(%lf, %lf)\n", a.x, a.y);
}



// -----------------------------------------



MVLADEF V3i v3i(signed int x, signed int y, signed int z){
  V3i vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3i v3ii(signed int x){
  return v3i(x, x, x);
}

MVLADEF V3i v3iAdd(V3i a, V3i b){
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3i v3iSub(V3i a, V3i b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3i v3iMul(V3i a, V3i b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3i v3iDiv(V3i a, V3i b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3i v3iMin(V3i a, V3i b){
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  a.z = mini(a.z, b.z);
  return a;
}

MVLADEF V3i v3iMax(V3i a, V3i b){
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  a.z = maxi(a.z, b.z);
  return a;
}

MVLADEF void printV3i(V3i a){
  printf("V3i(%d, %d, %d)\n", a.x, a.y, a.z);
}



MVLADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z){
  V3u vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3u v3uu(unsigned int x){
  return v3u(x, x, x);
}

MVLADEF V3u v3uAdd(V3u a, V3u b){
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3u v3uSub(V3u a, V3u b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3u v3uMul(V3u a, V3u b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3u v3uDiv(V3u a, V3u b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3u v3uMin(V3u a, V3u b){
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  a.z = minu(a.z, b.z);
  return a;
}

MVLADEF V3u v3uMax(V3u a, V3u b){
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  a.z = maxu(a.z, b.z);
  return a;
}

MVLADEF void printV3u(V3u a){
  printf("V3u(%u, %u, %u)\n", a.x, a.y, a.z);
}



MVLADEF V3f v3f(float x, float y, float z){
  V3f vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3f v3ff(float x){
  return v3f(x, x, x);
}

MVLADEF V3f v3fAdd(V3f a, V3f b){
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3f v3fSub(V3f a, V3f b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3f v3fMul(V3f a, V3f b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3f v3fDiv(V3f a, V3f b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3f v3fMin(V3f a, V3f b){
  a.x = fminf(a.x, b.x);
  a.y = fminf(a.y, b.y);
  a.z = fminf(a.z, b.z);
  return a;
}

MVLADEF V3f v3fMax(V3f a, V3f b){
  a.x = fmaxf(a.x, b.x);
  a.y = fmaxf(a.y, b.y);
  a.z = fmaxf(a.z, b.z);
  return a;
}

MVLADEF V3f v3fSqrt(V3f a){
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  a.z = sqrtf(a.z);
  return a;
}

MVLADEF V3f v3fPoww(V3f a, float exp){
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  a.z = powf(a.z, exp);
  return a;
}

MVLADEF V3f v3fPow(V3f a, V3f exp){
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  a.z = powf(a.z, exp.z);
  return a;
}

MVLADEF V3f v3fExp(V3f a){
  a.x = powf(C_E, a.x);
  a.y = powf(C_E, a.y);
  a.z = powf(C_E, a.z);
  return a;
}

MVLADEF V3f v3fSin(V3f a){
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  a.z = sinf(a.z);
  return a;
}

MVLADEF V3f v3fCos(V3f a){
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  a.z = cosf(a.z);
  return a;
}

MVLADEF V3f v3fTan(V3f a){
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  a.z = tanf(a.z);
  return a;
}

MVLADEF float v3fLen(V3f a){
  float sqr = a.x*a.x + a.y*a.y + a.z*a.z;
  return sqrtf(sqr);
}

MVLADEF void printV3f(V3f a){
  printf("V3f(%f, %f, %f)\n", a.x, a.y, a.z);
}



MVLADEF V3d v3d(double x, double y, double z){
  V3d vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

MVLADEF V3d v3dd(double x){
  return v3d(x, x, x);
}

MVLADEF V3d v3dAdd(V3d a, V3d b){
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

MVLADEF V3d v3dSub(V3d a, V3d b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  return a;
}

MVLADEF V3d v3dMul(V3d a, V3d b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  return a;
}

MVLADEF V3d v3dDiv(V3d a, V3d b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  return a;
}

MVLADEF V3d v3dMin(V3d a, V3d b){
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  return a;
}

MVLADEF V3d v3dMax(V3d a, V3d b){
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  return a;
}

MVLADEF V3d v3dSqrt(V3d a){
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  a.z = sqrt(a.z);
  return a;
}

MVLADEF V3d v3dPoww(V3d a, double exp){
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  a.z = pow(a.z, exp);
  return a;
}

MVLADEF V3d v3dPow(V3d a, V3d exp){
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  a.z = pow(a.z, exp.z);
  return a;
}

MVLADEF V3d v3dExp(V3d a){
  a.x = pow(C_E, a.x);
  a.y = pow(C_E, a.y);
  a.z = pow(C_E, a.z);
  return a;
}

MVLADEF V3d v3dSin(V3d a){
  a.x = sin(a.x);
  a.y = sin(a.y);
  a.z = sin(a.z);
  return a;
}

MVLADEF V3d v3dCos(V3d a){
  a.x = cos(a.x);
  a.y = cos(a.y);
  a.z = cos(a.z);
  return a;
}

MVLADEF V3d v3dTan(V3d a){
  a.x = tan(a.x);
  a.y = tan(a.y);
  a.z = tan(a.z);
  return a;
}

MVLADEF double v3dLen(V3d a){
  double sqr = a.x*a.x + a.y*a.y + a.z*a.z;
  return sqrt(sqr);
}

MVLADEF void printV3d(V3d a){
  printf("V3d(%lf, %lf, %lf)\n", a.x, a.y, a.z);
}



// -----------------------------------------



MVLADEF V4i v4i(signed int x, signed int y, signed int z, signed int w){
  V4i vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4i v4ii(signed int x){
  return v4i(x, x, x, x);
}

MVLADEF V4i v4iAdd(V4i a, V4i b){
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4i v4iSub(V4i a, V4i b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4i v4iMul(V4i a, V4i b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4i v4iDiv(V4i a, V4i b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4i v4iMin(V4i a, V4i b){
  a.x = mini(a.x, b.x);
  a.y = mini(a.y, b.y);
  a.z = mini(a.z, b.z);
  a.w = mini(a.w, b.w);
  return a;
}

MVLADEF V4i v4iMax(V4i a, V4i b){
  a.x = maxi(a.x, b.x);
  a.y = maxi(a.y, b.y);
  a.z = maxi(a.z, b.z);
  a.w = maxi(a.w, b.w);
  return a;
}

MVLADEF void printV4i(V4i a){
  printf("V4i(%d, %d, %d, %d)\n", a.x, a.y, a.z, a.w);
}



MVLADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w){
  V4u vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4u v4uu(unsigned int x){
  return v4u(x, x, x, x);
}

MVLADEF V4u v4uAdd(V4u a, V4u b){
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4u v4uSub(V4u a, V4u b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4u v4uMul(V4u a, V4u b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4u v4uDiv(V4u a, V4u b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4u v4uMin(V4u a, V4u b){
  a.x = minu(a.x, b.x);
  a.y = minu(a.y, b.y);
  a.z = minu(a.z, b.z);
  a.w = minu(a.w, b.w);
  return a;
}

MVLADEF V4u v4uMax(V4u a, V4u b){
  a.x = maxu(a.x, b.x);
  a.y = maxu(a.y, b.y);
  a.z = maxu(a.z, b.z);
  a.w = maxu(a.w, b.w);
  return a;
}

MVLADEF void printV4u(V4u a){
  printf("V4u(%u, %u, %u, %u)\n", a.x, a.y, a.z, a.w);
}



MVLADEF V4f v4f(float x, float y, float z, float w){
  V4f vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4f v4ff(float x){
  return v4f(x, x, x, x); 
}

MVLADEF V4f v4fAdd(V4f a, V4f b){
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4f v4fSub(V4f a, V4f b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4f v4fMul(V4f a, V4f b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4f v4fDiv(V4f a, V4f b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4f v4fMin(V4f a, V4f b){
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  a.w = fmin(a.w, b.w);
  return a;
}

MVLADEF V4f v4fMax(V4f a, V4f b){
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  a.w = fmax(a.w, b.w);
  return a;
}

MVLADEF V4f v4fSqrt(V4f a){
  a.x = sqrtf(a.x);
  a.y = sqrtf(a.y);
  a.z = sqrtf(a.z);
  a.w = sqrtf(a.w);
  return a;
}

MVLADEF V4f v4fPoww(V4f a, float exp){
  a.x = powf(a.x, exp);
  a.y = powf(a.y, exp);
  a.z = powf(a.z, exp);
  a.w = powf(a.w, exp);
  return a;
}

MVLADEF V4f v4fPow(V4f a, V4f exp){
  a.x = powf(a.x, exp.x);
  a.y = powf(a.y, exp.y);
  a.z = powf(a.z, exp.z);
  a.w = powf(a.w, exp.w);
  return a;
}

MVLADEF V4f v4fExp(V4f a){
  a.x = powf(C_E, a.x);
  a.y = powf(C_E, a.y);
  a.z = powf(C_E, a.z);
  a.w = powf(C_E, a.w);
  return a;
}

MVLADEF V4f v4fSin(V4f a){
  a.x = sinf(a.x);
  a.y = sinf(a.y);
  a.z = sinf(a.z);
  a.w = sinf(a.w);
  return a;
}

MVLADEF V4f v4fCos(V4f a){
  a.x = cosf(a.x);
  a.y = cosf(a.y);
  a.z = cosf(a.z);
  a.w = cosf(a.w);
  return a;
}

MVLADEF V4f v4fTan(V4f a){
  a.x = tanf(a.x);
  a.y = tanf(a.y);
  a.z = tanf(a.z);
  a.w = tanf(a.w);
  return a;
}

MVLADEF float v4fLen(V4f a){
  float sqr = a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
  return sqrtf(sqr);
}

MVLADEF void printV4f(V4f a){
  printf("V4f(%f, %f, %f, %f)\n", a.x, a.y, a.z, a.w);
}



MVLADEF V4d v4d(double x, double y, double z, double w){
  V4d vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  return vec;
}

MVLADEF V4d v4dd(double x){
  return v4d(x, x, x, x); 
}

MVLADEF V4d v4dAdd(V4d a, V4d b){
  a.x += b.x; 
  a.y += b.y;
  a.z += b.z;
  a.w += b.w;
  return a;
}

MVLADEF V4d v4dSub(V4d a, V4d b){
  a.x -= b.x;
  a.y -= b.y;
  a.z -= b.z;
  a.w -= b.w;
  return a;
}

MVLADEF V4d v4dMul(V4d a, V4d b){
  a.x *= b.x;
  a.y *= b.y;
  a.z *= b.z;
  a.w *= b.w;
  return a;
}

MVLADEF V4d v4dDiv(V4d a, V4d b){
  a.x /= b.x;
  a.y /= b.y;
  a.z /= b.z;
  a.w /= b.w;
  return a;
}

MVLADEF V4d v4dMin(V4d a, V4d b){
  a.x = fmin(a.x, b.x);
  a.y = fmin(a.y, b.y);
  a.z = fmin(a.z, b.z);
  a.w = fmin(a.w, b.w);
  return a;
}

MVLADEF V4d v4dMax(V4d a, V4d b){
  a.x = fmax(a.x, b.x);
  a.y = fmax(a.y, b.y);
  a.z = fmax(a.z, b.z);
  a.w = fmax(a.w, b.w);
  return a;
}

MVLADEF V4d v4dSqrt(V4d a){
  a.x = sqrt(a.x);
  a.y = sqrt(a.y);
  a.z = sqrt(a.z);
  a.w = sqrt(a.w);
  return a;
}

MVLADEF V4d v4dPoww(V4d a, double exp){
  a.x = pow(a.x, exp);
  a.y = pow(a.y, exp);
  a.z = pow(a.z, exp);
  a.w = pow(a.w, exp);
  return a;
}

MVLADEF V4d v4dPow(V4d a, V4d exp){
  a.x = pow(a.x, exp.x);
  a.y = pow(a.y, exp.y);
  a.z = pow(a.z, exp.z);
  a.w = pow(a.w, exp.w);
  return a;
}

MVLADEF V4d v4dExp(V4d a){
  a.x = pow(C_E, a.x);
  a.y = pow(C_E, a.y);
  a.z = pow(C_E, a.z);
  a.w = pow(C_E, a.w);
  return a;
}

MVLADEF V4d v4dSin(V4d a){
  a.x = sin(a.x);
  a.y = sin(a.y);
  a.z = sin(a.z);
  a.w = sin(a.w);
  return a;
}

MVLADEF V4d v4dCos(V4d a){
  a.x = cos(a.x);
  a.y = cos(a.y);
  a.z = cos(a.z);
  a.w = cos(a.w);
  return a;
}

MVLADEF V4d v4dTan(V4d a){
  a.x = tan(a.x);
  a.y = tan(a.y);
  a.z = tan(a.z);
  a.w = tan(a.w);
  return a;
}

MVLADEF double v4dLen(V4d a){
  double sqr = a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
  return sqrt(sqr);
}

MVLADEF void printV4d(V4d a){
  printf("V4d(%lf, %lf, %lf, %lf)\n", a.x, a.y, a.z, a.w);
}



// -----------------------------------------



/*
** @brief:   Create a vector with a specified length
** @params:  length {unsigned int} - length of vector
** @returns: vec {Vec} - new vec with specified length and initial values of 0
*/
MVLADEF Vec vec(unsigned int length){
  Vec vec;
  vec.length = length;
  vec.data = calloc(length, sizeof(float));

  return vec;
}

/*
** @brief:   Adds a vector to another
** @params:  a {Vec} - first vector, b {Vec} - second vector
** @returns: c {Vec} - new vector equal to the i_th element of a plus the i_th element of b
*/
MVLADEF Vec vecAdd(Vec a, Vec b){
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);
  
  for(int i = 0; i < a.length; i++) c.data[i] = a.data[i] + b.data[i];

  return c;
}

/*
** @brief:   Subtract a vector from another
** @params:  a {Vec} - first vector, b {Vec} - second vector
** @returns: c {Vec} - new vector equal to the i_th element of a minus the i_th element of b
*/
MVLADEF Vec vecSub(Vec a, Vec b){
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);

  for(int i = 0; i < a.length; i++) c.data[i] = a.data[i] - b.data[i];

  return c;
}

/*
** @brief:   Multiplies the elements of two vectors together
** @params:  a {Vec} - first vector, b {Vec} - second vector
** @returns: c {Vec} - new vector with elements equal to i_th element of a multiplied with the i_th element of b
*/
MVLADEF Vec vecMul(Vec a, Vec b){
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);

  for(int i = 0; i < a.length; i++) c.data[i] = a.data[i] * b.data[i];

  return c;
}

/*
** @brief:   Multiplies a vector with a scalar
** @params:  a {Vec} - vector to multiply, b {float} - scalar to multiply the vector by
** @returns: c {Vec} - new vector equal to a's elements multiplied by b
*/
MVLADEF Vec vecMull(Vec a, float b){
  assert(a.data);
  
  Vec c = vec(a.length);
  
  for(int i = 0; i < a.length; i++) c.data[i] = a.data[i] * b;

  return c;
}

/*
** @brief:   Calculates dot product of two vectors
** @params:  a {Vec} - first vector (a length must equal b length), b {Vec} - second vector (b length must equal a length)
** @returns: c {Vec} - new vector equal to the vector product of a and b (length of 1)
*/
MVLADEF Vec vecDot(Vec a, Vec b){
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(1);

  for(int i = 0; i < a.length; i++) c.data[0] += a.data[i] * b.data[i];

  return c;
}

/*
** @brief:   Divide the i_th element of the first vector by the i_th element of the second vector
** @params:  a {Vec} - vector to divide, b {Vec} - vector to divide a by
** @returns: c {Vec} - new vector with elements equal to a divided by b
*/
MVLADEF Vec vecDiv(Vec a, Vec b){
  assert(a.length == b.length);
  assert(a.data);
  assert(b.data);

  Vec c = vec(a.length);

  for(int i = 0; i < a.length; i++){
    if(b.data[i] == 0) continue;
    c.data[i] = (float) a.data[i] / b.data[i];
  }
  return c;
}

/*
** @brief:   Maps a function of type :: Float -> Float onto each element of a vector
** @params:  a {Vec} - vector to map, func {float (*ptr)(float)} - function to apply to each vector element
** @returns: c {Vec} - new vector with elements equal to mapped elements of a
*/
MVLADEF Vec vecMap(Vec a, float (*func)(float)){
  assert(a.data);

  Vec c = vec(a.length);

  for(int i = 0; i < a.length; i++){
    c.data[i] = func(a.data[i]);
  }

  return c;
}

/*
** @brief:   Turn a row of a matrix into a vector
** @params:  a {Mat} - matrix to turn into a vector, row {int} - row of matrix to turn into vector
** @returns: c {Vec} - new vector that represents a single row of the matrix, a
*/
MVLADEF Vec matRowToVec(Mat a, int row){
  assert(a.data);
  assert(a.rows > row);

  Vec c = vec(a.cols);

  for(int i = 0; i < a.cols; i++) c.data[i] = a.data[row][i];

  return c;
}

/*
** @brief:   Turn a column of a matrix into a vector
** @params:  a {Mat} - matrix to turn into a vector, col {int} - the column of the matrix to turn into vector
** @returns: c {Vec} - new vector that represents a single column of the matrix, a
*/
MVLADEF Vec matColToVec(Mat a, int col){
  assert(a.data);
  assert(a.cols > col);
  
  Vec c = vec(a.rows);

  for(int i = 0; i < a.rows; i++){
    c.data[i] = a.data[i][col];
  }
  
  return c;
}

/*
** @brief:   Turn a float * into a vector
** @params:  a {float *} - float * to turn into a vector, length {unsigned int} - length of the vector
** @returns: c {Vec} - new vector that represents the float *, a
*/
MVLADEF Vec fPtrToVec(float *a, unsigned int length){
  assert(a);

  Vec c = vec(length);

  for(int i = 0; i < length; i++) c.data[i] = a[i];

  return c;
}

/*
** @brief:   Get the length of a vector (square root of all elements squared and summed)
** @params:  a {const Vec} - vector to find the length of
** @returns: length {float} - the length of the vector
*/
MVLADEF float vecLength(const Vec a){
  assert(a.data);
  
  float length = 0.0;
  
  for(int i = 0; i < a.length; i++) length += a.data[i]*a.data[i];
  
  return sqrtf(length);
}

/*
** @brief:   Fill a vector with random numbers between 0 and 1
** @params:  a {Vec *} - vector to fill with random numbers
** @returns: N/A
*/
MVLADEF void vecFillRand(Vec *a){
  assert(a->data);

  for(int i = 0; i < a->length; i++) a->data[i] = randF();
}

/*
** @brief:   Free a vector's data property and set its length to -1
** @params:  a {Vec *} - vector to free
** @returns: N/A
*/
MVLADEF void freeVec(Vec *a){
  free(a->data);
  a->length = -1;
}

/*
** @brief:   Prints the elements of a vector
** @params:  a {const Vec} - vector to print
** @returns: N/A
*/
MVLADEF void printVec(const Vec a){
  for(int i = 0; i < a.length; i++) printf("%lf ", a.data[i]);
  printf("\n");
}

/*
** @brief:   Prints the length of a vector
** @params:  a {const Vec} - vector with length to print
** @returns: N/A
*/
MVLADEF void printVecEleCount(const Vec a){
  printf("Vector Length: %d\n", a.length);
}



// -----------------------------------------



/*
** @brief:   Create a matrix with varying row and column count
** @params:  rows {unsigned int} - row count, cols {unsigned int} - column count
** @returns: mat {Mat} - new matrix with size of rows*cols and initial values of 0
*/
MVLADEF Mat mat(unsigned int rows, unsigned int cols){
  Mat mat;
  mat.rows = rows;
  mat.cols = cols;

  mat.data = calloc(rows, sizeof(float *));
  for(int i = 0; i < rows; i++) mat.data[i] = calloc(cols, sizeof(float));

  return mat;
}

/*
** @brief:   Create a matrix with equal row and column count
** @params:  dim {unsigned int} - row/column count
** @returns: mat {Mat} - new matrix with size dim*dim and initial values of 0
*/
MVLADEF Mat matt(unsigned int dim){
  Mat mat;
  mat.rows = dim;
  mat.cols = dim;

  mat.data = calloc(dim, sizeof(float *));
  for(int i = 0; i < dim; i++) mat.data[i] = calloc(dim, sizeof(float));

  return mat;
}

/*
** @brief:   Create an identity matrix
** @params:  dim {unsigned int} - row/column count
** @returns: mat {Mat} - new identity matrix with size dim*dim
*/
MVLADEF Mat matId(unsigned int dim){
  assert(dim > 0);

  Mat mat = matt(dim);

  for(int i = 0; i < dim; i++) mat.data[i][i] = 1.0;

  return mat;
}

/*
** @brief:   Adds a matrix to another
** @params:  a {Mat} - first matrix, b {Mat} - second matrix
** @returns: c {Mat} - new matrix equal to the i_th j_th element of a plus the i_th j_th element of b
*/
MVLADEF Mat matAdd(Mat a, Mat b){
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      c.data[i][j] = a.data[i][j] + b.data[i][j];
    }
  }
  
  return c;
}

/*
** @brief:   Subtract a matrix from another
** @params:  a {Mat} - first matrix, b {Mat} - second matrix
** @returns: c {Mat} - new matrix equal to the i_th j_th element of a subtracting the i_th j_th element of b
*/
MVLADEF Mat matSub(Mat a, Mat b){
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      c.data[i][j] = a.data[i][j] - b.data[i][j];
    }
  }
  
  return c;
}

/*
** @brief:   Multiplies the elements of two matrices together
** @params:  a {Mat} - first matrix, b {Mat} - second matrix
** @returns: c {Mat} - new matrix with elements equal to i_th j_th element of a multiplied with the i_th j_th element of b
*/
MVLADEF Mat matMul(Mat a, Mat b){
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      c.data[i][j] = a.data[i][j] * b.data[i][j];
    }
  }
  
  return c;
}

/*
** @brief:   Multiplies a matrix with a scalar
** @params:  a {Mat} - matrix to multiply, b {float} - scalar to multiply the matrix by
** @returns: c {Mat} - new matrix equal to a's elements multiplied by b
*/
MVLADEF Mat matMull(Mat a, float b){
  assert(a.data);
  
  Mat c = mat(a.rows, a.cols);
  
  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      c.data[i][j] = a.data[i][j] * b;
    }
  }

  return c;
}

/*
** @brief:   Calculates dot product (matrix product) of two matrices
** @params:  a {Mat} - first matrix (a cols must equal b rows), b {Mat} - second matrix (b rows must equal a cols)
** @returns: c {Mat} - new matrix equal to the matrix product of a and b
*/
MVLADEF Mat matDot(Mat a, Mat b){
  // m * p (dot) p * n = m * n
  assert(a.cols == b.rows);
  assert(a.data);
  assert(b.data);
  assert(b.cols <= a.cols && "b.cols cannot be greater than a.cols! It will access memory outside of the allocated memory for a!");

  Mat c = mat(a.rows, b.cols);

  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < b.cols; j++){
      for (int k = 0; k < b.cols; k++){
        c.data[i][j] += a.data[i][k] * b.data[k][j]; // BUG! if b.cols > a.cols, it will segfault
      }
    }
  }

  return c;
}

/*
** @brief:   Divide the i_th j_th element of the first matrix by the i_th j_th element of the second matrix
** @params:  a {Mat} - matrix to divide, b {Mat} - matrix to divide a by
** @returns: c {Mat} - new matrix with elements equal to a divided by b
*/
MVLADEF Mat matDiv(Mat a, Mat b){
  assert(a.rows == b.rows);
  assert(a.cols == b.cols);
  assert(a.data);
  assert(b.data);

  Mat c = mat(a.rows, a.cols);

  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      if(b.data[i][j] == 0) continue;
      c.data[i][j] = (float) a.data[i][j] / b.data[i][j];
    }
  }
  
  return c;
}

/*
** @brief:   Transpose a matrix
** @params:  a {Mat} - matrix to transpose
** @returns: c {Mat} - new matrix equal to the transpose of a
*/
MVLADEF Mat matTranspose(Mat a){
  assert(a.data);
  
  Mat c = mat(a.cols, a.rows);

  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      c.data[j][i] = a.data[i][j];
    }
  }

  return c;
}

/*
** @brief:   Maps a function of type :: Float -> Float onto each element of a matrix
** @params:  a {Mat} - matrix to map, func {float (*ptr)(float)} - function to apply to each matrix element
** @returns: c {Mat} - new matrix with elements equal to mapped elements of a
*/
MVLADEF Mat matMap(Mat a, float (*func)(float)){
  assert(a.data);

  Mat c = mat(a.rows, a.cols);

  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      c.data[i][j] = func(a.data[i][j]);
    }
  }

  return c;
}

/*
** @brief:   Turn a vector into a matrix (row vector into matrix)
** @params:  a {Vec} - vector to turn into a matrix
** @returns: c {Mat} - new matrix that represents the row vector, a
*/
MVLADEF Mat vecToMat(Vec a){
  Mat c = mat(1, a.length);

  for(int i = 0; i < a.length; i++) c.data[0][i] = a.data[i];
  
  return c;
}

/*
** @brief:   Fill a matrix with random numbers between 0 and 1
** @params:  a {Mat *} - matrix to fill with random numbers
** @returns: N/A
*/
MVLADEF void matFillRand(Mat *a){
  assert(a->data);

  for(int i = 0; i < a->rows; i++){
    for(int j = 0; j < a->cols; j++){
      a->data[i][j] = randF();
    }
  }
}

/*
** @brief:   Free a matrix's data property and set its row and column count to -1
** @params:  a {Mat *} - matrix to free
** @returns: N/A
*/
MVLADEF void freeMat(Mat *a){
  for(int i = 0; i < a->rows; i++) free(a->data[i]);
  free(a->data);
  a->rows = -1;
  a->cols = -1;
}

/*
** @brief:   Prints the elements of a matrix in order of rows and columns
** @params:  a {const Mat} - matrix to print
** @returns: N/A
*/
MVLADEF void printMat(const Mat a){
  for(int i = 0; i < a.rows; i++){
    for(int j = 0; j < a.cols; j++){
      printf("%lf ", a.data[i][j]);
    }
    printf("\n");
  }
}

/*
** @brief:   Prints the row and column count of a matrix
** @params:  a {const Mat} - matrix with row and column count to print
** @returns: N/A
*/
MVLADEF void printMatRowsCols(const Mat a){
  printf("Matrix (Rows, Columns): (%d, %d)\n", a.rows, a.cols);
}


#endif // MVLA_IMPLEMENTATION



#ifdef __cplusplus
}
#endif // __cplusplus



/*
** TODO:
** - implement quality-of-life functions in a separate block/file and remove PV__ macros
** - fix matrix product bug where b.cols must be greater than a.cols
** - comment all V__ functions
** - add assert() for >=1 length, row, and column counts
** - add a function to map a function on the vectors (rows/cols) of a matrix (for use with softmax)
**
*/
