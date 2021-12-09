#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;
namespace fre {
	class Stock
	{
	private:
		string symbol, name; // 
		string date, period_end;
		vector<double> earning; // {estimate, reported, surprise, surprise%}
		map<string, double> price;

	public:
		Stock(string symbol_, string name_, string date_, string period_end_, vector<double> earning_): 
			symbol(symbol_), name(name_), date(date_), period_end(period_end_ ), earning(earning_)
		{
			price = {};
		};
		void updatePrice(map<string, double> price_)
		{
			price = price_;
		}

		string getName()const { return name; }
		string getSymbol()const { return symbol; }
		string getAnnounceDate()const { return date; }
		string getPeriodEnd()const { return period_end; }
		map<string, double> getPrice()const { return price; }

		vector<double> calAR(const Stock& benchmark) const;
		vector<double> calCR() const;

		
	};

}
