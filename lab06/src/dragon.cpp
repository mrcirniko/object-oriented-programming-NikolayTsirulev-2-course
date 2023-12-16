#include "elf.hpp"
#include "knight.hpp"
#include "dragon.hpp"

Dragon::Dragon(const std::string &name, int x, int y) : NPC(DragonType, name, x, y) {}
Dragon::Dragon(const std::string &name, std::istream &is) : NPC(DragonType, name, is) {}

void Dragon::print() {
    std::cout << *this;
}

bool Dragon::is_dragon() const {
    return true;
}

std::string Dragon::getType() const {
    return "Dragon";
}

bool Dragon::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, true);
    return true;
}

bool Dragon::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, true);
    return true;
}

bool Dragon::fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, true);
    return true;
}

void Dragon::save(std::ostream &os) {
    os << DragonType << std::endl;
    NPC::save(os);
}

bool Dragon::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon) {
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}