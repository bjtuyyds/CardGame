#include"CardResConfig.h"

std::unordered_map<CardSuitType, std::string> CardResConfig::_suitToRes;
std::unordered_map<CardFaceType, std::string> CardResConfig::_faceToResBB; 
std::unordered_map<CardFaceType, std::string> CardResConfig::_faceToResSB;
std::unordered_map<CardFaceType, std::string> CardResConfig::_faceToResBR; //大红数字的路径映射
std::unordered_map<CardFaceType, std::string> CardResConfig::_faceToResSR; //小红数字的路径映射

void CardResConfig::init() {
	//suit 的路径
	_suitToRes[CardSuitType::CST_CLUBS]="suits/club.png";
	_suitToRes[CardSuitType::CST_DIAMONDS] = "suits/diamond.png";
	_suitToRes[CardSuitType::CST_HEARTS] = "suits/heart.png";
	_suitToRes[CardSuitType::CST_SPADES] = "suits/spade.png";

	//
	_faceToResBB[CardFaceType::CFT_ACE] = "nums/big_black_A.png";
	_faceToResBB[CardFaceType::CFT_TWO] = "nums/big_black_2.png";
	_faceToResBB[CardFaceType::CFT_THREE] = "nums/big_black_3.png";
	_faceToResBB[CardFaceType::CFT_FOUR] = "nums/big_black_4.png";
	_faceToResBB[CardFaceType::CFT_FIVE] = "nums/big_black_5.png";
	_faceToResBB[CardFaceType::CFT_SIX] = "nums/big_black_6.png";
	_faceToResBB[CardFaceType::CFT_SEVEN] = "nums/big_black_7.png";
	_faceToResBB[CardFaceType::CFT_EIGHT] = "nums/big_black_8.png";
	_faceToResBB[CardFaceType::CFT_NINE] = "nums/big_black_9.png";
	_faceToResBB[CardFaceType::CFT_TEN] = "nums/big_black_10.png";
	_faceToResBB[CardFaceType::CFT_JACK] = "nums/big_black_J.png";
	_faceToResBB[CardFaceType::CFT_QUEEN] = "nums/big_black_Q.png";
	_faceToResBB[CardFaceType::CFT_KING] = "nums/big_black_K.png";

	_faceToResSB[CardFaceType::CFT_ACE] = "nums/small_black_A.png";
	_faceToResSB[CardFaceType::CFT_TWO] = "nums/small_black_2.png";
	_faceToResSB[CardFaceType::CFT_THREE] = "nums/small_black_3.png";
	_faceToResSB[CardFaceType::CFT_FOUR] = "nums/small_black_4.png";
	_faceToResSB[CardFaceType::CFT_FIVE] = "nums/small_black_5.png";
	_faceToResSB[CardFaceType::CFT_SIX] = "nums/small_black_6.png";
	_faceToResSB[CardFaceType::CFT_SEVEN] = "nums/small_black_7.png";
	_faceToResSB[CardFaceType::CFT_EIGHT] = "nums/small_black_8.png";
	_faceToResSB[CardFaceType::CFT_NINE] = "nums/small_black_9.png";
	_faceToResSB[CardFaceType::CFT_TEN] = "nums/small_black_10.png";
	_faceToResSB[CardFaceType::CFT_JACK] = "nums/small_black_J.png";
	_faceToResSB[CardFaceType::CFT_QUEEN] = "nums/small_black_Q.png";
	_faceToResSB[CardFaceType::CFT_KING] = "nums/small_black_K.png";

	_faceToResBR[CardFaceType::CFT_ACE] = "nums/big_red_A.png";
	_faceToResBR[CardFaceType::CFT_TWO] = "nums/big_red_2.png";
	_faceToResBR[CardFaceType::CFT_THREE] = "nums/big_red_3.png";
	_faceToResBR[CardFaceType::CFT_FOUR] = "nums/big_red_4.png";
	_faceToResBR[CardFaceType::CFT_FIVE] = "nums/big_red_5.png";
	_faceToResBR[CardFaceType::CFT_SIX] = "nums/big_red_6.png";
	_faceToResBR[CardFaceType::CFT_SEVEN] = "nums/big_red_7.png";
	_faceToResBR[CardFaceType::CFT_EIGHT] = "nums/big_red_8.png";
	_faceToResBR[CardFaceType::CFT_NINE] = "nums/big_red_9.png";
	_faceToResBR[CardFaceType::CFT_TEN] = "nums/big_red_10.png";
	_faceToResBR[CardFaceType::CFT_JACK] = "nums/big_red_J.png";
	_faceToResBR[CardFaceType::CFT_QUEEN] = "nums/big_red_Q.png";
	_faceToResBR[CardFaceType::CFT_KING] = "nums/big_red_K.png";

	_faceToResSR[CardFaceType::CFT_ACE] = "nums/small_red_A.png";
	_faceToResSR[CardFaceType::CFT_TWO] = "nums/small_red_2.png";
	_faceToResSR[CardFaceType::CFT_THREE] = "nums/small_red_3.png";
	_faceToResSR[CardFaceType::CFT_FOUR] = "nums/small_red_4.png";
	_faceToResSR[CardFaceType::CFT_FIVE] = "nums/small_red_5.png";
	_faceToResSR[CardFaceType::CFT_SIX] = "nums/small_red_6.png";
	_faceToResSR[CardFaceType::CFT_SEVEN] = "nums/small_red_7.png";
	_faceToResSR[CardFaceType::CFT_EIGHT] = "nums/small_red_8.png";
	_faceToResSR[CardFaceType::CFT_NINE] = "nums/small_red_9.png";
	_faceToResSR[CardFaceType::CFT_TEN] = "nums/small_red_10.png";
	_faceToResSR[CardFaceType::CFT_JACK] = "nums/small_red_J.png";
	_faceToResSR[CardFaceType::CFT_QUEEN] = "nums/small_red_Q.png";
	_faceToResSR[CardFaceType::CFT_KING] = "nums/small_red_K.png";

}

std::string CardResConfig::getSuitPath(CardSuitType type)
{
	if (type > CardSuitType::CST_NONE && type < CardSuitType::CST_NUM_CARD_SUIT_TYPES) {
		return CardResConfig::_suitToRes[type];
	}
	
}

std::string CardResConfig::getBnumPath(CardSuitType suit,CardFaceType type)
{
	if (suit == CardSuitType::CST_DIAMONDS || suit == CardSuitType::CST_HEARTS) {
		return _faceToResBR[type];
	}
	else if (suit == CardSuitType::CST_CLUBS || suit == CardSuitType::CST_SPADES) {
		return CardResConfig::_faceToResBB[type];
	}
	
		
}

std::string CardResConfig::getSnumPath(CardSuitType suit,CardFaceType type)
{
	if (suit == CardSuitType::CST_DIAMONDS || suit == CardSuitType::CST_HEARTS) {
		return _faceToResSR[type];
	}
	else if (suit == CardSuitType::CST_CLUBS || suit == CardSuitType::CST_SPADES) {
		return CardResConfig::_faceToResSB[type];
	}
	
}
