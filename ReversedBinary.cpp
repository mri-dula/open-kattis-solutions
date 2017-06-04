#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int x, dividend = 1, reminder = 0, power, reversedValue = 0, i=0;
	cin >> x;
	string binary = "";

	while(dividend != 0) {
		dividend = x/2;
		reminder = x %2;
		binary = binary + to_string(reminder);
		x = dividend;
	}
	
	power = binary.length() - 1;

	while(power >= 0) {
		reversedValue += pow(2, power--) * (binary[i] == '0' ? 0 : 1); 
		i++;
	}
	cout << reversedValue << "\n";	
	return 0;
}