#include<PlayFieldController.h>


bool PlayFieldController::_onClick(CardView* target) {

	CCLOG("the card has been clicked");
	auto cardModel = this->_vmMapManager->getCardModelWithView(target);
	if (cardModel->getCurPlace() == PlaceBelong::MAIN_FILD) {
		CCLOG("main field been clicked: %d", cardModel->getCardFace());
	}
	else if (cardModel->getCurPlace() == PlaceBelong::RESERVE_FILD) {
		CCLOG("reserved field been clicked: %d", cardModel->getCardFace());
	}
	else {
		CCLOG("stack field been clicked");
		return false;
	}
	/*return true;*/


	if (_gameModel->mainCards.empty())return false;
	if (!match(target))return false;
	_gameModel->stackCards.push(cardModel);
	cardModel->setCurPlace(PlaceBelong::STACK_FILD);
	_playFieldView->setMoveView(target);
	target->setZOrder(_gameModel->stackCards.size());
	this->_playFieldView->playMatchAnimation();
	CCLOG("%d",_gameModel->stackCards.size());
}


PlayFieldController* PlayFieldController::init(GameModel* model, VMMapManager* vmMapManager) {
	PlayFieldController* playFieldController = new PlayFieldController();
	playFieldController->_gameModel = model;
	//playFieldController->_undoManager = undoManager;
	playFieldController->_vmMapManager = vmMapManager;
	return playFieldController;
}

void PlayFieldController::initView(GameView* _gameView)
{

	this->_playFieldView = new PlayFieldView();
	for (auto cardModel : _gameModel->mainCards) {
		auto cardView = CardView::createWithCardModel(cardModel);
		auto& position = cardModel->getCardPosition();
		CCLOG("x=%d ,y=%d", position.x, position.y);
		cardView->setPosition(position.x,position.y+stackheight);
		this->_playFieldView->insert(cardView);
		this->_vmMapManager->bindMToV(cardModel, cardView);
		this->_vmMapManager->bindVToM(cardView, cardModel);
		_gameView->addChild(cardView);

	}

	this->_mainCardManger = MainCardManager::init(this->_playFieldView->_playFieldView);

	for (auto cardView:this->_playFieldView->_playFieldView) {
		auto listener = EventListenerTouchOneByOne::create();
		listener->onTouchBegan = [this, cardView](Touch* touch, Event* event) {
			Vec2 localPos = cardView->convertToNodeSpace(touch->getLocation());
			Rect rect(0, 0, cardView->getContentSize().width, cardView->getContentSize().height);
			if (rect.containsPoint(localPos)) {
				CCLOG("Clicked specific cardView");
				this->_onClick(cardView);
				return true;
			}
			return false;
			};
		listener->setSwallowTouches(true);
		cardView->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, cardView);
	}
	CCLOG("there are %d playfieldviews", _gameModel->mainCards.size());
	this->_playFieldView->playEntranceAnimation();
	return;
}

bool PlayFieldController::match(CardView* cardView)
{
	auto model=_gameModel->stackCards.top();
	auto modelClicked = _vmMapManager->getCardModelWithView(cardView);

	if (abs(model->getCardFace() - modelClicked->getCardFace()) == 1 && _mainCardManger->remove(cardView)) {
		return true;
	}

	return false;
}

void PlayFieldController::undo(CardModel* cardModel)
{
	_gameModel->mainCards.push_back(cardModel);
	cardModel->setCurPlace(cardModel->getInitPlace());
	_playFieldView->gotoPosition(_vmMapManager->getCardViewWithModel(cardModel),cardModel->getCardPosition().x, cardModel->getCardPosition().y+stackheight);
	_mainCardManger->insert(_vmMapManager->getCardViewWithModel(cardModel));
	
}
