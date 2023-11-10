// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/


#include <bits/stdc++.h>
using namespace std;

// TC = O(N)
// SC = O(N)
void solve_brute(int arr[], int n) {
    vector<int> storeNegatives;
    vector<int> storePositives;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            storeNegatives.push_back(arr[i]);
        }
        else {
            storePositives.push_back(arr[i]);
        }
    }

    int ptr1 = 0;
    int ptr2 = 0;
    int idx = 0;
    bool flag = 1;

    while(ptr1 < storeNegatives.size() && ptr2 < storePositives.size()) {
        if (flag) {
            arr[idx++] = storeNegatives[ptr1++];
        }
        else {
            arr[idx++] = storePositives[ptr2++];
        }
        flag = !flag;
    }

    while (ptr1 < storeNegatives.size()) {
        arr[idx++] = storeNegatives[ptr1++];
    }

    while (ptr2 < storePositives.size()) {
        arr[idx++] = storePositives[ptr2++];
    }
}

// TC = O(N)
// SC = O(N)
void solve_better(int arr[], int n) {
    vector<int> pos;
    vector<int> neg;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) neg.push_back(arr[i]);
        else pos.push_back(arr[i]);
    }
    
    if (pos.size() > neg.size()) {
        // handle equal elements from both pos and neg
        for (int i = 0; i < neg.size(); i++) {
            arr[2*i]   = neg[i];
            arr[2*i+1] = pos[i];
        }
        // handle remaining pos elements
        int idx = 2*neg.size();
        for (int i = neg.size(); i < pos.size(); i++) {
            arr[idx++] = pos[i];
        }
    }
    else {
        //handle equal elements
        for (int i = 0; i < pos.size(); i++) {
            arr[2*i]   = neg[i];
            arr[2*i+1] = pos[i];
        }
        // handle remaining neg elements
        int idx = 2*pos.size();
        for (int i = pos.size(); i < neg.size(); i++) {
            arr[idx++] = neg[i];
        }
    }
}


// TC = O(N)
// SC = O(1)
// Occurrences of elements are not in their correct sequence (unordred sequence) -> N P N P N P ...
void solve_optimal_unordered_1(int arr[], int n) {
    int i = -1; 
    int j =  n;

    // First, partition the array into negative and positive parts
    while (1) {
        do{i++;} while (i < n  && arr[i] > 0);
        do{j--;} while (j >= 0 && arr[j] < 0);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
        else break;
    }

    // If there are no negative numbers or all are negative numbers, no need to rearrange
    if (i == 0 || i == n) return;

    // Start rearranging array
    for (int k = 0; k < n && i < n; k += 2) {
        swap(arr[k], arr[i++]);
    }
}

// TC = O(N)
// SC = O(1)
void solve_optimal_unordered_2(int arr[], int n) {
    // First, partition the array into negative and positive parts
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }

    // If there are no negative numbers or all are negative numbers, no need to rearrange
    if (j == 0 || j == n)
        return;

    // Start rearranging array
    int pos = j, neg = 1;
    while (pos < n && neg < pos && arr[neg] < 0) {
        swap(arr[pos], arr[neg]);
        neg += 2;
        pos += 1;
    }
}

void rightRotate(int arr[], int outOfPlace, int cur) {
    int tmp = arr[cur];
    for (int i = cur; i > outOfPlace; i--) {
        arr[i] = arr[i - 1];
    }
    arr[outOfPlace] = tmp;
}

// TC = O(N * N)
// SC = O(1)
void solve_optimal_ordered(int arr[], int n) {
    int outOfPlace = -1;

    for (int index = 0; index < n; index++) {
        if (outOfPlace >= 0) {
            if ((arr[index] >= 0 && arr[outOfPlace] < 0) ||
                (arr[index] < 0 && arr[outOfPlace] >= 0)) {
                
                rightRotate(arr, outOfPlace, index);
                
                if (index - outOfPlace >= 2) {
                    outOfPlace = outOfPlace + 2;
                } else {
                    outOfPlace = -1;
                }
            }
        }

        if (outOfPlace == -1) {
            // (!(index & 0x01)) -> check if index is even
            // (index & 0x01)    -> check if index is odd
            // +ve no. at the even place and -ve no. at the odd place
            if (((arr[index] >= 0) && (!(index & 0x01)) ||
                ((arr[index] < 0) && (index & 0x01)))) {
                outOfPlace = index;
            }
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main() {
    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
    int n     = (sizeof(arr) / sizeof(arr[0]));
/* 

    solve_brute(arr, n);
    cout << "\nprinting alternating positive and negative numbers (Brute - Force) : \n";
    print_array(arr, n);


    solve_better(arr, n);
    cout << "\nprinting alternating positive and negative numbers (Better) : \n";
    print_array(arr, n);
    

    // bad approach since the order of array's elements lost 
    solve_optimal_unordered_1(arr, n);
    cout << "\nprinting alternating positive and negative numbers (Optimally Unordered-1): \n";
    print_array(arr, n);

    solve_optimal_unordered_2(arr, n);
    cout << "\nprinting alternating positive and negative numbers (Optimally Unordered-2): \n";
    print_array(arr, n);
    
    
 */
    solve_optimal_ordered(arr, n);
    cout << "\nprinting alternating positive and negative numbers (Optimally  Ordered): \n";
    print_array(arr, n);


    cout << endl;
    return 0;
}