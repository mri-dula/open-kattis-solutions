#include <iostream>

using namespace std;

int main() {
	const char adrian[] = {'C', 'A', 'B'}, bruno[] = { 'C', 'B', 'A', 'B'}, goran[] = { 'B', 'C', 'C', 'A', 'A', 'B' };
	int adrianSet = 0, brunoSet = 0, goranSet = 0;
	int adrianCount = 0, brunoCount = 0, goranCount = 0;
	int maxCount = 0;
	int n = 0;
	string seq = "";

	cin >> n;
	cin >> seq;

	for(int i = 1; i <= n; i++) {
		char answer = seq[i -1];
		int adrianIndex = i%3;
		int brunoIndex = i%4;
		int goranIndex = i%6;
		if(answer == adrian[adrianIndex])
			adrianCount++;
		if(answer == bruno[brunoIndex])
			brunoCount++;
		if(answer == goran[goranIndex])
			goranCount++;
	}
	maxCount = adrianCount;
	if(brunoCount > maxCount)
		maxCount = brunoCount;
	if(goranCount > maxCount)
		maxCount = goranCount;
	cout << maxCount << "\n";

	if(adrianCount == maxCount)
		cout << "Adrian\n";
	if(brunoCount == maxCount)
		cout << "Bruno\n";
	if(goranCount == maxCount)
		cout << "Goran\n";
	return 0;
}
