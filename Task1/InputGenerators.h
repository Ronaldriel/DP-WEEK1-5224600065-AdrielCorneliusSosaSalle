#pragma once
#include "IInputGenerator.h"

// Implementasi 1: selalu return angka tetap (3)
class FixedInputGenerator : public IInputGenerator {
public:
    TurnInput generate() override;
};

// Implementasi 2 (Modification 1): return angka random 1-10
class RandomInputGenerator : public IInputGenerator {
public:
    TurnInput generate() override;
};
