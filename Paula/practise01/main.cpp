#include "PiGenerator.hpp"
#include <TFile.h>
#include <TH1.h>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

int main()
{
    //
    // auto file = TFile("hist.root", "RECREATE");
    //
    // auto histogramm = TH1F("h1", "h1 titel", 100, 0, 5.);
    // histogramm.FillRandom("gaus", 10000);
    // histogramm.Write();
    //
    // file.Close();

    //
    std::cout << "starting the program\n";
    auto pi_generator = PiGenerator{};
    pi_generator.set_num_of_loops(10000);
    pi_generator.set_num_of_stones(10000);
    std::cout << "starting the file creation\n";
    pi_generator.create_hist_file();

    // auto results = pi_generator.get_results();
    // std::cout << "Value: " << results.value << "\terror:" << results.error << "\n";
    std::cout << "Program ends\n";
    return 0;
}
