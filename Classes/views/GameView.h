#pragma once
#include <cocos2d.h>
#include"CardView.h"
#include"PlayFieldView.h"
#include"StackView.h"
#include "ui/CocosGUI.h"
class GameView : public cocos2d::Scene
{
    

public:
    

    static cocos2d::Scene* createScene();

    bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameView);


   /* Menu* UndoButtum;*/

};