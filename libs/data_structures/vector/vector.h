#ifndef LW_5B_VECTOR_H
#define LW_5B_VECTOR_H

#include <stdio.h>

typedef struct vector{
    int *data;
    size_t size;
    size_t capacity;
} vector;


/*!
 * Возвращает структуру-дескриптор вектор из n значений
 * @param n
 * @return vector
 */
vector createVector(size_t n);

/*!
 * Изменяет количество памяти, выделенное под хранение элементов вектора
 * @param v
 * @param newCapacity
 */
void reserve(vector *v, size_t newCapacity);

/*!
 * Удаляет элементы из контейнера, но не освобождает выделенную память
 * @param v
 */
void clear(vector *v);

/*!
 * Освобождает память, выделенную под неиспользуемые элементы
 * @param v
 */
void shrinkToFit(vector *v);

/*!
 * Освобождает память, выделенную вектору
 * @param v
 */
void deleteVector(vector *v);


_Bool isEmpty(vector *v);


_Bool isFull(vector *v);


int getVectorValue(vector *v, size_t i);


void pushBack(vector *v, int x);


void popBack(vector *v);


int* atVector(vector *v, size_t index);


int* back(vector *v);


int* front(vector *v);

#endif //LW_5B_VECTOR_H