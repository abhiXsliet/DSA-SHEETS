// https://www.codingninjas.com/studio/problems/switch-case-statement_8357244



#include <bits/stdc++.h>
using namespace std; 

double areaSwitchCase(int ch, vector<double> a) {
	switch(ch) {
		// use M_PI built in func. 
		case 1: return (M_PI*a[0]*a[0]); 
		case 2: return (double)(a[0]*a[1]);
		default: return 0;
	}
	return 0;
}
