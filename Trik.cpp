#include <iostream>
#include <cstring>
using namespace std;

class Cup {
	private :
	int isBallInside;

	public :
	Cup(int b){
		this->isBallInside = b;
	}

	bool getIsBallInside() {
		return this->isBallInside;
	}

	void setIsBallInside(bool b) {
		this->isBallInside = b;
	}
};

int main() {
	string sequence = "";
	int currentPosition = 1;
	char move = '\0';
	int temp = 0;
	Cup left(1), middle(0), right(0);

	cin >> sequence;

	for(int i; i < sequence.length(); i++) {
		char move = sequence[i];
		switch(move){
			case 'A':
				temp = left.getIsBallInside();
				left.setIsBallInside(middle.getIsBallInside());
				middle.setIsBallInside(temp);
				break;
			case 'B':
				temp = middle.getIsBallInside();
				middle.setIsBallInside(right.getIsBallInside());
				right.setIsBallInside(temp);
				break;
			case 'C':
				temp = right.getIsBallInside();
				right.setIsBallInside(left.getIsBallInside());
				left.setIsBallInside(temp);
				break;

		}
	}

	if(left.getIsBallInside() == 1) {
		cout << 1 << "\n";
	}

	if(middle.getIsBallInside() == 1) {
		cout << 2 << "\n";
	}

	if(right.getIsBallInside() == 1) {
		cout << 3 << "\n";
	}

	return 0;
}