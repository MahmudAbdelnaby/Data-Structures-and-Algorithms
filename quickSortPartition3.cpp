#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

 void partition3(vector<int> &a, int l, int r, int first, int last) {
	int x = a[l];
	int j = l;
	first = 0;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < x) {
			j++;
			swap(a[i], a[j]);
		}

		else if (a[i] == x) {
			j++;
			swap(a[i], a[j]);
			if(first==0)
				first = j;
		}

		last = j;
	}
	swap(a[l], a[j]);
	//return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}
	int first = 0; int last=0;
	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	partition3(a, l, r, first, last);

	randomized_quick_sort(a, l, first - 1);
	randomized_quick_sort(a, last + 1, r);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}

	system("pause");
}
