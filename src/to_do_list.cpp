#include "to_do_list.hpp"
#include <iostream>

TodoList::TodoList() {}

void TodoList::add(const std::string& taskName) {
    tasks.push_back({taskName, false});
}

bool TodoList::complete(const std::string& taskName) {
    for (auto& t : tasks) {
        if (t.name == taskName) {
            t.done = true;
            return true;
        }
    }
    return false;
}

std::vector<std::string> TodoList::allList() const {
    std::vector<std::string> result;
    for (const auto& t : tasks) result.push_back(t.name);
    return result;
}

std::vector<std::string> TodoList::completedList() const {
    std::vector<std::string> result;
    for (const auto& t : tasks)
        if (t.done) result.push_back(t.name);
    return result;
}

std::vector<std::string> TodoList::incompleteList() const {
    std::vector<std::string> result;
    for (const auto& t : tasks)
        if (!t.done) result.push_back(t.name);
    return result;
}

void TodoList::all() const {
    auto list = allList();
    if (list.empty()) {
        std::cout << "(The list is empty)\n";
        return;
    }
    std::cout << "All tasks:\n";
    for (const auto& task : list)
        std::cout << "- " << task << "\n";
}

void TodoList::completed() const {
    auto list = completedList();
    if (list.empty()) {
        std::cout << "(No completed tasks)\n";
        return;
    }
    std::cout << "Completed tasks:\n";
    for (const auto& task : list)
        std::cout << "- " << task << "\n";
}

void TodoList::incomplete() const {
    auto list = incompleteList();
    if (list.empty()) {
        std::cout << "(No incomplete tasks)\n";
        return;
    }
    std::cout << "Incomplete tasks:\n";
    for (const auto& task : list)
        std::cout << "- " << task << "\n";
}

void TodoList::clear() {
    tasks.clear();
}
