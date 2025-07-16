#pragma once
#include "models/CardResConfig.h"
#include <stdexcept>

class IntToSuitType {
public:
	static CardSuitType intToSuitType(int num);
};