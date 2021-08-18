#include <iostream>
#include <Matrix.h>
#include <MatrixCalculator.h>
using namespace std;

int main()
{
    MatrixCalculator mc("Omar");
    int choice;
    bool stop = true;
    while(stop){
        mc.mainMenu();
        cout << "Choice: ";
        cin >> choice;
        mc.makeOperation(choice);
        cout << "Do you want to make another operation?(1=yes, 0=no)\n";
        cin >> stop;
    }//end of while
    return 0;
}
