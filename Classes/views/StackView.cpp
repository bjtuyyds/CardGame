#include"StackView.h"



void StackView::playMatchAnimation() {
	if (_stackView.empty())return;

	CardView* cardView=this->_stackView.back();
	this->_stackView.pop_back();
	auto animation=cocos2d::MoveTo::create(0.25,cocos2d::Vec2(stackPosition.x,stackPosition.y));
	cardView->runAction(animation);
	for (auto& card : _stackView) {
		auto animation = cocos2d::MoveBy::create(0.25, cocos2d::Vec2(100,0));
		card->runAction(animation);
	}

}

void StackView::goBack(CardView* cardView) {
	for (auto& card : _stackView) {
		auto animation = cocos2d::MoveBy::create(0.25, cocos2d::Vec2(-100, 0));
		card->runAction(animation);
	}
	this->_stackView.push_back(cardView);
	auto animation = cocos2d::MoveTo::create(0.25, cocos2d::Vec2(reservePosition.x, reservePosition.y));
	cardView->runAction(animation);
	cardView->setZOrder(0);
}
void StackView::insert(CardView* cardView) {
	this->_stackView.push_back(cardView);
}
void StackView::remove(CardView* cardView) {
	
}

void StackView::playEntranceAnimation() {
	int y = reservePosition.y;
	int x = reservePosition.x;
	int n = _stackView.size();
	x -= (n-1) * dis;
	CCLOG("there are %d stackviews", n);
	for (int i = 0; i <n;i++,x+=dis) {
		auto cardView = _stackView[i];
		cardView->setPosition(x,y);
	}
}