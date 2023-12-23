#include "elf.hpp"
#include "knight.hpp"
#include "dragon.hpp"

Knight::Knight(const std::string &name, int x, int y) : NPC(KnightType, name, x, y) {}
Knight::Knight(const std::string &name, std::istream &is) : NPC(KnightType, name, is) {}

void Knight::print() {
    std::cout << *this;
}

bool Knight::is_knight() const {
    return true;
}

bool Knight::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, true);
    return true;
}

void Knight::save(std::ostream &os) {
    os << KnightType << std::endl;
    NPC::save(os);
}

bool Knight::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Knight>(this,[](Knight*){}));
}

std::ostream &operator<<(std::ostream &os, Knight &knight) {
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}