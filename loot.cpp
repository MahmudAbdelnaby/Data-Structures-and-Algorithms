#include<iostream>
#include <iomanip>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int number;
	double t1, t2;
	unsigned int  capacity;
	vector < pair < double,  double>> v;
	double finalValue = 0;

	cin >> number >> capacity;

	for (int i = 0; i < number; i++) {

		cin >> t1 >> t2;
		v.push_back(make_pair(t1 / t2,  t2));
		
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < number; i++) {
		
		while (v[number - 1 - i].second != 0 && capacity != 0) {
			capacity--;
			v[number - 1 - i].second--;
			finalValue += v[number - 1 - i].first;
		}
	
	}
	
	std::cout << std::fixed;
	std::cout << std::setprecision(4);
	std::cout << finalValue;
	

	system("pause");
}