#pragma once

// Interface: kontrak untuk siapapun yang mau jadi "penghitung reward"
class IRewardRule {
public:
    virtual int compute(int baseScore, int round) = 0;
    virtual ~IRewardRule() = default;
};
