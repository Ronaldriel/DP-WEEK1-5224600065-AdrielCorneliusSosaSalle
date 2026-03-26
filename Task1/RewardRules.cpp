#include "RewardRules.h"

int BaseRewardRule::compute(int baseScore, int round) {
    return baseScore;
}

int BonusRewardRule::compute(int baseScore, int round) {
    if (round == 2)
        return baseScore + 2; // ronde 2: tambah 2
    if (round == 3)
        return baseScore * 2; // ronde 3: kali 2
    return baseScore;
}
