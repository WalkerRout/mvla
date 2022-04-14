

/*
** FUNCTION PROTOTYPES
*/
#ifndef MVLA_H
#define MVLA_H

// -----------------------------------------
/*
** INCLUDES
*/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
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

#define PV2i "V2i(%d, %d)"
#define PV2u "V2u(%u, %u)"
#define PV2f "V2f(%f, %f)"
#define PV2d "V2d(%lf, %lf)"
#define PV3i "V3i(%d, %d, %d)"
#define PV3u "V3u(%u, %u, %u)"
#define PV3f "V3f(%f, %f, %f)"
#define PV3d "V3d(%lf, %lf, %lf)"

#define MALLOC(size, type) (type*) alloc((size) * sizeof(type))
// -----------------------------------------



#ifdef INC_TENSORS
// -----------------------------------------
/*
** GENERIC 1D AND 2D TENSOR DEFINITIONS
*/
#define t1gen(v, n) ((v) = alloc((n) * sizeof *(v)))
#define t1free(v)    \
  do {               \
    free(v);         \
    v = NULL;        \
  } while (0)

#define t2gen(a, m, n)                  \
  do {                                  \
    t1gen(a, (m) + 1);                  \
    for(size_t i = 0; i < (m); i++){    \
      t1gen((a)[i], (n));               \
    }                                   \
    (a)[m] = NULL;                      \
  } while (0)
#define t2free(a)                                 \
  do {                                            \
    if (a != NULL) {                              \
      for (size_t i = 0; (a)[i] != NULL; i++){    \
        t1free((a)[i]);                           \
      }                                           \
      t1free(a);                                  \
      a = NULL;                                   \
    }                                             \
  } while (0)
// -----------------------------------------
#endif //INC_TENSORS



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
// -----------------------------------------



// -----------------------------------------
/*
** MATH FUNCTION PROTOTYPES
*/
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

MVLADEF V2u v2u(unsigned int x, unsigned int y);
MVLADEF V2u v2uu(unsigned int x);
MVLADEF V2u v2uAdd(V2u a, V2u b);
MVLADEF V2u v2uSub(V2u a, V2u b);
MVLADEF V2u v2uMul(V2u a, V2u b);
MVLADEF V2u v2uDiv(V2u a, V2u b);
MVLADEF V2u v2uMin(V2u a, V2u b);
MVLADEF V2u v2uMax(V2u a, V2u b);

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

MVLADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z);
MVLADEF V3u v3uu(unsigned int x);
MVLADEF V3u v3uAdd(V3u a, V3u b);
MVLADEF V3u v3uSub(V3u a, V3u b);
MVLADEF V3u v3uMul(V3u a, V3u b);
MVLADEF V3u v3uDiv(V3u a, V3u b);
MVLADEF V3u v3uMin(V3u a, V3u b);
MVLADEF V3u v3uMax(V3u a, V3u b);

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
  const float E = 2.718281;
  a.x = powf(E, a.x);
  a.y = powf(E, a.y);
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
  const double E = 2.718281828;
  a.x = pow(E, a.x);
  a.y = pow(E, a.y);
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
  const float E = 2.718281;
  a.x = powf(E, a.x);
  a.y = powf(E, a.y);
  a.z = powf(E, a.z);
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
  const double E = 2.718281828;
  a.x = pow(E, a.x);
  a.y = pow(E, a.y);
  a.z = pow(E, a.z);
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



#endif

