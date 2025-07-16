#include "CardModel.h"
#include<stdexcept>



CardFaceType& CardModel::getCardFace() {
	return _cardFace;
}

CardSuitType& CardModel::getCardSuit() {
	return _cardSuit;
}

Position& CardModel::getCardPosition() {
	return _initCardPosition;
}

void CardModel::setCardFace(int cardFace)
{
	if (cardFace > CardFaceType::CFT_NONE && cardFace < CardFaceType::CFT_NUM_CARD_FACE_TYPES) {
		this->_cardFace = static_cast<CardFaceType>(cardFace);
	}
	else {
		this->_cardFace = CardFaceType::CFT_NONE;
		throw std::invalid_argument("the face of the card is invalid");
	}

	return;
}

void CardModel::setCardSuit(int cardSuit)
{
	if (cardSuit > CardFaceType::CFT_NONE && cardSuit < CardFaceType::CFT_NUM_CARD_FACE_TYPES) {
		this->_cardSuit = static_cast<CardSuitType>(cardSuit);
	}
	else {
		this->_cardSuit = CardSuitType::CST_NONE;
		throw std::invalid_argument("the suit of card is invalid");
	}
	return;
}

void CardModel::setInitCardPosition(int positionX, int positionY)
{
	this->_initCardPosition.x = positionX;
	this->_initCardPosition.y = positionY;
	return ;
}



PlaceBelong CardModel::getCurPlace()
{
	return _curPlace;
}

PlaceBelong CardModel::getInitPlace()
{
	return _initPlace;
}


void CardModel::setCurPlace(PlaceBelong place)
{
	this->_curPlace = place;
}

void CardModel::setInitPlace(PlaceBelong place)
{
	this->_initPlace = place;
}





