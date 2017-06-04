#include <iostream>

using namespace std;

int main() {
	int h = 0, m = 0, difference = 45;
	cin >> h;
	cin >> m;

	if(m - difference <=0) {
		int x = m - difference;
		m = 60 + x;
		if(m == 60) {
			m = 0;
		}
		h --;
	}
	else {
		m = m - difference;
	}
	if(h == -1) {
		h =23;
	}
	cout << h << " " << m << "\n;
	return 0;
}