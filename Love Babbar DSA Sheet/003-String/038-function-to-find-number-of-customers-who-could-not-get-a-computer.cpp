// https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/



#include <iostream>
#include <cstring>
using namespace std;

// ASSUMING CUSTOMERS HAVE UPPERCASE ENGLISH ALPHABETS ONLY
int runCustomerSimulation(int n, string customers) {
    int seen[26] = {0};

    // keep track of no. of customers who didn't get their computer allocated
    int result = 0;
    int occupiedComputers = 0;

    for (int i = 0; i < customers.length(); i++) {

        int idx = customers[i] - 'A';

        // Customer seen for the first time (arrival)
        if (seen[idx] == 0) {

            seen[idx] = 1;
            
            if (occupiedComputers < n) {

                occupiedComputers ++;

                seen[idx] = 2;
            }
            else {
                result ++;
            }
        }
        // Customer seen for the second time (departure)
        else {
            if (seen[idx] == 2) {
                occupiedComputers --;
            }
            seen[idx] = 0;
        }
    }
    return result;
}

int main() {
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl; 
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl; 
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl; 
    cout << runCustomerSimulation(1, "ABCBCA") << endl; 
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl; 
    return 0; 
}