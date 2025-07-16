#pragma once
#include"GameModel.h"


class UndoManager {
	GameModel* _gameModel;

public:
	static UndoManager* init(GameModel* gameModel);
	

};