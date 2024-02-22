//
// Created by Reuven Ostrofsky on 2024-02-21.
//

#include "CharacterTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

void CharacterTest::setUp() {
    //Create a test character
    character = new Character("Test Character", 5);
}

void CharacterTest::tearDown() {
    delete character; // Clean up
    character = nullptr;
}

void CharacterTest::testAddition() {
    int a = 2;
    int b = 3;
    int result = a + b;
    CPPUNIT_ASSERT(result == 5); // This should pass
};
void CharacterTest::testInitialization() {
    // Test initialization of a Character object
    CPPUNIT_ASSERT_EQUAL(std::string("Test Character"), character->getName()); // Check if name is initialized correctly
    CPPUNIT_ASSERT_EQUAL(5, character->getLevel()); // Check if level is initialized correctly
    //make sure ability scores are initialized
    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Strength) > 0);
    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Dexterity) > 0);
    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Constitution) > 0);
    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Intelligence) > 0);
    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Wisdom) > 0);
    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Charisma) > 0);
    //make sure ability modifiers are initialized
    //make sure stats are initialized
    CPPUNIT_ASSERT(character->getStat(Character::Stats::HP) > 0);
    CPPUNIT_ASSERT(character->getStat(Character::Stats::PB) > 0);
    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > 0);
    CPPUNIT_ASSERT(character->getStat(Character::Stats::AB) > 0);
    CPPUNIT_ASSERT(character->getStat(Character::Stats::DB) > 0);
}

void CharacterTest::testArmorEquip() {
    // Test equipping armor
    //create an armor item
    Item armor = Item(Item::ItemType::ARMOR);
    //equip the armor
    //save player AC before
    int acBefore = character->getStat(Character::Stats::AC);
    character->equip(armor);
    //check if the armor is equipped
    CPPUNIT_ASSERT(character->isItemEquipped(armor));
    //check if the armor is affecting the character's stats
    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
    //unequip the armor
    int acAfter = character->getStat(Character::Stats::AC);
    character->unequip(armor);
    //check if the armor is unequipped
    CPPUNIT_ASSERT(!character->isItemEquipped(armor));
    //check if the armor is no longer affecting the character's stats
    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));


}

void CharacterTest::testWeaponEquip() {
    // Test equipping a weapon
    //create a weapon item
    Item weapon = Item(Item::ItemType::WEAPON);
    //equip the weapon
    //save player AB before
    int abBefore = character->getStat(Character::Stats::AB);
    character->equip(weapon);
    //check if the weapon is equipped
    CPPUNIT_ASSERT(character->isItemEquipped(weapon));
    //check if the weapon is affecting the character's stats
    CPPUNIT_ASSERT(character->getStat(Character::Stats::AB) > abBefore);
    //unequip the weapon
    character->unequip(weapon);
    //check if the weapon is unequipped
    CPPUNIT_ASSERT(!character->isItemEquipped(weapon));
    //check if the weapon is no longer affecting the character's stats
    CPPUNIT_ASSERT_EQUAL(abBefore, character->getStat(Character::Stats::AB));

}

void CharacterTest::testHelmetEquip() {
    // Test equipping a helmet
    //create a helmet item
    Item helmet = Item(Item::ItemType::HELMET);
    //equip the helmet
    //save player AC before
    int acBefore = character->getStat(Character::Stats::AC);
    character->equip(helmet);
    //check if the helmet is equipped
    CPPUNIT_ASSERT(character->isItemEquipped(helmet));
    //check if the helmet is affecting the character's stats
    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
    //unequip the helmet
    character->unequip(helmet);
    //check if the helmet is unequipped
    CPPUNIT_ASSERT(!character->isItemEquipped(helmet));
    //check if the helmet is no longer affecting the character's stats
    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));

}

void CharacterTest::testRingEquip() {
    //test equipping a ring
    //create a ring item
    Item ring = Item(Item::ItemType::RING);
    //equip the ring
    //save player AC before
    int acBefore = character->getStat(Character::Stats::AC);
    character->equip(ring);
    //check if the ring is equipped
    CPPUNIT_ASSERT(character->isItemEquipped(ring));
    //check if the ring is affecting the character's stats
    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
    //unequip the ring
    character->unequip(ring);
    //check if the ring is unequipped
    CPPUNIT_ASSERT(!character->isItemEquipped(ring));
    //check if the ring is no longer affecting the character's stats
    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));

}

void CharacterTest::testShieldEquip() {
    //test equipping a shield
    //create a shield item
    Item shield = Item(Item::ItemType::SHIELD);
    //equip the shield
    //save player AC before
    int acBefore = character->getStat(Character::Stats::AC);
    character->equip(shield);
    //check if the shield is equipped
    CPPUNIT_ASSERT(character->isItemEquipped(shield));
    //check if the shield is affecting the character's stats
    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
    //unequip the shield
    character->unequip(shield);
    //check if the shield is unequipped
    CPPUNIT_ASSERT(!character->isItemEquipped(shield));
    //check if the shield is no longer affecting the character's stats
    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));

}

void CharacterTest::testBeltEquip() {

}

void CharacterTest::testBootsEquip() {


}





