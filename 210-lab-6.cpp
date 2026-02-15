// COMSC-210 | Lab 6 | Gillian Rhett
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <limits>
using namespace std;

void enterArrayData(double*);
void outputArrayData(double*);
double sumArray(double*);

const int arrSize = 5;

main() {
    double* myArr = new double[arrSize];
    
    enterArrayData(myArr);
    outputArrayData(myArr);
    cout << "Sum of values: " << fixed << setprecision(1) << sumArray(myArr);

    delete myArr;
    myArr = nullptr;
}

void enterArrayData(double* arr){
// takes a pointer to an array of doubles
//  and appends values entered by user
    cout << "Data entry for the array:" << endl;
    bool validInput;
    double input;
    for (int i = 0; i < arrSize; ++i) {
        cout << " > Element #" << i + 1 << ": ";
        validInput = false;
        while (!validInput) {
            try { 
                cin >> input;
                if (cin.fail())
                    throw string("Enter a valid double: "); 
                else
                    validInput = true;
            }
            catch(string error) { 
                cout << error << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max());
            }
        }
        *(arr + i) = input;
    }    
    cout << "Data entry complete." << endl;
}

void outputArrayData(double* arr) {
// takes a pointer to an array of doubles
//  and displays the elements
    cout << "Outputting array elements: ";
    for (int i = 0; i < arrSize; ++i) {
        cout << fixed << setprecision(1) << *(arr + i) << " ";
    }
    cout << endl;
}

double sumArray(double* arr) {
// takes a pointer to an array of doubles
//  and adds them all and returns the sum
    double sum = 0;
    for (int i = 0; i < arrSize; ++i) {
        sum += *(arr + i);
    }
    return sum;
}
