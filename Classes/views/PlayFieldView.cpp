#include"PlayFieldView.h"

void PlayFieldView::playMatchAnimation() {
	auto action = cocos2d::MoveTo::create(0.25,cocos2d::Vec2(stackPosition.x,stackPosition.y));
	if (_needmoveView != nullptr) {
		_needmoveView->runAction(action);
	}

}
void PlayFieldView::gotoPosition(CardView* cardView,int x, int y)
{
	auto action = cocos2d::MoveTo::create(0.25, cocos2d::Vec2(x,y));
	if (cardView != nullptr) {
		cardView->runAction(action);
		cardView->setZOrder(0);
	}
	
}


void PlayFieldView::insert(CardView* cardView){
	this->_playFieldView.push_back(cardView);
}
void PlayFieldView::remove(CardView* cardView){
	
}
void PlayFieldView::playEntranceAnimation(){
	CCLOG("there are %d playfieldviews", this->_playFieldView.size());
	/*for (auto cardView : this->_playFieldView) {
		cocos2d::Director::getInstance()->getRunningScene()->addChild(cardView);
	}*/


}

void PlayFieldView::setMoveView(CardView* cardView)
{
	this->_needmoveView = cardView;
}
