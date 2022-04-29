#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MVLA_IMPLEMENTATION
#include "include/mvla.h"

#define DOWN printf("\n")

struct InputLayer{
  void *prevLayer;

  Mat out;
};

struct HiddenLayer {
  void *prevLayer;

  Mat in; // 1000 x 12 or something

  Mat bias; // n_neurons x 1
  Mat weights; // n_neurons x 12

  double (*activationFunction)(Vec sample, Vec weights);

  Mat out;
};

struct OutputLayer {
  void *prevLayer;

  Mat in;
  Mat weights;
  double (*classificationFunction)(Vec sample, Vec weights);
  Mat out;
};



float **matToFloatPtrPtr(Mat a){
  return a.data;
}

float *matToFloatPtr(Mat a){
  assert(a.rows == 1);

  return a.data[0];
}

float *vecToFloatPtr(Vec a){
  return a.data;
}



struct InputLayer initInput(void *prevLayer, Mat in){
  struct InputLayer input;
  input.prevLayer = prevLayer;
  input.out = in;
  
  return input;
}

struct HiddenLayer initHidden(void *prevLayer, Mat in, Mat bias, Mat weights){
  struct HiddenLayer hidden = {0};
  hidden.prevLayer = prevLayer;
  hidden.in = in;
  hidden.bias = bias;
  hidden.weights = weights;
  hidden.out = mat(bias.rows, bias.cols);

  return hidden;
}

struct OutputLayer initOutput(void *prevLayer, Mat in, Mat bias, Mat weights){
  struct OutputLayer output;
  output.prevLayer = prevLayer;
  output.in = in;
  output.weights = weights;
  output.out = mat(weights.rows, weights.cols);

  return output;
}



int main(void){
  srand(time(NULL));

  
  struct InputLayer layerOne = initInput(NULL, mat(2000, 8));
  /*
  layerOne.out = mat(2000, 8);
  layerOne.prevLayer = NULL;
  */
  
  matFillRand(&layerOne.out);

  struct HiddenLayer layerTwo = initHidden(&layerOne, layerOne.out, mat(8, 1), mat(8, layerOne.out.cols));
  /*
  layerTwo.prevLayer = &layerOne;
  layerTwo.in = layerOne.out;
  layerTwo.bias = mat(8, 1); // 8 neurons
  layerTwo.weights = mat(8, layerTwo.in.cols); // 8 neurons, 8 features
  layerTwo.out = mat(8, 1);
  */
  
  matFillRand(&layerTwo.bias);
  matFillRand(&layerTwo.weights);

  for(int i = 0; i < layerTwo.out.rows; i++){
    Vec v1 = fPtrToVec(layerTwo.in.data[i], layerTwo.in.cols);
    Vec v2 = fPtrToVec(layerTwo.weights.data[i], layerTwo.weights.cols);
  
    layerTwo.out.data[i][0] = vecDot(v1, v2).data[0];
  }

  layerTwo.out = matAdd(layerTwo.out, layerTwo.bias);

  struct HiddenLayer layerThree = initHidden(&layerTwo, layerTwo.out, mat(4, 1), mat(4, layerTwo.out.cols));
  /*
  layerThree.prevLayer = &layerTwo;
  layerThree.in = layerTwo.out;
  layerThree.bias = mat(4, 1); // 4 neurons
  layerThree.weights = mat(4, layerThree.in.cols); // 4 neurons, layerThree.in.cols features
  layerThree.out = mat(4, 1);
  */

  matFillRand(&layerThree.bias);
  matFillRand(&layerThree.weights);

  for(int i = 0; i < layerThree.out.rows; i++){
    Vec v1 = fPtrToVec(layerThree.in.data[i], layerThree.in.cols);
    Vec v2 = fPtrToVec(layerThree.weights.data[i], layerThree.weights.cols);
  
    layerThree.out.data[i][0] = vecDot(v1, v2).data[0];
  }

  layerThree.out = matAdd(layerThree.out, layerThree.bias);

  struct OutputLayer layerFour = initOutput(&layerThree, layerThree.out, mat(4, 1), mat(4, layerThree.out.cols));

  printMat(layerOne.out);
  DOWN;
  printMat(layerTwo.out);
  DOWN;
  printMat(layerThree.out);
  
  return 0;
}
 


/*

// Neural Network Layer?
struct Layer {
  matrix in;              // Saved input to a layer
  matrix w;               // Current weights for a layer
  matrix dw;              // Current weight updates
  matrix v;               // Past weight updates (for use with momentum)
  matrix out;             // Saved output from the layer
  float (*activation)(struct Layer *layer);  // Activation the layer uses
}
*/