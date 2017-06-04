#include <iostream>

using namespace std;

struct trafficSignal
{
public:
	int d;
	int r;
	int g;
};


int main()
{
	int n, l;
	cin >> n;
	cin >> l;
	trafficSignal *signals = new trafficSignal[n];
	for(int i = 0; i < n; i++)
	{

		cin >> signals[i].d;
		cin >> signals[i].r;
		cin >> signals[i].g;
	}

	int time = 0;
	for(int i = 0; i < l ; i++)
	{
		time++;
		trafficSignal s;
		bool foundSignal = false;;
		for(int j = 0; j < n; j++)
		{
			if(signals[j].d == i + 1)
			{
				s = signals[j];
				foundSignal = true;
				break;
			}
		}
		if(foundSignal)
		{
			int m = time%(s.r + s.g);
			if(m < s.r)
			{
				time += (s.r - m );
			}
		}

	}
	cout << time << "\n";
	return 0;
}




