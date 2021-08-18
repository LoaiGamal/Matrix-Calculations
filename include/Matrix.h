#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
    public:
        Matrix():Matrix{0,0}{}

        Matrix(int rowNumber,int columnNumber){
            allocateMatrixMemory(rowNumber,columnNumber);
        }

        virtual ~Matrix(){
            delete [] matrix;
        }

        ///ALLOCATE MEMORY
        void allocateMatrixMemory(int rowNumber, int columnNumber){
            this->rowNumber = rowNumber;
            this->columnNumber = columnNumber;
            matrix = new T*[rowNumber];
            for(int matrixIndex=0; matrixIndex<rowNumber; matrixIndex++){
                matrix[matrixIndex] = new T[columnNumber];
            }
        }

        ///OVERLOADING OPERATOR>>
        friend istream& operator>>(istream& in, Matrix<T>& source){
            for(int x=0; x<source.rowNumber; x++){
                for(int y=0; y<source.columnNumber; y++){
                    printf("enter element[%d][%d]: ", x, y);
                    in >> source.matrix[x][y];
                }
            }

            return in;
        }

        ///OVERLOADING OPERATOR<<
        friend ostream& operator<<(ostream& out, const Matrix<T>& source){
            for(int x=0; x<source.rowNumber; x++){
                for(int y=0; y<source.columnNumber; y++){
                    out << source.matrix[x][y] << " ";
                }
                out << "\n";
            }

            return out;
        }

        ///OVERLOADING OPERATOR+
        Matrix operator+(const Matrix<T>& source){
            Matrix temp(this->rowNumber, this->columnNumber);
            for(int x=0; x<source.rowNumber; x++){
                for(int y=0; y<source.columnNumber; y++){
                    temp.matrix[x][y] = this->matrix[x][y] + source.matrix[x][y];
                }
            }
            return temp;
        }

        ///OVERLOADING OPERATOR-
        Matrix<T> operator-(const Matrix<T>& source){

            Matrix<T> temp(source.rowNumber, source.columnNumber);
            for(int x=0; x<source.rowNumber; x++){
                for(int y=0; y<source.columnNumber; y++){
                    temp.matrix[x][y] = this->matrix[x][y] - source.matrix[x][y];
                }
            }
            return temp;
        }

        ///OVERLOADING OPERATOR*
        Matrix<T> operator*(const Matrix<T>& source){
            //n x m && m x p
            int n = this->rowNumber;
            int p = source.columnNumber;
            int m = this->columnNumber; // or m = source.rowNumber;
            Matrix<T> temp(n, p);
            for(int i=0; i<n; i++){
                for(int j=0; j<p; j++){
                    int sum = 0;
                    for(int k=0; k<m; k++){
                        sum += matrix[i][k] * source.matrix[k][j];
                    }
                    temp.matrix[i][j] = sum;
                }
            }
            return temp;
        }

        ///OVERLOADING OPERATOR=
        void operator=(const Matrix<T>& rhs){
            this->rowNumber = rhs.rowNumber;
            this->columnNumber = rhs.columnNumber;
            allocateMatrixMemory(rhs.rowNumber, rhs.columnNumber);
            for(int x=0; x<rhs.rowNumber; x++){
                for(int y=0; y<rhs.columnNumber; y++){
                    matrix[x][y] = rhs.matrix[x][y];
                }
            }
        }

        ///TRANSOPSE
        friend Matrix<T> transpose(const Matrix& source){
            Matrix<T> temp(source.columnNumber, source.rowNumber);
            cout << "temp.rowNumber: " << temp.rowNumber << endl;
            cout << "temp.columnNumber: " << temp.columnNumber << endl;
            for(int x=0; x<temp.rowNumber; x++){
                for(int y=0; y<temp.columnNumber; y++){
                    printf("x: %d, y: %d \t", x, y);
                    cout << source.matrix[y][x] << endl;
                    temp.matrix[x][y] = source.matrix[y][x];
                }
            }

            return temp;
        }

        ///GETTERS
        int getColumnNumber(){return columnNumber;}
        int getRowNumber(){return rowNumber;}

    protected:

    private:
        T** matrix;
        int rowNumber, columnNumber;


};

#endif // MATRIX_H
