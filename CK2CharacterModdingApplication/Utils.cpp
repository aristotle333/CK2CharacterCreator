#include "Utils.h"

// returns a random integer in the range of [lowerBound, upperBound] (inclusive)
int randNumInRange(int lowerBound, int upperBound) {
    uniform_int_distribution<int> dist(lowerBound, upperBound);
    random_device rd;
    mt19937 gen(rd());

    return dist(gen);
}

// returns a random integer in the range of [meanVal - variance, meanVal + variance] (inclusive)
int randNumWithVar(int meanVal, int variance) {
    uniform_int_distribution<int> dist(meanVal - variance, meanVal + variance);
    random_device rd;
    mt19937 gen(rd());

    return dist(gen);
}