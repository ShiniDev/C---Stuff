#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "roman_int.h"
#include "FCoutput.h"

void error(std::string);//Declaration of error function, see definition below main()
void keep_window_open();

//Global Constants
const char c_Eof = 'E';
const char c_Print = '=';
const char c_Exit = ';';
const char c_Num = 'd';
const char c_From = 'F';
const char c_To = 'T';
const int c_Default = 0;
//Global Variable
std::ofstream ofs;
ofc::OutputCF ofcout(ofs, std::cout, std::cin);

class R_Int {//A class for storing values or arithmetic expressions
public:
	R_Int(){}
	R_Int(int v)
		:val_(v),ch_(c_Num){}
	R_Int(char c)
		:val_(c_Default), ch_(c) {}
	char ch() { return ch_; }
	int val() { return val_; }
private:
	int val_;
	char ch_;
};

class R_Stream {//A class for managing R_Int classes
public:
	R_Stream()
		:buffer(R_Int(c_Default)),isFull_(false){}
	R_Int get();
	R_Int get(std::istream&);
	void unget(R_Int);
	void clear() { buffer = R_Int(c_Default); isFull_ = false; }
private:
	R_Int buffer;
	bool isFull_;
};

void R_Stream::unget(R_Int r) { //A function for putting a R_Int to the R_Stream
	if (isFull_)error("unget() on full stream");
	buffer = r;
	isFull_ = true;
}

R_Int R_Stream::get() {
	if (isFull_) {//Checks if the R_Stream is full
		isFull_ = false;
		return buffer;
	}
	char ch;
	ofcout >> ch;
	switch (ch) {
	case c_Print:
	case c_Exit:
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
		return R_Int(ch);
	case 'm':case 'd':case 'c':case 'l':case 'x':case 'v':case 'i':
	case 'M':case 'D':case 'C':case 'L':case 'X':case 'V':case 'I': {
		std::string exp = "";
		ofcout.is.unget();
		while (true) {
			char c;
			ofcout >> c;
			if (c == 'M' || c == 'D' || c == 'C' || c == 'L' || c == 'X' || c == 'V' || c == 'I') {
				exp += c;
			}
			else if (c == 'm' || c == 'd' || c == 'c' || c == 'l' || c == 'x' || c == 'v' || c == 'i') {
				exp += c;
			}
			else {
				ofcout.is.unget();
				break;
			}
		}
		RomanInt r(exp);
		return R_Int(r.arabicValue());
	}
	default:
		ofcout.is.unget();
		std::string command;
		ofcout >> command;
		if (command == "from") return R_Int(c_From);
		else if (command == "to") return R_Int(c_To);
		else error("Invalid Input");
	}
}

R_Stream rs;

double firstPrio();
double secondPrio();
double thirdPrio();
//For reading in expression from file
double firstPrio(std::istream&);
double secondPrio(std::istream&);
double thirdPrio(std::istream&);

double firstPrio() {
	R_Int r = rs.get();
	switch (r.ch()) {
	case c_Num:
		return r.val();
	case '(': {
		double d = thirdPrio();
		r = rs.get();
		if (r.ch() != ')')error(") not found");
		return d;
	}
	default:
		error("Invalid start of expression");
	}
}

double secondPrio() {
	double d = firstPrio();
	R_Int r = rs.get();
	while (true) {
		switch (r.ch()) {
		case '*':
			d *= firstPrio();
			r = rs.get();
			break;
		case '/':
			d /= firstPrio();
			r = rs.get();
			break;
		default:
			rs.unget(r);
			return d;
		}
	}
}

double thirdPrio() {
	double d = secondPrio();
	R_Int r = rs.get();
	while (true) {
		switch (r.ch()) {
		case '+':
			d += secondPrio();
			r = rs.get();
			break;
		case '-':
			d -= secondPrio();
			r = rs.get();
			break;
		default:
			rs.unget(r);
			return d;
		}
	}
}

double fromFile() {
	std::string s;
	ofcout >> s;
	std::ifstream is;
	is.open(s.c_str(), std::ios_base::in);
	if (is.bad())error("Unexisting file");
	else if (is.eof())error("Debug 1");
	else if (is.fail())error("Debug 2");
	double d = thirdPrio(is);
	is.close();
	return d;
}

void ui() {
	ofcout << "Roman Numeral Calculator!\n";
	ofcout << "Available operators: +, -, *, /, ()\n";
	ofcout << "Available commands: = to print, ; to quit\n";
	ofcout << "from (text file name), to (text file name)\n";
	double d = 0;
	while (true) {
		ofcout << "> ";
		R_Int r = rs.get();
		if (r.ch() == c_Exit)break;
		else if (r.ch() == c_From) {
			std::string res = std::to_string(fromFile());
			ofcout << "< " << res << "\n";
			rs.clear();
			continue;
		}
		else if (r.ch() == c_To) {
			std::string s;
			ofcout >> s;
			ofs.open(s.c_str(), std::ios_base::out);
		}
		else {
			rs.unget(r);
			d = thirdPrio();
			r = rs.get();
			if (r.ch() == c_Print)ofcout << "< " << d << '\n';
			else rs.unget(r);
		}
	}
}

int main() {
	try {
		ui();
		keep_window_open();
	}
	catch (std::exception& e) {
		ofcout << "Error: " << e.what() << "\n";
		keep_window_open();
		return -1;
	}
	catch (RomanInt::InvalidRomanInt& e) {
		ofcout << "Invalid Roman Expression!\n";
		keep_window_open();
		return -1;
	}
	return 0;
}

//Some functions overload are defined below, for cleaner code purposes

void error(std::string s) {
	throw std::runtime_error(s);
}

void keep_window_open() {
	ofcout << "Input any key to continue...";
	char ch;
	std::cin >> ch;
}

R_Int R_Stream::get(std::istream& is) {
	if (isFull_) {//Checks if the R_Stream is full
		isFull_ = false;
		return buffer;
	}
	char ch;
	is >> ch;
	if (is.eof()) {
		is.clear(std::ios_base::eofbit);
		return R_Int(c_Eof);
	}
	switch (ch) {
	case c_Print:
	case c_Exit:
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
		return R_Int(ch);
	case 'm':case 'd':case 'c':case 'l':case 'x':case 'v':case 'i':
	case 'M':case 'D':case 'Cs':case 'L':case 'X':case 'V':case 'I': {
		std::string exp = "";
		is.unget();
		while (true) {
			char c;
			is >> c;
			if (is.eof())break;
			if (c == '*' || c == '-' || c == '+' || c == '/') {
				is.unget();
				break;
			}
			if (c == 'M' || c == 'D' || c == 'C' || c == 'L' || c == 'X' || c == 'V' || c == 'I') {
				exp += c;
			}
			else if (c == 'm' || c == 'd' || c == 'c' || c == 'l' || c == 'x' || c == 'v' || c == 'i') {
				exp += c;
			}
			else {
				is.unget();
				break;
			}
		}
		RomanInt r(exp);
		return R_Int(r.arabicValue());
	}
	default:
		is.unget();
		std::string command;
		is >> command;
		if (command == "from") return R_Int(c_From);
		else if (command == "to") return R_Int(c_To);
		else error("Invalid Input");
	}
}

double firstPrio(std::istream& is) {
	R_Int r = rs.get(is);
	switch (r.ch()) {
	case c_Num:
		return r.val();
	case '(': {
		double d = thirdPrio(is);
		r = rs.get(is);
		if (r.ch() != ')')error(") not found");
		return d;
	}
	default:
		return 0;
	}
}

double secondPrio(std::istream& is) {
	double d = firstPrio(is);
	R_Int r = rs.get(is);
	while (true) {
		switch (r.ch()) {
		case '*':
			d *= firstPrio(is);
			r = rs.get(is);
			break;
		case '/':
			d /= firstPrio(is);
			r = rs.get(is);
			break;
		default:
			rs.unget(r);
			return d;
		}
	}
}

double thirdPrio(std::istream& is) {
	double d = secondPrio(is);
	R_Int r = rs.get(is);
	while (true) {
		switch (r.ch()) {
		case '+':
			d += secondPrio(is);
			r = rs.get(is);
			break;
		case '-':
			d -= secondPrio(is);
			r = rs.get(is);
			break;
		default:
			rs.unget(r);
			return d;
		}
	}
}

