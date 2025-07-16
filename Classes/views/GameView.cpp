/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameView.h"
#include "SimpleAudioEngine.h"
#include "CardView.h"
#include "loaders/LevelConfigLoader.h"

USING_NS_CC;

Scene* GameView::createScene()
{
    return GameView::create();
}


// on "init" you need to initialize your instance
bool GameView::init()
{

    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    //GameView初始化UI:
   
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //using namespace cocos2d::ui;


    //auto button = Button::create();
    //// 设置位置
    //button->setPosition(Vec2(500, 1000));

    //// 设置按钮标题（文字）
    //button->setTitleText("回退");
    //button->setTitleFontName("fonts/Marker Felt.ttf");  // 字体路径
    //button->setTitleFontSize(100);                       // 字体大小
    //button->setTitleColor(Color3B::WHITE);              // 字体颜色

    //// 添加点击事件
    //button->addClickEventListener([](Ref* sender) {
    //    CCLOG("Button clicked!");
    //    });

    //this->addChild(button);

    /*MenuItemFont::setFontSize(100);
    MenuItemFont::setFontName("fonts/Marker Felt.ttf");

    auto menuItem1 = MenuItemFont::create("Undo", CC_CALLBACK_1(GameView::undo, this));

    auto menu = Menu::create(menuItem1,nullptr);
    menu->setPosition(950,290);
    menu->alignItemsVertically();
    menu->alignItemsVerticallyWithPadding(100);
     ->addChild(menu);*/

    return true;
}

//void GameView::addsubView(StackView* _stackView, PlayFieldView* _playFieldView)
//{
//    this->_stackView = _stackView;
//    this->_playFieldView = _playFieldView;
//
//}
//
//
//void GameView::playEntranceAnimation() {
//    this->_stackView->playEntranceAnimation();
//    this->_playFieldView->playEntranceAnimation();
//
//}


