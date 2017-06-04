#include <iostream>

using namespace std;


class SingleInput {
	private:
		
	public: 
		int speed;
		int hours;
		SingleInput * next;
		SingleInput(int speed, int hours) {
			this->speed = speed;
			this->hours = hours;
			this->next = NULL;
		}
};

class InputSet {
	public:
		int i;
		SingleInput * speedListHead;
		InputSet * nextSet;
};

int main() {
	InputSet * head, * temp;
	SingleInput * tempSingleInput;
	head = NULL;
	int x = 0, speed = 0, hours = 0;
	while(x != -1) {
		cin >> x;
		if(x == -1) {
			break;
		}
		else {
			InputSet *newSet = new InputSet();
			newSet -> nextSet = NULL;
			newSet -> i = x;
			if(head == NULL) {
				head = newSet;
			}
			else {
				temp->nextSet = newSet;
			}
			temp = newSet;

			for(int i=0; i< x; i++) {
				SingleInput *singleInput;
				cin >> speed;
				cin >> hours;
				singleInput = new SingleInput(speed, hours);
				if(temp->speedListHead == NULL) {
					temp->speedListHead = singleInput;
				}
				else {
					tempSingleInput->next = singleInput;
				}
				tempSingleInput = singleInput;
			}
		}
		

	}
	temp = head;
	while (temp != NULL) {
		int miles = 0,  previousHours = 0;
		tempSingleInput = temp->speedListHead;
		while(tempSingleInput != NULL) {
			//cout << tempSingleInput->speed << " * (" << tempSingleInput->hours << " - " << previousHours << ")";
			miles += (tempSingleInput->speed * (tempSingleInput->hours - previousHours));
			previousHours = tempSingleInput->hours;
			tempSingleInput = tempSingleInput->next;
		}
		cout << miles << " miles\n"; 
		temp = temp -> nextSet;
	}
	return 0;

}