// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/


#include <bits/stdc++.h>
using namespace std;
#define N 5


// condition of specific pair -> (mat[c][d] - mat[a][b]) should be maximum 
// for all possible indexes such that  c > a and d > b

// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a and d > b.

// TC = O(N * N * N * N)
// SC = O(1)
int findSpecificPair_brute_1(int mat[][N]) {
    int ans = INT_MIN;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    if (c > a && d > b) {
                        ans = max(ans, (mat[c][d] - mat[a][b]));
                    }
                }
            }
        }
    }
    return ans;
}

// TC = O(N * N * N * N)
// SC = O(1)
int findSpecificPair_brute_2(int mat[][N]) {
    int ans = INT_MIN;
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = a+1; c < N; c++) {
                for (int d = b+1; d < N; d++) {
                    ans = max(ans, (mat[c][d] - mat[a][b]));
                }
            }
        }
    }
    return ans;
}

// TC = O(N * N)
// SC = O(N * N)
int findSpecificPair_better(int mat[][N]) {
    vector<vector<int>> matMax(N, vector<int>(N, INT_MIN));

    matMax[N-1][N-1] = mat[N-1][N-1];
    bool flag = true;

    // fill the last row of the matMax
    for (int j = N - 2; j >= 0; j--) {
        matMax[N-1][j] = max(mat[N-1][j], max(matMax[N-1][j], matMax[N-1][j+1]));
    }

    // fill the last col of the matMax
    for (int i = N - 2; i >= 0; i--) {
        matMax[i][N-1] = max(mat[i][N-1], max(matMax[i][N-1], matMax[i+1][N-1]));
    }

    // fill the remaining portion of the matMax
    for (int i = N-2; i >= 0; i--) {
        for (int j = N-2; j >= 0; j--) {
            matMax[i][j] = max(mat[i][j], max(matMax[i+1][j], matMax[i][j+1]));
        }
    }

    // finding the answer
    int ans = INT_MIN;
    for (int a = 0; a < N-1; a++) {
        for (int b = 0; b < N-1; b++) {
            ans = max(ans, (matMax[a+1][b+1] - mat[a][b]));
        }
    }
    return ans;
}

// TC = O(N * N)
// SC = O(N)
int findSpecificPair_Optimal(int mat[][N]) {
    vector<int> vec1(N, INT_MIN);
    vector<int> vec2(N, INT_MIN);

    // Intialize last element of vec1
    vec1[N - 1] = mat[N - 1][N - 1];

    // fill matrix last row maximum into vec1 
    for (int j = N - 2; j >= 0; j--) {
        vec1[j] = max(vec1[j + 1], mat[N - 1][j]);
    }

    int ans = INT_MIN;

    // fill the remaining rows of vec1 starting from n-2
    for (int i = N - 2; i >= 0; i--) {
        // fill matrix last col maximum into vec2
        vec2[N - 1] = max(mat[i][N - 1], vec1[N - 1]);

        for (int j = N - 2; j >= 0; j--) {
            ans     = max(ans, (vec1[j + 1] - mat[i][j]));
            vec2[j] = max({mat[i][j], vec1[j], vec2[j + 1]});
        }

        vec1 = vec2;
    }

    return ans;
}

int main() {

    int mat[N][N] = {{ 1,  2, -1,  -4, -20 },
                    { -8, -3,  4,   2,   1 }, 
                    {  3,  8,  6,   1,   3 },
                    { -4, -1,  1,   7,  -6 },
                    {  0, -4,  10, -5,   1 }};

    int ans1 = findSpecificPair_brute_1(mat);   
    cout << "\nPrinting Maximum value of specific pair(Brute)   : " << ans1 << endl; 

    int ans2 = findSpecificPair_brute_2(mat);   
    cout << "\nPrinting Maximum value of specific pair(Brute)   : " << ans2 << endl; 

    int ans3 = findSpecificPair_better(mat);   
    cout << "\nPrinting Maximum value of specific pair(Better)  : " << ans3 << endl; 

    int ans4 = findSpecificPair_Optimal(mat);   
    cout << "\nPrinting Maximum value of specific pair(Optimal) : "<< ans4 << endl; 


    cout << endl;
    return 0;
}