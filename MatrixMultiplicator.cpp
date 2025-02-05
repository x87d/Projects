#include <iostream>
using namespace std;

int main() {
    int aRows, aCols, bRows, bCols;
    int **A, **B, **C;

    cout << "Enter the number of rows for matrix A: ";
    cin >> aRows;
    cout << "Enter the number of columns for matrix A: ";
    cin >> aCols;

    if (aRows <= 0 || aCols <= 0) {    
        cout << "Invalid input." << endl;
        return 1;
    }

    cout << "Enter the number of rows for matrix B: ";
    cin >> bRows;
    cout << "Enter the number of columns for matrix B: ";
    cin >> bCols;

    if (bRows <= 0 || bCols <= 0) {  
        cout << "Invalid input." << endl;
        return 1;
    }

    if (aCols != bRows) {    
        cout << "Multiplication not possible: Columns of A must match Rows of B." << endl;
        return 1;
    }

    // Dynamic memory allocation for matrices
    A = new int*[aRows];
    B = new int*[bRows];
    C = new int*[aRows];

    for (int i = 0; i < aRows; i++) A[i] = new int[aCols];
    for (int i = 0; i < bRows; i++) B[i] = new int[bCols];
    for (int i = 0; i < aRows; i++) C[i] = new int[bCols];

    // Input for matrix A with clear prompts
    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < aCols; j++) {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Input for matrix B with clear prompts
    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < bRows; i++) {
        for (int j = 0; j < bCols; j++) {
            cout << "Enter element B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    // Matrix multiplication
    for (int i = 0; i < aRows; i++) {  
        for (int j = 0; j < bCols; j++) {  
            C[i][j] = 0;  // Initialize result matrix
            for (int k = 0; k < aCols; k++) {  
                C[i][j] += A[i][k] * B[k][j];  
            }
        }
    }

    // Output result matrix
    cout << "\nResultant Matrix C (A * B):" << endl;
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Free allocated memory
    for (int i = 0; i < aRows; i++) delete[] A[i];
    for (int i = 0; i < bRows; i++) delete[] B[i];
    for (int i = 0; i < aRows; i++) delete[] C[i];

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
