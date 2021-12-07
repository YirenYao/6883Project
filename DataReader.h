#pragma once
#include <map>
#include "curl/curl.h"
#include "Stock.h"

using namespace std;

namespace fre {
	void readBasic(
		map<string, Stock>& BeatStocks,
		map<string, Stock>& MeetStocks,
		map<string, Stock>& MissStocks,
		double thr1, double thr2);

	void readPrice(map<string, Stock>& stocks, int N);

	void readPrice(Stock stock, string from, string to);

}