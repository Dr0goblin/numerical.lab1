#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double g(double x) {
    return exp(-x);
}

double f(double x) {
    return exp(-x) - x;
}

void fixed_point_iteration(double initial_guess, double tolerance, int maxIterations) {
    double x = initial_guess;
    double x_next;
    int iterations = 0;

    cout << fixed << setprecision(6);

    while (iterations < maxIterations) {
        x_next = g(x); 

        if (fabs(x_next - x) < tolerance) {
            cout << "Estimated root: " << x_next << endl;
            cout << "Functional value at root: " << f(x_next) << endl;
            cout << "Number of iterations: " << iterations + 1 << endl;
            return;
        }

        x = x_next; 
        iterations++;
    }

    cout << "Fixed Point Iteration did not converge within the maximum number of iterations.\n";
}

int main() {
    double initial_guess, tolerance;
    int maxIterations;

    cout << "Enter the initial guess: ";
    cin >> initial_guess;

    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    fixed_point_iteration(initial_guess, tolerance, maxIterations);

    return 0;
}

