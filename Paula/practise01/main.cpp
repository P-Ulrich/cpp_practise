#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include "PiGenerator.hpp"
#include <TH1.h>
#include <TFile.h>




int main()
{
 

    auto file = TFile("hist.root", "hist");

    auto histogramm = TH1F("h1", "h1 titel",100,0, 5.);
    histogramm.FillRandom("gaus", 10000);
    histogramm.Write();
    histogramm.DrawCopy();

    file.Close();

    // 
    // std::cout << "starting the program\n";
    // auto pi_generator = PiGenerator{};
    // pi_generator.set_num_of_loops(10000);
    // pi_generator.set_num_of_stones(10000);
    //
    // auto results = pi_generator.get_results();
    // std::cout << "Value: " << results.value << "\terror:" << results.error << "\n";
    // std::cout << "Program ends\n";
    return 0;
}

