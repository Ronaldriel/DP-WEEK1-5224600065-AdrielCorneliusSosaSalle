#pragma once
#include "IInputGenerator.h"

// Interface: kontrak untuk siapapun yang mau jadi "penghitung score"
class IScoringRule {
public:
    virtual int compute(TurnInput input) = 0;
    virtual ~IScoringRule() = default;
};
