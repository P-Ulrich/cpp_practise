#include <cmath>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

struct Result
{
    double value{};
    double error{};
};

class PiGenerator
{
  public:
    PiGenerator() = default;
    void set_num_of_loops(int loops) { num_loops = loops; }
    void set_num_of_stones(int stones) { num_stones = stones; }
    auto rd_num_gen(double interval_left, double interval_right) -> double
    {
        auto dis = std::uniform_real_distribution<>{ interval_left, interval_right };
        return dis(gen);
    }
    double calculate_pi(int num_stones)
    {
        auto circle_stone_counts = int{};
        auto quartered_circle = int{ 4 };
        auto radius_circle_squared = double{ 1. };

        for (int i = 0; i < num_stones; ++i)
        {
            auto random_x_val = rd_num_gen(interval_left, interval_right);
            auto random_y_val = rd_num_gen(interval_left, interval_right);
            auto distance_origin_squared = (random_x_val * random_x_val + random_y_val * random_y_val);

            if (distance_origin_squared <= radius_circle_squared)
            {
                ++circle_stone_counts;
            }
        }

        return static_cast<double>(quartered_circle * circle_stone_counts) / num_stones;
    }

    void pi_mean_and_err(int num_stones, int precision)
    {

        std::vector<double> pi_estimates(precision);
        auto sum_pi = double{};
        auto sum_pi_squared = double{};

        for (int i = 0; i < precision; ++i)
        {
            // std::cout << "loop starts\n";
            pi_estimates[i] = calculate_pi(num_stones);
            sum_pi += pi_estimates[i];
            // std::cout << "loop ends\n";
        }

        double mean_pi = sum_pi / precision;

        pi_result.value = mean_pi;

        for (int i = 0; i < precision; ++i)
        {
            sum_pi_squared += (pi_estimates[i] - mean_pi) * (pi_estimates[i] - mean_pi);
        }

        auto variance = sum_pi_squared / precision;

        pi_result.error = sqrt(variance);
    }

    auto get_results()
    {
        pi_mean_and_err(num_stones, num_loops);
        return pi_result;
    }

  private:
    int num_stones{};
    int num_loops{};
    Result pi_result;
    std::random_device rd{};
    std::mt19937 gen{ rd() };
    double interval_left{ 0. };
    double interval_right{ 1. };
    // uniform_real_distribution<> dis{ interval_left, interval_right };
};
int main()
{

    std::cout << "starting the program\n";
    auto pi_generator = PiGenerator{};
    pi_generator.set_num_of_loops(10000);
    pi_generator.set_num_of_stones(10000);

    auto results = pi_generator.get_results();
    std::cout << "Value: " << results.value << "\terror:" << results.error << "\n";
    std::cout << "Program ends\n";
    return 0;
}
