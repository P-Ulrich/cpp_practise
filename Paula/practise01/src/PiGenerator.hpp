#pragma once
#include <random>

struct Result
{
    double value{};
    double error{};
};

class PiGenerator
{
  public:
    PiGenerator() = default;
    void set_num_of_loops(int loops);
    void set_num_of_stones(int stones);
    auto get_results() -> Result;

  private:
    int num_stones{};
    int num_loops{};
    Result pi_result;
    std::random_device rd{};
    std::mt19937 gen{ rd() };
    double interval_left{ 0. };
    double interval_right{ 1. };
    // uniform_real_distribution<> dis{ interval_left, interval_right };
    auto rd_num_gen(double interval_left, double interval_right) -> double;
    double calculate_pi(int num_stones);
    void pi_mean_and_err(int num_stones, int precision);
};
