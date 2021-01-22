#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

class RomanInt {
public:
	class InvalidRomanInt{};

	RomanInt(std::string);
	RomanInt();

	bool isValid();
	int arabicValue() { return arabicValue_; }
	std::string rom() { return rom_; }
private:
	std::string rom_;
	int arabicValue_;
};

int initializeMaxValue(std::string,std::map<char,int>,int&,int,int&,int,int&);
std::ostream& operator<<(std::ostream&, RomanInt);
std::istream& operator>>(std::istream&, RomanInt&);