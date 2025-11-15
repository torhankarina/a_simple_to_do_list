#pragma once
#include <string>
#include <vector>

class TodoList {
private:
    struct Task {
        std::string name;
        bool done;
    };

    std::vector<Task> tasks;

public:
    TodoList();

    void add(const std::string& taskName);
    bool complete(const std::string& taskName);

    std::vector<std::string> allList() const;
    std::vector<std::string> completedList() const;
    std::vector<std::string> incompleteList() const;

    void all() const;
    void completed() const;
    void incomplete() const;

    void clear();
};