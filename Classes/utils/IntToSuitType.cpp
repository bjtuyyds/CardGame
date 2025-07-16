#include "IntToSuitType.h"

CardSuitType IntToSuitType::intToSuitType(int num)
{
	if (num > CardSuitType::CST_NONE && num < CardSuitType::CST_NUM_CARD_SUIT_TYPES) {
		CardSuitType suitType = static_cast<CardSuitType>(num);
		return suitType;
	}
	else {
		throw std::invalid_argument("the argument is out of range");
	}
}
