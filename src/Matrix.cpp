//#include "Matrix.h"
//
//#include <iostream>
//using namespace std;
//
//template <typename T>
//Matrix<T>::Matrix(int rowNumber,int columnNumber){
//    this->rowNumber = rowNumber;
//    this->columnNumber = columnNumber;
//    matrix = new T*[rowNumber];
//    for(int matrixIndex=0; matrixIndex<rowNumber; matrixIndex++){
//        matrix[matrixIndex] = new T[columnNumber];
//    }
//}
//
//template <typename T>
//Matrix<T>::Matrix()
//:rowNumber{0}, columnNumber{0}{
//}
//
//template <typename T>
//Matrix<T>::~Matrix(){
//    delete [] matrix;
//}
//
//template <typename T>
//istream& operator>>(istream& in, Matrix<T>& source){
//    for(int x=0; x<source.rowNumber; x++){
//        for(int y=0; y<source.columnNumber; y++){
//            printf("enter element[%d][%d]: ", x, y);
//            in >> source.matrix[x][y];
//        }
//    }
//
//    return in;
//}
//
//template <typename T>
//ostream& operator<<(ostream& out, const Matrix<T>& source){
//    for(int x=0; x<source.rowNumber; x++){
//        for(int y=0; y<source.columnNumber; y++){
//            out << source.matrix[x][y] << " ";
//        }
//        out << "\n";
//    }
//
//    return out;
//}
