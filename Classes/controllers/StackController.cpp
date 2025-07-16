#include"StackController.h"


bool StackController::onClick(CardView* target)
{
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


	if (_model->reserveCards.empty())return false;
	auto card = _model->reserveCards.back();
	_model->reserveCards.pop_back();
	_model->stackCards.push(card);
	card->setCurPlace(PlaceBelong::STACK_FILD);
	target->setZOrder(_model->stackCards.size());
	this->_stackView->playMatchAnimation();

	return true;
}

StackController* StackController::init(GameModel* model,  VMMapManager* vmMapManager)
{
	StackController* p = new StackController();
	p->_model = model;
	//p->_undoManager = undoManager;
	p->_vmMapManager = vmMapManager;
	return p;
}

void StackController::initView(GameView* _gameView) {
	
	this->_stackView = new StackView();
	for (auto cardModel : _model->reserveCards) {
		auto cardView=CardView::createWithCardModel(cardModel);
		this->_stackView->insert(cardView);
		this->_vmMapManager->bindMToV(cardModel,cardView);
		this->_vmMapManager->bindVToM(cardView, cardModel);
		_gameView->addChild(cardView);

		auto listener = EventListenerTouchOneByOne::create();
		listener->onTouchBegan = [this, cardView](Touch* touch, Event* event) {
			Vec2 localPos = cardView->convertToNodeSpace(touch->getLocation());
			Rect rect(0, 0, cardView->getContentSize().width, cardView->getContentSize().height);
			if (rect.containsPoint(localPos)) {
				CCLOG("Clicked specific cardView");
				this->onClick(cardView);
				return true;
			}
			return false;
		};
		listener->setSwallowTouches(true);
		cardView->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,cardView);

	}
	CCLOG("there are %d stackviews",_model->reserveCards.size());
	this->_stackView->playEntranceAnimation();

	auto card=_model->reserveCards.back();
	_model->reserveCards.pop_back();
	_model->stackCards.push(card);
	card->setCurPlace(PlaceBelong::STACK_FILD);
	this->_stackView->playMatchAnimation();
	

	return;
}


void StackController::undo(CardModel* card) {

	this->_model->reserveCards.push_back(card);
	card->setCurPlace(card->getInitPlace());
	this->_stackView->goBack(_vmMapManager->getCardViewWithModel(card));

}