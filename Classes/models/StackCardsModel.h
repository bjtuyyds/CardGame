#pragma once
#include<stack>
#include"CardModel.h"

class StackCardsModel {
private:
	std::stack<CardModel::CardId> _cards;

public:

	CardModel::CardId popCard();
	void pushCard(CardModel::CardId card);
	CardModel::CardId topCard();
	bool isEmpty();

};