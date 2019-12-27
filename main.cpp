#include <iostream>
#include <stdlib.h>
#include "MatrixOperations.h"

using namespace std;

int n, A[100][100], B[100][100], C[100][100];

void showMenu(){
    // var selection is used for saving user input
    int selection;

    cout << "What are you going to do?(enter corresponding number):" << endl;
    cout << "1.Inputing matrixes" << endl;
    cout << "2.Displaying matrixes" << endl;
    cout << "3.Sum matrixes A and B" << endl;
    cout << "4.Multiple matrixes A and B" << endl;
    cout << "5.Search in matrix A" << endl;
    cout << "6.Search in matrix B" << endl;
    cout << "7.Sort columns of matrix A" << endl;
    cout << "8.Sort columns of matrix B" << endl;
    cout << "9.Show median of matrix A rows" << endl;
    cout << "10.Show median of matrix B rows" << endl;

    cout << "11.Show Transpose of matrix A" << endl;
    cout << "12.Show Transpose of matrix B" << endl;
    cout << "13.Show sum of elements if matrix A was upper triangular" << endl;
    cout << "14.Show sum of elements if matrix B was upper triangular" << endl;
    cout << "15.Exit" << endl << endl;

    cin >> selection;
    cout << endl;
    switch(selection){
        case 1:
            cout << "Enter array length: ";
            cin >> n;
            input(A,n);
            input(B,n);
            break;
        case 2:
            cout << "Matrix A :" << endl;
            display(A,n,n);
            cout << endl << "Matrix B :" << endl;
            display(B,n,n);
            break;
        case 3:
            sumMatrix(A,B,C,n,n);
            cout << "A + B is :" << endl;
            display(C,n,n);
            break;
        case 4:
            mulMatrix(A,B,C,n,n,n);
            cout << "A * B is :" << endl;
            display(C,n,n);
            break;
        case 5:
            searchMatrix(A,n,n,'A');
            break;
        case 6:
            searchMatrix(B,n,n,'B');
            break;
        case 7:
            sortColMatrix(A,C,n,n);
            cout << "Column sorted form of A : " << endl;
            display(C,n,n);
            break;
        case 8:
            sortColMatrix(B,C,n,n);
            cout << "Column sorted form of B : " << endl;
            display(C,n,n);
            break;
        case 9:
            cout << "Matrix A medians:" << endl;
            medianRowMatrix(A,n,n);
            break;
        case 10:
            cout << "Matrix B medians:" << endl;
            medianRowMatrix(B,n,n);
            cout << endl;
            break;
        case 11:
            transposeMatrix(A,C,n,n);
            cout << "Transpose of matrixs A is " << endl;
            display(C,n,n);
            break;
        case 12:
            transposeMatrix(B,C,n,n);
            cout << "Trnaspose of matrix B is " << endl;
            display(C,n,n);
            break;
        case 13:
            printSumOfUpperTriangularMatrix(A,n,n,'A');
            break;
        case 14:
            printSumOfUpperTriangularMatrix(B,n,n,'B');
            break;
        case 15:
            exit(0);
            break;
        default:
            cout << "Please input a valid number!" << endl;

    }

    cout << endl << endl;
    showMenu();
}

int main()
{
    showMenu();
    return 0;
}
