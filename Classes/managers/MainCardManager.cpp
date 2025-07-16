#include<MainCardManager.h>



MainCardManager* MainCardManager::init(std::vector<CardView*>& cards) {
	MainCardManager* mcm = new MainCardManager();
	auto& graph = mcm->_graph;
	auto& indegree = mcm->_indegree;
	auto& zeros = mcm->_zeroIndegree;
	for (auto cardv:cards) {
		auto rec=cardv->getBoundingBox();
		std::vector<CardView*> collect;
		for (auto upCard : zeros) {
			auto rec2 = upCard->getBoundingBox();
			if (rec.intersectsRect(rec2)) {
				graph[cardv].push_back(upCard);
				indegree[upCard]++;
				if (zeros.find(upCard)!=zeros.end()) {
					collect.push_back(upCard);
				}
			}
		}
		for (auto cv : collect) {
			zeros.erase(cv);
		}
		zeros.insert(cardv);
	}

	return mcm;
	
}


void MainCardManager::insert(CardView* cardv) {
	auto& graph = this->_graph;
	auto& indegree = this->_indegree;
	auto& zeros = this->_zeroIndegree;
	auto rec = cardv->getBoundingBox();
	for (auto upCard : zeros) {
		auto rec2 = upCard->getBoundingBox();
		if (rec.intersectsRect(rec2)) {
			graph[cardv].push_back(upCard);
			indegree[upCard]++;
			if (zeros.find(upCard) != zeros.end()) {
				zeros.erase(upCard);
			}
		}
	}
	zeros.insert(cardv);
	

}


bool MainCardManager::remove(CardView* cardv) {
	if (this->_zeroIndegree.find(cardv)== this->_zeroIndegree.end()) {
		return false;
	}
	this->_zeroIndegree.erase(cardv);
	for (auto card : this->_graph[cardv]) {
		_indegree[card]--;
		if (_indegree[card] == 0) {
			_zeroIndegree.insert(card);
		}
	}
	_graph.erase(cardv);
	return true;
}