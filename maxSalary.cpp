#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int myCompare(string x, string y){
	
	string xy = x.append(y);
	string yx = y.append(x);

	return xy.compare(yx) > 0 ? 1 : 0;

}

int main() {
	vector <string> a;
	int size;
	string t;
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> t;
		a.push_back(t);
	}

	sort(a.begin(), a.end(), myCompare);

	for (int i = 0; i < size; i++) {
		cout << a[i];
	}

}