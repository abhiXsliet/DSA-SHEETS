// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/


#include <bits/stdc++.h>
using namespace std;

// Approach - 1 : Iterative Approach
// TC = O(N)
// SC = O(1)
void reverse_array_iterative(int arr[], int n) {
    int start = 0;
    int end   = n - 1;

    while (start <= end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Approach - 2 : Recursive Approach
// TC = O(N)
// SC = O(1)
void reverse_array_recursive(int arr[], int start, int end) {
    // base case
    if (start > end) 
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // recursive call
    reverse_array_recursive(arr, start + 1, end - 1);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};

    int n     = sizeof(arr) / sizeof(arr[0]);

    cout << "\nPrinting reversed array using iterative approach : " << endl;
    reverse_array_iterative(arr, n);
    print_array(arr, 6);

    cout << "\nPrinting reversed array using recursive approach : " << endl;
    reverse_array_recursive(arr, 0, n);
    print_array(arr, 6);

    cout << endl;
    return 0;
}