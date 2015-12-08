#include <iostream>
#include <fstream>
#include "SymbolContainer.h"

std::vector<std::string> split_str(std::string source, std::string delimiter);

int main(int arc, char* arv) 
{
	std::string filename;
	/*
	This sets up our program to read our stocksymbol file.. the correct format for the file is as follows:
		SYM $PRICE TIME(24HR)
		eg. "GOG $10 1240"
		each transaction should be seperated by a newline >> \n
	*/
	if (arc == 2) {
		filename = arv[1];
	}
	else {
		std::cout << "What file do you want to read from?" << std::endl;
		std::cin >> filename;
	}
	std::ifstream stockFile;
	//opens our file with read priv only
	stockFile.open(filename.c_str(), std::ios::in);
	std::string line;
	SymbolContainer sc;
	std::cin.clear();
	int i = 0;
	if (stockFile.is_open()) {
		//read file line by line
		while (getline(stockFile, line)) {
			//tokenize each line, seperating by a single space
			std::vector<std::string> sym_parts = split_str(line, " ");
			//add line to our collection, our add function handles all the other work., erase first character of the 2nd parameter to ensure "$50" would convert to "50.0"
			sc.add(sym_parts[0], sym_parts[1].erase(0,1), sym_parts[2]);
		}
	}
	//closes our file and prints the collection
	stockFile.close();
	std::cout << sc.tostr();
	std::cin.get();
	return 0;
}

//tokenizes the string
//c++ offers a way to do this, but the uses are trivial so we just made our own function. could probably use some more error checking, but it gets the job done.
std::vector<std::string> split_str(std::string source, std::string delimiter) {
	std::vector<std::string> split;
	std::size_t pos;
	//if our delimiter is found, push it to our vector then reset the source string to the end of the delimiter
	while ((pos = source.find(delimiter)) != std::string::npos) {
		std::string token = source.substr(0, pos);
		split.push_back(token);
		source = source.substr(pos + delimiter.size());
	}
	//push whatever is left of the source into the vector
	split.push_back(source);
	return split;
}