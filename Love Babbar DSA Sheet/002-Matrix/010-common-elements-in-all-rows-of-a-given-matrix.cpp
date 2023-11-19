// https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/



#include <bits/stdc++.h>
using namespace std;
#define N 4
#define M 5

// TC = O(M * N * M) where M = cols & N = rows of matrix
// SC = O(1)
vector<int> search_ele_brute(int mat[N][M]) {
    vector<int> result;
    for (int i = 0; i < M; i++) {
        int ele = mat[0][i];

        int cnt = 0;
        for (int j = 1; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (mat[j][k] == ele)
                    cnt++;
            }
        }

        if (cnt == N - 1) {
            result.push_back(ele);
        }
    }
    return result;
}

bool binary_search(int arr[], int tar) {
    int l = 0;
    int h = M - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;

        if (arr[mid] == tar) {
            return true;
        }
        else if (arr[mid] < tar) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return false;
}

// TC = O(M * N * log(M))
// SC = O(1)
// row wise sorted matrix -> binary search
vector<int> search_ele_better(int Mat[N][M]) {
    vector<int> result;
    for (int i = 0; i < M; i++) {
        int ele = Mat[0][i];

        int cnt = 0;
        for (int row = 1; row < N; row++) {
            if (binary_search(Mat[row], ele) ) {
                cnt++;
            }
        }

        if (cnt == N - 1) {
            result.push_back(ele);
        }
    }
    return result;
}

// TC = O(N * M)
// SC = O(N)
vector<int> search_ele_optimal(int Mat[N][M]) {
    vector<int> result;
    map<int, int> mpp; // {ele, cnt_of_ele}

    for (int col = 0; col < M; col++) {
        mpp[Mat[0][col]] ++;
    }

    int cnt = 0;

    for (int row = 1; row < N; row++) {
        for (int col = 0; col < M; col++) {
            int ele = Mat[row][col];

            if(mpp.find(ele) != mpp.end()) {
                mpp[ele]++;
                cnt++;
            }
        }
    }

    for (auto& i : mpp) {
        if (i.second == N)
            result.push_back(i.first);
    }

    return result;
}

int main() {
    int mat[N][M] = {   {1, 2, 3, 4, 5 },
                        {1, 4, 5, 8, 10},
                        {1, 5, 7, 9, 11},
                        {1, 3, 5, 7, 9 },
                    };

    cout << "\nFinding common element brute - Approach (linear search)..." << endl;
    vector<int> ans = search_ele_brute(mat);
    for (int& i : ans) cout << i << " ";
    cout << endl;


    cout << "\nFinding common element better - Approach (binary search)..." << endl;
    vector<int> ans2 = search_ele_better(mat);
    for (int& i : ans2) cout << i << " ";
    cout << endl;


    cout << "\nFinding common element Optimal - Approach (using map)..." << endl;
    vector<int> ans3 = search_ele_optimal(mat);
    for (int& i : ans3) cout << i << " ";
    cout << endl;

    cout << endl;
    return 0;
}