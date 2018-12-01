#include "GPRandNumGenerator.hpp"

int RandNumGenerator::genRandNumber(int min, int max) {
    std::uniform_int_distribution<> rand_num(min, max);
    std::random_device rand;
    std::mt19937 gen(rand());
    return rand_num(gen);
}
