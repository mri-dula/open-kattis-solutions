#include <iostream>

using namespace std;

int main(){
	int n = 0;
	string spell = "Abracadabra";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << i + 1 << " " << spell << "\n";
	}
	return 0;
}