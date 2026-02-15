// COMSC-210 | Lab 6 | Gillian Rhett
#include <iostream>
#include <stdexcept>
#include <limits> // for clearing input after error
using namespace std;

void enterArrayData(double*);
void outputArrayData(double*);
double sumArray(double*);

const int arrSize = 5;

main() {
    double* myArr = new double[arrSize];

    enterArrayData(myArr);
    outputArrayData(myArr);
    cout << "Sum of values: " << sumArray(myArr);

    delete myArr;
    myArr = nullptr;
}

void enterArrayData(double* arr){
// takes a pointer to an array of doubles
//  and appends values entered by user
    cout << "Data entry for the array:" << endl;
    double input;
    bool validInput = false;

    for (int i = 0; i < arrSize; ++i) {
        validInput = false; // needs to be reset for each iteration
        while (!validInput) {
            cout << "  > Element #" << i + 1 << ": ";
            try {
                cin >> input;
                if (cin.fail()) {
                    throw invalid_argument("Error: input needs to be a double.");
                }
                // input was valid so save this value in the array
                validInput = true;
                *(arr + i) = input;
            }
            catch (invalid_argument &e) {
                cout << e.what() << endl; // tell user it needs to be a double
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    cout << "Data entry complete." << endl;
}

void outputArrayData(double* arr) {
// takes a pointer to an array of doubles
//  and displays the elements
    cout << "Outputting array elements: ";
    for (int i = 0; i < arrSize; ++i) {
        cout << *(arr + i) << " ";
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
