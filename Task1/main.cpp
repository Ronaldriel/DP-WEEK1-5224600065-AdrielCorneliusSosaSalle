#include <cstdlib>
#include "RunSession.h"
#include "InputGenerators.h"
#include "ScoringRules.h"
#include "RewardRules.h"

int main() {
    srand(42); // seed random supaya hasilnya konsisten

    // Modification 1: pakai RandomInputGenerator (bukan FixedInputGenerator)
    // Modification 2: pakai BonusRewardRule (bukan BaseRewardRule)
    // Ganti object di sini TANPA menyentuh RunSession sama sekali
    RandomInputGenerator gen;
    SimpleScoring        scoring;
    BonusRewardRule      reward;

    RunSession session(&gen, &scoring, &reward);
    session.run();

    return 0;
}
