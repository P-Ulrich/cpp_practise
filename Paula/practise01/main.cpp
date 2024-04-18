#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

double throw_stones_in_circle(int num_stones) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    auto random_x_val = double{};
    auto random_y_val = double{};
    auto distance_origin_squared = double{};
    auto circle_stone_counts = int{};
    auto quartered_circle =int{4};
    auto radius_circle_squared= double{1.};

    for (int i = 0; i < num_stones; ++i) {
        random_x_val = dis(gen);
        random_y_val = dis(gen);
         distance_origin_squared= (random_x_val * random_x_val + random_y_val * random_y_val);

        if (distance_origin_squared <= radius_circle_squared)
            ++circle_stone_counts;

    }

    return static_cast<double>(quartered_circle * circle_stone_counts) / num_stones;
}

double pi_std_err_2(int num_stones, int precision) {
    vector<double> pi_estimates(precision);
    auto sum_pi = double{};
    auto sum_pi_squared = double{};

    for (int i = 0; i < precision; ++i) {
        pi_estimates[i] = throw_stones_in_circle(num_stones);
        sum_pi += pi_estimates[i];
    }

    double mean_pi = sum_pi / precision;

    for (int i = 0; i < precision; ++i) {
        sum_pi_squared += (pi_estimates[i] - mean_pi) * (pi_estimates[i] - mean_pi);
    }

    auto variance = double{sum_pi_squared / precision};
    auto std_dev = double{sqrt(variance)};

    return std_dev;
}

int main() {
    auto num_stones = 10000;   // Anzahl der Punkte
    auto precision = 1000;  // Anzahl der Schätzungen
    auto result = throw_stones_in_circle(num_stones);
    auto err = pi_std_err_2(num_stones, precision);
    cout << "Approximated value of PI: " << result << endl;
    cout << "Approximated deviation of PI: " << err << endl;
    return 0;
}
