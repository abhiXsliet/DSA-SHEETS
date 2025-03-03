// https://www.naukri.com/code360/problems/1062679



#include <bits/stdc++.h>
typedef long long ll;

int calcPow(int x, int y, int M) {
  ll ans = 1;
  for (int i = 1; i <= y; i ++) {
    ans *= x;
    if (ans > M) {
      return -1;
    }
  }
  return ans == M;
}

// TC : O(log2(M) * log2(n))
// SC : O(1)
int approach_1(int n, int m) {
  int low = 1, high = m;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (pow(mid, n) == m)
      return mid;
    if (pow(mid, n) > m) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

// TC : O(log2(M) * n)
// SC : O(1)
int approach_2(int n, int m) {
  int low = 1, high = m;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int calcPower = calcPow(mid, n, m);

    if (calcPower == 1)
      return mid;
    else if (calcPower == -1) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int NthRoot(int n, int m) {
  // return approach_1(n, m);  // if pow fn. works
  return approach_2(n, m);
}