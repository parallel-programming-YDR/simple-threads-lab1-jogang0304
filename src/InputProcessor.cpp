#include "InputProcessor.h"
#include <stdexcept>

const void InputProcessor::validateNumberOfTries(int argc, char **argv)
{
  try
  {
    int64_t tries = std::stoll(argv[1]);
    if (tries <= 0)
    {
      throw std::exception();
    }
  }
  catch (std::exception e)
  {
    throw std::invalid_argument("Number of tries must be a positive number");
  }
}

const void InputProcessor::validateSeed(int argc, char **argv)
{
  if (argc == 3)
  {
    try
    {
      int seed = std::stoi(argv[2]);
      if (seed < 0)
      {
        throw std::exception();
      }
    }
    catch (std::exception e)
    {
      throw std::invalid_argument("Seed must be a positive number");
    }
  }
}

const void InputProcessor::validateInitialInput(int argc, char **argv)
{
  if (argc < 2 || argc > 3)
  {
    throw std::invalid_argument("Program accepts 2 or 3 arguments");
  }

  this->validateNumberOfTries(argc, argv);
  this->validateSeed(argc, argv);
}

const InputProcessor::InitialInput InputProcessor::getInitialInput(int argc, char **argv)
{
  this->validateInitialInput(argc, argv);
  InitialInput answer{
    static_cast<uint64_t>(std::stoll(argv[1])),
    0,
  };

  if (argc == 3)
  {
    answer.seed = static_cast<uint32_t>(std::stoi(argv[2]));
  }

  return answer;
}

const void InputProcessor::validateCircleInput(int radius, int cpus)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius must be positive");
  }
  if (cpus <= 0)
  {
    throw std::invalid_argument("Number of threads must be positive");
  }
}
