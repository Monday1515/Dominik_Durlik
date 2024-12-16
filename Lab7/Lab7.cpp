#include <iostream>
#include <vector>
#include <string>

class User {
private:
    std::string name;
    std::string email;

public:
    User(const std::string& name, const std::string& email)
        : name(name), email(email) {}

    const std::string& getName() const {
        return name;
    }

    const std::string& getEmail() const {
        return email;
    }

    void display() const {
        std::cout << "Name: " << name << ", Email: " << email << "\n";
    }
};

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const std::string& name, const std::string& email) {
        users.emplace_back(name, email);
    }

    void displayAllUsers() const {
        if (users.empty()) {
            std::cout << "No users available.\n";
            return;
        }

        for (const auto& user : users) {
            user.display();
        }
    }

    const std::vector<User>& getUsers() const {
        return users;
    }
};

class UserSaver {
public:
    void saveUsersToFile(const std::vector<User>& users, const std::string& filename) {
        std::cout << "Saving users to file: " << filename << "\n";
        for (const auto& user : users) {
            std::cout << "Saving: " << user.getName() << ", " << user.getEmail() << "\n";
        }
    }
};

class Discount {
protected:
    double discounted_price = (double)0;
public:
    virtual double calculateDiscount(double base_price) = 0;
    virtual void display() {
        std::cout << "Discounted price: " << discounted_price << std::endl;
    }
    virtual ~Discount() {}
};

class RegularDiscount : public Discount {
protected:
    double base_price;
public:
    virtual double calculateDiscount(double base_price = (double)0) override {
        if (base_price != (double)0) {
            this->base_price = base_price;
        }
        discounted_price = this->base_price * (double)0.9;
        return base_price * (double)0.9;
    }
    RegularDiscount(double base_price) : base_price(base_price) { calculateDiscount(); }
    ~RegularDiscount() {}
};

class SeasonalDiscount : public Discount {
protected:
    double base_price;
public:
    virtual double calculateDiscount(double base_price = (double)0) override {
        if (base_price != (double)0) {
            this->base_price = base_price;
        }
        discounted_price = this->base_price * (double)0.8;
        return base_price * (double)0.8;
    }
    SeasonalDiscount(double base_price) : base_price(base_price) { calculateDiscount(); }
    ~SeasonalDiscount() {}
};

int main() {
    UserManager userManager;

    userManager.addUser("Alice", "alice@example.com");
    userManager.addUser("Bob", "bob@example.com");

    std::cout << "All users:\n";
    userManager.displayAllUsers();

    UserSaver userSaver;
    userSaver.saveUsersToFile(userManager.getUsers(), "users.txt");

    RegularDiscount regular((double)12);
    regular.display();
    SeasonalDiscount seasonal((double)12);
    seasonal.display();

    return 0;
}