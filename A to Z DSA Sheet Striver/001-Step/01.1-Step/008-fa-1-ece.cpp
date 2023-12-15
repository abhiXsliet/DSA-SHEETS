// https://www.codingninjas.com/studio/problems/fa-1-ece_4606261



#include <iostream>
using namespace std;

int Maximum(int x, int y)
{
	if (x < y) return y;
	else return x;
}

void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int test, a, b, r;
	cin >> test;
	cin >> a >> b;
	switch (test)
	{
	case 1:
		r = Maximum(a, b);
		cout << r;
		break;
	case 2:
		Swap(a, b);
		cout << a << " " << b;
		break;
	default:
		cout << "Invalid test option";
	}
	return 0;
}