#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <locale>
#include <iomanip>
#include <fstream>
#include "curl/curl.h"
#include "Stock.h"
#include "DataReader.h"

using namespace std;

namespace fre {
	void readBasic(
		map<string, Stock>& BeatStocks,
		map<string, Stock>& MeetStocks,
		map<string, Stock>& MissStocks,
		double thr1, double thr2)
	{
		// read csv file of symbol and earning
		// initiate Stock object 
		// compare earning superise% with thr and add to corresponding map
	}

	void readPrice(map<string, Stock>& stocks, int N)
	{
		// iterate over input map; retrieve -N:N price and update Stock object
	}
	void readPrice(Stock stock, string from, string to)
	{
		// retrieve benchmark(IWB) price within given range, and update Stock object
	}
}