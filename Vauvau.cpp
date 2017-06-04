# include  <iostream>

using namespace std;
int a, b, c, d;

int getNumberOfDogsWhoAttacked(int minPersonArrived)
{
	int i = 1;
	int n = 0;
	int attackPeriodStart = 1;
	int attackPeriodStop = a;
	while(attackPeriodStart <= minPersonArrived)
	{
		if(minPersonArrived >= attackPeriodStart && minPersonArrived <= attackPeriodStop)
		{
			n++;
			break;
		}
		attackPeriodStart = attackPeriodStop + b + 1;
		attackPeriodStop = attackPeriodStart + a - 1;

	}
	attackPeriodStart = 1;
	attackPeriodStop = c;
	while(attackPeriodStart <= minPersonArrivedx)
	{
		if(minPersonArrived >= attackPeriodStart && minPersonArrived <= attackPeriodStop)
		{
			n++;
			break;
		}
		attackPeriodStart = attackPeriodStop + d + 1;
		attackPeriodStop = attackPeriodStart + c - 1;

	}
	return n;
}

int main()
{
	//int a, b, c, d;
	int p, m, g;
	int i;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> p;
	cin >> m;
	cin >> g;

	i = getNumberOfDogsWhoAttacked(p);
	if(i == 0)
		cout << "none\n";
	if(i == 1)
		cout << "one\n";
	if(i == 2)
		cout << "both\n";
	i = getNumberOfDogsWhoAttacked(m);
	if(i == 0)
		cout << "none\n";
	if(i == 1)
		cout << "one\n";
	if(i == 2)
		cout << "both\n";
	i = getNumberOfDogsWhoAttacked(g);
	if(i == 0)
		cout << "none\n";
	if(i == 1)
		cout << "one\n";
	if(i == 2)
		cout << "both\n";
	return 0;
}

