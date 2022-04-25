#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout, std::endl;

double f(double x);
double fprim(double x);
double fpprim(double x);
double newt(double x, double a, double b, double eps);
double hal(double a, double b, double eps);

int main() {

    // Set the precision scope to 6 digits
    cout << std::setprecision(6) << std::fixed;

    // X is the initial guess. Interval range is: <a, b>. Epsilon is: 10^(-6).
    cout << newt(9, 8, 10, pow(10, -6)) << endl;
    cout << hal(8, 10, pow(10, -6)) << endl;

    return 0;
}

// Declare function to solve
double f(double x) {
    return pow(x, 4) - 9*pow(x,3) - 15;
}

// First derivative
double fprim(double x) {
    return 4*pow(x, 3) - 27*pow(x, 2);
}

// Second derivative
double fpprim(double x) {
    return 12*pow(x, 2) - 54*x;
}

// Newton-Raphson method
double newt(double x, double a, double b, double eps) {

    // Abbreviate the formula
    double h = f(x) / fprim(x);

    // Check for input errors
    if (f(a) * f(b) >= 0) return 0;

    while (abs(h) >= eps) {
        h = f(x)/fprim(x);

        // Main x formula: x(i+1) = x(i) - f(x) / f'(x)
        x = x-h;
        if (x <= eps) return x;
    }
    return x;
}

// Halley's method
double hal(double a, double b, double eps) {

    // Declare, define
    double x, top, bottom;
    double x0 = (a+b) / 2;

    // Abbreviate variables
    top = 2 * f(x0) * fprim(x0);
    bottom = 2 * pow(fprim(x0), 2) - fpprim(x0) * f(x0);

    // Check for input errors
    if (a >= b) return 0;
    if (f(a)*f(b) >= 0) return 0;

    do {
        // Main formula for x
        x = x0 - (top / bottom);

        // Conditions to end the loop
        if (f(x) == 0 || f(x) <= eps) return x;
        x0 = x;
    }
    while (true);

}