#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <regex>
#include <stdlib.h>
#include "TablePrint.h"
#include "Person.h"

void askName(std::string& n) {
	std::getline(std::cin, n);
	while (true) {
		std::cout << "Enter Name: ";
		std::getline(std::cin, n);
		if (n.size() > 29) {
			std::cout << "Name will not fit\n";
			continue;
		}
		break;
	}
}

void askPhone(std::string& p) {
	while (true) {
		std::cout << "Enter phone number: ";
		std::cin >> p;
		if (p.size() != 11) {
			std::cout << "Invalid length of phone number\n";
			continue;
		}
		if (p[0] != '0'&&p[1] != '9') {
			std::cout << "Invalid start of phone number\n";
			continue;
		}
		break;
	}
}

void askEmail(std::string& e) {
	while (true) {
		std::cout << "Enter email address: ";
		std::cin >> e;
		static std::regex reg("^[\\w]{1,16}[\@][a-z]{2,8}[.][a-z]{1,4}$");
		static std::smatch match;
		bool isValid = std::regex_search(e, match, reg);
		if (isValid) {
			break;
		}
		else {
			std::cout << "Invalid email address\n";
		}
	}
}

void askAge(int& a) {
	while (true) {
		std::cout << "Enter age: ";
		std::cin >> a;
		if (a < 1 || a>99) {
			std::cout << "Invalid Age\n";
			continue;
		}
		break;
	}
}

void askLanguages(std::string& l) {
	std::getline(std::cin, l);
	while (true) {
		std::cout << "Enter languages: ";
		std::getline(std::cin, l);
		if (l.size() > 29) {
			std::cout << "Input will not fit\n";
			continue;
		}
		break;
	}
}

void printPersonColumn(int i,const haba::Person& p) {
	switch (i) {
	case 0:
		printColumn('|',p.name(), '|', 30, true);
		break;
	case 1:
		printColumn('|',p.phone(), '|', 30, false);
		break;
	case 2:
		printColumn('|', p.email(), '|', 30, false);
		break;
	case 3:
		printColumn('|', std::to_string(p.age()), '|', 30, false);
		break;
	case 4:
		printColumn('|', p.lang() , '|', 30, false);
	default:
		break;
	}
}

void ui() {
	std::cout << std::setw(95) << "Personal Informations Console App" << '\n'
		<< std::setw(99) << "By: Mark Joefrey Jan Willard M. Laurente\n";
	std::vector<haba::Person> persons;
	persons.push_back(haba::Person("Mark", "09162295606", "mark@gmail.com", 18, "C++,Java"));
	while (true)
	{
		std::cout << "[1]Print Persons\n[2]Add Person\n[3]Clear Screen\n[4]Exit\n\n";
		std::string cmd;
		std::cout << "Command: ";
		std::cin >> cmd;
		switch (cmd[0]) {
		case '1': {
			std::vector<std::string> heads{ "Names","Telephone Numbers","Email","Ages","Programming Language" };
			printTableHead('|', heads, '|', 30);
			printTableBotEmpty('|', heads, '|', 30);
			std::cout << '\n';
			for (size_t i = 0; i < persons.size(); ++i) {
				for (size_t j = 0; j < 5; ++j) {
					printPersonColumn(j,persons[i]);
				}
				if(i+1==persons.size())printTableBot('|', heads, '|', 30);
				else printTableBotEmpty('|', heads, '|', 30);
				std::cout << '\n';
			}
			std::cout << "\n\n";
			break;
		}
		case '2':{
			std::string name, phone, email, lang;
			int age;
			askName(name);
			askPhone(phone);
			askEmail(email);
			askAge(age);
			askLanguages(lang);
			haba::Person p(name, phone, email, age, lang);
			persons.push_back(p);
			 break;
		}
		case '3':
			system("CLS");
			break;
		case '4':
			break;
		default:
			std::cout << "Invalid Command\n\n";
		}
		if (cmd[0] == '4')break;
	}
}

int main() {
	try {
		ui();
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	return 0;
}