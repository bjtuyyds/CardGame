#pragma once
#include<stack>
#include"CardModel.h"
#include<vector>
#include<set>

class GameModel {
private:
	//class MainCardsModel {
	//	private:
	//		std::vector<std::list<CardModel*>> _graph;
	//		std::set<CardModel*> _zeroDegreeCards;
	//		std::vector<unsigned int> _indegree;

	//	public:
	//		
	//		void insert(CardModel* cardId);
	//		bool remove(CardModel* cardId);
	//};
	////std::vector<CardModel*> _cards;
public:

	std::stack<CardModel*> stackCards;
	std::vector<CardModel*> reserveCards;
	std::vector<CardModel*>  mainCards;

};

