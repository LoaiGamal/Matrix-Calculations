#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include <string>
#include <Matrix.h>
using namespace std;

class MatrixCalculator
{
    public:
        MatrixCalculator(string);
        virtual ~MatrixCalculator();
        void mainMenu();
        void makeOperation(int&);
        Matrix<int> createMatrix();

    protected:

    private:
        string userName;
};

#endif // MATRIXCALCULATOR_H
