// https://www.codingninjas.com/studio/problems/sum-of-even-odd_624650



#include<iostream>
using namespace std;

int main() {
	long n;
	cin >> n;
	int evenSum = 0;
	int oddSum  = 0;
	while(n) {
		int rem = n % 10;
		
		if (rem % 2 == 0) {
			evenSum += rem;
		}
		else oddSum += rem;

		n = n / 10;
	}
	cout << evenSum << " " << oddSum;
}
