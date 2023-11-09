// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/


#include <bits/stdc++.h>
using namespace std;


// Approach - 1
// TC = O(N)
// SC = O(1)
void move_negative_numbers_1(int arr[], int size) {
    int low = 0;
    int high = size - 1;

    while (low < high) {
        if (arr[low] < 0) 
            low ++;
        else if(arr[high] > 0) 
            high --;
        else {
            swap(arr[low], arr[high]);
        }
    }
}

// Approach - 2 
// TC = O(N)
// SC = O(1)
void move_negative_numbers_2(int arr[], int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            swap(arr[i], arr[j]);
        }
        j++;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 }; 
    int     n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nRe-Arranged Array-1 : " << endl;
    move_negative_numbers_1(arr, n);
    print_array(arr, n);


    cout << "\nRe-Arranged Array-2 : " << endl;
    move_negative_numbers_2(arr, n);
    print_array(arr, n);


    return 0;
}