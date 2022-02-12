#ifndef LW_5B_VECTOR_H
#define LW_5B_VECTOR_H

#include <stdio.h>

typedef struct vector {
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

/*!
 * Проверяет, является ли вектор пустым
 * @param v
 * @return 0 или 1
 */
_Bool isEmpty(vector *v);

/*!
 * Проверяет, является ли вектор заполненным
 * @param v
 * @return 0 или 1
 */
_Bool isFull(vector *v);

/*!
 * Возвращает i-ый элемент вектора v
 * @param v
 * @param i
 */
int getVectorValue(vector *v, size_t i);

/*!
 * Добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает количество выделенной ему памяти в 2 раза
 * @param v
 * @param x
 */
void pushBack(vector *v, int x);

/*!
 * Удаляет последний элемент из непустого вектора
 * При пустом векторе завершает работу с ошибкой 1
 * @param v
 */
void popBack(vector *v);


int *atVector(vector *v, size_t index);


int *back(vector *v);


int *front(vector *v);

#endif //LW_5B_VECTOR_H