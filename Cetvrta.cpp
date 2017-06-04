#include <iostream>

using namespace std;

int main() {
	int coOrdinates[3][2];
	
	int x = 1001, y = 1001;

	for(int i = 0; i < 3; i++) {
		cin >> coOrdinates[i][0];
		cin >> coOrdinates[i][1];

	}

	if(coOrdinates[0][0] == coOrdinates[1][0]) {
		x = coOrdinates[2][0];
	}
	else if(coOrdinates[0][0] == coOrdinates[2][0]) {
		x = coOrdinates[1][0];
	}
	else if(coOrdinates[1][0] == coOrdinates[2][0]) {
		x = coOrdinates[0][0];
	}
	
	if(coOrdinates[0][1] == coOrdinates[1][1]) {
		y = coOrdinates[2][1];
	}
	else if(coOrdinates[0][1] == coOrdinates[2][1]) {
		y = coOrdinates[1][1];
	}
	else if(coOrdinates[1][1] == coOrdinates[2][1]) {
		y = coOrdinates[0][1];
	}

	cout << x << " " << y << "\n;
	return 0;
}
