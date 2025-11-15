#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/to_do_list.hpp"

TEST_CASE("Add tasks") {
    TodoList list;

    list.add("A");
    list.add("B");

    auto items = list.allList();

    REQUIRE(items.size() == 2);
    REQUIRE(items[0] == "A");
    REQUIRE(items[1] == "B");
}

TEST_CASE("Complete task") {
    TodoList list;

    list.add("A");
    list.add("B");

    REQUIRE(list.complete("B") == true);

    auto c = list.completedList();
    auto i = list.incompleteList();

    REQUIRE(c.size() == 1);
    REQUIRE(c[0] == "B");

    REQUIRE(i.size() == 1);
    REQUIRE(i[0] == "A");
}

TEST_CASE("Complete non-existent") {
    TodoList list;

    list.add("A");

    REQUIRE(list.complete("Z") == false);

    REQUIRE(list.completedList().size() == 0);
    REQUIRE(list.incompleteList().size() == 1);
}

TEST_CASE("Clear works") {
    TodoList list;

    list.add("A");
    list.add("B");

    list.clear();

    REQUIRE(list.allList().size() == 0);
    REQUIRE(list.completedList().size() == 0);
    REQUIRE(list.incompleteList().size() == 0);
}