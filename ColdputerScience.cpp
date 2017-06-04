#include <iostream>

using namespace std;

int main() {
	int totalTemperatures;
	cin >> totalTemperatures;
	int temperatures[totalTemperatures];
	int numberOfDays = 0;
	for(int i; i< totalTemperatures; i++) {
		cin >> temperatures[i];
		if(temperatures[i] < 0) {
			numberOfDays++;
		}
	}
	cout << numberOfDays << "\n";
	return 0;
}