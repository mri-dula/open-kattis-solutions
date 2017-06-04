# include <iostream>
# include <iomanip>
using namespace std;

int main()
{
	const double pi = 3.141592;
	double c, r;
	double totalArea, totalAreaWithCheese;
	cin >> r;
	cin >> c;

	totalArea = r * r * pi;
	totalAreaWithCheese = (r - c) * (r - c) * pi;

	double p = (totalAreaWithCheese)/totalArea * 100;
	cout << fixed;
	cout << std::setprecision(6);
	cout << p << "\n";
	return 0;
}