//
// Created by Reuven Ostrofsky on 2024-03-19.
//

#include "FighterDirector.h"

#include <utility>

void FighterDirector::setBuilder(FighterBuilder *fb) {
   this->builder = fb;

}

Fighter* FighterDirector::constructFighter() {
    builder->buildAbilityScores();
    builder->buildAbilityModifiers();
    builder->buildStats();
    return builder->getFighter();
}

Fighter* FighterDirector::constructFighter(string name) {
    builder->buildAbilityScores();
    builder->buildAbilityModifiers();
    builder->buildStats();
    builder->buildName(std::move(name));
    return builder->getFighter();
}


