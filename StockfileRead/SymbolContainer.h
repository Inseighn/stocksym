#pragma once
#include "StockSymbol.h"

class SymbolContainer {
public:
	void add(std::string, std::string, std::string);
	bool contains(std::string);
	std::string tostr();

	template<typename Func>
	StockSymbol find(Func);

private:
	std::vector<StockSymbol> _symbols;


};