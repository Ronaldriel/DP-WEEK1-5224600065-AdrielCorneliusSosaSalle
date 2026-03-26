#pragma once
#include "IRewardRule.h"

// Implementasi reward dasar: reward = base score
class BaseRewardRule : public IRewardRule {
public:
    int compute(int baseScore, int round) override;
};

// Modification 2: reward berbeda tergantung ronde
// - Ronde ganjil: reward = baseScore + 2
// - Ronde genap:  reward = baseScore * 2
class BonusRewardRule : public IRewardRule {
public:
    int compute(int baseScore, int round) override;
};
