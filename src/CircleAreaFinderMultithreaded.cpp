#include "CircleAreaFinder.h"
#include <atomic>
#include <thread>
#include <vector>

const double CircleAreaFinderMultithreaded::getCircleArea(uint32_t radius, uint32_t cpus)
{
  const uint64_t       square_area      = 4 * radius * radius;
  const uint64_t       tries_per_thread = this->tries_ / cpus + 1;
  const uint64_t       total_tries      = tries_per_thread * cpus;
  std::atomic_uint64_t total_hits       = 0;

  std::vector<std::thread> threads(0);

  for (uint32_t i = 0; i < cpus; ++i)
  {
    threads.emplace_back(
      [this, radius, i, tries_per_thread, &total_hits]
      {
        CircleAreaFinder thisThreadFinder(this->seed_generator_(), tries_per_thread);
        total_hits += thisThreadFinder.countHitsIn1Circle();
      });
  }
  for (auto &t : threads)
  {
    if (t.joinable())
    {
      t.join();
    }
  }

  double answer = square_area * (total_hits * 1.0l / total_tries);

  return answer;
}
