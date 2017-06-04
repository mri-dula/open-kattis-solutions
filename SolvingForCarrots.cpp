# include <iostream>

using namespace std;

int main() {
	int studentCount, successfulProblems;
	string description;
	cin >> studentCount;
	cin >> successfulProblems;

	for(int i = 0; i< studentCount; i++) {
		cin >> description;
	}

	cout << successfulProblems << "\n";
	return 0;
}