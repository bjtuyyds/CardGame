#pragma once

#include<cocos2d.h>
#include"models/CardResConfig.h"
#include "Utils.h"
#include"CardModel.h"
#include <unordered_map>

class CardView : public cocos2d::Sprite{

private:
	cocos2d::Sprite* _suit;
	cocos2d::Sprite* _bigNum;
	cocos2d::Sprite* _smallNum;

	bool _initWithSuitAndNum(CardSuitType suit, CardFaceType num);
	bool _initWithSuitAndNum(int suit, int num);
	static CardView* createWithSuitAndNum(CardSuitType suit, CardFaceType num);
	static CardView* createWithSuitAndNum(int suit, int num);

public:
	
	static CardView* createWithCardModel(CardModel* card);

};