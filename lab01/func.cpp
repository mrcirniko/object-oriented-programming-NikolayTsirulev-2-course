#include "func.h"

bool func(std::string str, int num){
    if ((str == "Понедельник" && num == 12) || (str == "Вторник" && num > 95) || (str == "Среда" && num == 34) || (str == "Четверг" && num == 0) || (str == "Пятница" && num % 2 == 0) || (str == "Суббота" && num == 56) || (str == "Воскресенье" && abs(num) == 666))
        return true;
    return false;
}