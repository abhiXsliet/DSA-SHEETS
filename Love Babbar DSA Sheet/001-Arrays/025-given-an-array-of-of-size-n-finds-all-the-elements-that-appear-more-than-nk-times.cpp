// https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/



#include <bits/stdc++.h>
using namespace std;

// TC = O(N * N)
// SC = O(N) 
vector<int> generateElements_brute(int arr[], int n, int k) {
    unordered_set<int> st;
    int occ = n / k;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                cnt++;
        }

        if (cnt > occ) 
            st.insert(arr[i]);
    }
    vector<int> result;
    for (int i : st) 
        result.push_back(i);

    return result;
}

// TC = O(N)
// SC = O(N)
vector<int> generateElements_better(int arr[], int n, int k) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int cnt = n/k;
    vector<int> ans;

    for (int i = 0; i < mpp.size(); i++) {
        if (mpp[arr[i]] > cnt) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

// TC = O(N * K)
// SC = O(K)
// Moore's Voting Algorithm
pair<int,int> generateElements_optimal(int arr[], int n, int k) {
    pair<int, int> result;
    int ele = INT_MIN;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            ele = arr[i];
            cnt = 1;
        }
        else if (ele == arr[i]) cnt++;
        else cnt--;
    }
    
    // count the no. of occurrences of element
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ele == arr[i]) count++;
    }

    return {ele, count}; // {ele, no. of occurrences of element}
}

void print_array(vector<int>& arr, int n) {
    cout << "{ " ;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "}" ;
    cout << endl;
}

int main() {
    // int arr[] = { 4, 5, 6, 7, 8, 4, 4 };
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int k     = 4;
    int n     = sizeof(arr) / sizeof(arr[0]);

    cout << "\nPrinting Elements which appear more than n/k times (Brute) : " << endl;
    vector<int> ans = generateElements_brute(arr, n, k);
    print_array(ans, ans.size());


    cout << "\nPrinting Elements which appear more than n/k times (Better-than-brute) : " << endl;
    vector<int> ans2 = generateElements_better(arr, n, k);
    print_array(ans2, ans2.size());


    cout << "\nPrinting Elements which appear more than n/k times (Optimally): " << endl;
    pair<int,int> p = generateElements_optimal(arr, n, k);
    cout << "Number : " << p.first << " Count : " << p.second << endl;


    cout << endl;
    return 0;
}