#include "roman_int.h"

RomanInt::RomanInt(std::string s)
	:rom_(s),arabicValue_(0) {
	if (!(isValid()))throw InvalidRomanInt();
}

RomanInt::RomanInt()
	:rom_("III"),arabicValue_(3){}

bool RomanInt::isValid() {
	if (rom_.size() < 1 || rom_.size() > 15)return false;
	static std::map<char,int> romansNums;
	romansNums['I'] = 1;
	romansNums['V'] = 5;
	romansNums['X'] = 10;
	romansNums['L'] = 50;
	romansNums['C'] = 100;
	romansNums['D'] = 500;
	romansNums['M'] = 1000;
	int m = 0, d = 0, c = 0, l = 0, x = 0, v = 0, ir = 0;
	for (std::size_t i = 0; i < rom_.size(); ++i) {
		rom_.at(i) = toupper(rom_.at(i));
		if(romansNums.count(rom_.at(i)) < 1)return false;
		switch (rom_.at(i)) {
		case 'M':++m; break;
		case 'D':++d; break;
		case 'C':++c; break;
		case 'L':++l; break;
		case 'X':++x; break;
		case 'V':++v; break;
		case 'I':++ir; break;
		}
		if (m > 4 || d > 1 || c > 4 || l > 1 || x > 4 || v > 1 || ir > 3) {
			return false;
		}
	}
	if (rom_.size() == 1)return true;
	int maximumValue = 10000;
	int currentValue = 0;
	for (int i = 0; i < rom_.size();) {
		int j = i;
		maximumValue = initializeMaxValue(rom_,romansNums,i,j,currentValue,maximumValue,arabicValue_);
		if (maximumValue == -1)return false;
	}
}
int initializeMaxValue
(std::string rom_,std::map<char,int> romansNums,int& in,int i,int& cur,int m,int& aV) {
	if (i + 1 < rom_.size()) {
		if (romansNums[rom_.at(i)] == romansNums[rom_.at(i + 1)]) {
			if (i + 2 < rom_.size()) {
				if (romansNums[rom_.at(i + 1)] == romansNums[rom_.at(i + 2)]) {
					if (i + 3 < rom_.size()) {
						if (romansNums[rom_.at(i + 2)] == romansNums[rom_.at(i + 3)])return -1;
					}
					in = i + 3;
					cur = romansNums[rom_.at(i)];
					aV += romansNums[rom_.at(i)] * 3;
					if (m != 10000) {
						if (cur > m)return -1;
					}
					return romansNums[rom_.at(i)] - 1;
				}
			}
			in = i + 2;
			cur = romansNums[rom_.at(i)];
			aV += romansNums[rom_.at(i)] * 2;
			if (m != 10000) {
				if (cur > m)return -1;
			}
			return romansNums[rom_.at(i)] - 1;
		}
		if (romansNums[rom_.at(i)] < romansNums[rom_.at(i + 1)]) {
			char c = rom_.at(i + 1);
			char b = rom_.at(i);
			aV += romansNums[c] - romansNums[b];
			if (b == 'I'&& (c == 'X'|| c == 'V')) {
				in = i + 2;
				cur = romansNums[c]- romansNums[b];
				if (m != 10000) {
					if (cur > m)return -1;
				}
				return romansNums[rom_.at(i)] - 1;
			}
			if (b == 'X'&& (c == 'C' || c == 'L')) {
				in = i + 2;
				cur = romansNums[c] - romansNums[b];
				if (m != 10000) {
					if (cur > m)return -1;
				}
				return romansNums[rom_.at(i)] - 1;
			}
			if (b == 'C'&& (c == 'M' || c == 'D')) {
				in = i + 2;
				cur = romansNums[c] - romansNums[b];
				if (m != 10000) {
					if (cur > m)return -1;
				}
				return romansNums[rom_.at(i)] - 1;
			}
			return -1;
		}
		in = i + 1;
		aV += romansNums[rom_.at(i)];
		cur = romansNums[rom_.at(i)];
		if (m != 10000) {
			if (cur > m)return -1;
		}
		return romansNums[rom_.at(i)] - 1;
	}
	in = i + 1;
	cur = romansNums[rom_.at(i)];
	aV += romansNums[rom_.at(i)];
	if (m != 10000) {
		if (cur > m)return -1;
	}
	return romansNums[rom_.at(i)] - 1;
}

std::ostream& operator<<(std::ostream& os, RomanInt r) {
	return os << r.rom();
}

std::istream& operator>>(std::istream& is, RomanInt& r) {
	std::string s;
	is >> s;
	if (!is) return is;
	r = RomanInt(s);
	return is;
}