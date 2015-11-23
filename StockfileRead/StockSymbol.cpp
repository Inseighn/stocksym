#include "StockSymbol.h"

std::string StockSymbol::get_symbol() const
{
	return StockSymbol::symbol;
}

void StockSymbol::add_transaction(double a, std::string t)
{
	transaction n = { a, t };
	StockSymbol::transactions.push_back(n);

}

int StockSymbol::transaction_count()
{
	return transactions.size();
}
//adds all values in the transaction collection
double StockSymbol::sum()
{
	double d = 0;
	for (auto it = transactions.begin(); it != transactions.end(); ++it) {
		d += (*it).amount;
	}
	return d;
}

StockSymbol::StockSymbol(std::string symbol)
{
	StockSymbol::symbol = symbol;
}
StockSymbol::StockSymbol() {
	StockSymbol::symbol = "";
}

StockSymbol::~StockSymbol()
{

}
//operator overloads, lets us compare Symbols with == and !=
bool operator==(const StockSymbol& lhs, const StockSymbol& rhs) {
	return lhs.get_symbol() == rhs.get_symbol();
}
bool operator!=(const StockSymbol& lhs, const StockSymbol& rhs) {
	return lhs.get_symbol() != rhs.get_symbol();
}