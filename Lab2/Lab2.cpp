#include<iostream>

class Samoch�d
{
private:
    std::string marka;
    std::string model;
    int rokProdukcji;

public:
    Samoch�d(std::string marka, std::string model, int rokProdukcji)
    {
        this->marka = marka;
        this->model = model;
        this->rokProdukcji = rokProdukcji;
    }
    Samoch�d()
    {
        this->marka = "unknown";
        this->model = "unknown";
        this->rokProdukcji = 0;
    }
    ~Samoch�d()
    {
        std::cout << "Destroy " << marka << " " << model << std::endl;
    }
};


class Tablica {
private:
    int* arr;
    int size;

public:
    Tablica() {
        this->size = 10;
        this->arr = new int[size];
        std::cout << "Default construct" << std::endl;
    }

    Tablica(int s) {
        this->size = s;
        this->arr = new int[size];
        std::cout << "Parram construct" << std::endl;
    }

    ~Tablica() {
        delete[] arr;
        std::cout << "Destroy table" << std::endl;
    }

};


int main()
{
    Samoch�d();
    Samoch�d("A", "B", 2024);
    Tablica();
    Tablica(5);
}