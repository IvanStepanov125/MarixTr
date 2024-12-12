#include "Vector.h"
#include "Matrix.h"

int main(){
    Vector <int>a(5, 2);
    a[2] = 1;
    a[3] = 2;
    Vector <int>b(5, 2);
    b[2] = 1;
    b[3] = 2; 
    std::cout << a;
    std::cout << b;
    //std::cout << a - b;

    Matrix <int>aM(3);
    aM[0][0] = 1;
    aM[0][1] = 1;
    aM[0][2] = 1;

    
    aM[1][1] = 1;
    aM[1][2] = 1;

   
    aM[2][2] = 1;

    std::cout << aM;
    std::cout << "------------"<< "\n";

    Matrix <int>bM(3);
    bM[0][0] = 1;
    bM[0][1] = 1;
    bM[0][2] = 1;

    
    bM[1][1] = 1;
    bM[1][2] = 1;

   
    bM[2][2] = 1;

    std::cout << bM << "\n";
    std::cout << "------------" << "\n";

    std::cout << aM * bM;
}