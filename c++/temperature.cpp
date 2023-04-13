#include <iostream>

class Temperature {

    public:
        Temperature();
        void set_C(double i);
        void set_K(double i);
        void set_F(double i);
        double get_C();
        double get_K();
        double get_F();

    private:
        double temp_kelv;

};

Temperature::Temperature () {
    temp_kelv = 0.0;
}

void Temperature::set_C(double i) {

    if (i < (-273.15)) {
        temp_kelv = 0.0;
        throw std::invalid_argument( "The passed temperature is below absolute zero");
    }

    temp_kelv = i + 273.15;
}

void Temperature::set_K(double i) {

    if (i < 0) {
        temp_kelv = 0.0;
        throw std::invalid_argument( "The passed temperature is below absolute zero");
    }

    temp_kelv = i;
}

void Temperature::set_F(double i) {

    if (i < (-459.67)) {
        temp_kelv = 0.0;
        throw std::invalid_argument( "The passed temperature is below absolute zero");
    }

    double celc{ (i - 32) * (5.0/9)};
    temp_kelv = celc + 273.15;
}

double Temperature::get_C() {
    return temp_kelv - 273.15;
}
double Temperature::get_K() {
    return temp_kelv;
}
double Temperature::get_F() {
    double celc{ temp_kelv - 273.15};
    return ((celc*(9.0/5.0)) + 32);
}