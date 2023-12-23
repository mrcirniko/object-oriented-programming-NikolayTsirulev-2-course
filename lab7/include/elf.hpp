#pragma once

#include "npc.hpp"

class Elf : public NPC {
public:
    Elf(const std::string &name, int x, int y);
    Elf(const std::string &name, std::istream &is);

    void print() override;
    
    bool is_elf() const;

    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Dragon> other) override;

    void save(std::ostream &os) override;

    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Elf &elf);
};