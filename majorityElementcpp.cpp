#include<iostream>
#include<map>
using namespace std;

int main() {

	map<int, int> m;
	int t, n;
	int f = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		m[t]++;
	}

	for (auto i = m.begin(); i!=m.end(); i++) {
		if (i->second > (n / 2) )
			f = 1;
	}

	cout << f << endl;
	system("pause");
}