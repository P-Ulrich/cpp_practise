#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include "PiGenerator.hpp"

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

