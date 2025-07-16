#pragma once
#include<stdexcept>
#include <unordered_map>
#include <string>

// 花色类型
enum CardSuitType
{
    CST_NONE = -1,
    CST_CLUBS,      // 梅花
    CST_DIAMONDS,   // 方块
    CST_HEARTS,     // 红桃
    CST_SPADES,     // 黑桃
    CST_NUM_CARD_SUIT_TYPES
};

// 正面类型
enum CardFaceType
{
    CFT_NONE = -1,
    CFT_ACE,
    CFT_TWO,
    CFT_THREE,
    CFT_FOUR,
    CFT_FIVE,
    CFT_SIX,
    CFT_SEVEN,
    CFT_EIGHT,
    CFT_NINE,
    CFT_TEN,
    CFT_JACK,
    CFT_QUEEN,
    CFT_KING,
    CFT_NUM_CARD_FACE_TYPES
};

static std::string CardGeneralPath = "card_general.png";


class CardResConfig {
public:

    static void init();

    // 查询资源路径
    static std::string getSuitPath(CardSuitType type);
    static std::string getBnumPath(CardSuitType suit,CardFaceType type); //获得大数字的路径
    static std::string getSnumPath(CardSuitType suit,CardFaceType type); //获得小数字的路径

private:
    static std::unordered_map<CardSuitType, std::string> _suitToRes;
    static std::unordered_map<CardFaceType, std::string> _faceToResBB; //大黑数字的路径映射
    static std::unordered_map<CardFaceType, std::string> _faceToResSB; //小黑数字的路径映射
    static std::unordered_map<CardFaceType, std::string> _faceToResBR; //大红数字的路径映射
    static std::unordered_map<CardFaceType, std::string> _faceToResSR; //小红数字的路径映射

};
