#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include "Stock.h"
#include "Group.h"
#include "Matrix.h"
using namespace std;

namespace fre {
    typedef vector<vector<double>> Matrix;

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
    
    // BOOTSTRAP
    void Group::calByBootstrap(const Stock &benchmark, int simuNum)
    {
        int idx = 0;
        Matrix ARmat(simuNum);
        Matrix CARmat(simuNum);
        map<string, Stock> ::iterator itr = (*stocks).begin();
        int plen = (int)itr -> second.getPriceVal().size() - 1; // get price lenth 2N
        
        // Initialization for matrix
        for (int i = 0; i < simuNum; i++)
        {
            ARmat[i].resize(plen);
            CARmat[i].resize(plen);
        }
        // bootstrap for AR and CAR matrix (~, 2N)
        for (int i = 0; i < simuNum; i++)
        {
            idx = rand() % simuNum; //random idx
            advance(itr, idx);
            ARmat[i] = itr -> second.calAR(benchmark, N);
            CARmat[i] = itr -> second.calCR(benchmark, N);
            itr = (*stocks).begin();
        }
        
        AAR = matrixMean(ARmat);
        AAR_STD = matrixStd(ARmat);
        CAAR = matrixMean(CARmat);
        CAAR_STD = matrixStd(CARmat);
    }
    
}
