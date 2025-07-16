#include "LevelConfigLoader.h"


std::string LevelConfigLoader::getConfigPathWithLevelId(int levelId)
{
    return "../Classes/configs/models/LevelConfig.json";
}

const cocos2d::Vec2 stackCardPosition(100,100);


json LevelConfigLoader::loadLevelConfig(int levelId)
{
    std::string filePath= getConfigPathWithLevelId(levelId);
    std::ifstream file(filePath); // 
    if (!file) {
        CCLOG("cant't open file ");
        exit(0);
    }
    json j;
    file >> j;
    return j;

}
