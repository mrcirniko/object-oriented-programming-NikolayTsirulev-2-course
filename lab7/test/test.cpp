#include <gtest/gtest.h>

#include "npc.hpp"
#include "observer.hpp"
#include "elf.hpp"
#include "knight.hpp"
#include "dragon.hpp"

TEST(FightTest1, ElfVsKnight) {
    auto elf = factory(ElfType, "Elf", 0, 0, "log_test.txt");
    auto knight = factory(KnightType, "Knight", 1, 1, "log_test.txt");
    ASSERT_FALSE(elf->accept(knight));
    ASSERT_TRUE(knight->isAlive());
}

TEST(FightTest1, KnightVsDragon) {
    testing::internal::CaptureStdout();
    auto knight = factory(KnightType, "Knight", 0, 0, "log_test.txt");
    auto dragon = factory(DragonType, "Dragon", 1, 1, "log_test.txt");
    ASSERT_TRUE(dragon->accept(knight));
    dragon->mustDie();

    ASSERT_TRUE(knight->isAlive());
    ASSERT_FALSE(dragon->isAlive());
    testing::internal::GetCapturedStdout();
}

TEST(FightTest2, MainFighting) {
    testing::internal::CaptureStdout();
    
    set_t NPCs;
    NPCs.insert(factory(ElfType, "Elf1", 10, 15, "log_test.txt"));
    NPCs.insert(factory(ElfType, "Elf2", 15, 10, "log_test.txt"));
    NPCs.insert(factory(ElfType, "Elf3", 20, 10, "log_test.txt"));
    NPCs.insert(factory(ElfType, "Elf4", 10, 20, "log_test.txt"));
    NPCs.insert(factory(ElfType, "Elf5", 20, 15, "log_test.txt"));
    NPCs.insert(factory(DragonType, "Dragon", 40, 40, "log_test.txt"));

    ASSERT_EQ(6, NPCs.size());

    set_t NPCsKilled;

    for (auto& attacker : NPCs) {
        for (auto& defender : NPCs) {
            if (attacker->isAlive())
                if (defender->isAlive() && (attacker != defender))
                    if (defender->accept(attacker)) {
                        defender->mustDie();
                        NPCsKilled.insert(defender);
                    }
        }
    }
    for (const auto& npc : NPCsKilled) {
        NPCs.erase(npc);
    }

    testing::internal::GetCapturedStdout();
    ASSERT_EQ(1, NPCs.size());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}