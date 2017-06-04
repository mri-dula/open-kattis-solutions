#include<iostream>

using namespace std;

struct output
{
public:
	string str;
	int distance;
};

struct testCase
{
public:
	string input;
	int suggestionCount;
	string suggestions[10];
};


struct keyBoard
{
public:
	int x;
	int y;
};

int getIndexOfLetter(char ch)
{
	int i = 0;
	
	switch(ch)
	{
		case 'a':
		i = 0;
		break;
		case 'b':
		i = 1;
		break;
		case 'c':
		i = 2;
		break;
		case 'd':
		i = 3;
		break;
		case 'e':
		i = 4;
		break;
		case 'f':
		i = 5;
		break;
		case 'g':
		i = 6;
		break;
		case 'h':
		i = 7;
		break;
		case 'i':
		i = 8;
		break;
		case 'j':
		i = 9;
		break;
		case 'k':
		i = 10;
		break;
		case 'l':
		i = 11;
		break;
		case 'm':
		i = 12;
		break;
		case 'n':
		i = 13;
		break;
		case 'o':
		i = 14;
		break;
		case 'p':
		i = 15;
		break;
		case 'q':
		i = 16;
		break;
		case 'r':
		i = 17;
		break;
		case 's':
		i = 18;
		break;
		case 't':
		i = 19;
		break;
		case 'u':
		i = 20;
		break;
		case 'v':
		i = 21;
		break;
		case 'w':
		i = 22;
		break;
		case 'x':
		i = 23;
		break;
		case 'y':
		i = 24;
		break;
		case 'z':
		i = 25;
		break;

	}
	return i;
}

int main()
{
	output temp;
	output *outputs = new output[10];

	keyBoard *keys = new keyBoard[26];
	keyBoard inputCoordinates, suggestionCoordinates;
	//a
	keys[0].x = 1;
	keys[0].y = 0;
	//b
	keys[1].x = 2;
	keys[1].y = 4;
	//c
	keys[2].x = 2;
	keys[2].y = 2;
	//d
	keys[3].x = 1;
	keys[3].y = 2;
	//e
	keys[4].x = 0;
	keys[4].y = 2;
	//f
	keys[5].x = 1;
	keys[5].y = 3;
	//g
	keys[6].x = 1;
	keys[6].y = 4;
	//h
	keys[7].x = 1;
	keys[7].y = 5;
	//i
	keys[8].x = 0;
	keys[8].y = 7;
	//j
	keys[9].x = 1;
	keys[9].y = 6;
	//k
	keys[10].x = 1;
	keys[10].y = 7;
	//l
	keys[11].x = 1;
	keys[11].y = 8;
	//m
	keys[12].x = 2;
	keys[12].y = 6;
	//n
	keys[13].x = 2;
	keys[13].y = 5;
	//o
	keys[14].x = 0;
	keys[14].y = 8;
	//p
	keys[15].x = 0;
	keys[15].y = 9;
	//q
	keys[16].x = 0;
	keys[16].y = 0;
	//r
	keys[17].x = 0;
	keys[17].y = 3;
	//s
	keys[18].x = 1;
	keys[18].y = 1;
	//t
	keys[19].x = 0;
	keys[19].y = 4;
	//u
	keys[20].x = 0;
	keys[20].y = 6;
	//v
	keys[21].x = 2;
	keys[21].y = 3;
	//w
	keys[22].x = 0;
	keys[22].y = 1;
	//x
	keys[23].x = 2;
	keys[23].y = 1;
	//y
	keys[24].x = 0;
	keys[24].y = 5;
	//z
	keys[25].x = 2;
	keys[25].y = 0;



	int n;
	cin >> n;
	testCase *testCases  = new testCase[n];
	for (int i = 0; i < n; i++)
	{
		cin >> testCases[i].input;
		cin >> testCases[i].suggestionCount;
		for(int j = 0; j < testCases[i].suggestionCount; j++)
		{
			cin >> testCases[i].suggestions[j];
		}
	}

	for(int i = 0; i<n; i++)
	{

		for(int j = 0; j < testCases[i].suggestionCount; j++)
		{
			string suggestion = testCases[i].suggestions[j];
			string input = testCases[i].input;
			int length = 0;
			for (int k = 0; k < suggestion.length(); k++)
			{
				inputCoordinates = keys[getIndexOfLetter(input[k])];
				suggestionCoordinates = keys[getIndexOfLetter(suggestion[k])];
				length += (abs(inputCoordinates.y - suggestionCoordinates.y) + abs(inputCoordinates.x - suggestionCoordinates.x));
				
			}
			outputs[j].str = suggestion;
			outputs[j].distance = length;
		}

		for(int k = 0; k < testCases[i].suggestionCount; k++)
		{
			int temp;
			string tempStr;
			for(int m = k+1 ; m < testCases[i].suggestionCount; m++)
			{
				if(outputs[k].distance > outputs[m].distance)
				{
					temp = outputs[k].distance;
					tempStr = outputs[k].str;
					outputs[k].distance = outputs[m].distance;
					outputs[k].str = outputs[m].str;
					outputs[m].distance = temp;
					outputs[m].str = tempStr;
				}
				else if(outputs[k].distance == outputs[m].distance && outputs[k].str.compare(outputs[m].str) > 0)
				{
					temp = outputs[k].distance;
					tempStr = outputs[k].str;
					outputs[k].distance = outputs[m].distance;
					outputs[k].str = outputs[m].str;
					outputs[m].distance = temp;
					outputs[m].str = tempStr;
				}
			}
		}

		for(int k = 0; k < testCases[i].suggestionCount; k++)
		{
			//cout << "k: " << k << "\n";
			cout << outputs[k].str << " " << outputs[k].distance << "\n";
		}
	}
	return 0;
}


