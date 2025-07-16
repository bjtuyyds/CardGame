#pragma once
#include "GameModel.h"
#include "cocos2d.h"

void from_json(const json& j, Position& p);
void from_json(const json& j, CardModel& cardModel);


class GameModelFromLevelGenerator {
public:

	static void generateGameModel(GameModel* a,json& j);

};