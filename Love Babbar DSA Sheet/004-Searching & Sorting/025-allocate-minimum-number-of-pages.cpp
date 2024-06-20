// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1




//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  private:
    typedef long long ll;
    
    // TC : O(N)
    // SC : O(1)
    int getStudentsCnt(int arr[], int n, int targetPageCnt) {
        int pageSum     = 0;
        int studentsCnt = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] + pageSum <= targetPageCnt) {
                pageSum += arr[i];
            }
            else {
                studentsCnt ++;
                pageSum = arr[i];
            }
        }
        return studentsCnt;
    }

    // TC : O(N * log(Sum)) where N = array size and sum = total no. of pages
    // SC : O(1)
    ll way_1(int A[], int N, int M) {
        if (M > N) return -1;
        
        int low  = 0;
        int high = 0;
        for (int i = 0; i < N; i++) {
            low   = max(low, A[i]);
            high += A[i];
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (getStudentsCnt(A, N, mid) <= M) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
    
    bool isPossibleToAllocate(int arr[], int n, int mid, int totalStudents) {
        // is it possible to allocate atmax 'mid' no. of pages to totalStudents ?
        int pagesCnt   = 0;
        int studentCnt = 1;
        for (int i = 0; i < n; i ++) {
            if (pagesCnt + arr[i] <= mid) {
                pagesCnt += arr[i];
            } else {
                studentCnt += 1;
                if (studentCnt > totalStudents || arr[i] > mid)
                    return false;
                pagesCnt    = arr[i];
            }
        }
        return true;
    }

    // TC : O(N*log(sum))
    // SC : O(1)
    ll way_2(int arr[], int n, int m) {
        if (m > n) return -1;
        
        // 0-pages assigned to a student
        int low  = 0; 
        int high = accumulate(arr, arr + n, 0);

        ll maxPgCnt = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;

            if (isPossibleToAllocate(arr, n, mid, m)) {
                maxPgCnt = mid;
                high     = mid - 1; // try to minimize the result
            } else {
                low  = mid + 1;
            }
        }
        return maxPgCnt;
    }
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // return way_1(arr, n, m);
        
        return way_2(arr, n, m);    // MORE INTUTIVE TO ME
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}
// } Driver Code Ends