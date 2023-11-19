// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/


#include <bits/stdc++.h>
using namespace std;

// TC = O(N * log(N))
// SC = O(1)
void printDuplicates(string str)
{
    int n = str.length();
 
    // Sorting the string
    sort(str.begin(), str.end());
 
    // Loop through the sorted string to find duplicates
    for (int i = 0; i < n; i++) {
        int count = 1;
 
        // Counting the occurrences of each character
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
 
        // Printing the duplicate character and its count
        if (count > 1) {
            cout << str[i] << ", count = " << count << endl;
        }
    }
}

// TC = O(N)
// SC = O(N)
void printDups(string str) {
    int n = str.length();
    unordered_map<char, int> count;

    for (int i = 0; i < n; i++) {
        count[str[i]]++;
    }

    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second << "\n";
    }
}

int main()
{
    string str = "test string";

    cout << "\nPrinting duplicats using sorting method..." << endl;
    printDuplicates(str);

    cout << "\nPrinting duplicats using storing in map..." << endl;
    printDups(str);

    cout << endl;
    return 0;
}