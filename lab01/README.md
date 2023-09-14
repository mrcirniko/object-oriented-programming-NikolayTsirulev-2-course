# Отчёт по лабораторной работе №1 по курсу "Объектно-ориентированное программирование"

<b>Студент группы:</b> <ins>М80-208Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

## 1. Тема
Первая программа на C++

## 2. Цель работы
- Изучить систему сборки CMake
- Изучить базовые операторы и конструкции C++
- Изучить библиотеку для написания Unit-тестов Google Test
- Научится писать простые программы, использующие ввод/вывод через потоки std::cin и std::cout

## 3. Задание (вариант № 2)
У меня сумасшедшее психическое заболевание. Я очень не люблю цифры. Но при этом немного запутанно: Число, которого я боюсь, зависит от того, какой сегодня день недели... Вот конкретное описание моей психической болезни:
 Понедельник --> 12
Вторник --> числа больше 95
Среда --> 34
Четверг --> 0
Пятница --> числа, кратные 2
Суббота --> 56
Воскресенье --> 666 или -666
Напишите функцию, которая принимает строку (день недели) и целое число (проверяемое число), чтобы она сообщала врачу, боюсь я или нет. (возвращает булево число)

## 4. Код программы

```:src/task01.cpp
#include <iostream>
#include "func.h"

int main()
{
    std::string str;
    int num;
    std::cout << "enter day of the week:";
    std::cin  >> str;
    std::cout << "enter a number:";
    std::cin  >> num;
    
    std::cout << "result: " << func(str,num) << std::endl;
    
    return 0;
}
```

```:src/func.h
#pragma once

#include <string>
#include <iostream>

bool func(std::string str, int num);
```

```:src/func.cpp
#include "func.h"

bool func(std::string str, int num){
    if ((str == "Понедельник" && num == 12) || (str == "Вторник" && num > 95) || (str == "Среда" && num == 34) || (str == "Четверг" && num == 0) || (str == "Пятница" && num % 2 == 0) || (str == "Суббота" && num == 56) || (str == "Воскресенье" && abs(num) == 666))
        return true;
    return false;
}
```

## 5. Тесты

```:src/tests01.cpp
#include <gtest/gtest.h>
#include "func.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(func("Понедельник",12)==1);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(func("Понедельник",35)==0);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(func("Вторник",96)==1);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(func("Вторник",95)==0);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(func("Среда",34)==1);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(func("Среда",25)==0);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(func("Четверг",0)==1);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(func("Четверг",87)==0);
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(func("Пятница",438)==1);
}

TEST(test_10, basic_test_set)
{
    ASSERT_TRUE(func("Пятница",439)==0);
}

TEST(test_11, basic_test_set)
{
    ASSERT_TRUE(func("Суббота",56)==1);
}

TEST(test_12, basic_test_set)
{
    ASSERT_TRUE(func("Суббота",687)==0);
}

TEST(test_13, basic_test_set)
{
    ASSERT_TRUE(func("Воскресенье",666)==1);
}

TEST(test_14, basic_test_set)
{
    ASSERT_TRUE(func("Воскресенье",-666)==1);
}

TEST(test_15, basic_test_set)
{
    ASSERT_TRUE(func("Воскресенье",456)==0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## 6. Распечатка протокола 

```
hacker@warmachine:~/prog/oop/lab01/build$ cmake --build .
[ 50%] Built target task01
[100%] Built target tests01
hacker@warmachine:~/prog/oop/lab01/build$ ./tests01
[==========] Running 15 tests from 15 test suites.
[----------] Global test environment set-up.
[----------] 1 test from test_01
[ RUN      ] test_01.basic_test_set
[       OK ] test_01.basic_test_set (0 ms)
[----------] 1 test from test_01 (0 ms total)

[----------] 1 test from test_02
[ RUN      ] test_02.basic_test_set
[       OK ] test_02.basic_test_set (0 ms)
[----------] 1 test from test_02 (0 ms total)

[----------] 1 test from test_03
[ RUN      ] test_03.basic_test_set
[       OK ] test_03.basic_test_set (0 ms)
[----------] 1 test from test_03 (0 ms total)

[----------] 1 test from test_04
[ RUN      ] test_04.basic_test_set
[       OK ] test_04.basic_test_set (0 ms)
[----------] 1 test from test_04 (0 ms total)

[----------] 1 test from test_05
[ RUN      ] test_05.basic_test_set
[       OK ] test_05.basic_test_set (0 ms)
[----------] 1 test from test_05 (0 ms total)

[----------] 1 test from test_06
[ RUN      ] test_06.basic_test_set
[       OK ] test_06.basic_test_set (0 ms)
[----------] 1 test from test_06 (0 ms total)

[----------] 1 test from test_07
[ RUN      ] test_07.basic_test_set
[       OK ] test_07.basic_test_set (0 ms)
[----------] 1 test from test_07 (0 ms total)

[----------] 1 test from test_08
[ RUN      ] test_08.basic_test_set
[       OK ] test_08.basic_test_set (0 ms)
[----------] 1 test from test_08 (0 ms total)

[----------] 1 test from test_09
[ RUN      ] test_09.basic_test_set
[       OK ] test_09.basic_test_set (0 ms)
[----------] 1 test from test_09 (0 ms total)

[----------] 1 test from test_10
[ RUN      ] test_10.basic_test_set
[       OK ] test_10.basic_test_set (0 ms)
[----------] 1 test from test_10 (0 ms total)

[----------] 1 test from test_11
[ RUN      ] test_11.basic_test_set
[       OK ] test_11.basic_test_set (0 ms)
[----------] 1 test from test_11 (0 ms total)

[----------] 1 test from test_12
[ RUN      ] test_12.basic_test_set
[       OK ] test_12.basic_test_set (0 ms)
[----------] 1 test from test_12 (0 ms total)

[----------] 1 test from test_13
[ RUN      ] test_13.basic_test_set
[       OK ] test_13.basic_test_set (0 ms)
[----------] 1 test from test_13 (0 ms total)

[----------] 1 test from test_14
[ RUN      ] test_14.basic_test_set
[       OK ] test_14.basic_test_set (0 ms)
[----------] 1 test from test_14 (0 ms total)

[----------] 1 test from test_15
[ RUN      ] test_15.basic_test_set
[       OK ] test_15.basic_test_set (0 ms)
[----------] 1 test from test_15 (0 ms total)

[----------] Global test environment tear-down
[==========] 15 tests from 15 test suites ran. (0 ms total)
[  PASSED  ] 15 tests.
hacker@warmachine:~/prog/oop/lab01/build$
```
