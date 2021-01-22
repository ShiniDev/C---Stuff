#pragma once
#include <string>

namespace haba {
	class Person {
	public:
		class InvalidPerson{};

		Person() {}
		Person(std::string, std::string, std::string, int, std::string);
		~Person() {}

		std::string name() const { return name_; }
		std::string email() const { return email_; }
		std::string phone() const { return phone_; }
		int age() const { return age_; }
		std::string lang() const { return lang_; }

	private:
		std::string name_;
		std::string email_;
		std::string phone_;
		int age_;
		std::string lang_;
	};
}
