#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

double pi_stones(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    double random_x_val;
    double random_y_val;
    double distance;
    int circle = 0;
    int square = 0;

    for (int i = 0; i < n; ++i) {
        random_x_val = dis(gen);
        random_y_val = dis(gen);
        distance = sqrt(random_x_val * random_x_val + random_y_val * random_y_val);

        if (distance <= 1)
            circle++;

        square++;
    }

    return double(4 * circle) / square;
}

double pi_std_err_2(int n, int precision) {
    vector<double> pi_estimates(precision);
    double sum_pi = 0;
    double sum_pi_squared = 0;

    for (int i = 0; i < precision; ++i) {
        pi_estimates[i] = pi_stones(n);
        sum_pi += pi_estimates[i];
    }

    double mean_pi = sum_pi / precision;

    for (int i = 0; i < precision; ++i) {
        sum_pi_squared += (pi_estimates[i] - mean_pi) * (pi_estimates[i] - mean_pi);
    }

    double variance = sum_pi_squared / precision;
    double std_dev = sqrt(variance);
    double std_err = std_dev / sqrt(precision);

    return std_err;
}

int main() {
    int n = 10000;   // Anzahl der Punkte
    int pre = 1000;  // Anzahl der Schätzungen
    double result = pi_stones(n);
    double err = pi_std_err_2(n, pre);
    cout << "Approximated value of PI: " << result << endl;
    cout << "Approximated error of PI: " << err << endl;
    return 0;
}
