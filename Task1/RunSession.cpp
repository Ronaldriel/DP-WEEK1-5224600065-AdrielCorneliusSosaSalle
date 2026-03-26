#include "RunSession.h"
#include <iostream>

RunSession::RunSession(IInputGenerator* g, IScoringRule* s, IRewardRule* r)
    : inputGen(g), scoring(s), reward(r), money(0) {}

void RunSession::run() {
    std::cout << "=== RUN START ===\n";

    for (int round = 1; round <= 3; round++) {
        std::cout << "\nRound " << round << "\n";

        // Fase 1: Generate input
        TurnInput input = inputGen->generate();
        std::cout << "[PLAY] input generated: " << input.value << "\n";

        // Fase 2: Compute base score
        int score = scoring->compute(input);
        std::cout << "[SCORE] base score: " << score << "\n";

        // Fase 3: Compute reward
        int gain = reward->compute(score, round);

        // Fase 4: Update money (HANYA di sini, tidak boleh di tempat lain)
        money += gain;
        std::cout << "[REWARD] gain: " << gain << " | money: " << money << "\n";

        // Fase 5: Shop phase
        shop.offer(money);

        // Fase 6: Advance round (loop berlanjut otomatis)
    }

    std::cout << "\n=== RUN END ===\n";
    std::cout << "Final money: " << money << "\n";
}
