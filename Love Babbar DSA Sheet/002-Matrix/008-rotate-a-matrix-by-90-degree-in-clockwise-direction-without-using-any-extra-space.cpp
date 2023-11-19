// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/


#include <bits/stdc++.h>
using namespace std;

// TC = O(N * N)
// SC = O(N * N)
void rotate90Clockwise_brute_1(vector<vector<int>>& arr, int n) {
    vector<vector<int>> store(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            store[i][j] = arr[n - 1 - j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = store[i][j];
        }
    }
}

// TC = O(N * N)
// SC = O(N * N)
void rotate90Clockwise_brute_2(vector<vector<int>>& arr, int n) {
/*     
    //Consider a 3 x 3 matrix having indices (i, j) as follows
    00 01 02 
    10 11 12 
    20 21 22

    //After rotating the matrix by 90 degrees in clockwise direction, indices transform into
    20 10 00  current_row_index = 0, i = 2, 1, 0 
    21 11 01  current_row_index = 1, i = 2, 1, 0 
    22 12 02  current_row_index = 2, i = 2, 1, 0

 */
    vector<vector<int>> store(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            store[i][n - 1 - j] = arr[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = store[i][j];
        }
    }
}

// TC = O(N*N)
// SC = O(1)
void rotate90Clockwise_optimal(vector<vector<int>>& arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(begin(arr[i]), end(arr[i]));
    }
}

// TC = O(N * N)
// SC = O(1)
void rotate90_anti_clockwise_optimal_1(vector<vector<int>>& mat, int n) {
    // reverse every row
    for (int i = 0; i < n; i++) {
        reverse(begin(mat[i]), end(mat[i]));
    }
    
    // transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

// TC = O(N * N)
// SC = O(1)
void rotate90_anti_clockwise_optimal_2(vector<vector<int>>& matrix, int n) {
    // transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
     
    // reverse the columns  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            swap(matrix[i][j], matrix[n-1-j][i]);
        }
    }
}


// Function for print matrix
void printMatrix(vector<vector<int>>& arr, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

// Driver code
int main()
{
    vector<vector<int>> arr{{1, 2, 3}, 
                            {4, 5, 6}, 
                            {7, 8, 9}};
    int n = arr.size();
    cout << "\nPrinting Input Matrix..." << endl;
    printMatrix(arr, n);
 
    cout << "\nPrinting rotated Matrix (Brute-1)  : " << endl;
    rotate90Clockwise_brute_1(arr, n);
    printMatrix(arr, n);

    
    cout << "\nPrinting rotated Matrix (Brute-2)  : " << endl;
    rotate90Clockwise_brute_2(arr, n);
    printMatrix(arr, n);

     
    cout << "\nPrinting rotated Matrix (Optimal)  : " << endl;
    rotate90Clockwise_optimal(arr, n);
    printMatrix(arr, n);
    cout << endl;
     
    
    cout << "\nPrinting counter-clockwise rotated Matrix (Optimal-1) : " << endl;
    rotate90_anti_clockwise_optimal_1(arr, n);
    printMatrix(arr, n);

    cout << "\nPrinting counter-clockwise rotated Matrix (Optimal-2) : " << endl;
    rotate90_anti_clockwise_optimal_2(arr, n);
    printMatrix(arr, n);
    

    cout << endl;
    return 0;
}