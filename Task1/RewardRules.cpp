#include "RewardRules.h"

int BaseRewardRule::compute(int baseScore, int round) {
    return baseScore;
}

int BonusRewardRule::compute(int baseScore, int round) {
    if (round % 2 == 0)
        return baseScore * 2; // ronde genap: double reward
    return baseScore + 2;     // ronde ganjil: tambah 2
}
