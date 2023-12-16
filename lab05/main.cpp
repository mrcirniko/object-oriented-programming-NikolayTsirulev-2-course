#include "allocator.hpp"
#include "stack.hpp"

int main(int argc, char **argv)
{
    std::map<int, int, std::less<int>,Allocator<std::pair<int,int>, 3> > my_map;

    my_map[1]=10;
    my_map[2]=20;
    my_map[3]=30;
    std::cout <<"Map:" << std::endl;
    for(const auto& pair: my_map) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    Stack<int, Allocator<int, 10>> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(34);
    stack.pop();
    std::cout <<"Stack:" << std::endl;
    for (const auto &i : stack) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}