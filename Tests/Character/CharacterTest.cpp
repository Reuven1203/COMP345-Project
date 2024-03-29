/**
 * @file CharacterTest.cpp
 * @brief Implementation of the CharacterTest class methods.
 * @author Reuven Ostrofsky
 * @date 2024-02-21
 */



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
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Strength) > 0);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Dexterity) > 0);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Constitution) > 0);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Intelligence) > 0);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Wisdom) > 0);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Charisma) > 0);
//    //make sure ability modifiers are initialized
//    //make sure stats are initialized
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::HP) > 0);
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::PB) > 0);
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > 0);
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AB) > 0);
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::DB) >= 0);
}

//void CharacterTest::testArmorEquip() {
//    // Test equipping armor
//    //create an armor item
//    Item armor = Item(Item::ItemType::ARMOR);
//    //equip the armor
//    //save player AC before
//    int acBefore = character->getStat(Character::Stats::AC);
//    character->equip(armor);
//    //check if the armor is equipped
//    CPPUNIT_ASSERT(character->isItemEquipped(armor));
//    //check if the armor is affecting the character's stats
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
//    //unequip the armor
//    int acAfter = character->getStat(Character::Stats::AC);
//    character->unequip(armor);
//    //check if the armor is unequipped
//    CPPUNIT_ASSERT(!character->isItemEquipped(armor));
//    //check if the armor is no longer affecting the character's stats
//    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));
//
//
//}
//
//void CharacterTest::testWeaponEquip() {
//    // Test equipping a weapon
//    //create a weapon item
//    Item weapon = Item(Item::ItemType::WEAPON);
//    //equip the weapon
//    //save player AB before
//    int abBefore = character->getStat(Character::Stats::AB);
//    character->equip(weapon);
//    //check if the weapon is equipped
//    CPPUNIT_ASSERT(character->isItemEquipped(weapon));
//    //check if the weapon is affecting the character's stats
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AB) > abBefore);
//    //unequip the weapon
//    character->unequip(weapon);
//    //check if the weapon is unequipped
//    CPPUNIT_ASSERT(!character->isItemEquipped(weapon));
//    //check if the weapon is no longer affecting the character's stats
//    CPPUNIT_ASSERT_EQUAL(abBefore, character->getStat(Character::Stats::AB));
//
//}
//
//void CharacterTest::testHelmetEquip() {
//    // Test equipping a helmet
//    //create a helmet item
//    Item helmet = Item(Item::ItemType::HELMET);
//    //equip the helmet
//    //save player AC before
//    int acBefore = character->getStat(Character::Stats::AC);
//    int intBefore = character->getAbilityScore(Character::Ability::Intelligence);
//    int wisBefore = character->getAbilityScore(Character::Ability::Wisdom);
//    character->equip(helmet);
//    //check if the helmet is equipped
//    CPPUNIT_ASSERT(character->isItemEquipped(helmet));
//    //check if the helmet is affecting the character's stats
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Intelligence) > intBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Wisdom) > wisBefore);
//    //unequip the helmet
//    character->unequip(helmet);
//    //check if the helmet is unequipped
//    CPPUNIT_ASSERT(!character->isItemEquipped(helmet));
//    //check if the helmet is no longer affecting the character's stats
//    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));
//    CPPUNIT_ASSERT_EQUAL(intBefore, character->getAbilityScore(Character::Ability::Intelligence));
//    CPPUNIT_ASSERT_EQUAL(wisBefore, character->getAbilityScore(Character::Ability::Wisdom));
//
//}
//
//void CharacterTest::testRingEquip() {
//    //test equipping a ring
//    //create a ring item
//    Item ring = Item(Item::ItemType::RING);
//    //equip the ring
//    //save player AC before
//    int acBefore = character->getStat(Character::Stats::AC);
//    int charBefore = character->getAbilityScore(Character::Ability::Charisma);
//    int strBefore = character->getAbilityScore(Character::Ability::Strength);
//    int conBefore = character->getAbilityScore(Character::Ability::Constitution);
//    int wisBefore = character->getAbilityScore(Character::Ability::Wisdom);
//    character->equip(ring);
//    //check if the ring is equipped
//    CPPUNIT_ASSERT(character->isItemEquipped(ring));
//    //check if the ring is affecting the character's stats
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Charisma) > charBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Strength) > strBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Constitution) > conBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Wisdom) > wisBefore);
//    //unequip the ring
//    character->unequip(ring);
//    //check if the ring is unequipped
//    CPPUNIT_ASSERT(!character->isItemEquipped(ring));
//    //check if the ring is no longer affecting the character's stats
//    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));
//    CPPUNIT_ASSERT_EQUAL(charBefore, character->getAbilityScore(Character::Ability::Charisma));
//    CPPUNIT_ASSERT_EQUAL(strBefore, character->getAbilityScore(Character::Ability::Strength));
//    CPPUNIT_ASSERT_EQUAL(conBefore, character->getAbilityScore(Character::Ability::Constitution));
//    CPPUNIT_ASSERT_EQUAL(wisBefore, character->getAbilityScore(Character::Ability::Wisdom));
//}
//
//void CharacterTest::testShieldEquip() {
//    //test equipping a shield
//    //create a shield item
//    Item shield = Item(Item::ItemType::SHIELD);
//    //equip the shield
//    //save player AC before
//    int acBefore = character->getStat(Character::Stats::AC);
//    character->equip(shield);
//    //check if the shield is equipped
//    CPPUNIT_ASSERT(character->isItemEquipped(shield));
//    //check if the shield is affecting the character's stats
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
//    //unequip the shield
//    character->unequip(shield);
//    //check if the shield is unequipped
//    CPPUNIT_ASSERT(!character->isItemEquipped(shield));
//    //check if the shield is no longer affecting the character's stats
//    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));
//
//}
//
//void CharacterTest::testBeltEquip() {
//    //test equipping a belt
//    //create a belt item
//    Item belt = Item(Item::ItemType::BELT);
//    //equip the belt
//    //save player AC before
//    int strBefore = character->getAbilityScore(Character::Ability::Strength);
//    int conBefore = character->getAbilityScore(Character::Ability::Constitution);
//    character->equip(belt);
//    //check if the belt is equipped
//    CPPUNIT_ASSERT(character->isItemEquipped(belt));
//    //check if the belt is affecting the character's stats
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Strength) > strBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Constitution) > conBefore);
//    //unequip the belt
//    character->unequip(belt);
//    //check if the belt is unequipped
//    CPPUNIT_ASSERT(!character->isItemEquipped(belt));
//    //check if the belt is no longer affecting the character's stats
//    CPPUNIT_ASSERT_EQUAL(strBefore, character->getAbilityScore(Character::Ability::Strength));
//    CPPUNIT_ASSERT_EQUAL(conBefore, character->getAbilityScore(Character::Ability::Constitution));
//
//}
//
//void CharacterTest::testBootsEquip() {
//    //test equipping boots
//    //create a boots item
//    Item boots = Item(Item::ItemType::BOOTS);
//    //equip the boots
//    //save player AC before
//    int acBefore = character->getStat(Character::Stats::AC);
//    int dexBefore = character->getAbilityScore(Character::Ability::Dexterity);
//    character->equip(boots);
//    //check if the boots are equipped
//    CPPUNIT_ASSERT(character->isItemEquipped(boots));
//    //check if the boots are affecting the character's stats
//    CPPUNIT_ASSERT(character->getStat(Character::Stats::AC) > acBefore);
//    CPPUNIT_ASSERT(character->getAbilityScore(Character::Ability::Dexterity) > dexBefore);
//    //unequip the boots
//    character->unequip(boots);
//    //check if the boots are unequipped
//    CPPUNIT_ASSERT(!character->isItemEquipped(boots));
//    //check if the boots are no longer affecting the character's stats
//    CPPUNIT_ASSERT_EQUAL(acBefore, character->getStat(Character::Stats::AC));
//    CPPUNIT_ASSERT_EQUAL(dexBefore, character->getAbilityScore(Character::Ability::Dexterity));
//}





