// Check if a string is a valid shuffle of two distinct strings



#include <bits/stdc++.h>
using namespace std;

bool checkLength(string& s1, string& s2, string& result) {
    if (s1.length() + s2.length() != result.length()) 
        return false;
    else 
        return true;
}

bool suffleCheck(string& s1, string& s2, string result) {
    // sort each string to make comparison easier
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(result.begin(), result.end());

    int i = 0, j = 0, k = 0;

    while (k != result.length()) {
        if (i < s1.length() && s1[i] == result[k]) {
            i++;
        }
        else if (j < s2.length() && s2[j] == result[k]) {
            j++;
        }
        else {
            return false;
        }
        k++;
    }

    if (i < s1.length() || j < s2.length()) 
        return false;

    return true;
}

int main() {
    string first  = "xy";
    string second = "12";
    vector<string> results = {"1xy2", "y1x2", "y21xx"};

    cout <<"\n";
    for (string& result : results) {
        if (checkLength(first, second, result) && suffleCheck(first, second, result)) {
            cout << "string " << result << " is a valid suffle of " << first << " and " << second << endl;
        }
        else {
            cout << "string " << result << " is not a valid suffle of " << first << " and " << second << endl;
        }
    }

    cout << endl;
    return 0;
}