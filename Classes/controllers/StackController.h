#pragma once
#include"GameModel.h"
#include"StackView.h"
#include"UndoManager.h"
#include"VMMapManager.h"
#include"GameView.h"
#include<cocos2d.h>

USING_NS_CC;

class StackController {
	GameModel* _model=nullptr;
	StackView* _stackView=nullptr;
	//UndoManager* _undoManager = nullptr;
	VMMapManager* _vmMapManager = nullptr;
	bool onClick(CardView* target);

public:
	
	static StackController* init(GameModel* model, VMMapManager* vmMapManager);
	void initView(GameView* _gameView);

	void undo(CardModel*);

};