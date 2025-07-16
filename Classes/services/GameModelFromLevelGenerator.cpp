#include "GameModelFromLevelGenerator.h"


void from_json(const json& j, Position& p)
{
    j.at("x").get_to(p.x);
    j.at("y").get_to(p.y);
}

void from_json(const json& j, CardModel& cardModel) {
    j.at("CardFace").get_to(cardModel.getCardFace());
    j.at("CardSuit").get_to(cardModel.getCardSuit());
    j.at("Position").get_to(cardModel.getCardPosition());
}


void GameModelFromLevelGenerator::generateGameModel(GameModel* gameModel,json& j)
{
    std::vector<CardModel> playField = j["Playfield"].get<std::vector<CardModel>>();
    std::vector<CardModel> stack = j["Stack"].get<std::vector<CardModel>>();

    CCLOGERROR("%d %d\n", playField.size(), stack.size());

    for (int i = 0; i < playField.size(); i++) {
        playField[i].setInitPlace(PlaceBelong::MAIN_FILD);
        CardModel* card = new CardModel(playField[i]);
        gameModel->mainCards.push_back(card);
    }

    for (int i = 0; i < stack.size(); i++) {
        stack[i].setInitPlace(PlaceBelong::RESERVE_FILD);
        CardModel* card = new CardModel(stack[i]);
        gameModel->reserveCards.push_back(card);
    }

}
