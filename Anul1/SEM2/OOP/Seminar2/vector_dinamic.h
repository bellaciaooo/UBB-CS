#pragma once
typedef void* TElement;

typedef void (*TElementDestroyFn)(TElement);

typedef struct {
	TElement* elements;
	int capacity;
	int size;
	TElementDestroyFn destroyElement;
}DynamicVector;

DynamicVector* createVector(TElementDestroyFn destroyElem);

void destroyVector(DynamicVector* vector);

void addElement(DynamicVector* vector,TElement element);

void deleteElement(DynamicVector* vector,TElement element);

void testLifeCycle();

void testAdd();







