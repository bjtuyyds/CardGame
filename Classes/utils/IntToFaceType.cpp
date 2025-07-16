#include "IntToFaceType.h"

CardFaceType IntToFaceType::intToFaceType(int num) {
	if (num > CardFaceType::CFT_NONE && num < CardFaceType::CFT_NUM_CARD_FACE_TYPES) {
		CardFaceType faceType = static_cast<CardFaceType>(num);
		return faceType;
	}
	else {
		throw std::invalid_argument("the argument is out of range");
	}
}
