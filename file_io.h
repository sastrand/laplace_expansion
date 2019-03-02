#include <stdio.h>

// Get file size
//
int matrix_size(char* fpath) {
  FILE *fp = fopen(fpath, "r");
  int ret=0, tmp=0;
  while (fscanf(fp, "%d", &tmp) == 1) 
    ret++;
  return ret;
}

// Create N x N matrix of values from 0 to m
//
int** random_mat(int n, int m) {
  // set default m = 8192
  printf("starting random mat init\n");
  int** ret = (int**) malloc(n * sizeof(int*));
  for (int i=0; i<n; i++) {
    ret[i] = (int*) malloc(n * sizeof(int)); 
  }
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++) {
      ret[i][j] = rand()%m;
    }
  }
  return ret;
}

// Read N x N matrix from a file
//
int** read_matrix(char* fpath, int n){
  FILE *fp = fopen(fpath, "r");
  int** ret = (int**) malloc(n * sizeof(int*));
  for (int i=0; i<n; i++) {
    ret[i] = (int*) malloc(n * sizeof(int)); 
  }
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++) {
      fscanf(fp, "%d", &ret[i][j]);
    }
  }
  fclose(fp);
  return ret;
}

// Write N x N matrix to a file
//
void write_matrix(char* fpath, int** mat, int n) {
  FILE *fp = fopen(fpath, "w");
  printf("starting write to file\n");
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      fprintf(fp, "%d ", mat[i][j]);  
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}

