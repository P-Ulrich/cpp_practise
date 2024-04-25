#include "PiGenerator.hpp"

void PiGenerator::set_num_of_loops(int loops) { num_loops = loops; }

void PiGenerator::set_num_of_stones(int stones) { num_stones = stones; }

auto PiGenerator::rd_num_gen(double interval_left, double interval_right) -> double
{
    auto dis = std::uniform_real_distribution<>{ interval_left, interval_right };
    return dis(gen);
}

double PiGenerator::calculate_pi(int num_stones)
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

void PiGenerator::pi_mean_and_err(int num_stones, int precision)
{
    auto pi_estimates = std::vector<double>{};
    pi_estimates.reserve(precision);
    auto sum_pi = double{};
    auto sum_pi_squared = double{};

    for (int i{}; i < precision; ++i)
    {

        pi_estimates.emplace_back(calculate_pi(num_stones));
    }

    for (const auto& element : pi_estimates)
    {
        sum_pi += element;
    }

    double mean_pi = sum_pi / precision;

    pi_result.value = mean_pi;

    for (const auto& element : pi_estimates)
    {
        sum_pi_squared += (element - mean_pi) * (element - mean_pi);
    }

    auto variance = sum_pi_squared / precision;

    pi_result.error = sqrt(variance);
}

auto PiGenerator::get_results() -> Result
{
    pi_mean_and_err(num_stones, num_loops);
    return pi_result;
}
