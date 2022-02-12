#include <assert.h>
#include "libs/data_structures/vector/vector.h"

//------------------------------------ SHRINK TESTING
static void test_shrinkToFit_notEmptyVector() {
    vector v = createVector(10);
    pushBack(&v, 0);
    pushBack(&v, 10);

    shrinkToFit(&v);

    assert(v.capacity == 2);
}

void test_shrinkToFit() {
    test_shrinkToFit_notEmptyVector();
}


//------------------------------------ GET VALUE TESTING
static void test_getVectorValue_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 0);
    pushBack(&v, 10);
    pushBack(&v, 20);

    assert(getVectorValue(&v, 1) == 10);
}

void test_getVectorValue() {
    test_getVectorValue_notEmptyVector();
}


//------------------------------------ PUSH-BACK TESTING
static void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 10);
}

static void test_pushBack_notEmptyVector() {
    vector v = createVector(10);
    v.size = 5;
    pushBack(&v, 10);

    assert(v.data[5] == 10);
    assert(v.size == 5 + 1);
    assert(v.capacity == 10);
}

static void test_pushBack_fullVector() {
    vector v = createVector(100);
    v.size = 100;
    pushBack(&v, 10);

    assert(v.data[100] == 10);
    assert(v.size == 100 + 1);
    assert(v.capacity == 100 * 2);
    //expanded memory allocation x2
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_notEmptyVector();
    test_pushBack_fullVector();
}


//------------------------------------ POP-BACK TESTING
static void test_popBack_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

static void test_popBack_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);
    pushBack(&v, 20);
    assert(v.size == 3);

    popBack(&v);
    assert(v.size == 2);
    assert(v.capacity == 3);
}

void test_popBack() {
    test_popBack_oneElementInVector();
    test_popBack_notEmptyVector();
}


//------------------------------------ ACCESS TO ELEMENTS TESTING
//------------------ AT VECTOR TESTING
static void test_atVector_requestToFirstElement() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);
    pushBack(&v, 20);

    int *index = atVector(&v, 0);
    assert(*index == 0);
}

static void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);

    int *index = atVector(&v, 1);
    assert(*index == 10);
}

static void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 0);
    pushBack(&v, 10);
    pushBack(&v, 20);

    int *index = atVector(&v, 2);
    assert(*index == 20);
}

void test_atVector() {
    test_atVector_requestToFirstElement();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}


//------------------ BACK TESTING
static void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);

    assert(*back(&v) == 10);
}

static void test_back_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);

    assert(*back(&v) == 20);
}

void test_back() {
    test_back_oneElementInVector();
    test_back_notEmptyVector();
}


//------------------ FRONT TESTING TESTING
static void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);

    assert(*front(&v) == 10);
}

static void test_front_notEmptyVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    pushBack(&v, 20);

    assert(*front(&v) == 10);
}

void test_front() {
    test_front_oneElementInVector();
    test_front_notEmptyVector();
}


//------------------------------------ FULL TESTING
void test() {
    test_shrinkToFit();
    test_getVectorValue();
    test_pushBack();
    test_popBack();
    test_atVector();
    test_back();
    test_front();

}


int main() {
    test();
    printf("ALL SYSTEMS OPERATIONAL!");

    return 0;
}
