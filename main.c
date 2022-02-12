#include <assert.h>
#include "libs/data_structures/vector/vector.h"

//------------------------------------ PUSH-BACK TESTING
void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 10);
}

void test_pushBack_notEmptyVector() {
    vector v = createVector(10);
    v.size = 5;
    pushBack(&v, 10);

    assert(v.data[5] == 10);
    assert(v.size == 5 + 1);
    assert(v.capacity == 10);
}

void test_pushBack_fullVector() {
    vector v = createVector(100);
    v.size = 100;
    pushBack(&v, 10);

    assert(v.data[100] == 10);
    assert(v.size == 100 + 1);
    assert(v.capacity == 100 * 2);
    //expanded memory allocation x2
}

//------------------------------------ POP-BACK TESTING
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_popBack_fullVector() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 20);
    pushBack(&v, 30);
    assert(v.size == 3);

    popBack(&v);
    assert(v.size == 2);
    assert(v.capacity == 3);
}

//------------------------------------ FULL TESTING
void test() {
    test_pushBack_emptyVector();
    test_pushBack_notEmptyVector();
    test_pushBack_fullVector();

    test_popBack_notEmptyVector();
    test_popBack_fullVector();
// последующие тесты
}

int main() {
    test();

    return 0;
}
