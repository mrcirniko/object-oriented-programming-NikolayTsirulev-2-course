#pragma once

#include "npc.hpp"
#include "visitor.hpp"

class Knight : public NPC {
public:
    Knight(const std::string &name, int x, int y);
    Knight(const std::string &name, std::istream &is);

    void print() override;
    
    bool is_knight() const;

    std::string getType() const override;
    
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Dragon> other) override;

    void save(std::ostream &os) override;

    bool accept(Visitor &visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};