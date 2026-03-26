#pragma once

// Struct yang menyimpan data input per ronde
struct TurnInput {
    int value;
};

// Interface: kontrak untuk siapapun yang mau jadi "generator input"
class IInputGenerator {
public:
    virtual TurnInput generate() = 0;
    virtual ~IInputGenerator() = default;
};
