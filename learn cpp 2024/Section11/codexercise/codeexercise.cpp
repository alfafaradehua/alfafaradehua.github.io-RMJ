#include <iostream>
#include <cmath>
using namespace std;
double fahrenheit_to_celsius(double fahrenheit_temperature);
double fahrenheit_to_kelvin(double fahrenheit_temperature);

int main()
{
    cout << fahrenheit_to_celsius(1.0) << endl;
    cout << fahrenheit_to_kelvin(1.0) << endl;
}
double fahrenheit_to_celsius(double fahrenheit_temperature)
{
    cout << "Function input is" << endl;
    cout << fahrenheit_temperature << endl;
    double celsius_temperature{0.0};
    //(5.0/9.0)*(temperature - 32)
    celsius_temperature = (5.0 / 9.0) * (fahrenheit_temperature - 32);
    return round(celsius_temperature);
}
double fahrenheit_to_kelvin(double fahrenheit_temperature)
{
    cout << "Function input is" << endl;
    cout << fahrenheit_temperature << endl;
    double kelvin_temperature{0.0};
    //(5.0/9.0)*(temperature - 32) + 273
    kelvin_temperature = (5.0 / 9.0) * (fahrenheit_temperature - 32) + 273;
    return round(kelvin_temperature);
}