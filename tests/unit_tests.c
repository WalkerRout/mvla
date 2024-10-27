#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define EPSILONF 1e-5f
#define EPSILOND 1e-9

#define MVLA_IMPLEMENTATION
#include "../mvla.h"
#undef  MVLA_IMPLEMENTATION

// NDEBUG disables assert, this will never be disabled
#define ALWAYS_ASSERT(expr) \
  ((expr) ? (void)0 : (fprintf(stderr, "Assertion failed at line %d: %s\n", __LINE__, #expr), exit(0)))

bool approxf(float x, float y) {
  return fabsf(x - y) < EPSILONF;
}

bool approxd(double x, double y) {
  return fabs(x - y) < EPSILOND;
}

void test_v2i() {
  // v2i
  v2i_t veca = v2i(3, 4);
  ALWAYS_ASSERT(veca.x == 3);
  ALWAYS_ASSERT(veca.y == 4);

  // v2ii
  v2i_t vecb = v2ii(5);
  ALWAYS_ASSERT(vecb.x == 5);
  ALWAYS_ASSERT(vecb.y == 5);

  // v2i_add
  v2i_t vec_sum = v2i_add(veca, vecb);
  ALWAYS_ASSERT(vec_sum.x == 8);
  ALWAYS_ASSERT(vec_sum.y == 9);

  // v2i_sub
  v2i_t vec_diff = v2i_sub(veca, vecb);
  ALWAYS_ASSERT(vec_diff.x == -2);
  ALWAYS_ASSERT(vec_diff.y == -1);

  // v2i_mul
  v2i_t vec_prod = v2i_mul(veca, vecb);
  ALWAYS_ASSERT(vec_prod.x == 15);
  ALWAYS_ASSERT(vec_prod.y == 20);

  // v2i_div
  v2i_t vec_div = v2i_div(veca, v2i(1, 2)); // care div by zero
  ALWAYS_ASSERT(vec_div.x == 3);
  ALWAYS_ASSERT(vec_div.y == 2);

  // v2i_min
  v2i_t vec_min = v2i_min(veca, vecb);
  ALWAYS_ASSERT(vec_min.x == 3);
  ALWAYS_ASSERT(vec_min.y == 4);

  // v2i_max
  v2i_t vec_max = v2i_max(veca, vecb);
  ALWAYS_ASSERT(vec_max.x == 5);
  ALWAYS_ASSERT(vec_max.y == 5);
}

void test_v2u() {
  // v2u
  v2u_t veca = v2u(3, 4);
  ALWAYS_ASSERT(veca.x == 3);
  ALWAYS_ASSERT(veca.y == 4);

  // v2uu
  v2u_t vecb = v2uu(5);
  ALWAYS_ASSERT(vecb.x == 5);
  ALWAYS_ASSERT(vecb.y == 5);

  // v2u_add
  v2u_t vec_sum = v2u_add(veca, vecb);
  ALWAYS_ASSERT(vec_sum.x == 8);
  ALWAYS_ASSERT(vec_sum.y == 9);

  // v2u_sub
  v2u_t vec_diff = v2u_sub(veca, vecb);
  ALWAYS_ASSERT(vec_diff.x == (unsigned int)-2); // check/handle underflow
  ALWAYS_ASSERT(vec_diff.y == (unsigned int)-1);

  // v2u_mul
  v2u_t vec_prod = v2u_mul(veca, vecb);
  ALWAYS_ASSERT(vec_prod.x == 15);
  ALWAYS_ASSERT(vec_prod.y == 20);

  // v2u_div
  v2u_t vec_div = v2u_div(veca, v2u(1, 2));
  ALWAYS_ASSERT(vec_div.x == 3);
  ALWAYS_ASSERT(vec_div.y == 2);

  // v2u_min
  v2u_t vec_min = v2u_min(veca, vecb);
  ALWAYS_ASSERT(vec_min.x == 3);
  ALWAYS_ASSERT(vec_min.y == 4);

  // v2u_max
  v2u_t vec_max = v2u_max(veca, vecb);
  ALWAYS_ASSERT(vec_max.x == 5);
  ALWAYS_ASSERT(vec_max.y == 5);
}

void test_v2f() {
  // v2f
  v2f_t veca = v2f(3.5f, 4.5f);
  ALWAYS_ASSERT(approxf(veca.x, 3.5f));
  ALWAYS_ASSERT(approxf(veca.y, 4.5f));

  // v2ff
  v2f_t vecb = v2ff(5.0f);
  ALWAYS_ASSERT(approxf(vecb.x, 5.0f));
  ALWAYS_ASSERT(approxf(vecb.y, 5.0f));

  // v2f_add
  v2f_t vec_sum = v2f_add(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_sum.x, 8.5f));
  ALWAYS_ASSERT(approxf(vec_sum.y, 9.5f));

  // v2f_sub
  v2f_t vec_diff = v2f_sub(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_diff.x, -1.5f));
  ALWAYS_ASSERT(approxf(vec_diff.y, -0.5f));

  // v2f_mul
  v2f_t vec_prod = v2f_mul(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_prod.x, 17.5f));
  ALWAYS_ASSERT(approxf(vec_prod.y, 22.5f));

  // v2f_div
  v2f_t vec_div = v2f_div(veca, v2f(1.0f, 2.0f));
  ALWAYS_ASSERT(approxf(vec_div.x, 3.5f));
  ALWAYS_ASSERT(approxf(vec_div.y, 2.25f));

  // v2f_min
  v2f_t vec_min = v2f_min(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_min.x, 3.5f));
  ALWAYS_ASSERT(approxf(vec_min.y, 4.5f));

  // v2f_max
  v2f_t vec_max = v2f_max(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_max.x, 5.0f));
  ALWAYS_ASSERT(approxf(vec_max.y, 5.0f));

  // v2f_sqrt
  v2f_t vec_sqrt = v2f_sqrt(v2f(4.0f, 9.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.x, 2.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.y, 3.0f));

  // v2f_poww
  v2f_t vec_poww = v2f_poww(veca, 2.0f);
  ALWAYS_ASSERT(approxf(vec_poww.x, 12.25f));
  ALWAYS_ASSERT(approxf(vec_poww.y, 20.25f));

  // v2f_pow
  v2f_t vec_pow = v2f_pow(veca, v2f(2.0f, 3.0f));
  ALWAYS_ASSERT(approxf(vec_pow.x, 12.25f));
  ALWAYS_ASSERT(approxf(vec_pow.y, 91.125f));

  // v2f_exp
  v2f_t vec_exp = v2f_exp(v2f(1.0f, 2.0f));
  ALWAYS_ASSERT(approxf(vec_exp.x, expf(1.0f)));
  ALWAYS_ASSERT(approxf(vec_exp.y, expf(2.0f)));

  // v2f_sin
  v2f_t vec_sin = v2f_sin(v2f(0.0f, M_PI / 2.0f));
  ALWAYS_ASSERT(approxf(vec_sin.x, sinf(0.0f)));
  ALWAYS_ASSERT(approxf(vec_sin.y, sinf(M_PI / 2.0f)));

  // v2f_cos
  v2f_t vec_cos = v2f_cos(v2f(0.0f, M_PI));
  ALWAYS_ASSERT(approxf(vec_cos.x, cosf(0.0f)));
  ALWAYS_ASSERT(approxf(vec_cos.y, cosf(M_PI)));

  // v2f_tan
  v2f_t vec_tan = v2f_tan(v2f(0.0f, M_PI / 4.0f));
  ALWAYS_ASSERT(approxf(vec_tan.x, tanf(0.0f)));
  ALWAYS_ASSERT(approxf(vec_tan.y, tanf(M_PI / 4.0f)));

  // v2f_len
  float vec_len = v2f_len(v2f(3.0f, 4.0f));
  ALWAYS_ASSERT(approxf(vec_len, 5.0f));
}

void test_v2d() {
  // v2d
  v2d_t veca = v2d(3.5, 4.5);
  ALWAYS_ASSERT(approxd(veca.x, 3.5));
  ALWAYS_ASSERT(approxd(veca.y, 4.5));

  // v2dd
  v2d_t vecb = v2dd(5.0);
  ALWAYS_ASSERT(approxd(vecb.x, 5.0));
  ALWAYS_ASSERT(approxd(vecb.y, 5.0));

  // v2d_add
  v2d_t vec_sum = v2d_add(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_sum.x, 8.5));
  ALWAYS_ASSERT(approxd(vec_sum.y, 9.5));

  // v2d_sub
  v2d_t vec_diff = v2d_sub(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_diff.x, -1.5));
  ALWAYS_ASSERT(approxd(vec_diff.y, -0.5));

  // v2d_mul
  v2d_t vec_prod = v2d_mul(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_prod.x, 17.5));
  ALWAYS_ASSERT(approxd(vec_prod.y, 22.5));

  // v2d_div
  v2d_t vec_div = v2d_div(veca, v2d(1.0, 2.0));
  ALWAYS_ASSERT(approxd(vec_div.x, 3.5));
  ALWAYS_ASSERT(approxd(vec_div.y, 2.25));

  // v2d_min
  v2d_t vec_min = v2d_min(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_min.x, 3.5));
  ALWAYS_ASSERT(approxd(vec_min.y, 4.5));

  // v2d_max
  v2d_t vec_max = v2d_max(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_max.x, 5.0));
  ALWAYS_ASSERT(approxd(vec_max.y, 5.0));

  // v2d_sqrt
  v2d_t vec_sqrt = v2d_sqrt(v2d(4.0, 9.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.x, 2.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.y, 3.0));

  // v2d_poww
  v2d_t vec_poww = v2d_poww(veca, 2.0);
  ALWAYS_ASSERT(approxd(vec_poww.x, 12.25));
  ALWAYS_ASSERT(approxd(vec_poww.y, 20.25));

  // v2d_pow
  v2d_t vec_pow = v2d_pow(veca, v2d(2.0, 3.0));
  ALWAYS_ASSERT(approxd(vec_pow.x, 12.25));
  ALWAYS_ASSERT(approxd(vec_pow.y, 91.125));

  // v2d_exp
  v2d_t vec_exp = v2d_exp(v2d(1.0, 2.0));
  ALWAYS_ASSERT(approxd(vec_exp.x, exp(1.0)));
  ALWAYS_ASSERT(approxd(vec_exp.y, exp(2.0)));

  // v2d_sin
  v2d_t vec_sin = v2d_sin(v2d(0.0, M_PI / 2.0));
  ALWAYS_ASSERT(approxd(vec_sin.x, sin(0.0)));
  ALWAYS_ASSERT(approxd(vec_sin.y, sin(M_PI / 2.0)));

  // v2d_cos
  v2d_t vec_cos = v2d_cos(v2d(0.0, M_PI));
  ALWAYS_ASSERT(approxd(vec_cos.x, cos(0.0)));
  ALWAYS_ASSERT(approxd(vec_cos.y, cos(M_PI)));

  // v2d_tan
  v2d_t vec_tan = v2d_tan(v2d(0.0, M_PI / 4.0));
  ALWAYS_ASSERT(approxd(vec_tan.x, tan(0.0)));
  ALWAYS_ASSERT(approxd(vec_tan.y, tan(M_PI / 4.0)));

  // v2d_len
  double vec_len = v2d_len(v2d(3.0, 4.0));
  ALWAYS_ASSERT(approxd(vec_len, 5.0));
}

void test_v2() {
  test_v2i();
  test_v2u();
  test_v2f();
  test_v2d();
}

void test_v3i() {
  // v3i
  v3i_t veca = v3i(3, 4, 5);
  ALWAYS_ASSERT(veca.x == 3);
  ALWAYS_ASSERT(veca.y == 4);
  ALWAYS_ASSERT(veca.z == 5);

  // v3ii
  v3i_t vecb = v3ii(7);
  ALWAYS_ASSERT(vecb.x == 7);
  ALWAYS_ASSERT(vecb.y == 7);
  ALWAYS_ASSERT(vecb.z == 7);

  // v3i_add
  v3i_t vec_sum = v3i_add(veca, vecb);
  ALWAYS_ASSERT(vec_sum.x == 10);
  ALWAYS_ASSERT(vec_sum.y == 11);
  ALWAYS_ASSERT(vec_sum.z == 12);

  // v3i_sub
  v3i_t vec_diff = v3i_sub(veca, vecb);
  ALWAYS_ASSERT(vec_diff.x == -4);
  ALWAYS_ASSERT(vec_diff.y == -3);
  ALWAYS_ASSERT(vec_diff.z == -2);

  // v3i_mul
  v3i_t vec_prod = v3i_mul(veca, vecb);
  ALWAYS_ASSERT(vec_prod.x == 21);
  ALWAYS_ASSERT(vec_prod.y == 28);
  ALWAYS_ASSERT(vec_prod.z == 35);

  // v3i_div
  v3i_t vec_div = v3i_div(veca, v3i(1, 2, 5));
  ALWAYS_ASSERT(vec_div.x == 3);
  ALWAYS_ASSERT(vec_div.y == 2);
  ALWAYS_ASSERT(vec_div.z == 1);

  // v3i_min
  v3i_t vec_min = v3i_min(veca, vecb);
  ALWAYS_ASSERT(vec_min.x == 3);
  ALWAYS_ASSERT(vec_min.y == 4);
  ALWAYS_ASSERT(vec_min.z == 5);

  // v3i_max
  v3i_t vec_max = v3i_max(veca, vecb);
  ALWAYS_ASSERT(vec_max.x == 7);
  ALWAYS_ASSERT(vec_max.y == 7);
  ALWAYS_ASSERT(vec_max.z == 7);
}

void test_v3u() {
  // v3u
  v3u_t veca = v3u(3, 4, 5);
  ALWAYS_ASSERT(veca.x == 3);
  ALWAYS_ASSERT(veca.y == 4);
  ALWAYS_ASSERT(veca.z == 5);

  // v3uu
  v3u_t vecb = v3uu(7);
  ALWAYS_ASSERT(vecb.x == 7);
  ALWAYS_ASSERT(vecb.y == 7);
  ALWAYS_ASSERT(vecb.z == 7);

  // v3u_add
  v3u_t vec_sum = v3u_add(veca, vecb);
  ALWAYS_ASSERT(vec_sum.x == 10);
  ALWAYS_ASSERT(vec_sum.y == 11);
  ALWAYS_ASSERT(vec_sum.z == 12);

  // v3u_sub
  v3u_t vec_diff = v3u_sub(veca, vecb);
  ALWAYS_ASSERT(vec_diff.x == (unsigned int)-4); // care underflow
  ALWAYS_ASSERT(vec_diff.y == (unsigned int)-3);
  ALWAYS_ASSERT(vec_diff.z == (unsigned int)-2);

  // v3u_mul
  v3u_t vec_prod = v3u_mul(veca, vecb);
  ALWAYS_ASSERT(vec_prod.x == 21);
  ALWAYS_ASSERT(vec_prod.y == 28);
  ALWAYS_ASSERT(vec_prod.z == 35);

  // v3u_div
  v3u_t vec_div = v3u_div(veca, v3u(1, 2, 5));
  ALWAYS_ASSERT(vec_div.x == 3);
  ALWAYS_ASSERT(vec_div.y == 2);
  ALWAYS_ASSERT(vec_div.z == 1);

  // v3u_min
  v3u_t vec_min = v3u_min(veca, vecb);
  ALWAYS_ASSERT(vec_min.x == 3);
  ALWAYS_ASSERT(vec_min.y == 4);
  ALWAYS_ASSERT(vec_min.z == 5);

  // v3u_max
  v3u_t vec_max = v3u_max(veca, vecb);
  ALWAYS_ASSERT(vec_max.x == 7);
  ALWAYS_ASSERT(vec_max.y == 7);
  ALWAYS_ASSERT(vec_max.z == 7);
}

void test_v3f() {
  // v3f
  v3f_t veca = v3f(3.5f, 4.5f, 5.5f);
  ALWAYS_ASSERT(approxf(veca.x, 3.5f));
  ALWAYS_ASSERT(approxf(veca.y, 4.5f));
  ALWAYS_ASSERT(approxf(veca.z, 5.5f));

  // v3ff
  v3f_t vecb = v3ff(7.0f);
  ALWAYS_ASSERT(approxf(vecb.x, 7.0f));
  ALWAYS_ASSERT(approxf(vecb.y, 7.0f));
  ALWAYS_ASSERT(approxf(vecb.z, 7.0f));

  // v3f_add
  v3f_t vec_sum = v3f_add(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_sum.x, 10.5f));
  ALWAYS_ASSERT(approxf(vec_sum.y, 11.5f));
  ALWAYS_ASSERT(approxf(vec_sum.z, 12.5f));

  // v3f_sub
  v3f_t vec_diff = v3f_sub(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_diff.x, -3.5f));
  ALWAYS_ASSERT(approxf(vec_diff.y, -2.5f));
  ALWAYS_ASSERT(approxf(vec_diff.z, -1.5f));

  // v3f_mul
  v3f_t vec_prod = v3f_mul(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_prod.x, 24.5f));
  ALWAYS_ASSERT(approxf(vec_prod.y, 31.5f));
  ALWAYS_ASSERT(approxf(vec_prod.z, 38.5f));

  // v3f_div
  v3f_t vec_div = v3f_div(veca, v3f(1.0f, 2.0f, 5.5f));
  ALWAYS_ASSERT(approxf(vec_div.x, 3.5f));
  ALWAYS_ASSERT(approxf(vec_div.y, 2.25f));
  ALWAYS_ASSERT(approxf(vec_div.z, 1.0f));

  // v3f_min
  v3f_t vec_min = v3f_min(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_min.x, 3.5f));
  ALWAYS_ASSERT(approxf(vec_min.y, 4.5f));
  ALWAYS_ASSERT(approxf(vec_min.z, 5.5f));

  // v3f_max
  v3f_t vec_max = v3fMax(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_max.x, 7.0f));
  ALWAYS_ASSERT(approxf(vec_max.y, 7.0f));
  ALWAYS_ASSERT(approxf(vec_max.z, 7.0f));

  // v3f_sqrt
  v3f_t vec_sqrt = v3f_sqrt(v3f(4.0f, 9.0f, 16.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.x, 2.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.y, 3.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.z, 4.0f));

  // v3f_poww
  v3f_t vec_poww = v3f_poww(veca, 2.0f);
  ALWAYS_ASSERT(approxf(vec_poww.x, 12.25f));
  ALWAYS_ASSERT(approxf(vec_poww.y, 20.25f));
  ALWAYS_ASSERT(approxf(vec_poww.z, 30.25f));

  // v3f_pow
  v3f_t vec_pow = v3f_pow(veca, v3f(2.0f, 2.0f, 2.0f));
  ALWAYS_ASSERT(approxf(vec_pow.x, 12.25f));
  ALWAYS_ASSERT(approxf(vec_pow.y, 20.25f));
  ALWAYS_ASSERT(approxf(vec_pow.z, 30.25f));

  // v3f_exp
  v3f_t vec_exp = v3f_exp(v3f(1.0f, 0.0f, -1.0f));
  ALWAYS_ASSERT(approxf(vec_exp.x, expf(1.0f)));
  ALWAYS_ASSERT(approxf(vec_exp.y, expf(0.0f)));
  ALWAYS_ASSERT(approxf(vec_exp.z, expf(-1.0f)));

  // v3f_sin
  v3f_t vec_sin = v3f_sin(v3f(0.0f, M_PI_2, M_PI));
  ALWAYS_ASSERT(approxf(vec_sin.x, sinf(0.0f)));
  ALWAYS_ASSERT(approxf(vec_sin.y, sinf(M_PI_2)));
  ALWAYS_ASSERT(approxf(vec_sin.z, sinf(M_PI)));

  // v3f_cos
  v3f_t vec_cos = v3f_cos(v3f(0.0f, M_PI_2, M_PI));
  ALWAYS_ASSERT(approxf(vec_cos.x, cosf(0.0f)));
  ALWAYS_ASSERT(approxf(vec_cos.y, cosf(M_PI_2)));
  ALWAYS_ASSERT(approxf(vec_cos.z, cosf(M_PI)));

  // v3f_tan
  v3f_t vec_tan = v3f_tan(v3f(0.0f, M_PI_4, M_PI_2));
  ALWAYS_ASSERT(approxf(vec_tan.x, tanf(0.0f)));
  ALWAYS_ASSERT(approxf(vec_tan.y, tanf(M_PI_4)));
  ALWAYS_ASSERT(approxf(vec_tan.z, tanf(M_PI_2))); // to infinity and beyond

  // v3f_len
  float length = v3f_len(v3f(3.0f, 4.0f, 12.0f));
  ALWAYS_ASSERT(approxf(length, 13.0f));
}

void test_v3d() {
  // v3d
  v3d_t veca = v3d(3.5, 4.5, 5.5);
  ALWAYS_ASSERT(approxd(veca.x, 3.5));
  ALWAYS_ASSERT(approxd(veca.y, 4.5));
  ALWAYS_ASSERT(approxd(veca.z, 5.5));

  // v3dd
  v3d_t vecb = v3dd(7.0);
  ALWAYS_ASSERT(approxd(vecb.x, 7.0));
  ALWAYS_ASSERT(approxd(vecb.y, 7.0));
  ALWAYS_ASSERT(approxd(vecb.z, 7.0));

  // v3d_add
  v3d_t vec_sum = v3d_add(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_sum.x, 10.5));
  ALWAYS_ASSERT(approxd(vec_sum.y, 11.5));
  ALWAYS_ASSERT(approxd(vec_sum.z, 12.5));

  // v3d_sub
  v3d_t vec_diff = v3d_sub(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_diff.x, -3.5));
  ALWAYS_ASSERT(approxd(vec_diff.y, -2.5));
  ALWAYS_ASSERT(approxd(vec_diff.z, -1.5));

  // v3d_mul
  v3d_t vec_prod = v3d_mul(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_prod.x, 24.5));
  ALWAYS_ASSERT(approxd(vec_prod.y, 31.5));
  ALWAYS_ASSERT(approxd(vec_prod.z, 38.5));

  // v3d_div
  v3d_t vec_div = v3d_div(veca, v3d(1.0, 2.0, 5.5));
  ALWAYS_ASSERT(approxd(vec_div.x, 3.5));
  ALWAYS_ASSERT(approxd(vec_div.y, 2.25));
  ALWAYS_ASSERT(approxd(vec_div.z, 1.0));

  // v3d_min
  v3d_t vec_min = v3d_min(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_min.x, 3.5));
  ALWAYS_ASSERT(approxd(vec_min.y, 4.5));
  ALWAYS_ASSERT(approxd(vec_min.z, 5.5));

  // v3d_max
  v3d_t vec_max = v3d_max(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_max.x, 7.0));
  ALWAYS_ASSERT(approxd(vec_max.y, 7.0));
  ALWAYS_ASSERT(approxd(vec_max.z, 7.0));

  // v3d_sqrt
  v3d_t vec_sqrt = v3d_sqrt(v3d(4.0, 9.0, 16.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.x, 2.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.y, 3.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.z, 4.0));

  // v3d_poww
  v3d_t vec_poww = v3d_poww(veca, 2.0);
  ALWAYS_ASSERT(approxd(vec_poww.x, 12.25));
  ALWAYS_ASSERT(approxd(vec_poww.y, 20.25));
  ALWAYS_ASSERT(approxd(vec_poww.z, 30.25));

  // v3d_pow
  v3d_t vec_pow = v3d_pow(veca, v3d(2.0, 2.0, 2.0));
  ALWAYS_ASSERT(approxd(vec_pow.x, 12.25));
  ALWAYS_ASSERT(approxd(vec_pow.y, 20.25));
  ALWAYS_ASSERT(approxd(vec_pow.z, 30.25));

  // v3d_exp
  v3d_t vec_exp = v3d_exp(v3d(1.0, 0.0, -1.0));
  ALWAYS_ASSERT(approxd(vec_exp.x, exp(1.0)));
  ALWAYS_ASSERT(approxd(vec_exp.y, exp(0.0)));
  ALWAYS_ASSERT(approxd(vec_exp.z, exp(-1.0)));

  // v3d_sin
  v3d_t vec_sin = v3d_sin(v3d(0.0, M_PI_2, M_PI));
  ALWAYS_ASSERT(approxd(vec_sin.x, sin(0.0)));
  ALWAYS_ASSERT(approxd(vec_sin.y, sin(M_PI_2)));
  ALWAYS_ASSERT(approxd(vec_sin.z, sin(M_PI)));

  // v3d_cos
  v3d_t vec_cos = v3d_cos(v3d(0.0, M_PI_2, M_PI));
  ALWAYS_ASSERT(approxd(vec_cos.x, cos(0.0)));
  ALWAYS_ASSERT(approxd(vec_cos.y, cos(M_PI_2)));
  ALWAYS_ASSERT(approxd(vec_cos.z, cos(M_PI)));

  // v3d_tan
  v3d_t vec_tan = v3d_tan(v3d(0.0, M_PI_4, M_PI_2));
  ALWAYS_ASSERT(approxd(vec_tan.x, tan(0.0)));
  ALWAYS_ASSERT(approxd(vec_tan.y, tan(M_PI_4)));
  // M_PI_2 tends to infinity, omit it

  // v3d_len
  double length = v3d_len(v3d(3.0, 4.0, 12.0));
  ALWAYS_ASSERT(approxd(length, 13.0));
}

void test_v3() {
  test_v3i();
  test_v3u();
  test_v3f();
  test_v3d();
}

void test_v4i() {
  // v4i
  v4i_t veca = v4i(3, 4, 5, 6);
  ALWAYS_ASSERT(veca.x == 3);
  ALWAYS_ASSERT(veca.y == 4);
  ALWAYS_ASSERT(veca.z == 5);
  ALWAYS_ASSERT(veca.w == 6);

  // v4ii
  v4i_t vecb = v4ii(7);
  ALWAYS_ASSERT(vecb.x == 7);
  ALWAYS_ASSERT(vecb.y == 7);
  ALWAYS_ASSERT(vecb.z == 7);
  ALWAYS_ASSERT(vecb.w == 7);

  // v4i_add
  v4i_t vec_sum = v4i_add(veca, vecb);
  ALWAYS_ASSERT(vec_sum.x == 10);
  ALWAYS_ASSERT(vec_sum.y == 11);
  ALWAYS_ASSERT(vec_sum.z == 12);
  ALWAYS_ASSERT(vec_sum.w == 13);

  // v4i_sub
  v4i_t vec_diff = v4i_sub(veca, vecb);
  ALWAYS_ASSERT(vec_diff.x == -4);
  ALWAYS_ASSERT(vec_diff.y == -3);
  ALWAYS_ASSERT(vec_diff.z == -2);
  ALWAYS_ASSERT(vec_diff.w == -1);

  // v4i_mul
  v4i_t vec_prod = v4i_mul(veca, vecb);
  ALWAYS_ASSERT(vec_prod.x == 21);
  ALWAYS_ASSERT(vec_prod.y == 28);
  ALWAYS_ASSERT(vec_prod.z == 35);
  ALWAYS_ASSERT(vec_prod.w == 42);

  // v4i_div
  v4i_t vec_div = v4i_div(veca, v4i(1, 2, 5, 6));
  ALWAYS_ASSERT(vec_div.x == 3);
  ALWAYS_ASSERT(vec_div.y == 2);
  ALWAYS_ASSERT(vec_div.z == 1);
  ALWAYS_ASSERT(vec_div.w == 1);

  // v4i_min
  v4i_t vec_min = v4i_min(veca, vecb);
  ALWAYS_ASSERT(vec_min.x == 3);
  ALWAYS_ASSERT(vec_min.y == 4);
  ALWAYS_ASSERT(vec_min.z == 5);
  ALWAYS_ASSERT(vec_min.w == 6);

  // v4i_max
  v4i_t vec_max = v4i_max(veca, vecb);
  ALWAYS_ASSERT(vec_max.x == 7);
  ALWAYS_ASSERT(vec_max.y == 7);
  ALWAYS_ASSERT(vec_max.z == 7);
  ALWAYS_ASSERT(vec_max.w == 7);
}

void test_v4u() {
  // v4u
  v4u_t veca = v4u(3, 4, 5, 6);
  ALWAYS_ASSERT(veca.x == 3);
  ALWAYS_ASSERT(veca.y == 4);
  ALWAYS_ASSERT(veca.z == 5);
  ALWAYS_ASSERT(veca.w == 6);

  // v4uu
  v4u_t vecb = v4uu(7);
  ALWAYS_ASSERT(vecb.x == 7);
  ALWAYS_ASSERT(vecb.y == 7);
  ALWAYS_ASSERT(vecb.z == 7);
  ALWAYS_ASSERT(vecb.w == 7);

  // v4u_add
  v4u_t vec_sum = v4u_add(veca, vecb);
  ALWAYS_ASSERT(vec_sum.x == 10);
  ALWAYS_ASSERT(vec_sum.y == 11);
  ALWAYS_ASSERT(vec_sum.z == 12);
  ALWAYS_ASSERT(vec_sum.w == 13);

  // v4u_sub
  v4u_t vec_diff = v4u_sub(vecb, veca);
  ALWAYS_ASSERT(vec_diff.x == 4);
  ALWAYS_ASSERT(vec_diff.y == 3);
  ALWAYS_ASSERT(vec_diff.z == 2);
  ALWAYS_ASSERT(vec_diff.w == 1);

  // v4u_mul
  v4u_t vec_prod = v4u_mul(veca, vecb);
  ALWAYS_ASSERT(vec_prod.x == 21);
  ALWAYS_ASSERT(vec_prod.y == 28);
  ALWAYS_ASSERT(vec_prod.z == 35);
  ALWAYS_ASSERT(vec_prod.w == 42);

  // v4u_div
  v4u_t vec_div = v4u_div(vecb, v4u(1, 2, 5, 7));
  ALWAYS_ASSERT(vec_div.x == 7);
  ALWAYS_ASSERT(vec_div.y == 3);
  ALWAYS_ASSERT(vec_div.z == 1);
  ALWAYS_ASSERT(vec_div.w == 1);

  // v4u_min
  v4u_t vec_min = v4u_min(veca, vecb);
  ALWAYS_ASSERT(vec_min.x == 3);
  ALWAYS_ASSERT(vec_min.y == 4);
  ALWAYS_ASSERT(vec_min.z == 5);
  ALWAYS_ASSERT(vec_min.w == 6);

  // v4u_max
  v4u_t vec_max = v4u_max(veca, vecb);
  ALWAYS_ASSERT(vec_max.x == 7);
  ALWAYS_ASSERT(vec_max.y == 7);
  ALWAYS_ASSERT(vec_max.z == 7);
  ALWAYS_ASSERT(vec_max.w == 7);
}

void test_v4f() {
  // v4f
  v4f_t veca = v4f(1.0f, 2.0f, 3.0f, 4.0f);
  ALWAYS_ASSERT(approxf(veca.x, 1.0f));
  ALWAYS_ASSERT(approxf(veca.y, 2.0f));
  ALWAYS_ASSERT(approxf(veca.z, 3.0f));
  ALWAYS_ASSERT(approxf(veca.w, 4.0f));

  // v4ff
  v4f_t vecb = v4ff(5.0f);
  ALWAYS_ASSERT(approxf(vecb.x, 5.0f));
  ALWAYS_ASSERT(approxf(vecb.y, 5.0f));
  ALWAYS_ASSERT(approxf(vecb.z, 5.0f));
  ALWAYS_ASSERT(approxf(vecb.w, 5.0f));

  // v4f_add
  v4f_t vec_sum = v4f_add(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_sum.x, 6.0f));
  ALWAYS_ASSERT(approxf(vec_sum.y, 7.0f));
  ALWAYS_ASSERT(approxf(vec_sum.z, 8.0f));
  ALWAYS_ASSERT(approxf(vec_sum.w, 9.0f));

  // v4f_sub
  v4f_t vec_diff = v4f_sub(vecb, veca);
  ALWAYS_ASSERT(approxf(vec_diff.x, 4.0f));
  ALWAYS_ASSERT(approxf(vec_diff.y, 3.0f));
  ALWAYS_ASSERT(approxf(vec_diff.z, 2.0f));
  ALWAYS_ASSERT(approxf(vec_diff.w, 1.0f));

  // v4f_mul
  v4f_t vec_prod = v4f_mul(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_prod.x, 5.0f));
  ALWAYS_ASSERT(approxf(vec_prod.y, 10.0f));
  ALWAYS_ASSERT(approxf(vec_prod.z, 15.0f));
  ALWAYS_ASSERT(approxf(vec_prod.w, 20.0f));

  // v4f_div
  v4f_t vec_div = v4f_div(vecb, v4f(1.0f, 2.0f, 5.0f, 4.0f));
  ALWAYS_ASSERT(approxf(vec_div.x, 5.0f));
  ALWAYS_ASSERT(approxf(vec_div.y, 2.5f));
  ALWAYS_ASSERT(approxf(vec_div.z, 1.0f));
  ALWAYS_ASSERT(approxf(vec_div.w, 1.25f));

  // v4f_min
  v4f_t vec_min = v4f_min(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_min.x, 1.0f));
  ALWAYS_ASSERT(approxf(vec_min.y, 2.0f));
  ALWAYS_ASSERT(approxf(vec_min.z, 3.0f));
  ALWAYS_ASSERT(approxf(vec_min.w, 4.0f));

  // v4f_max
  v4f_t vec_max = v4f_max(veca, vecb);
  ALWAYS_ASSERT(approxf(vec_max.x, 5.0f));
  ALWAYS_ASSERT(approxf(vec_max.y, 5.0f));
  ALWAYS_ASSERT(approxf(vec_max.z, 5.0f));
  ALWAYS_ASSERT(approxf(vec_max.w, 5.0f));

  // v4f_sqrt
  v4f_t vec_sqrt = v4f_sqrt(v4f(16.0f, 9.0f, 4.0f, 1.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.x, 4.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.y, 3.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.z, 2.0f));
  ALWAYS_ASSERT(approxf(vec_sqrt.w, 1.0f));

  // v4f_poww
  v4f_t vec_poww = v4f_poww(veca, 2.0f);
  ALWAYS_ASSERT(approxf(vec_poww.x, 1.0f));
  ALWAYS_ASSERT(approxf(vec_poww.y, 4.0f));
  ALWAYS_ASSERT(approxf(vec_poww.z, 9.0f));
  ALWAYS_ASSERT(approxf(vec_poww.w, 16.0f));

  // v4f_pow
  v4f_t vec_pow = v4f_pow(veca, v4f(2.0f, 2.0f, 2.0f, 2.0f));
  ALWAYS_ASSERT(approxf(vec_pow.x, 1.0f));
  ALWAYS_ASSERT(approxf(vec_pow.y, 4.0f));
  ALWAYS_ASSERT(approxf(vec_pow.z, 9.0f));
  ALWAYS_ASSERT(approxf(vec_pow.w, 16.0f));

  // v4f_exp
  v4f_t vec_exp = v4f_exp(v4f(0.0f, 1.0f, 2.0f, 3.0f));
  ALWAYS_ASSERT(approxf(vec_exp.x, 1.0f));
  ALWAYS_ASSERT(approxf(vec_exp.y, 2.7182818f));
  ALWAYS_ASSERT(approxf(vec_exp.z, 7.3890561f));
  ALWAYS_ASSERT(approxf(vec_exp.w, 20.085537f));

  // v4f_sin
  v4f_t vec_sin = v4f_sin(v4f(0.0f, M_PI_2, M_PI, 3 * M_PI_2));
  ALWAYS_ASSERT(approxf(vec_sin.x, 0.0f));
  ALWAYS_ASSERT(approxf(vec_sin.y, 1.0f));
  ALWAYS_ASSERT(approxf(vec_sin.z, 0.0f));
  ALWAYS_ASSERT(approxf(vec_sin.w, -1.0f));

  // v4f_cos
  v4f_t vec_cos = v4f_cos(v4f(0.0f, M_PI_2, M_PI, 3 * M_PI_2));
  ALWAYS_ASSERT(approxf(vec_cos.x, 1.0f));
  ALWAYS_ASSERT(approxf(vec_cos.y, 0.0f));
  ALWAYS_ASSERT(approxf(vec_cos.z, -1.0f));
  ALWAYS_ASSERT(approxf(vec_cos.w, 0.0f));

  // v4f_tan
  v4f_t vec_tan = v4f_tan(v4f(0.0f, M_PI_4, M_PI, 3 * M_PI_4));
  ALWAYS_ASSERT(approxf(vec_tan.x, 0.0f));
  ALWAYS_ASSERT(approxf(vec_tan.y, 1.0f));
  ALWAYS_ASSERT(approxf(vec_tan.z, 0.0f));
  ALWAYS_ASSERT(approxf(vec_tan.w, -1.0f));

  // v4f_len
  float vec_len = v4f_len(v4f(1.0f, 1.0f, 1.0f, 1.0f));
  ALWAYS_ASSERT(approxf(vec_len, 2.0f));
}

void test_v4d() {
  // v4d
  v4d_t veca = v4d(1.0, 2.0, 3.0, 4.0);
  ALWAYS_ASSERT(approxd(veca.x, 1.0));
  ALWAYS_ASSERT(approxd(veca.y, 2.0));
  ALWAYS_ASSERT(approxd(veca.z, 3.0));
  ALWAYS_ASSERT(approxd(veca.w, 4.0));

  // v4dd
  v4d_t vecb = v4dd(5.0);
  ALWAYS_ASSERT(approxd(vecb.x, 5.0));
  ALWAYS_ASSERT(approxd(vecb.y, 5.0));
  ALWAYS_ASSERT(approxd(vecb.z, 5.0));
  ALWAYS_ASSERT(approxd(vecb.w, 5.0));

  // v4d_add
  v4d_t vec_sum = v4d_add(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_sum.x, 6.0));
  ALWAYS_ASSERT(approxd(vec_sum.y, 7.0));
  ALWAYS_ASSERT(approxd(vec_sum.z, 8.0));
  ALWAYS_ASSERT(approxd(vec_sum.w, 9.0));

  // v4d_sub
  v4d_t vec_diff = v4d_sub(vecb, veca);
  ALWAYS_ASSERT(approxd(vec_diff.x, 4.0));
  ALWAYS_ASSERT(approxd(vec_diff.y, 3.0));
  ALWAYS_ASSERT(approxd(vec_diff.z, 2.0));
  ALWAYS_ASSERT(approxd(vec_diff.w, 1.0));

  // v4d_mul
  v4d_t vec_prod = v4d_mul(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_prod.x, 5.0));
  ALWAYS_ASSERT(approxd(vec_prod.y, 10.0));
  ALWAYS_ASSERT(approxd(vec_prod.z, 15.0));
  ALWAYS_ASSERT(approxd(vec_prod.w, 20.0));

  // v4d_div
  v4d_t vec_div = v4d_div(vecb, v4d(1.0, 2.0, 5.0, 4.0));
  ALWAYS_ASSERT(approxd(vec_div.x, 5.0));
  ALWAYS_ASSERT(approxd(vec_div.y, 2.5));
  ALWAYS_ASSERT(approxd(vec_div.z, 1.0));
  ALWAYS_ASSERT(approxd(vec_div.w, 1.25));

  // v4d_min
  v4d_t vec_min = v4d_min(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_min.x, 1.0));
  ALWAYS_ASSERT(approxd(vec_min.y, 2.0));
  ALWAYS_ASSERT(approxd(vec_min.z, 3.0));
  ALWAYS_ASSERT(approxd(vec_min.w, 4.0));

  // v4d_max
  v4d_t vec_max = v4d_max(veca, vecb);
  ALWAYS_ASSERT(approxd(vec_max.x, 5.0));
  ALWAYS_ASSERT(approxd(vec_max.y, 5.0));
  ALWAYS_ASSERT(approxd(vec_max.z, 5.0));
  ALWAYS_ASSERT(approxd(vec_max.w, 5.0));

  // v4d_sqrt
  v4d_t vec_sqrt = v4d_sqrt(v4d(16.0, 9.0, 4.0, 1.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.x, 4.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.y, 3.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.z, 2.0));
  ALWAYS_ASSERT(approxd(vec_sqrt.w, 1.0));

  // v4d_poww
  v4d_t vec_poww = v4d_poww(veca, 2.0);
  ALWAYS_ASSERT(approxd(vec_poww.x, 1.0));
  ALWAYS_ASSERT(approxd(vec_poww.y, 4.0));
  ALWAYS_ASSERT(approxd(vec_poww.z, 9.0));
  ALWAYS_ASSERT(approxd(vec_poww.w, 16.0));

  // v4d_pow
  v4d_t vec_pow = v4d_pow(veca, v4d(2.0, 2.0, 2.0, 2.0));
  ALWAYS_ASSERT(approxd(vec_pow.x, 1.0));
  ALWAYS_ASSERT(approxd(vec_pow.y, 4.0));
  ALWAYS_ASSERT(approxd(vec_pow.z, 9.0));
  ALWAYS_ASSERT(approxd(vec_pow.w, 16.0));

  // v4d_exp
  v4d_t vec_exp = v4d_exp(v4d(0.0, 1.0, 2.0, 3.0));
  ALWAYS_ASSERT(approxd(vec_exp.x, exp(0.0)));
  ALWAYS_ASSERT(approxd(vec_exp.y, exp(1.0)));
  ALWAYS_ASSERT(approxd(vec_exp.z, exp(2.0)));
  ALWAYS_ASSERT(approxd(vec_exp.w, exp(3.0)));

  // v4d_sin
  v4d_t vec_sin = v4d_sin(v4d(0.0, M_PI_2, M_PI, 3 * M_PI_2));
  ALWAYS_ASSERT(approxd(vec_sin.x, 0.0));
  ALWAYS_ASSERT(approxd(vec_sin.y, 1.0));
  ALWAYS_ASSERT(approxd(vec_sin.z, 0.0));
  ALWAYS_ASSERT(approxd(vec_sin.w, -1.0));

  // v4d_cos
  v4d_t vec_cos = v4d_cos(v4d(0.0, M_PI_2, M_PI, 3 * M_PI_2));
  ALWAYS_ASSERT(approxd(vec_cos.x, 1.0));
  ALWAYS_ASSERT(approxd(vec_cos.y, 0.0));
  ALWAYS_ASSERT(approxd(vec_cos.z, -1.0));
  ALWAYS_ASSERT(approxd(vec_cos.w, 0.0));

  // v4d_tan
  v4d_t vec_tan = v4d_tan(v4d(0.0, M_PI_4, M_PI, 3 * M_PI_4));
  ALWAYS_ASSERT(approxd(vec_tan.x, 0.0));
  ALWAYS_ASSERT(approxd(vec_tan.y, 1.0));
  ALWAYS_ASSERT(approxd(vec_tan.z, 0.0));
  ALWAYS_ASSERT(approxd(vec_tan.w, -1.0));

  // v4d_len
  double vec_len = v4d_len(v4d(1.0, 1.0, 1.0, 1.0));
  ALWAYS_ASSERT(approxd(vec_len, 2.0));
}

void test_v4() {
  test_v4i();
  test_v4u();
  test_v4f();
  test_v4d();
}

int main(void) {
  printf("Running tests...\n");

  test_v2();
  test_v3();
  test_v4();

  printf("All tests passing...\n");

  return 0;
}
