#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int value, vector<unsigned int>data, int l, int r) {

	int m = (l + r) / 2;
	if (l > r)
		return -1;
	if (data[m] == value)
		return m;
	if (value > data[m])
		return binarySearch(value, data, m + 1, r);
	if (value < data[m])
		return binarySearch(value, data, l, m - 1);

}

int Binary_Search(vector<unsigned int> Arr, int n, int Target) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (Arr[mid] == Target)
			return mid;
		else if (Arr[mid] < Target) {
			l = mid + 1;
		}
		else if (Arr[mid] > Target) {
			r = mid - 1;
		}
	}
	return -1;
}
int main() {
	
	
	int n, k;
	unsigned int t;
	cin >> n;
	vector<unsigned int> data(n);

	for (int i = 0; i < n; i++) {
		cin >> data[i];	
	}
	
	cin >> k;
	//vector<int> wanted(k);
	for (int i = 0; i < k; i++) {
		cin >> t;
		cout<< Binary_Search(data,n,t)<<" ";
	}

	
	system("pause");
}