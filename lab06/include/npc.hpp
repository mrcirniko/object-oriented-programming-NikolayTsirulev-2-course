#pragma once

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
#include <random>
#include <memory>
#include <time.h>
#include "observer.hpp"

class NPC;
class Elf;
class Knight;
class Dragon;
class Visitor;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType {
    Unknown = 0,
    ElfType = 1,
    KnightType = 2,
    DragonType = 3
};

class NPC: public std::enable_shared_from_this<NPC> {
private:
    NpcType type;
    int x{0};
    int y{0};
    std::string name;
public:
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, const std::string &_name, int _x, int _y);
    NPC(NpcType t, const std::string &_name, std::istream &is);
    
    const std::string& getName() const;
    virtual std::string getType() const = 0;
    
    void subscribe(std::shared_ptr<IFightObserver> observer);
    void fight_notify(const std::shared_ptr<NPC> defender, bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool fight(std::shared_ptr<Elf> other) = 0;
    virtual bool fight(std::shared_ptr<Knight> other) = 0;
    virtual bool fight(std::shared_ptr<Dragon> other) = 0;

    virtual void print() = 0;
    
    virtual void save(std::ostream &os);

    virtual bool accept(Visitor &visitor) = 0;

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    ~NPC() = default;
};