#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

struct testCase
{
public:
	string recording;
	int preRecordedCount;
	string preRecords[100];
};

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

bool isSoundPreRecorded(string sound, testCase aTestCase)
{
	int i = 0;
	for(; i< aTestCase.preRecordedCount; i++)
	{
		string preRecordedSound = split(aTestCase.preRecords[i], ' ')[2];

		if(sound.compare(preRecordedSound) == 0)
			break;

	}
	return i < aTestCase.preRecordedCount;
}

int main()
{
	int n = 0, i = 0, j = 0;
	string str = "";
	string const testCaseEnd = "what does the fox say?";
	cin >> n;
	testCase *temp = NULL;
	testCase *testCases  = new testCase[n];
	cin.ignore();
	while(i < n)
	{
		j = 0;
		getline(cin, testCases[i].recording);
		do 
		{
			getline(cin,str);
			if(str.compare(testCaseEnd) == 0)
			{
				break;
			}
			testCases[i].preRecords[j] = str;
			j++;
		} while(true);
		testCases[i].preRecordedCount = j;
		i++;
	}
	for(i = 0; i < n; i++)
	{
		vector<string> sounds = split(testCases[i].recording,' ');
		for(int k = 0; k < sounds.size(); k++) 
		{
			string sound = sounds[k];
			if(!isSoundPreRecorded(sound, testCases[i]))
			{
				cout << sound << " ";
			}
		}
		cout << "\n";
	}
	//cout << testCases[0].preRecordedCount;

	return 0;
}