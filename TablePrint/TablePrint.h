#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

inline void printTableBot(char ch, std::vector<std::string> s, char ch2, int maxw) {
	std::cout << '\n';
	for (size_t i = 0; i < s.size(); ++i) {
		int width = maxw / 2;
		if (i == 0)std::cout << std::left << std::setw(width) << std::setfill('_') << ch;
		else       std::cout << std::left << std::setw(width) << std::setfill('_') << "";
		std::cout << std::right << std::setw(width) << std::setfill('_') << ch2;
	}
}

inline void printTableBotEmpty(char ch, std::vector<std::string> s, char ch2, int maxw) {
	std::cout << '\n';
	for (size_t i = 0; i < s.size(); ++i) {
		int width = maxw / 2;
		if (i == 0)std::cout << std::left << std::setw(width) << std::setfill(' ') << ch;
		else       std::cout << std::left << std::setw(width) << std::setfill(' ') << "";
		std::cout << std::right << std::setw(width) << std::setfill(' ') << ch2;
	}
}

inline void printTableContents(char ch, std::vector<std::string> s, char ch2, int maxw) {
	for (size_t i = 0; i < s.size(); ++i) {
		int max = maxw - s[i].size();
		bool even = false;
		if (s[i].size() % 2 == 0)even = true;
		int widthL, widthR;
		if (even) {
			widthL = max / 2;
			widthR = widthL;
		}
		else {
			widthL = max / 2;
			widthR = widthL;
			widthL++;
		}
		if (i == 0)std::cout << std::left << std::setw(widthL) << ch;
		else       std::cout << std::left << std::setw(widthL) << "";
		std::cout << s[i];
		std::cout << std::right << std::setw(widthR) << ch2;
	}
}

inline void printColumn(char ch, std::string s, char ch2, int maxw, bool isLeft) {
	bool even = false;
	if (s.size() % 2 == 0)even = true;
	int max = maxw - s.size();
	int widthL, widthR;
	if (even) {
		widthL = max / 2;
		widthR = widthL;
	}
	else {
		widthL = max / 2;
		widthR = widthL;
		widthL++;
	}
	if (isLeft)std::cout << std::left << std::setw(widthL) << ch;
	else       std::cout << std::left << std::setw(widthL) << "";
	std::cout << s;
	std::cout << std::right << std::setw(widthR) << ch2;
}

inline void printTableHead(char ch, std::vector<std::string> s, char ch2, int maxw) {
	int topWidth = maxw * s.size();
	for (int i = 0; i < topWidth; ++i)std::cout << '_';
	printTableBotEmpty(ch, s, ch2, maxw);
	std::cout << '\n';
	printTableContents(ch, s, ch2, maxw);
	printTableBot(ch, s, ch2, maxw);
}