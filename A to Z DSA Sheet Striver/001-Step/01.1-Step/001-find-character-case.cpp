// https://www.codingninjas.com/studio/problems/find-character-case_58513



#include<iostream>
using namespace std;

void solve_1(char &ch) {
	if (ch >= 'A' && ch <= 'Z') {
		cout << "1";
	}
	else if (ch >= 'a' && ch <= 'z') {
		cout<< "0";
	}
	else cout<< "-1";
}

void solve_2(char &ch) {
	if (isupper(ch)) {
		cout << "1";
	}
	else if (islower(ch)) {
		cout<< "0";
	}
	else cout<< "-1";
}

int main() {
	char ch;
	cin >> ch;

	// solve_1(ch);

	solve_2(ch);
	
	return 0;
}
