#pragma once
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include "Stock.h"

using namespace std;

namespace fre {
    typedef vector<vector<map<string, vector<double>>>> matrix; // row : each group, columns : 4 vectors
    typedef vector<double> Vector;
    class Group
    {
    private:
        map<string, Stock>* stocks;
        int N;
        Vector AAR, AAR_STD, CAAR, CAAR_STD;

    public:
        Group(map<string, Stock>* stocks_, int N_): stocks(stocks_), AAR(2*N_), AAR_STD(2*N_), CAAR(2*N_), CAAR_STD(2*N_), N(N_)
        {
            srand((unsigned)time(NULL));
        }

        vector<double> getAAR()const { return AAR; }
        vector<double> getAAR_STD()const { return AAR_STD; }
        vector<double> getCAAR()const { return CAAR; }
        vector<double> getCAAR_STD()const { return CAAR_STD; }

        void calByBootstrap(const Stock &benchmark, int simuNum);
    };
}
