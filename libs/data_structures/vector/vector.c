#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "vector.h"

vector createVector(size_t n) {
    int *a = (int *) malloc(sizeof(int) * n);
    if (a == NULL) {
        fprintf(stderr, "Memory allocation went wrong");
        exit(1);
    } else
        return (vector) {a, 0, n};
}


void reserve(vector *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "Memory allocation went wrong");
            exit(1);
        }

        v->capacity = newCapacity;

        if (v->size > newCapacity)
            v->size = newCapacity;
    } else {
        free(v->data);
        v->data = NULL;
    }
}


void clear(vector *v) {
    v->size = 0;
}


void shrinkToFit(vector *v) {
    reserve(v, v->size);
}


void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}


_Bool isEmpty(vector *v) {
    return (v->size == 0);
}


_Bool isFull(vector *v) {
    return (v->capacity == v->size);
}


int getVectorValue(vector *v, size_t i) {
    return (v->data[i]);
}


void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);

    v->data[v->size] = x;
    v->size++;
}


void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector has no elements to destroy");
        exit(1);
    }

    v->size--;
}


int *atVector(vector *v, size_t index) {
    if (index >= v->size)
        fprintf(stderr, "IndexError: a[%lld] does not exists", index);
    else
        return (&v->data[index]);
}


int *back(vector *v) {
    return (atVector(v, v->size - 1));
}


int *front(vector *v) {
    return (atVector(v, 0));
}