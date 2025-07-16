#pragma once
#include<stack>
#include<list>
#include<CardModel.h>


class UndoModel {
public:
	std::stack<CardModel*> _operators;
	static UndoModel* init();
};


