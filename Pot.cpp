# include <iostream>
# include <math.h>
using namespace std;
int main() {

	int x = 0, p, remainder, dividend, total = 0;
	cin >> x;

	while (x != 0) {
		cin >> p;
		dividend = p/10;
		remainder = p%10;
		total += pow(dividend, remainder);
		x--;
	}
	cout << total << "\n;
	return 0;
}