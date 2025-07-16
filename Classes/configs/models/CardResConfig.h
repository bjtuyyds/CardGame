#pragma once
#include<stdexcept>
#include <unordered_map>
#include <string>

// ��ɫ����
enum CardSuitType
{
    CST_NONE = -1,
    CST_CLUBS,      // ÷��
    CST_DIAMONDS,   // ����
    CST_HEARTS,     // ����
    CST_SPADES,     // ����
    CST_NUM_CARD_SUIT_TYPES
};

// ��������
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

    // ��ѯ��Դ·��
    static std::string getSuitPath(CardSuitType type);
    static std::string getBnumPath(CardSuitType suit,CardFaceType type); //��ô����ֵ�·��
    static std::string getSnumPath(CardSuitType suit,CardFaceType type); //���С���ֵ�·��

private:
    static std::unordered_map<CardSuitType, std::string> _suitToRes;
    static std::unordered_map<CardFaceType, std::string> _faceToResBB; //������ֵ�·��ӳ��
    static std::unordered_map<CardFaceType, std::string> _faceToResSB; //С�����ֵ�·��ӳ��
    static std::unordered_map<CardFaceType, std::string> _faceToResBR; //������ֵ�·��ӳ��
    static std::unordered_map<CardFaceType, std::string> _faceToResSR; //С�����ֵ�·��ӳ��

};
