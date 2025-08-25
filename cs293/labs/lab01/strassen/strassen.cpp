#include "common.h"

// Add two matrices
Matrix add(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      C[i][j] = A[i][j]+B[i][j];
    }
  }
  return C;
}

// Subtract two matrices
Matrix subtract(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      C[i][j] = A[i][j]-B[i][j];
    }
  }
  return C;
}

// Naive O(N^3) matrix multiplication
Matrix naiveMultiply(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n,0));
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      for (int k=0;k<n;k++) {
        C[i][j] += A[i][k]*B[k][j];
      }
    }
  }
  return C;
}

// Strassen's matrix multiplication, use the reference for the algorithm
Matrix strassenMultiply(const Matrix &A, const Matrix &B, int threshold) {
  int n = A.size();
  if (n<=threshold) return naiveMultiply(A, B);
  Matrix C(n, vector<int>(n));
  // TODO
  int a = n/2;
  Matrix A11(a, vector<int>(a));
  Matrix A12(a, vector<int>(a));
  Matrix A21(a, vector<int>(a));
  Matrix A22(a, vector<int>(a));
  Matrix B11(a, vector<int>(a));
  Matrix B12(a, vector<int>(a));
  Matrix B21(a, vector<int>(a));
  Matrix B22(a, vector<int>(a));
  for (int i=0;i<a;i++) {
    for (int j=0;j<a;j++) {
      A11[i][j] = A[i][j];
      A12[i][j] = A[i][a+j];
      A21[i][j] = A[i+a][j];
      A22[i][j] = A[i+a][j+a];
      B11[i][j] = B[i][j];
      B12[i][j] = B[i][a+j];
      B21[i][j] = B[i+a][j];
      B22[i][j] = B[i+a][j+a];
    }
  }
  Matrix M1 = strassenMultiply(add(A11,A22), add(B11,B22), threshold);
  Matrix M2 = strassenMultiply(add(A21,A22), B11, threshold);
  Matrix M3 = strassenMultiply(A11, subtract(B12,B22), threshold);
  Matrix M4 = strassenMultiply(A22, subtract(B21,B11), threshold);
  Matrix M5 = strassenMultiply(add(A11,A12), B22, threshold);
  Matrix M6 = strassenMultiply(subtract(A21,A11), add(B11,B12), threshold);
  Matrix M7 = strassenMultiply(subtract(A12,A22), add(B21,B22), threshold);
  for (int i=0;i<a;i++) {
    for (int j=0;j<a;j++) {
      C[i][j] = M1[i][j]+M4[i][j]-M5[i][j]+M7[i][j];
      C[i+a][j] = M2[i][j]+M4[i][j];
      C[i][j+a] = M3[i][j]+M5[i][j];
      C[i+a][j+a] = M1[i][j]-M2[i][j]+M3[i][j]+M6[i][j];
    }
  }
  return C;
}


bool equal(const Matrix &A, const Matrix &B) {
  int n = A.size();
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (A[i][j]!=B[i][j]) return false;
    }
  }
  return true; // Dummy return
}