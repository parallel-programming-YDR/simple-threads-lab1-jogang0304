#pragma once

#include <cstdint>

class InputProcessor
{
public:
  struct InitialInput
  {
    uint64_t tries;
    uint32_t seed;
  };

  explicit InputProcessor() {}

  const void         validateInitialInput(int argc, char **argv);
  const void         validateCircleInput(int radius, int cpus);
  const InitialInput getInitialInput(int argc, char **argv);

private:
  const void validateNumberOfTries(int argc, char **argv);
  const void validateSeed(int argc, char **argv);
};
