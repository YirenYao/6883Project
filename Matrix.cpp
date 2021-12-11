
#include "Matrix.h"
#include <cmath>
#include <iostream>
using namespace std;
namespace fre {


Vector operator+(const Vector& V, const Vector& W)
{
    int d = (int)V.size();
    Vector U(d);
    for (int j = 0; j < d; j++)  U[j] = V[j] + W[j];
    return U;
}
Vector operator-(const Vector& V, const Vector& W)
{
    int d = (int)V.size();
    Vector U(d);
    for (int j = 0; j < d; j++)  U[j] = V[j] - W[j];
    return U;
}
Vector operator/(const Vector& V, const double& a)
{
    int d = (int)V.size();
    Vector U(d);
    for (int j = 0; j < d; j++)  U[j] = V[j] / a;
    return U;
}

Vector Vpower(const Vector& V, double a)
{
    int d = (int)V.size();
    Vector U(d);
    for (int j = 0; j < d; j++) U[j] = pow(V[j], a);
    return U;
}
Matrix Mpower(const Matrix& M, double a)
{
    int m = (int)M.size();
    int n = (int)M[0].size();
    Matrix U(m);
    for (int i = 0; i < m; i++) U[i].resize(n);
    for (int i = 0; i < m; i++) U[i] = Vpower(M[i], a);
    return U;
}

// funciton 1: calculate matrix mean in axis = 1
vector<double> matrixMean(const Matrix& mat)
{
    int n = (int)mat[0].size();
    int m = (int)mat.size();
    vector<double> res(n);
    for (int i = 0; i < m; i++ )
        res = res + mat[i];
    return res / m;
}

// function 2: calculate matrix std in axis = 1
vector<double> matrixStd(const Matrix& mat)
{
    return Vpower(matrixMean(Mpower(mat, 2.0)) - Vpower(matrixMean(mat), 2.0), 0.5);
}


}
