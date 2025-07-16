#include<VMMapManager.h>


void VMMapManager::bindVToM(CardView* cardView, CardModel* cardModel)
{
	this->_viewToModel[cardView] = cardModel;
}

void VMMapManager::bindMToV(CardModel* cardModel, CardView* cardView)
{
	this->_modelToView[cardModel] = cardView;
}

CardModel* VMMapManager::getCardModelWithView(CardView* cardView)
{
	return _viewToModel[cardView];
}

CardView* VMMapManager::getCardViewWithModel(CardModel* cardModel)
{
	return _modelToView[cardModel];
}
