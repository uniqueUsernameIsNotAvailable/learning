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
 * @param n - кол-во значений в векторе
 * @return vector - структуру-дескриптор вектор
 */
vector createVector(size_t n);

/*!
 * Изменяет количество памяти, выделенное под хранение элементов вектора
 * @param v - указатель на вектор
 * @param newCapacity - новое значение памяти под выделение
 */
void reserve(vector *v, size_t newCapacity);

/*!
 * Удаляет элементы из контейнера, но не освобождает выделенную память
 * @param v - указатель на вектор
 */
void clear(vector *v);

/*!
 * Освобождает память, выделенную под неиспользуемые элементы
 * @param v - указатель на вектор
 */
void shrinkToFit(vector *v);

/*!
 * Освобождает память, выделенную вектору
 * @param v - указатель на вектор
 */
void deleteVector(vector *v);

/*!
 * Проверяет, является ли вектор пустым
 * @param v - указатель на вектор
 * @return 0 или 1
 */
_Bool isEmpty(vector *v);

/*!
 * Проверяет, является ли вектор заполненным
 * @param v - указатель на вектор
 * @return 0 или 1
 */
_Bool isFull(vector *v);

/*!
 * Возвращает i-ый элемент вектора v
 * @param v - указатель на вектор
 * @param i - позиция искомого элемента вектора
 */
int getVectorValue(vector *v, size_t i);

/*!
 * Добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает количество выделенной ему памяти в 2 раза
 * @param v - указатель на вектор
 * @param x - добавляемый элемент
 */
void pushBack(vector *v, int x);

/*!
 * Удаляет последний элемент из непустого вектора
 * При пустом векторе завершает работу с ошибкой 1
 * @param v - указатель на вектор
 */
void popBack(vector *v);

/*!
 * Возвращает указатель на index-ый элемент вектора. При попытке получить доступ вне пределов вектора - вывод ошибки
 * @param v - указатель на вектор
 * @param index - позиция искомого элемента вектора
 * @return указатель на заданный элемент вектора
 */
int *atVector(vector *v, size_t index);

/*!
 * Возвращает указатель на последний элемент вектора
 * @param v - указатель на вектор
 * @return последний элемент вектора
 */
int *back(vector *v);

/*!
 * Возвращает указатель на последний элемент вектора
 * @param v - указатель на вектор
 * @return последний элемент вектора
 */
int *front(vector *v);

#endif //LW_5B_VECTOR_H