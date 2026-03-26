#include "InputGenerators.h"
#include <cstdlib>

TurnInput FixedInputGenerator::generate() {
    return {3}; // selalu return 3
}

TurnInput RandomInputGenerator::generate() {
    return {rand() % 10 + 1}; // random antara 1-10
}
