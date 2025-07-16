#pragma once
#include<CardView.h>
#include<set>
#include"loaders/LevelConfigLoader.h"


class StackView {
public:
	void playMatchAnimation();
	void goBack(CardView* cardView);
	void insert(CardView* cardView);
	void remove(CardView* cardView);
	void playEntranceAnimation();
private:
	std::vector<CardView*> _stackView;
	Position _targetPos;
};