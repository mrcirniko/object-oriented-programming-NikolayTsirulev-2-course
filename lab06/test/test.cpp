#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

#include "npc.hpp"
#include "visitor.hpp"
#include "factory.hpp"
#include "elf.hpp"
#include "knight.hpp"
#include "dragon.hpp"

TEST(FightTest1, Fighting) {
    Elf elf("Elf", 10, 40);
    Knight knight("Knight", 5, 5);
    Dragon dragon("Dragon", 0, 50);

    EXPECT_TRUE(dragon.fight(std::make_shared<Elf>(elf)));
    EXPECT_TRUE(dragon.fight(std::make_shared<Knight>(knight)));
    EXPECT_TRUE(dragon.fight(std::make_shared<Dragon>(dragon)));
    EXPECT_FALSE(knight.fight(std::make_shared<Elf>(elf)));
    EXPECT_TRUE(knight.fight(std::make_shared<Dragon>(dragon)));
    EXPECT_FALSE(knight.fight(std::make_shared<Knight>(knight)));
    EXPECT_TRUE(elf.fight(std::make_shared<Knight>(knight)));
    EXPECT_FALSE(elf.fight(std::make_shared<Elf>(elf)));
    EXPECT_FALSE(elf.fight(std::make_shared<Dragon>(dragon)));
}

TEST(FightTest2, MainFighting) {
    std::ofstream file1("log.txt", std::ios::trunc);
    file1.close();
    testing::internal::CaptureStdout();
    set_t array;

    array.insert(factory(ElfType, "Elf1", 0, 50, "log.txt"));
    
    array.insert(factory(KnightType, "Knight1", 0, 50, "log.txt"));

    auto dead_list = fight(array, 20);
    for (auto &d : dead_list) {
        array.erase(d);
    }
    array.insert(factory(DragonType, "Dragon1", 10, 40, "log.txt"));

    dead_list = fight(array, 20);
    for (auto &d : dead_list) {
        array.erase(d);
    }
    std::string expectedOutput [] {
        "",
        "Murder: --------",
        "Elf Elf1 {0, 50} ",
        "Knight Knight1 {0, 50} ", 
        "Elf Elf1 killed Knight Knight1",
        "",
        "Murder: --------",
        "Dragon Dragon1 {10, 40} ", 
        "Elf Elf1 {0, 50} ", 
        "Dragon Dragon1 killed Elf Elf1",
        ""
    };
    std::ifstream file("log.txt");
    std::string line;
    
    for (auto &i : expectedOutput) {
        std::getline(file, line);
        EXPECT_EQ(i, line);
    } 

    testing::internal::GetCapturedStdout();

    EXPECT_EQ(array.size(), 1);
}

TEST(FightTest3, MainFighting) {
    testing::internal::CaptureStdout();
    
    set_t array;

    array.insert(factory(ElfType, "Elf1", 0, 50, "log.txt"));
    array.insert(factory(KnightType, "Knight1", 5, 5, "log.txt")); 
    array.insert(factory(DragonType, "Dragon1", 10, 40, "log.txt"));

    array.insert(factory(ElfType, "Elf2", 60, 90, "log.txt"));
    array.insert(factory(KnightType, "Knight2", 25, 35, "log.txt"));
    array.insert(factory(DragonType, "Dragon2", 0, 2, "log.txt"));

    array.insert(factory(ElfType, "Elf3", 20, 100, "log.txt"));
    array.insert(factory(KnightType, "Knight3", 40, 50, "log.txt"));
    array.insert(factory(DragonType, "Dragon3", 80, 90, "log.txt"));

    auto dead_list = fight(array, 20);
    for (auto &d : dead_list)
        array.erase(d);

    testing::internal::GetCapturedStdout();

    EXPECT_EQ(array.size(), 3);
}

TEST(VisitorTest, Visitor) {
    auto elf = std::make_shared<Elf>("Elf", 0, 5);
    auto knight = std::make_shared<Knight>("Knight", 10, 20);
    auto dragon = std::make_shared<Dragon>("Dragon", 5, 10);

    auto npcVisitor = std::make_shared<NPCVisitor>(elf);

    EXPECT_FALSE(elf->accept(*npcVisitor));
    EXPECT_TRUE(knight->accept(*npcVisitor));
    EXPECT_FALSE(dragon->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(knight);

    EXPECT_FALSE(elf->accept(*npcVisitor));
    EXPECT_FALSE(knight->accept(*npcVisitor));
    EXPECT_TRUE(dragon->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(dragon);

    EXPECT_TRUE(elf->accept(*npcVisitor));
    EXPECT_TRUE(knight->accept(*npcVisitor));
    EXPECT_TRUE(dragon->accept(*npcVisitor));
}

TEST(ObserverTest, Observer) {
    auto dragon = std::make_shared<Dragon>("Dragon", 0, 5);
    auto knight = std::make_shared<Knight>("Knight", 5, 10);
    
    testing::internal::CaptureStdout();

    auto textObserver = std::make_shared<TextObserver>();
    dragon->subscribe(textObserver);
    dragon->fight(knight);

    std::string textOutput = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "\nMurder: --------\ndragon: Dragon {0, 5} \nknight: Knight {5, 10} \nDragon killed Knight\n";

    EXPECT_EQ(textOutput, expectedOutput);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}