#include <iostream>

struct example {
    int a = 10;
    int b = 20;
    int c = 20;
};

int main(int argc, char** argv) {
    example ex = {10, 20, 30};
    int* p = &ex.a;
    std::cout << p << ':' << *p << std::endl;
    p += 1;
    std::cout << p << ':' << *p << std::endl;
    p += 1;
    std::cout << p << ':' << *p << std::endl;
}