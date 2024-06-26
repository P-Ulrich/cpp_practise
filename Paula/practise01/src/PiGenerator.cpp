#include "PiGenerator.hpp"
#include <iostream>
#include <TFile.h>
void PiGenerator::set_num_of_loops(int loops) { num_loops = loops; }

void PiGenerator::set_num_of_stones(int stones) { num_stones = stones; }

void PiGenerator::set_num_bins(int bins) { num_bins = bins; }

void PiGenerator::set_intervalls_hist(int left, int right)
{
    inter_hist_left = left;
    inter_hist_right = right;
}
void PiGenerator::set_num_hist(int num_hist) { num_hist_ = num_hist; }

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

    sum_pi = std::accumulate(pi_estimates.begin(), pi_estimates.end(), 0.);

    double mean_pi = sum_pi / precision;

    pi_result.value = mean_pi;

    // for (const auto& element : pi_estimates)
    // {
    //     sum_pi_squared += (element - mean_pi) * (element - mean_pi);
    // }

    auto variance = std::accumulate(pi_estimates.begin(),
                                    pi_estimates.end(),
                                    0.,
                                    [mean_pi, precision](auto init, auto element)
                                    { return init + ((element - mean_pi) * (element - mean_pi)) / precision; });
    // auto variance = sum_pi_squared / precision;

    pi_result.error = sqrt(variance);
}

void PiGenerator::fill_hist_pi()
{
    for (int i{}; i < num_hist_; ++i)
    {
        histogramm->Fill(calculate_pi(num_stones));
    }
}
void PiGenerator::create_hist_file()
{

    auto file = TFile("hist.root", "RECREATE");
    histogramm = std::make_unique<TH1F>("h1", "h1_titel", num_bins, inter_hist_left, inter_hist_right).release();
    std::cout << "Starting File Loop \n";
    fill_hist_pi();
    histogramm->Write();
    file.Close();
}

auto PiGenerator::get_results() -> Result
{
    pi_mean_and_err(num_stones, num_loops);
    return pi_result;
}
