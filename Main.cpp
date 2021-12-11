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
	int selecNum;
	int simuNum;
	/*
	- read in N, number of stock prices = 2N + 1, N >= 60.
	- read in selecNum, how many stocks are selected for each bootstrap sample, (< number of stocks inside each group), here default should be 80.
	- read in simuNum, how many bootstrap simulation we want, can be any number, defalut should be 40.
	*/
	vector<string> date_range = readDate(N);
	readPrice(benchmark, date_range[0], date_range[1]);

	readPrice(BeatStocks, N, &benchmark);
	readPrice(MeetStocks, N, &benchmark);
	readPrice(MissStocks, N, &benchmark);
	cout << BeatStocks.size() << ' ' << MeetStocks.size() << ' ' << MissStocks.size() << endl;

	Group BeatGroup(&BeatStocks, N);
	Group MeetGroup(&MeetStocks, N);
	Group MissGroup(&MissStocks, N);
	BeatGroup.calByBootstrap(benchmark, selecNum, simuNum);
	MeetGroup.calByBootstrap(benchmark, selecNum, simuNum);
	MissGroup.calByBootstrap(benchmark, selecNum, simuNum);

	/*
	implement menu
	and respond by command
	*/
	return 0;
}
