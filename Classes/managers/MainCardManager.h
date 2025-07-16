#pragma once
#include<unordered_map>
#include<CardModel.h>
#include<list>
#include<unordered_set>
#include<CardView.h>
#include<vector>

class MainCardManager {
private:
	std::unordered_map<CardView*, std::list<CardView*>> _graph;
	std::unordered_map<CardView*, int> _indegree;
	std::unordered_set<CardView*> _zeroIndegree;

public:
	static MainCardManager* init(std::vector<CardView*>& gameModel);
	void insert(CardView*);
	bool remove(CardView*);
};