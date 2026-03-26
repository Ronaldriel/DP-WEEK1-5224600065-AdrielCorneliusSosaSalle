#pragma once
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

// RunSession: sutradara game loop
// Tugasnya HANYA mengatur URUTAN fase, tidak boleh berisi logika scoring/reward/input
class RunSession {
    IInputGenerator* inputGen;
    IScoringRule*    scoring;
    IRewardRule*     reward;
    ShopSystem       shop;
    int              money;

public:
    RunSession(IInputGenerator* g, IScoringRule* s, IRewardRule* r);
    void run();
};
