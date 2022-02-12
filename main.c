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
void test_popBack_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);
    pushBack(&v, 20);
    assert(v.size == 3);

    popBack(&v);
    assert(v.size == 2);
    assert(v.capacity == 3);
}

//------------------------------------ ACCESS TO ELEMENTS TESTING
//------------------ AT VECTOR TESTING
void test_atVector_requestToFirstElement() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);
    pushBack(&v, 20);

    int *index = atVector(&v, 0);
    assert(*index == 0);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);

    int *index = atVector(&v, 1);
    assert(*index == 10);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);
    pushBack(&v, 20);

    int *index = atVector(&v, 2);
    assert(*index == 20);
}

//------------------ BACK TESTING
void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);

    assert(*back(&v) == 10);
}

void test_back_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);

    assert(*back(&v) == 20);
}

//------------------ FRONT TESTING TESTING
void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);

    assert(*front(&v) == 10);
}

void test_front_notEmptyVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    pushBack(&v, 20);

    assert(*front(&v) == 10);
}

//------------------------------------ FULL TESTING
void test() {
    test_pushBack_emptyVector();
    test_pushBack_notEmptyVector();
    test_pushBack_fullVector();

    test_popBack_oneElementInVector();
    test_popBack_notEmptyVector();

    test_atVector_requestToFirstElement();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();

    test_back_oneElementInVector();
    test_back_notEmptyVector();

    test_front_oneElementInVector();
    test_front_notEmptyVector();
}


int main() {
    test();
    printf("ALL SYSTEMS OPERATIONAL");

    return 0;
}
