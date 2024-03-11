// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/




#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
vector<int> compute_linear(vector<int>& powers, int p) {
	int cntSol = 0; // no. of solider bishu can beat
	int sumPow = 0; // sum of those beated soldier
	for (int i = 0; i < powers.size(); i++) {
		if (powers[i] <= p) {
			cntSol ++;
			sumPow += powers[i];
		} else break;
	}
	return {cntSol, sumPow};
}

// TC : O(log(N))
vector<int> compute_binary(vector<int>& powers, int p) {
	int cntSol = 0; // no. of solider bishu can beat
	int sumPow = 0; // sum of those beated soldier
	int low    = 0;
	int high   = powers.size() - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (powers[mid] <= p) {
			cntSol = max(cntSol, mid+1);
			low    = mid + 1;
		}
		else high   = mid - 1;
	}
	sumPow = accumulate(begin(powers), begin(powers)+cntSol, 0);
	return {cntSol, sumPow};
}

// TC : O(N^2)
void solve_1(vector<int>& powers, int p) {
	vector<int> ans = compute_linear(powers, p);		
	cout << ans[0] << " " << ans[1] << endl;
}

// TC : O(N*log(N))
void solve_2(vector<int>& powers, int p) {
	vector<int> ans = compute_binary(powers, p);		
	cout << ans[0] << " " << ans[1] << endl;
}

// Write your code here
int main() {
	int n, q, p;
	cin >> n; // no. of soldiers

	vector<int> powers(n);
	for (int i = 0; i < n; i++) 
		cin >> powers[i];	// power of each soldier

	cin >> q;	// no. of rounds

	sort(begin(powers), end(powers));

	while (q-- > 0) {
		cin >> p; 	// power of bishu	
		
		// solve_1(powers, p);
		
		solve_2(powers, p);
	}
	return 0;
}