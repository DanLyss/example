#include "../include/my_vector.hpp"
#include <cstdio>

void copy(int * from, int * to, int how_many){
    for (int i = 0; i < how_many; i++){
        to[i] = from[i];
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

MyVector::MyVector(){
    _size = 0;
    _capacity = 2;
    _data = new int [_capacity];
}

MyVector::MyVector(size_t init_capacity){
    _size = 0;
    _capacity = init_capacity;
    _data = new int [_capacity];
}

MyVector::~MyVector(){
    delete [] _data;
}

void MyVector::set(size_t index, int value){
    if (index >= _size){
        throw "Out of bounds exception";
    }
    _data[index] = value;
}

int MyVector::get(size_t index){
     if (index >= _size){
        throw "Out of bounds exception";
    }
    return _data[index];
}

size_t MyVector::size(){
    return _size;
}

size_t MyVector::capacity(){
    return _capacity;
}

void MyVector::push_back(int value){
    if (_size == _capacity){
        int * temp = new int [_capacity];
        copy(_data, temp, _size);
        delete [] _data;
        _capacity *= 2;
        _data = new int[_capacity];
        copy(temp, _data, _size);
        delete [] temp;
    }
    _data[_size] = value;
    _size ++;
}

void MyVector::insert(size_t index, int value){
    if (index > _size){
        throw "Out of bounds exception";
    }
    if (_size == _capacity){
        this -> reserve(_size * 2);
    }
    for (int i = _size - 1; i >= 0 && (size_t) i >= index; i--){
        _data[i + 1] = _data[i];
    }
    _data[index] = value;
    _size ++;
}

void MyVector::erase(size_t index){
    if (index >= _size){
        throw "Out of bounds exception";
    }
    for (int i = index; (size_t) i < _size - 1; i++){
        _data[i] = _data[i + 1];
    }
    _size --;
}

void MyVector::reserve(size_t new_capacity){
    if (new_capacity > _capacity){
        _capacity = new_capacity;
        int * temp = new int[_size];
        copy(_data, temp, _size);
        delete[] _data;
        _data = new int[_capacity];
        copy(temp, _data, _size);
        delete[] temp;
    }
}

void MyVector::resize(size_t new_size){
    if (new_size > _capacity){
        int new_capacity = max (new_size, 2 * _capacity);
        this -> reserve(new_capacity);
    }
    for (int i = _size; (size_t) i < new_size; i++){
        _data[i] = 0;
    }
    _size = new_size;
}
 
MyVector::MyVector(const MyVector & other){
    this -> reserve (other._capacity);
    this -> _size = other._size;
    copy(other._data, this -> _data, _size);
}

MyVector & MyVector:: operator= (const MyVector & other){
    if (this == &other){
        return *this;
    }
    delete [] this -> _data;
    this -> _size = 0;
    this -> reserve(other._capacity);
    this -> _size = other._size;
    copy(other._data, this -> _data, _size);
    return *this;
}
