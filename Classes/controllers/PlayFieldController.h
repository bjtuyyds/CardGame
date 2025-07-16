#pragma once
#include "GameModel.h"
#include"PlayFieldView.h"
#include"loaders/LevelConfigLoader.h"
#include"UndoManager.h"
#include"VMMapManager.h"
#include<cocos2d.h>
#include"GameView.h"
#include<MainCardManager.h>

USING_NS_CC;

class PlayFieldController {
	MainCardManager* _mainCardManger;
	GameModel * _gameModel=nullptr;
	PlayFieldView * _playFieldView=nullptr;
	/*UndoManager * _undoManager = nullptr;*/
	VMMapManager* _vmMapManager = nullptr;
	bool _onClick(CardView* target);
public:
	static PlayFieldController* init(GameModel* model,VMMapManager* vmMapManager);
	void initView(GameView* _gameView);
	bool match(CardView* gameView);
	void undo(CardModel* cardModel);
};