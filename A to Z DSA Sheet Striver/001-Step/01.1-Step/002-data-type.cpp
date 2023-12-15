// https://www.codingninjas.com/studio/problems/data-type_8357232



#include <bits/stdc++.h>
using namespace std; 

int dataTypes(string type) {
	if (type == "Long" || type == "Double") {
		return 8;
	}
	else if (type == "Float" || type == "Integer") {
		return 4;
	}
	else if (type == "Character") {
		return 1;
	}
	return 0;
}
