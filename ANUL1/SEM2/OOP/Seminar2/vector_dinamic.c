#include "vector_dinamic.h"
#include<malloc.h>
#include<assert.h>
#define CAPACITY 2

DynamicVector* createVector(TElementDestroyFn destroyElem)
{
	DynamicVector* vector = (DynamicVector*)malloc(sizeof(DynamicVector));
	if (vector == NULL) {
		return NULL;
	}
	vector->size = 0;
	vector->capacity = CAPACITY;
	vector->elements = (TElement*)malloc(sizeof(TElement) * CAPACITY);
	vector->destroyElement = destroyElem;
	return vector;
}

void destroyVector(DynamicVector* vector)
{
	for (int i = 0; i < vector->size; i++) {
		vector->destroyElement(vector->elements[i]);
	}
	free(vector->elements);
	free(vector);
}

void addElement(DynamicVector* vector,TElement element)
{
	if (vector->size == vector->capacity) {
		resize(vector);
	}
	vector->elements[vector->size++] = element;
}

void resize(DynamicVector* vector) {
	int new_capacity = vector->capacity * 2;
	TElement* new_elements = (TElement*)malloc(sizeof(TElement) * new_capacity);
	if (new_elements == NULL) {
		return;
	}
	for (int i = 0; i < vector->size; i++) {
		new_elements[i] = vector->elements[i];
	}
	free(vector->elements);
	vector->elements = new_elements;
	vector->capacity = new_capacity;
}

void deleteElement(DynamicVector* vector,TElement element)
{
}

void mockDestroy(TElement element) {
	//TODO
}

void testLifeCycle()
{
	DynamicVector* vector = createVector(mockDestroy);
	assert(vector->capacity==CAPACITY);
	assert(vector->size==0);
	destroyVector(vector);
}


void testAdd() {

}
