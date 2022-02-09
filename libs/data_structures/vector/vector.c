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
    if (newCapacity){
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
    if (v->data == NULL) {
            fprintf(stderr, "Memory allocation went wrong");
            exit(1);
        }

        v->capacity = newCapacity;
        if (v->size > newCapacity)
            v->size = newCapacity;
        else {
            free(v->data);
            v->data = NULL;
        }
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