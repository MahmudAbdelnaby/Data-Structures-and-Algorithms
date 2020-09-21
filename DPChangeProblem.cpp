#include<iostream>
#include<vector>
#include<map>
using namespace std;

int DPChange(int money, vector<int> coins) {

	map<int, int> minNumb; //map the money to its corresponding amount of coins
	int numberCoins;
	minNumb[0] = 0;

	for (int m = 1; m <= money; m++) {
		minNumb[m] = 9999;
	}
	int m;
	for (m = 1; m <= money; m++) {
		
		for (int i = 0; i < coins.size(); i++) {
			if (m >= coins[i]) {
				numberCoins = minNumb[m - coins[i]] + 1;
				if (numberCoins < minNumb[m])
					minNumb[m] = numberCoins;
			}
		}
	}

	return minNumb[money];
}

int main() {
	int money;
	vector <int> coins = { 1 , 3 , 4 };

	cin >> money;
	cout << DPChange(money, coins) << endl;

	system("pause");

}