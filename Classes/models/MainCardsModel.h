#pragma once
#include<MainCardsModel.h>
#include<vector>
#include<list>
#include<set>
#include"CardModel.h"



class MainCardModel {
private:
	std::vector<std::list<CardModel::CardId>> _graph;
	std::set<CardModel::CardId> _zeroDegreeCards; 
	std::vector<unsigned int> _indegree;

public:
	void insert(CardModel::CardId cardId);
	bool remove(CardModel::CardId cardId);


};