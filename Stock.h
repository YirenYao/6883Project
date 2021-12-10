#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;
namespace fre {
	class Stock
	{
	private:
		string symbol, name;
		string date, period_end;
		vector<double> earning; // {estimate, reported, surprise, surprise%}

		string startingdate, endingdate;
		vector<string> price_date;
		vector<double> price_val;

	public:
		Stock(string symbol_, string name_, string date_, string period_end_, vector<double> earning_): 
			symbol(symbol_), name(name_), date(date_), period_end(period_end_ ), earning(earning_)
		{
			startingdate = "";
			endingdate = "";
			price_date = {};
			price_val = {};
		}
		Stock()
		{
			symbol = "";
			name = "";
			date = "";
			period_end = "";
			earning = {};
			startingdate = "";
			endingdate = "";
			price_date = {};
			price_val = {};
		}
		Stock(const Stock& stock)
		{
			symbol = stock.symbol;
			name = stock.name;
			date = stock.date;
			period_end = stock.period_end;
			earning = stock.earning;
			startingdate = stock.startingdate;
			endingdate = stock.endingdate;
			price_date = stock.price_date;
			price_val = stock.price_val;
		}
		void updatePrice(vector<string> price_date_, vector<double> price_val_)
		{
			price_date = price_date_;
			price_val = price_val_;
			startingdate = price_date_.front();
			endingdate = price_date_.back();
		}

		string getName()const { return name; }
		string getSymbol()const { return symbol; }
		string getAnnounceDate()const { return date; }
		string getPeriodEnd()const { return period_end; }
		
		vector<string> getPriceDate()const { return price_date; }
		vector<double> getPriceVal()const { return price_val; }
		string getStartingDate()const { return startingdate; }
		string getEndingDate()const { return endingdate; }

		vector<double> calAR(const Stock& benchmark) const;
		vector<double> calCR() const;

		
	};

}
