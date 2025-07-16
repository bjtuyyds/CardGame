#pragma once
#include<unordered_map>
#include<CardView.h>
#include<CardModel.h>

class VMMapManager {
private:
	std::unordered_map<CardView*, CardModel*> _viewToModel;
	std::unordered_map<CardModel*, CardView*> _modelToView;
public:
	void bindVToM(CardView* cardView, CardModel* cardModel);
	void bindMToV(CardModel* cardModel, CardView* cardView);
	CardModel* getCardModelWithView(CardView* cardView);
	CardView* getCardViewWithModel(CardModel* cardModel);

};