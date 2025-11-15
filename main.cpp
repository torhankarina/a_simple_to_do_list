#include "src/to_do_list.hpp"
#include <iostream>
using namespace std;

int main() {
    TodoList list;

    list.add("Buy milk");
    list.add("Buy eggs");
    list.add("Prepare a lesson for CSC 122");
    list.add("Sow beet seeds");

    list.complete("Buy eggs");

    list.all(); cout << endl;
    list.completed(); cout << endl;
    list.incomplete(); cout << endl;

    list.clear(); cout << endl;

    list.all(); cout << endl;

    return 0;
}