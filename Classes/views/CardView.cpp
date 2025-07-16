#include "CardView.h"




CardView* CardView::createWithCardModel(CardModel* card)
{
    CardView* cardView=CardView::createWithSuitAndNum(card->getCardSuit(), card->getCardFace());

    return cardView;
}

//CardView* CardView::getCardViewWithCardModel(CardModel* card)
//{
//    if(CardView::cardViewMap.find(cardId)!= CardView::cardViewMap.end())
//        return CardView::cardViewMap[cardId];
//    else {
//        CCLOGERROR("the card: %d doesn't exist", cardId);
//        return nullptr;
//    }
//}

CardView* CardView::createWithSuitAndNum(CardSuitType suit, CardFaceType num)
{
    CardView* cardView = new (std::nothrow) CardView();
    if (cardView && cardView->initWithFile(CardGeneralPath) && cardView->_initWithSuitAndNum(suit, num))
    {
        cardView->autorelease();
        return cardView;
    }
    CC_SAFE_DELETE(cardView);
    return nullptr;
}

bool CardView::_initWithSuitAndNum(CardSuitType suit, CardFaceType num)
{
    auto suitPath = CardResConfig::getSuitPath(suit);
    auto bigNumPath = CardResConfig::getBnumPath(suit, num);
    auto smallNumPath = CardResConfig::getSnumPath(suit, num);

    _suit = Sprite::create(suitPath);
    _bigNum = Sprite::create(bigNumPath);
    _smallNum = Sprite::create(smallNumPath);

    if (!_suit || !_bigNum || !_smallNum) {
        if (!_suit) CCLOGERROR("Failed to load suit: %s", suitPath.c_str());
        if (!_bigNum) CCLOGERROR("Failed to load big num: %s", bigNumPath.c_str());
        if (!_smallNum) CCLOGERROR("Failed to load small num: %s", smallNumPath.c_str());
        return false;
    }

    cocos2d::Vec2 size = this->getContentSize();
    _bigNum->setPosition(cocos2d::Vec2(size.x * 0.5, size.y * 0.4));
    _smallNum->setAnchorPoint(cocos2d::Vec2(0, 1));
    _smallNum->setPosition(cocos2d::Vec2(size.x*0.1, size.y*0.9));
    _suit->setAnchorPoint(cocos2d::Vec2(1, 1));
    _suit->setPosition(cocos2d::Vec2(size.x*0.9, size.y*0.9));

    this->addChild(_suit);
    this->addChild(_bigNum);
    this->addChild(_smallNum);

    return true;
}

CardView* CardView::createWithSuitAndNum(int suit, int num)
{
    CardView* cardView = new (std::nothrow) CardView();
    if (cardView && cardView->initWithFile(CardGeneralPath) && cardView->_initWithSuitAndNum(suit, num))
    {
        cardView->autorelease();
        return cardView;
    }
    CC_SAFE_DELETE(cardView);
    return nullptr;
}

bool CardView::_initWithSuitAndNum(int suit, int num)
{
    try{
        CardSuitType esuit = IntToSuitType::intToSuitType(suit);
        CardFaceType faceType = IntToFaceType::intToFaceType(num);
        return _initWithSuitAndNum(esuit, faceType);
    }
    catch(std::invalid_argument e) {
        CCLOGERROR("CardView init failed. suit = %d, num = %d, reason: %s", suit, num, e.what());
        return false;
    }
    
}

