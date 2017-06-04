#include <iostream>

using namespace std;

int main() {
	const int expectedSequence[6] = {1, 1, 2, 2, 2, 8};
	int input[6];
	int output[6];

	for(int i = 0; i < 6; i++) {
		cin >> input[i];
		output[i] = expectedSequence[i] - input[i];
		cout << output[i];
		if(i < 5) {
			cout << " "; 
		}
	}
	cout << "\n";

	return 0;
}