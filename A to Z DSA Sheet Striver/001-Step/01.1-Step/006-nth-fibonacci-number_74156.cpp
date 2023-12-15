// https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156



#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{

    //step-1
    int prev1 = 1;
    int prev2 = 0;

    //edge case
    if(n == 0) {
        return prev2;
    }

    //step-2
    for(int i=2; i<=n; i++) {
        int curr = prev1 + prev2;
        //shifting logic
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


int main() {
    int n;
    cin >> n;

    int ans = fib(n);
    cout << ans << endl;

    return 0;
}