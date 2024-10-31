#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MVLA_IMPLEMENTATION
#include "include/mvla.h"
#undef MVLA_IMPLEMENTATION


int main(int argc, char *argv[]){
  Mat a = matt(10);
  matFillRand(&a);
  Mat b = mat(a.rows, a.cols);
    
  matCopyData(&b, &a);

  printMat(a);
  printf("\n");
  printMat(b);
  
  freeMat(&a);
  freeMat(&b);
  return 0;
}
