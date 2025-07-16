#pragma once
#include "models/CardResConfig.h"
#include <stdexcept>

class IntToFaceType {
public:
	static CardFaceType intToFaceType(int num);
};