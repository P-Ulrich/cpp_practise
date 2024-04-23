#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct Result {
  double value;
  double error;
};
class PiGenerator {
private:
  int num_stones;
  int num_loops;
  Result pi_result;

public:
  void set_num_of_loops(int loops) { num_loops = loops; }
  void set_num_of_stones(int stones) { num_stones = stones; }

  double calculate_pi(int num_stones) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    auto random_x_val = double{};
    auto random_y_val = double{};
    auto distance_origin_squared = double{};
    auto circle_stone_counts = int{};
    auto quartered_circle = int{4};
    auto radius_circle_squared = double{1.};

    for (int i = 0; i < num_stones; ++i) {
      random_x_val = dis(gen);
      random_y_val = dis(gen);
      distance_origin_squared =
          (random_x_val * random_x_val + random_y_val * random_y_val);

      if (distance_origin_squared <= radius_circle_squared)
        ++circle_stone_counts;
    }

    return static_cast<double>(quartered_circle * circle_stone_counts) /
           num_stones;
  }

  void pi_mean_and_err(int num_stones, int precision) {

    vector<double> pi_estimates(precision);
    auto sum_pi = double{};
    auto sum_pi_squared = double{};

    for (int i = 0; i < precision; ++i) {
      pi_estimates[i] = calculate_pi(num_stones);
      sum_pi += pi_estimates[i];
    }

    double mean_pi = sum_pi / precision;

    pi_result.value = mean_pi;

    for (int i = 0; i < precision; ++i) {
      sum_pi_squared +=
          (pi_estimates[i] - mean_pi) * (pi_estimates[i] - mean_pi);
    }

    auto variance = sum_pi_squared / precision;

    pi_result.error = variance;
  }

  auto get_results() {
    pi_mean_and_err(num_stones, num_loops);
    return pi_result;
  }
};
int main() {

  auto pi_generator = PiGenerator{};
  pi_generator.set_num_of_loops(10000);
  pi_generator.set_num_of_stones(10000);

  auto results = pi_generator.get_results();
  std::cout << "Value: " << results.value << "\terror:" << results.error
            << "\n";
  return 0;
}
