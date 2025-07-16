#include"MenuView.h"

Scene* MenuView::createScene() {
	return MenuView::create();
}


bool MenuView::init() {

	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	MenuItemFont::setFontSize(100);
	MenuItemFont::setFontName("fonts/Marker Felt.ttf");

	auto menuItem1 = MenuItemFont::create("Level 1", CC_CALLBACK_1(MenuView::level1, this));
	/*auto menuItem2 = MenuItemFont::create("Level 2", CC_CALLBACK_1(MenuView::level2, this));*/
	auto menuItem3 = MenuItemFont::create("game over", CC_CALLBACK_1(MenuView::gameOver, this));


	auto menu=Menu::create(menuItem1,menuItem3,nullptr);
	//menu->setPosition(0,0);
	menu->alignItemsVertically();
	menu->alignItemsVerticallyWithPadding(100);
	this->addChild(menu);
	
	return true;
}

void MenuView::level1(Ref* ref)
{
	GameController *gameController=new GameController();
	gameController->startGame(1);
	//TODO当游戏结束时释放
}

//void MenuView::level2(Ref* ref)
//{
//	GameController gameController;
//	gameController.startGame(2);
//}

void MenuView::gameOver(Ref* ref)
{
	Director::getInstance()->end();
}
