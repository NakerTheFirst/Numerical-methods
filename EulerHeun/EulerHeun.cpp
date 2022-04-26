#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl;

#define f(x, y) pow(y, 2);

// dy/dx = -y^2 = f(x, y)
// x in range <-1; 1>
// x0 = -1
// y0 = 2

double euler(double x0, double y0, double xn);

int main() {

    euler(-1, 1, 0);

    return 0;
}

double euler(double x0, double y0, double xn) {

    double h, yn, slope;
    int n;

    cin >> n;

    // Calculate step size
    h = (xn-x0)/n;

    for(int i = 0; i < n; ++i) {
        slope = f(x0, y0);
        yn = y0 = h * slope;
        y0 = yn;
        x0 = x0 + h;
    }

    cout << "Value of y at x = " << xn << " is " << yn << endl;

}