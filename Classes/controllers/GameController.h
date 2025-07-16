#pragma once
#include"loaders/LevelConfigLoader.h"
#include"models/CardResConfig.h"
#include"GameModel.h"
#include"GameModelFromLevelGenerator.h"
#include"PlayFieldController.h"
#include"StackController.h"
#include"UndoManager.h"
#include"GameView.h"
#include<unordered_map>
//#include<cocos2d.h>
#include"VMMapManager.h"

USING_NS_CC;

class GameController {
private:
	GameModel* _model = nullptr;
	GameView* _view = nullptr;
	PlayFieldController* _playFieldController=nullptr;
	StackController* _stackController=nullptr;
	UndoManager* _undoManager=nullptr;
	VMMapManager* _vmMapManager = nullptr;
	void undo(Ref* ref);
public:

    void startGame(int levelId);
	
};

