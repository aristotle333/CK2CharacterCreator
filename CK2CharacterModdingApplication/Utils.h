#pragma once
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// Generic functions that can be used throughout the project

// returns a random integer in the range of [lowerBound, upperBound] (inclusive)
int randNumInRange(int lowerBound, int upperBound);

// returns a random integer in the range of [meanVal - variance, meanVal + variance] (inclusive)
int randNumWithVar(int meanVal, int variance);