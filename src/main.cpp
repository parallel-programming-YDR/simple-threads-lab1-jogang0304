#include "CircleAreaFinder.h"
#include "InputProcessor.h"
#include <chrono>
#include <iostream>

int main(int argc, char **argv)
{
  InputProcessor input_processor;
  auto           ii = input_processor.getInitialInput(argc, argv);

  CircleAreaFinderMultithreaded finder(ii.seed, ii.tries);

  int64_t radius, cpus;
  while (std::cin >> radius >> cpus)
  {
    input_processor.validateCircleInput(radius, cpus);

    const auto start{std::chrono::high_resolution_clock::now()};
    double     area = finder.getCircleArea(radius, cpus);
    const auto finish{std::chrono::high_resolution_clock::now()};
    double     time_ms = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(finish - start).count();

    std::cout << time_ms << " " << area << std::endl;
  }
}
