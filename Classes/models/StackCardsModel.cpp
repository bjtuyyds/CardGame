#include "StackCardsModel.h"

CardModel::CardId StackCardsModel::popCard()
{
	if (!_cards.empty()) {
		CardModel::CardId card = _cards.top();
		_cards.pop();
		return card;
	}
	else {
		throw std::out_of_range("No more cards in BottomCardsModel");
	}
}

void StackCardsModel::pushCard(CardModel::CardId cardId)
{
	_cards.push(cardId);
	return;
}



CardModel::CardId StackCardsModel::topCard()
{
	if (!_cards.empty())
		return _cards.top();
	else {
		throw std::out_of_range("No more cards in BottomCardsModel");
	}
}

bool StackCardsModel::isEmpty()
{
	return _cards.empty();
}
