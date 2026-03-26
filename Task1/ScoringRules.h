#pragma once
#include "IScoringRule.h"

// Implementasi scoring sederhana: score = value dari input
class SimpleScoring : public IScoringRule {
public:
    int compute(TurnInput input) override;
};
