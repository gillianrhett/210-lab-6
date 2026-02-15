// COMSC-210 | Lab 6 | Gillian Rhett
#include <iostream>
using namespace std;

void enterArrayData(double*);
void outputArrayData(double*);
double sumArray(double*);

const int arrSize = 5;

main() {
    double* myArr = new double[arrSize];
    
    enterArrayData(myArr);

    delete myArr;
    myArr = nullptr;
}

void enterArrayData(double* arr){
// takes a pointer to an array of doubles
//  and appends values entered by user

    cout << "Data entry for the array:" << endl;
    double input = 0.0;
    for (int i = 0; i < arrSize; ++i) {
        cout << " > Element #" << i + 1 << ": ";
        cin >> *(arr + i);
    }
    
    cout << "\nData entry complete." << endl;
}

void outputArrayData(double* arr) {
// takes a pointer to an array of doubles
//  and displays the elements
    
}

double sumArray(double* arr) {
// takes a pointer to an array of doubles
//  and adds them all and returns the sum

    double sum = 0;

    return sum;
}
