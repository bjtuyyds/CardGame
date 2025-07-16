#pragma once
#include<vector>
#include<CardView.h>
#include<set>
#include<cocos2d.h>
#include"loaders/LevelConfigLoader.h"



class PlayFieldView {
public:

	void playMatchAnimation();
	void gotoPosition(CardView* cardView,int x,int y);
	void insert(CardView* cardView);
	void remove(CardView* cardView);
	void playEntranceAnimation();
	void setMoveView(CardView* cardView);
	std::vector<CardView*> _playFieldView;

private:
	
	Position _targetPos;
	CardView* _needmoveView = nullptr;
	
};