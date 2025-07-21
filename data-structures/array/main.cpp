#include <iostream>
#include <string>
#include <cassert>
#include "DynamicArray.hpp"

void testPushBack() {
    DynamicArray<int> arr;
    assert(arr.isEmpty());
    assert(arr.size() == 0);

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    assert(arr.size() == 3);
    assert(arr[0] == 10);
    assert(arr[1] == 20);
    assert(arr[2] == 30);
    std::cout << "✅ testPushBack passed\n";
}

void testInsert() {
    DynamicArray<std::string> arr;
    arr.push_back("A");
    arr.push_back("C");

    arr.insert(1, "B"); // Insert in middle
    arr.insert(0, "Start"); // Insert at beginning
    arr.insert(arr.size(), "End"); // Insert at end

    assert(arr.size() == 5);
    assert(arr[0] == "Start");
    assert(arr[1] == "A");
    assert(arr[2] == "B");
    assert(arr[3] == "C");
    assert(arr[4] == "End");

    std::cout << "✅ testInsert passed\n";
}

void testRemove() {
    DynamicArray<int> arr;
    for (int i = 0; i < 5; ++i) arr.push_back(i + 1); // 1 to 5

    arr.remove(0); // remove first
    arr.remove(2); // remove middle
    arr.remove(arr.size() - 1); // remove last

    assert(arr.size() == 2);
    assert(arr[0] == 2);
    assert(arr[1] == 3);

    std::cout << "✅ testRemove passed\n";
}

void testResizeBehavior() {
    DynamicArray<int> arr;
    int lastCapacity = arr.capacity();

    for (int i = 0; i < 100; ++i) {
        arr.push_back(i);
        if (arr.capacity() != lastCapacity) {
            std::cout << "Resized: New Capacity = " << arr.capacity() << '\n';
            lastCapacity = arr.capacity();
        }
    }

    assert(arr.size() == 100);
    for (int i = 0; i < 100; ++i) {
        assert(arr[i] == i);
    }

    std::cout << "✅ testResizeBehavior passed\n";
}

void testConstAccess() {
    DynamicArray<int> arr;
    arr.push_back(42);
    arr.push_back(77);

    const DynamicArray<int>& constRef = arr;

    assert(constRef[0] == 42);
    assert(constRef[1] == 77);
    std::cout << "✅ testConstAccess passed\n";
}

void testIsEmpty() {
    DynamicArray<int> arr;
    assert(arr.isEmpty());
    arr.push_back(1);
    assert(!arr.isEmpty());
    arr.remove(0);
    assert(arr.isEmpty());
    std::cout << "✅ testIsEmpty passed\n";
}

int main() {
    testPushBack();
    testInsert();
    testRemove();
    testResizeBehavior();
    testConstAccess();
    testIsEmpty();

    std::cout << "\n🎉 All tests passed!\n";
    return 0;
}
