#include "Vector.h"

template <class T>
class Matrix : public Vector<Vector <T>>{
public:
    Matrix(size_t n) : Vector<Vector <T>>(n){
        for (size_t i = 0; i < n; i ++){
            this->_array[i] = Vector<T>(n, i);
        }
    };

    Matrix(const Matrix& mt)  : Vector<Vector <T>>(mt){};

    Matrix(const Vector<Vector<T>>& mt) :Vector<Vector<T>>(mt){};

    Matrix& operator=(const Matrix& mt){
        return Vector<Vector <T>>::operator=(mt);
    };

    Matrix operator+(const Matrix& mt){
        return Vector<Vector <T>>::operator+(mt);
    };

    Matrix operator-(const Matrix& mt){
        return Vector<Vector <T>>::operator-(mt);
    };

    Matrix Convolution(){
        size_t size = this->GetSize();
        Matrix res(size - 2);
        for (size_t i = 0; i < size - 2; i ++){
            for (size_t j = 0; j < this->_array[i].GetSize() - 1; j ++){
                size_t a = this->_array[i][j], b= this->_array[i][j + 1], c= this->_array[i][j + 2], d= this->_array[i + 1][j + 2], e=this->_array[i + 2][j + 2];
                res[i][j] = a + b + c + d + e;
            }
        }
        return res;
    };

    Matrix operator*(const Matrix& mt){
        if (this->_size != mt.GetSize()){
            throw "Mnogo hochesh'";
        }
        size_t size = this->_size;
        Matrix res(size);
        for (size_t i = 0; i <size; i++){
            for (size_t j = 0; j <size; j++){
                for (size_t k = 0; k < size; k++){
                    if ((k < this->_array[i].GetStartIndex()) || (mt._array[k].GetStartIndex() > j))
                        continue;
                    
                    res[i][j] += this->_array[i][k] * mt._array[k][j];
                }
            }
        }
        return res;
    };

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mt){
        for(size_t i=0; i < mt._size;i++){
            os<<mt[i];
        }
        return os;
    }

};