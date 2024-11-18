#include <iostream>

class Car {
private:
    std::string make;
    std::string model;
    int year;
    int currentYear;

public:
    Car() {
        make        = "";
        model       = "";
        year        = 0;
        currentYear = 2023;
    }

    Car(
        std::string make, 
        std::string model, 
        int year, 
        int currentYear
    ) : 
        make(make), 
        model(model), 
        year(year), 
        currentYear(currentYear)
    {}

    void displayInfo() const {
        std::cout << "Make:\t" << make << "\nModel:\t" << model << "\nYear:\t" << year << std::endl << std::endl;
    }

    int getCarAge() const { return currentYear - year; }

    bool isSameCar(Car other) const {
        return (
            make        == other.make 
            && 
            model       == other.model
            &&
            year        == other.year
            &&
            currentYear == other.currentYear
            ); 
    }
};

int main() {
    Car car1("A", "A", 2010, 2024);
    Car car2("A", "A", 2010, 2024);
    Car car3("B", "B", 2005, 2024);
    
    std::cout << "Car 1" << std::endl;
    car1.displayInfo();

    std::cout << "Car 2" << std::endl;
    car2.displayInfo();

    std::cout << "Car 3" << std::endl;
    car3.displayInfo();

    if (car1.isSameCar(car2)) {
        std::cout << "Car 1 and Car 2 are the same." << std::endl;
    }
    else {
        std::cout << "Car 1 and Car 2 are different." << std::endl;
    }

    if (car1.isSameCar(car3)) {
        std::cout << "Car 1 and Car 3 are the same." << std::endl;
    }
    else {
        std::cout << "Car 1 and Car 3 are different." << std::endl;
    }

    return 0;
}