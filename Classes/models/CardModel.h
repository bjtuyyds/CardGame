#pragma once
#include "models/CardResConfig.h"
#include<vector>
#include<json.hpp>
#include<Utils.h>


using json = nlohmann::json;


enum PlaceBelong {
	MAIN_FILD,
	STACK_FILD,
	RESERVE_FILD	
};




class CardModel {
public:


	CardFaceType& getCardFace();
	CardSuitType& getCardSuit();
	Position& getCardPosition();

	void setCardFace(int cardFace);
	void setCardSuit(int cardSuit);
	void setInitCardPosition(int positionX, int positionY);
	

	PlaceBelong getCurPlace();
	void setCurPlace(PlaceBelong);
	PlaceBelong getInitPlace();
	void setInitPlace(PlaceBelong place);

private:
	PlaceBelong _initPlace;
	PlaceBelong _curPlace;
	CardFaceType _cardFace=CardFaceType::CFT_NONE;
	CardSuitType _cardSuit=CardSuitType::CST_NONE;
	Position _initCardPosition; 

};






