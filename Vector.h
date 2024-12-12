#pragma once
#include <iostream>

template <class T>
class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector(size_t size = 10, size_t startIndex = 0){
        _size = size;
        _startIndex = startIndex;
        _array=new T[size - startIndex];
        for(size_t i = 0; i < size - startIndex; i++){
            _array[i] = 0;
        }
    };
    Vector(const Vector& tmp){
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        _array = new T[_size - _startIndex];
        for (size_t i = 0; i < _size - _startIndex; i++){
            _array[i] = tmp._array[i];
        }
    };

    Vector(Vector&& maved){
        _size = maved._size;
        _startIndex = maved.GetStartIndex();
        _array = maved._array;
        maved._array= nullptr;
    };

    size_t GetSize() const{
        return _size;
    }

    size_t GetStartIndex(){
        return _startIndex;
    }

    T& At(size_t pos){
        if (pos >= _size - _startIndex || pos < _startIndex){
            throw "Nea";
        }
        return _array[pos];
    };

    T& operator[](size_t pos) const{
        return _array[pos - _startIndex];
    };

    Vector& operator=(const Vector& tmp){
        if (this == &tmp) {
            return *this;
        }
        if (_size != tmp._size){
            delete [] _array;
            _array = new T[tmp._size - tmp._startIndex];
        }
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        for (size_t i = 0; i < _size - _startIndex; ++i)
            _array[i] = tmp._array[i];
    return *this;
    };

    Vector operator+ (const T& tmp){
        Vector res(_size, _startIndex);
        for(size_t i = 0; i < _size; i ++){
            res[i] = _array[i] + tmp;
        }
        return res;
    };

    Vector operator- (const T& tmp){
        Vector res(_size, _startIndex);
        for(size_t i = 0; i < _size; i ++){
            res[i] = _array[i] - tmp;
        }
        return res;
    };

    Vector operator* (const T& tmp){
        Vector res(_size, _startIndex);
        for(size_t i = 0; i < _size; i ++){
            res[i] = _array[i] * tmp;
        }
        return res;
    };

    Vector operator+ (const Vector& tmp){
        Vector copy(*this);
        size_t size = copy._size;
        Vector res(size, copy._startIndex);
        if (size != tmp._size || _startIndex != tmp._startIndex){
            throw "Bit out of range!";
        }
        for(size_t i = 0; i < size; i ++){
            res[i] = copy[i] + tmp._array[i];
        }
        return res;
    };

    Vector operator- (const Vector& tmp){
        Vector copy(*this);
        size_t size = copy._size;
        Vector res(size, copy._startIndex);
        if (size != tmp._size || _startIndex != tmp._startIndex){
            throw "Bit out of range!";
        }
        for(size_t i = 0; i < size; i ++){
            res[i] = copy[i] - tmp._array[i];
        }
        return res;
    };

    T operator* (const Vector& tmp){
        size_t res = 0;
        if (_size != tmp._size || _startIndex != tmp._startIndex){
            throw "Bit out of range!";
        }
        for (size_t i = 0; i < _size; i++){
            res += _array[i] * tmp._array[i];
        }
        return res;
    };

    friend std::ostream& operator<<(std::ostream& os, const Vector& tmp){
        os << "(";
        for (size_t i = 0; i < tmp._startIndex; i ++){
            os << "0 ";
        }
        for (size_t i = 0; i < tmp._size - tmp._startIndex; i ++){
            os << tmp._array[i] << " ";
        }
        os << ")";
        os << "\n";
        return os;
    }

    ~Vector(){
        delete [] _array;
    };
};