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

	double thr1 = 6.0;
	double thr2 = 24.0;
	readBasic(BeatStocks, MeetStocks, MissStocks, thr1, thr2);
	cout << BeatStocks.size() << ' ' << MeetStocks.size() << ' ' << MissStocks.size() << endl;

	int N;
	/*
	read in N
	*/
	vector<string> date_range = readDate(N);
	readPrice(benchmark, date_range[0], date_range[1]);

	readPrice(BeatStocks, N, &benchmark);
	readPrice(MeetStocks, N, &benchmark);
	readPrice(MissStocks, N, &benchmark);
	cout << BeatStocks.size() << ' ' << MeetStocks.size() << ' ' << MissStocks.size() << endl;

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