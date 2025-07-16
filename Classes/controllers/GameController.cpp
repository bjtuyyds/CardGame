#include "GameController.h"


void GameController::startGame(int levelId)
{
	
	json j=LevelConfigLoader::loadLevelConfig(levelId);
	
	this->_model = new GameModel();
	
	GameModelFromLevelGenerator::generateGameModel(_model,j);

	this->_vmMapManager = new VMMapManager();
	this->_undoManager = UndoManager::init(_model);

	//创建GameView并压入场景栈
	this->_view = GameView::create();
	Director::getInstance()->pushScene(_view);

	//初始化各子控制器
	this->_playFieldController=PlayFieldController::init(_model, _vmMapManager);
	this->_stackController=StackController::init(_model, _vmMapManager);
	
	//初始化各子控制器的视图:
	this->_stackController->initView(this->_view);
	this->_playFieldController->initView(this->_view);

	MenuItemFont::setFontSize(100);
	MenuItemFont::setFontName("fonts/Marker Felt.ttf");

	auto menuItem1 = MenuItemFont::create("Undo", CC_CALLBACK_1(GameController::undo, this));

	auto menu = Menu::create(menuItem1, nullptr);
	menu->setPosition(950, 290);
	menu->alignItemsVertically();
	menu->alignItemsVerticallyWithPadding(100);
	this->_view->addChild(menu);

	CCLOG("%d", this->_model->mainCards.size());
	CCLOG("%p", this->_model);


	return;
}

void GameController::undo(Ref*) {

	if (this->_model->stackCards.size()<=1)return;
	CCLOG("%p", this->_model);
	auto card=this->_model->stackCards.top();
	this->_model->stackCards.pop();
	
	auto initP = card->getInitPlace();
	
	if (initP == PlaceBelong::MAIN_FILD) {
		_playFieldController->undo(card);
	}
	else if(initP == PlaceBelong::RESERVE_FILD){
		_stackController->undo(card);
	}
	else {

	}
	CCLOG("Button clicked!");
}