#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void horner(const vector<double>& coefficients, double x) {
    int n = coefficients.size() - 1;
    double polynomialValue = coefficients[0];
    double derivativeValue = 0.0;

    for (int i = 1; i <= n; i++) {
        derivativeValue = derivativeValue * x + polynomialValue;
        polynomialValue = polynomialValue * x + coefficients[i];
    }

    cout << fixed << setprecision(6);
    cout << "Value of the polynomial at x = " << x << " is: " << polynomialValue << endl;
    cout << "Value of the derivative at x = " << x << " is: " << derivativeValue << endl;
}

int main() {
    int degree;
    double x;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coefficients(degree + 1);
    cout << "Enter the coefficients of the polynomial (from highest degree to constant term):\n";
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of x^" << degree - i << ": ";
        cin >> coefficients[i];
    }

    cout << "Enter the value of x: ";
    cin >> x;
    horner(coefficients, x);
    return 0;
}

