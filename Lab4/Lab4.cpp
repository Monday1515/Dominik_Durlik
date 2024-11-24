#include <iostream>
#include <string>

class Person {
private: 
	std::string name;
	std::string surname;
	int			age;
	std::string email;
	std::string phone_number;

public:
	Person() : name(""), surname(""), age(0), email(""), phone_number("") {}
	Person(
		std::string name,
		std::string surname,
		int age = 0,
		std::string email = "",
		std::string phone_number = ""
	) : 
		name(name), 
		surname(surname),
		age(age),
		email(email),
		phone_number(phone_number)
	{}

	~Person() {}

	std::string getName()		 const { return name; }
	std::string getSurname()	 const { return surname; }
	int			getAge()		 const { return age; }
	std::string getEmail()		 const { return email; }
	std::string getPhoneNumber() const { return phone_number; }

	void setName(std::string name)		 { this->name = name; }
	void setSurname(std::string surname) { this->surname = surname; }
	void setAge(int age)				 { this->age = age; }

	void setEmail(std::string email) {
		if (email.find("@") == std::string::npos) {
			std::cout << "Email does not meet criteria. Setting as \"\"\n";
			this->email = "";
			return;
		}
		this->email = email;
	}

	void setPhoneNumber(std::string phone_number) {
		if (phone_number.length() != 9) {
			std::cout << "Phone number does not meet criteria. Setting as \"\"\n";
			this->phone_number = "";
			return;
		}
		this->phone_number = phone_number;
	}
};

class Worker {
protected:
	std::string position;
	double		salary;

public:
	Worker() : position(""), salary(0) {}
	Worker(
		std::string position,
		int salary
	) : 
		position(position), 
		salary(salary) 
	{}

	~Worker() {}
};

class Teacher : public Worker {
public:
	Teacher() : Worker("", 0) {}
	Teacher(
		std::string position,
		int			salary
	) : 
		Worker(
			position, 
			salary
		) 
	{}

	~Teacher() {}
};

class Administration : public Worker {
public:
	Administration() : Worker("", 0) {}
	Administration(
		std::string position,
		int			salary
	) :
		Worker(
			position,
			salary
		)
	{}

	~Administration() {}
};

int main() {

}