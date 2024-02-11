// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/



#include <iostream>
#include <string>
using namespace std;

#define R 3
#define C 3

void printRec(string arr[R][C], string result[R], int row, int col) {
    // add the current word in the result
    result[row] = arr[row][col];

    // print array if the row reached to the end (row == R - 1)
    if (row == R - 1) {
        for (int i = 0; i < R; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    // Recursive call for the next row
    for (int col = 0; col < C; col++) {
        if (arr[row + 1][col] != "") {
            printRec(arr, result, row + 1, col);
        }
    }
}

void print(string arr[R][C]) {
    string result[R];
    
    // Consider all words of first row as starting points 
    for (int col = 0; col < C; col++) {
        if (arr[0][col] != "") {
            printRec(arr, result, 0, col);
        }
    }
}

int main() {
    string arr[R][C]  = { {"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"} };
    print(arr);
    return 0;
}
