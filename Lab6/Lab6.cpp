#include <iostream>
#include <vector>

class Vehicle {
public:
	~Vehicle() {}

	virtual void accelerate() = 0;
	virtual void stop() = 0;
};

class Car : public Vehicle {
public:
	virtual void accelerate() override { 
		std::cout << "Car accelerating" << std::endl;
	}
	virtual void stop() override { 
		std::cout << "Car stopping" << std::endl;
	}
};

class Bike : public Vehicle {
public:
	virtual void accelerate() override {
		std::cout << "Bike accelerating" << std::endl;
	}
	virtual void stop() override {
		std::cout << "Bike stopping" << std::endl;
	}
};

class Motorbike : public Vehicle {
public:
	virtual void accelerate() override {
		std::cout << "Motorbike accelerating" << std::endl;
	}
	virtual void stop() override {
		std::cout << "Motorbike stopping" << std::endl;
	}
};

class Scooter : public Vehicle {
public:
	virtual void accelerate() override {
		std::cout << "Scooter accelerating" << std::endl;
	}
	virtual void stop() override {
		std::cout << "Scooter stopping" << std::endl;
	}
};

int main() {
	std::vector<Vehicle*> vector = { new Car(), new Bike(), new Motorbike(), new Scooter() };

	for (Vehicle* vehicle : vector) {
		vehicle->accelerate();
		vehicle->stop();
	}

	return 0;
}
