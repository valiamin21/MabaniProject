#include <iostream>
using namespace std;
#include "RandomGenerate.h"

// This function assigns array b to a
void arrAssignment(int a[][100], int b[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = b[i][j];
        }
    }
}

// putting some random numbers between 0 and 8 in arr
void input(int arr[][100],int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = getRandom(0,8);
        }
    }
}

// prints arr in output with rows and columns
void display(int arr[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// calculates sum of arrays a and b and puts the result in c
void sumMatrix(int a[][100], int b[][100], int c[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// multiplies arrays a and b and puts the result in c
void mulMatrix(int a[][100], int b[][100], int c[][100], int n, int m, int p){
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < p; j++){
            sum = 0;
            for(int k = 0; k < m; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
        cout << endl;
    }
}

// getting a key from user and searchs it in arr
void searchMatrix(int arr[][100], int n, int m, char matrixName){
    int key;
    cout << "Please enter a key for searching in matrix " << matrixName << ": ";
    cin >> key;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == key){
                cout << key << " exists in the matrix " << matrixName;
                return;
            }
        }
    }

    cout << key << " doesn't exist in the matrix " << matrixName;
}

// sorts arr according to columns and puts the result in res
void sortColMatrix(int arr[][100], int res[][100], int n, int m){
    arrAssignment(res,arr,n,m);
    for(int j = 0; j < m; j++){
        for(int pass = 0; pass < n; pass++){
            for(int i = 0; i < n-1; i++){
                if(res[i][j] > res[i+1][j]){
                    int temp = res[i][j];
                    res[i][j] = res[i+1][j];
                    res[i+1][j] = temp;
                }
            }
        }
    }
}

// sorts arr according to rows and puts the result in res
void sortRowMatrix(int arr[][100], int res[][100], int n, int m){
    arrAssignment(res,arr,n,m);
    for(int i = 0; i < n; i++){
        for(int pass = 0; pass < m; pass++){
            for(int j = 0; j < m - 1; j++){
                if(res[i][j] > res[i][j+1]){
                    int temp = res[i][j];
                    res[i][j] = res[i][j+1];
                    res[i][j+1] = temp;
                }
            }
        }
    }
}

// first sorts arr according to rows then prints median of each row in output
void medianRowMatrix(int arr[][100], int n, int m){
    int sortedArr[100][100];
    sortRowMatrix(arr,sortedArr,n,m);
    for(int i = 0; i < n; i++){
        float median;
        if(m % 2 == 1){
            median = sortedArr[i][m / 2];
        }else{
            median = (sortedArr[i][m / 2 - 1] + sortedArr[i][m / 2]) / 2.0;
        }

        cout << "median of row " << i << " is " << median << endl;
    }
}

// first sorts arr according to columns then prints median of each column in output
void transposeMatrix(int arr[][100], int res[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res[j][i] = arr[i][j];
        }
    }
}

// checks if arr is upper triangular or not
bool isUpperTriangularMatrix(int arr[][100], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i][j] != 0){
                return false;
            }
        }
    }

    return true;
}

// returns sum of all elements in arr
int sumMatrixElements(int arr[][100], int n, int m){
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += arr[i][j];
        }
    }

    return sum;
}

// prints sum of arr elements if arr was upper triangular
void printSumOfUpperTriangularMatrix(int arr[][100], int n, int m, char matrixName){
    if(isUpperTriangularMatrix(arr,n,m)){
        cout << "Sum of matrix " << matrixName << "  elements = " << sumMatrixElements(arr,n,m);
    }else{
        cout << matrixName << " is not upper triangular!";
    }
}
