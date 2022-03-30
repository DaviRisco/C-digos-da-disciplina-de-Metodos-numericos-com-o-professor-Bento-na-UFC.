#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void gauss_jordan(float **a, float *b, int n);

int main() {
  float **c, *v;
  int n;

  printf("Digite o tamanho da matriz: ");
  scanf("%d", &n);

  v = (float*)malloc(n*sizeof(float));
  c = (float**)malloc(n*sizeof(float*));
  for(int i = 0; i < n; i++){
    c[i] = (float*)malloc(n*sizeof(float));
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("Digite o elemento m[%d][%d]: ", i+1, j+1);
      scanf("%f", &c[i][j]); 
    }
  }

  for(int i = 0; i < n; i++){
    printf("Digite v[%d]: ", i+1);
    scanf("%f", &v[i]);
  }

  gauss_jordan(c, v, n);

  free(v);
  free(c);

  return 0;
} 

void gauss_jordan(float **a, float *b, int n){

  for(int k = 0; k < n; k++){
    for(int j = k+1; j < n; j++){
      a[k][j] = a[k][j]/a[k][k];
    }
    b[k] = b[k]/a[k][k];
    a[k][k] = 1;

    for(int i = 0; i < n; i++){
      if(i != k){
        for(int j = k+1; j < n; j++){
          a[i][j] = a[i][j] - a[i][k]*a[k][j];
        }
        b[i] = b[i] - a[i][k]*b[k];
        a[i][k] = 0;
      } 
    }
  }

  printf("Matriz A: \n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%.2f\t", a[i][j]);
    }
    printf("\n");
  }

  printf("\nVetor X: [ ");
  for(int i = 0; i < n; i++){
    printf("%.2f\t", b[i]);
  }
  printf("]\n");
}