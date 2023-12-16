#pragma once

#include <memory>

class NPC;
class Elf;
class Knight;
class Dragon;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual bool visit(Elf& elf) = 0;
    virtual bool visit(Knight& knight) = 0;
    virtual bool visit(Dragon& dragon) = 0;
};

class NPCVisitor : public Visitor {
public:
    NPCVisitor(std::shared_ptr<NPC> attacker);
    
    bool visit(Elf& elf) override;
    bool visit(Knight& knight) override;
    bool visit(Dragon& dragon) override;

private:
    std::shared_ptr<NPC> attacker_;
};