#include "src/to_do_list.hpp"
#include <iostream>

int main() {
    TodoList list;

    list.add("Buy milk");
    list.add("Buy eggs");
    list.add("Prepare a lesson for CSC 122");
    list.add("Sow beet seeds");

    list.complete("Buy eggs");

    list.all(); std::cout << std::endl;
    list.completed(); std::cout << std::endl;
    list.incomplete(); std::cout << std::endl;

    list.clear(); std::cout << std::endl;

    list.all(); std::cout << std::endl;

    return 0;
}