#include "SymbolContainer.h"

void SymbolContainer::add(std::string sym, std::string amt, std::string time)
{
	//if our container does not contain the symbol, we are going to add it and push our initial data to it
	if (!contains(sym)) {
		StockSymbol newSym(sym);
		newSym.add_transaction(std::stod(amt), time);
		_symbols.push_back(newSym);
	}
	//if the container contains the symbol, use that instead and just push a new transaction into it
	else {
		StockSymbol fSym = find([&](StockSymbol s) {return s.get_symbol() == sym; });
		fSym.add_transaction(std::stod(amt), time);
	}

}
//Checks to see if the symbol exists using a lambda expression to compare symbal string against the symbol in our StockSymbol object
bool SymbolContainer::contains(std::string sym)
{
	return find([&](StockSymbol cmp) {return sym == cmp.get_symbol(); }) != StockSymbol::NullSym();
}
std::string SymbolContainer::tostr()
{
	std::string r;
	for (auto it = _symbols.begin(); it != _symbols.end(); ++it) {
		r += ((*it).get_symbol() + "=" + std::to_string((*it).sum()) + "\n");
	}
	return r;
}
//Generic search through our symbol objects, allows for ANY lambda expression to be used for comparison , returns the first instance of the object that satifies the expression
template <typename Func>
StockSymbol SymbolContainer::find(Func func) {
	for (auto it = _symbols.begin(); it != _symbols.end(); ++it) {
		if (func(*it)) {
			return (*it);
		}
	}
	return StockSymbol::NullSym();
}
