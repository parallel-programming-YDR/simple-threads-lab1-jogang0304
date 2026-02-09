#include "CircleAreaFinder.h"

const double CircleAreaFinder::getCoordNormed()
{
  const uint32_t       rndnum   = (this->generator_)();
  static const int64_t max_half = static_cast<int64_t>(this->generator_.max() / 2);
  const double         ans      = (static_cast<int64_t>(rndnum) - max_half) * (1.0l / max_half);
  return ans;
}

const uint64_t CircleAreaFinder::countHitsIn1Circle()
{
  uint64_t hits = 0;

  for (uint64_t i = 0; i < this->tries_; ++i)
  {
    const double x = this->getCoordNormed();
    const double y = this->getCoordNormed();
    if (x * x + y * y <= 1)
    {
      ++hits;
    }
  }

  return hits;
}
