#include <iostream>

class Pizza {
private:
    std::string dough, sauce, topping;

    Pizza(const std::string dough, const std::string sauce, const std::string topping) : dough(dough), sauce(sauce), topping(topping) {}

public:
    class Builder {
    private:
        std::string dough, sauce, topping;

    public:
        Builder& setDough(std::string d) {
            dough = d;
            return *this;
        }

        Builder& setSauce(std::string s) {
            sauce = s;
            return *this;
        }

        Builder& setTopping(std::string t) {
            topping = t;
            return *this;
        }

        Pizza build() {
            return Pizza(dough, sauce, topping);
        }
    };


    void display() const {
		std::cout << "Pizza: \n\tDough: " << dough << ",\n\tSauce: " << sauce << ",\n\tTopping: " << topping << std::endl;
    }
};

int main() {
    Pizza pizza = Pizza::Builder().setDough("standard").setSauce("tomato").setTopping("cheese").build();
    pizza.display();
    return 0;
}