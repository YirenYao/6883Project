#pragma once
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include "Stock.h"

using namespace std;

namespace fre {
	typedef vector<vector<double>> matrix;

	class Group
	{
	private:
		map<string, Stock>* stocks;
		vector<double> AAR, AAR_STD, CAAR, CAAR_STD;
	public:
		Group(map<string, Stock>* stocks_): stocks(stocks_)
		{
			srand((unsigned)time(NULL));
		}

		vector<double> getAAR()const { return AAR; }
		vector<double> getAAR_STD()const { return AAR_STD; }
		vector<double> getCAAR()const { return CAAR; }
		vector<double> getCAAR_STD()const { return CAAR_STD; }

		void calByBootstrap();
	};
}
