#pragma once

#include <cstdint>
#include <random>

class CircleAreaFinder
{
public:
  explicit CircleAreaFinder(uint32_t seed, uint64_t tries) :
    tries_(tries),
    generator_(seed)
  {
  }
  const uint64_t countHitsIn1Circle();

private:
  const uint64_t tries_;
  std::mt19937   generator_;

  const double getCoordNormed(); // normed to [-1, 1]
};

class CircleAreaFinderMultithreaded
{
public:
  struct solve_return_t
  {
    double time_ms;
    double area;
  };

  explicit CircleAreaFinderMultithreaded(uint32_t seed, uint64_t tries) :
    tries_(tries),
    seed_generator_(seed)
  {
  }

  const double getCircleArea(uint32_t radius, uint32_t cpus);

private:
  const uint64_t tries_;
  std::mt19937   seed_generator_;
};
