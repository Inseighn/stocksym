#pragma once
#include <string>
#include <vector>

class StockSymbol
{
public:
	std::string get_symbol() const;

	void add_transaction(double, std::string);
	int transaction_count();
	double sum();

	friend bool operator==(const StockSymbol& lhs, const StockSymbol& rhs);
	friend bool operator!=(const StockSymbol& lhs, const StockSymbol& rhs);
	static StockSymbol NullSym() { return StockSymbol(); };

	StockSymbol(std::string symbol);
	StockSymbol();
	~StockSymbol();
	
private:
	std::string symbol;
	struct transaction {
		double amount;
		std::string time;
	};
	std::vector<transaction> transactions;
};