#include "Person.h"

namespace haba {
	Person::Person(std::string n, std::string p, std::string e, int a, std::string l)
		:name_(n), phone_(p), email_(e), age_(a), lang_(l) { }
}