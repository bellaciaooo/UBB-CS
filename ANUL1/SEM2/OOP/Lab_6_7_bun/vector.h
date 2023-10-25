#pragma once
#include<iostream>
#include"errors.h"

template<typename Type> class vector;
template<typename Type> std::ostream& operator<<(std::ostream& os, const vector<Type>& vector);

template<typename Type>
class vector
{

private:
    Type* elemente;
    int _size;
    int capacity;

    void resize();
public:
    //default constructor
    vector();
    //copy constructor
    vector(const vector<Type>& v);


    Type& operator[](int index);

    vector<Type>& operator=(const vector<Type>& v);

    vector<Type>& operator+(Type elem);

    vector<Type>& operator+=(Type elem);
    //adauga elemente in vector
    void push_back(Type element);
    //sterge elementeul de pe un index, daca exista
    void remove(int index);
    //lungime vector
    int size()const;
    //destructor
    ~vector();

    friend std::ostream& operator<< <>(std::ostream& os, const vector<Type>& v);

    class Iterator
    {
    private:
        Type* ptr;
    public:

        Iterator(Type* t);

        Iterator operator++();

        Iterator operator++(int);

        Type& operator*();

        bool operator!=(const Iterator& it);

        bool operator==(const Iterator& it);
    };

    Iterator begin()
    {
        return Iterator{ this->elemente };

    }
    Iterator end()
    {
        return Iterator{ this->elemente + this->size() };
    }
};

/*implementare vector*/
template <typename Type>
inline std::ostream& operator<<(std::ostream& os, const vector<Type>& v) {
    for (int i = 0; i < v.size(); i++)
    {
        os << v.elemente[i] << '\n';
    }
    return os;
}

template<typename Type>
void vector<Type>::resize()
{
    Type* temp = new Type[this->capacity * 2];

    for (int i = 0; i < this->size(); i++)
    {
        temp[i] = this->elemente[i];
    }
    delete[] this->elemente;
    this->elemente = temp;
    this->capacity *= 2;
}

template<typename Type>
vector<Type>::vector() {
    this->_size = 0;
    this->capacity = 1;
    this->elemente = new Type[this->capacity];
}

template <typename Type>
vector<Type>::vector(const vector<Type>& v)
{
    this->_size = v.size();
    this->capacity = v.capacity;
    this->elemente = new Type[this->capacity];

    for (int i = 0; i < v.size(); i++)
    {
        this->elemente[i] = v.elemente[i];
    }
}

template<typename Type>
Type& vector<Type>::operator[](int index)
{
    return this->elemente[index];
}

template<typename Type>
vector<Type>& vector<Type>::operator=(const vector<Type>& v)
{
    if (this == &v) {
        return *this;
    }

    this->_size = v._size;
    this->capacity = v.capacity;

    Type* aux = new Type[this->capacity];
    delete[] this->elemente;
    this->elemente = aux;

    for (int i = 0; i < this->size(); i++)
    {
        this->elemente[i] = v.elemente[i];
    }

    return *this;

}

template<typename Type>
inline vector<Type>& vector<Type>::operator+(Type elem)
{
    this->push_back(elem);
    return *this;
}

template<typename Type>
inline vector<Type>& vector<Type>::operator+=(Type elem)
{
    this->push_back(elem);
    return *this;
}

template<typename Type>
void vector<Type>::push_back(Type element) {
    if (this->_size >= this->capacity) {
        this->resize();
    }
    this->elemente[this->_size++] = element;
}

template<typename Type>
void vector<Type>::remove(int index) {
    if (index < 0 || index >= this->size()) {
     //   throw Errors().IndexOut;
    }
    for (int i = index; i < this->size() - 1; i++) {
        this->elemente[i] = this->elemente[i + 1];
    }
    this->_size--;
}

template<typename Type>
int vector<Type>::size()const {
    return this->_size;
}

template<typename Type>
vector<Type>::~vector() {
    delete[] this->elemente;
}

/// implementarea iteratorului vectorului

template<typename Type>
vector<Type>::Iterator::Iterator(Type* ptr) {
    this->ptr = ptr;
}

template<typename Type>
typename vector<Type>::Iterator vector<Type>::Iterator::operator++()
{
    this->ptr++;
    return this->ptr;
}

template<typename Type>
typename vector<Type>::Iterator vector<Type>::Iterator::operator++(int) {
    Type* tempPtr = this->ptr;
    this->ptr++;
    return tempPtr;
}

template<typename Type>
typename Type& vector<Type>::Iterator::operator*() {
    return *this->ptr;
}



template<typename Type>
typename bool vector<Type>::Iterator::operator!=(const vector<Type>::Iterator& it) {
    return this->ptr != it.ptr;
}

template<typename Type>
typename bool vector<Type>::Iterator::operator==(const vector<Type>::Iterator& it) {
    return this->ptr == it.ptr;
}
