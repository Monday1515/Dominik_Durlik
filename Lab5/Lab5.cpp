#include <iostream>

class Vehicle {
private:
	int year;

protected:
	std::string brand;
	std::string model;

public:
	virtual void accelerate() {}
	virtual void stop() {}
};

class Car : public Vehicle {
public:
	virtual void accelerate() override {
		std::cout << "Car" << std::endl;
	}
};

class Bike : public Vehicle {
public:
	virtual void accelerate() override {
		std::cout << "Bike" << std::endl;
	}
};

class Car5 : protected Vehicle {
public:
	std::string getBrand() {
		return brand;
	}
	std::string getModel() {
		return model;
	}
};

class Bike5 : protected Vehicle {
public:
	std::string getBrand() {
		return brand;
	}
	std::string getModel() {
		return model;
	}
};

class Car6 : private Vehicle {
	//year not accesible as is a private variable
}; 

class Bike6: private Vehicle{
	//year not accesible as is a private variable
};

class Combustion : protected Vehicle {
public:
	virtual void accelerate() override {}
};

class Electric : protected Vehicle {
public:
	virtual void charge() {}
};

class Hybrid : public Combustion, public Electric {
};

class Electric9 : protected Car {
public:
	virtual void accelerate() override {}
};
int main() {
	return 0;
}