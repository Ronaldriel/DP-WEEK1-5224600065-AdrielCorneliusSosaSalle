#include "ScoringRules.h"

int SimpleScoring::compute(TurnInput input) {
    return input.value; // base score langsung dari nilai input
}
