#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MVLA_IMPLEMENTATION
#include "include/mvla.h"



int main(int argc, char *argv[]){
  Mat a = matt(10);
  matFillRand(&a);
  Mat b = matClone(a);

  printMat(a);
  printf("\n");
  printMat(b);
  return 0;
}
