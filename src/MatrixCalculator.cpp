#include "MatrixCalculator.h"

#include <Matrix.h>
using namespace std;
MatrixCalculator::MatrixCalculator(string userName){
    this->userName = userName;
}

MatrixCalculator::~MatrixCalculator(){
    //dtor
}

void MatrixCalculator::mainMenu(){
    cout << "Welcome to " << userName << " Matrix Calculator\n";
    cout << "----------------------------------------\n";
    cout << "1- Perform Matrix Addition\n";
    cout << "2- Perform Matrix Subtraction\n";
    cout << "3- Perform Matrix Multiplication\n";
    cout << "4- Matrix Transpose\n";
}

void MatrixCalculator::makeOperation(int& choice){
    Matrix<int> A,B;
    switch(choice){
    case 1:
        A = createMatrix();
        B = createMatrix();
        cout << A << endl;
        cout << B << endl;
        cout << "the result is: \n";
        cout << A+B << endl;
        break;
    case 2:
        A = createMatrix();
        B = createMatrix();
        cout << "the result is: \n";
        cout << A-B << endl;
        break;
    case 3:
        A = createMatrix();
        B = createMatrix();
        if(A.getColumnNumber() == B.getRowNumber()){
            cout << "the result is: \n";
            cout << A*B << endl;
        }else{
            cout << "the two matrices can't be multiplied together\n";
        }
        break;
    case 4:
        A = createMatrix();
        cout << "the result is: \n";
        cout << transpose(A) << endl;
        break;
    default:
        cout << "you entered an invalid choice\n";
    }
}

//test: return by reference
Matrix<int> MatrixCalculator::createMatrix(){
    Matrix<int> A;
    int row, column;
    cout << "what are the dimension of the matrix\n";
    cout << "Rows: ";
    cin >> row;
    cout << "Columns: ";
    cin >> column;
    A.allocateMatrixMemory(row,column);
    cout << "enter the elements of the matrix\n";
    cin >> A;

    return A;
}
