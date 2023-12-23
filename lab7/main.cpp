#include "observer.hpp"
#include "npc.hpp"

#include <thread>
#include <chrono>
#include <queue>
#include <optional>
#include <array>
#include <sstream>

using namespace std::chrono_literals;
std::mutex print_mutex;

struct print : std::stringstream {
    ~print() {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};

struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager {
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;
    FightManager() {}
public:
    static FightManager &get() {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event) {
        std::lock_guard<std::shared_mutex> lck(mtx);
        events.push(event);
    }

    void operator()() {
        while (true) {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lck(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }
                if (event) {
                    if (event->attacker->isAlive())
                        if (event->defender->isAlive()) 
                            if (event->defender->accept(event->attacker)) {
                                event->defender->mustDie();
                            }
                } else
                    std::this_thread::sleep_for(1s);
            }
        }
    }
};

class GameSimulation {
private:
    static const int MAX_X = 20;
    static const int MAX_Y = 20;
    static const int NUM_NPC = 20;
    static const int MOVE_DISTANCE_ELF = 10;
    static const int MOVE_DISTANCE_KNIGHT = 30;
    static const int MOVE_DISTANCE_DRAGON = 50;
    static const int KILL_DISTANCE_ELF = 50;
    static const int KILL_DISTANCE_KNIGHT = 10;
    static const int KILL_DISTANCE_DRAGON = 30;

    set_t array;
    set_t survivors;

public:
    void generateNPCs() {
        std::cout << "Generating ..." << std::endl;
        std::string NameArray[50];

        std::srand(time(NULL));

        for (int i = 0; i < 50; ++i) {
            char randomLetter = 'A' + std::rand() % 26; 
            NameArray[i] = randomLetter + std::to_string(i);
        }
        for (size_t i = 0; i < 50; ++i) {
            array.insert(factory(NpcType(std::rand() % 3 + 1), NameArray[i], std::rand() % MAX_X, std::rand() % MAX_Y, "log.txt"));
        }

        save(array, "log.txt");
        std::cout << "Starting list:" << std::endl << array;
    }

    void moveNPCs() {
        while (true) {
            for (std::shared_ptr<NPC> npc : array) {
                if (npc->isAlive()) {
                    int shift_x = 0, shift_y = 0;
                    switch (npc->getType()) {
                        case ElfType:
                            shift_x = std::rand() % (2 * MOVE_DISTANCE_ELF + 1) - MOVE_DISTANCE_ELF;
                            shift_y = std::rand() % (2 * MOVE_DISTANCE_ELF + 1) - MOVE_DISTANCE_ELF;
                            break;
                        case KnightType:
                            shift_x = std::rand() % (2 * MOVE_DISTANCE_KNIGHT + 1) - MOVE_DISTANCE_KNIGHT;
                            shift_y = std::rand() % (2 * MOVE_DISTANCE_KNIGHT + 1) - MOVE_DISTANCE_KNIGHT;
                            break;
                        case DragonType:
                            shift_x = std::rand() % (2 * MOVE_DISTANCE_DRAGON + 1) - MOVE_DISTANCE_DRAGON;
                            shift_y = std::rand() % (2 * MOVE_DISTANCE_DRAGON + 1) - MOVE_DISTANCE_DRAGON;
                            break;
                    }
                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }

            for (std::shared_ptr<NPC> npc : array)
                for (std::shared_ptr<NPC> other : array)
                    if (other != npc) {
                        if (npc->isAlive() && other->isAlive()) {
                            int kill_distance = 0;
                            switch (npc->getType()) {
                                case ElfType:
                                    kill_distance = KILL_DISTANCE_ELF;
                                    break;
                                case KnightType:
                                    kill_distance = KILL_DISTANCE_KNIGHT;
                                    break;
                                case DragonType:
                                    kill_distance = KILL_DISTANCE_DRAGON;
                                    break;
                            }

                            int attack_strength = std::rand() % 6 + 1;
                            int defense_strength = std::rand() % 6 + 1;

                            if (attack_strength > defense_strength) {
                                FightManager::get().add_event({npc, other});
                            }
                        }
                    }

            std::this_thread::sleep_for(100ms);
        }
    }

    void printSurvivors() {
        auto start_time = std::chrono::steady_clock::now();
        while (true) {
            auto current_time = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() == 30) {
                std::cout << "Survivors after 30 seconds:\n";
                for (const auto& npc : array) {
                    if (npc->isAlive()) {
                        survivors.insert(npc);
                        npc->print();
                    }
                }
                std::cout << "Done" << std::endl;
                exit(0);
            }

            const int step_x = MAX_X / NUM_NPC, step_y = MAX_Y / NUM_NPC;
            {
                std::array<char, NUM_NPC * NUM_NPC> fields{0};
                for (std::shared_ptr<NPC> npc : array) {
                    auto [x, y] = npc->position();
                    int i = x / step_x;
                    int j = y / step_y;

                    if (npc->isAlive()) {
                        switch (npc->getType()) {
                            case ElfType:
                                fields[i + NUM_NPC * j] = 'E';
                                break;
                            case KnightType:
                                fields[i + NUM_NPC * j] = 'K';
                                break;
                            case DragonType:
                                fields[i + NUM_NPC * j] = 'D';
                                break;
                        }
                    } else
                        fields[i + NUM_NPC * j] = 'X';
                }

                std::lock_guard<std::mutex> lck(print_mutex);
                for (int j = 0; j < NUM_NPC; ++j) {
                    for (int i = 0; i < NUM_NPC; ++i) {
                        char c = fields[i + j * NUM_NPC];
                        if (c != 0)
                            std::cout << '[' << c << ']';
                        else
                            std::cout << "[ ]";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
            std::this_thread::sleep_for(1s);
        }
    }
};

int main() {
    GameSimulation game;

    std::thread fight_thread(std::ref(FightManager::get()));
    std::thread move_thread([&game]() { game.moveNPCs(); });
    game.generateNPCs();
    game.printSurvivors();

    move_thread.join();
    fight_thread.join();

    return 0;
}