#include"UndoManager.h"

UndoManager* UndoManager::init(GameModel* gameModel) {
	UndoManager* undoManager=new UndoManager();
	undoManager->_gameModel = gameModel;
	return undoManager;
}