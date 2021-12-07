#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Stock.h"
#include "Group.h"
#include "DataReader.h"
#include "Display.h"

using namespace std;
using namespace fre;

int main()
{
	map<string, Stock> BeatStocks, MeetStocks, MissStocks;
	Stock benchmark("IWB", "IWB", "", "", {});
	double thr1, thr2;
	/*
	find threshold thr1, thr2
	*/
	readBasic(BeatStocks, MeetStocks, MissStocks, thr1, thr2);
	
	int N;
	string from_date, to_date;
	/*
	read in N
	find from_date and to_date
	*/
	readPrice(BeatStocks, N);
	readPrice(MeetStocks, N);
	readPrice(MissStocks, N);
	readPrice(benchmark, from_date, to_date);

	Group BeatGroup(&BeatStocks);
	Group MeetGroup(&MeetStocks);
	Group MissGroup(&MissStocks);
	BeatGroup.calByBootstrap();
	MeetGroup.calByBootstrap();
	MeetGroup.calByBootstrap();

	/*
	implement menu
	and respond by command
	*/
	return 0;
}