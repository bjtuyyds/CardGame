#pragma once

#include<cocos2d.h>
#include"GameController.h"


USING_NS_CC;


class MenuView :public Scene {
public:
    static Scene* createScene();

    bool init();

    void level1(Ref* ref);

    void level2(Ref* ref);

    void gameOver(Ref* ref);

    CREATE_FUNC(MenuView);


};