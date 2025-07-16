#pragma once
#include<cocos2d.h>
#include<string>
#include"json.hpp"
#include<iostream>
#include"CardModel.h"
#include<fstream>
#include<vector>
#include<Utils.h>

using json = nlohmann::json;
void from_json(const json& j, Position& p);
void from_json(const json& j, CardModel& cardModel);

const int width = 1080;
const int stackheight = 580;
const int playFieldheight = 1500;
const Position stackPosition(700,290);
const Position reservePosition(400,290);
const int dis = 100;

class LevelConfigLoader {
public:
	static json loadLevelConfig(int levelId);
	static std::string getConfigPathWithLevelId(int levelId);
	

};