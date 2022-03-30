#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float newton_FL(float a3, float a2, float x0, float epsilon, int iterMax, float delta);

int main(){
  float x0, epsilon, raiz, delta;
  float a3, a2;
  float x, f_x, f_lin;

  printf("Digite o paramêtro a3: ");
  scanf("%f", &a3);
  printf("Digite o paramêtro a2: ");
  scanf("%f", &a2);
  printf("Digite delta: ");
  scanf("%f", &delta);
  

  x0 = 0.5;
  epsilon = 0.001;
  x = x0;

  f_x = a3*pow(x, 3) - 9*a2*x + 3;
  f_lin = 3*pow(x, 2) - 9;

  if(fabs(f_lin) < delta){
    printf("Não satisfaz a condição |f'(x0)| >= delta");
    return 1;
  }

  raiz = newton_FL(a3, a2, x0, epsilon, 50, delta);
  printf("raiz = %f \n", raiz);

  return 0;
}

float newton_FL(float a3, float a2, float x0, float epsilon, int iterMax, float delta){
  float x, f_x, f_lin, x1, FL, aux = 0;
  x = x0;


  f_x = a3*pow(x, 3) - 9*a2*x + 3;
  f_lin = 3*pow(x, 2) - 9;
  if(fabs(f_x) < epsilon or f_x == 0){
    return x0;
  }

  for(int k = 0; k < iterMax; k++){
    f_x = a3*pow(x, 3) - 9*a2*x + 3;
    f_lin = 3*pow(x, 2) - 9;
    if(fabs(f_lin) > delta){
      FL = f_lin;
    }else{
      f_lin = 3*pow(aux, 2) - 9;
      FL = f_lin;
    }
    x1 = x - f_x/FL;
    aux = x;
    x = x1;
    f_x = a3*pow(x, 3) - 9*a2*x + 3;
    if(fabs(f_x) <= epsilon or f_x == 0){
      return x1;
    }
  }

  printf("Número máximo de iterações atingida \n");
  return x1;
}