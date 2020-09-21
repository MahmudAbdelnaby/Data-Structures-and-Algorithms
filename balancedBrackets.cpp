#include<iostream>
#include<string>
#include<stack>
#include <utility> 

using namespace std;

void isBalanced(string s) {

	stack < pair < char, int > > store;
	int flag = 0;

	for (unsigned int i = 0; i < s.length(); i++) {
		if (flag == 1)
			break;
		switch (s[i])
		{
		case '[':
			store.push(make_pair('[', i));
			break;
		case '(':
			store.push(make_pair('(', i));
			break;
		case '{':
			store.push(make_pair('{', i));
			break;
		case ']':
			if (!store.empty()) {
				if (store.top().first == '[')
					store.pop();
				else {   //mismatch
					flag = 1;
					cout << i + 1 << endl; //position of the char that caused mismatch
				}
					
			}
			else {
				flag = 1;
				cout << i + 1 << endl;
			}
			break;

		case ')':
			if (!store.empty()) {
				if (store.top().first == '(')
					store.pop();
				else {
					flag = 1;
					cout << i + 1 << endl;
				}

			}
			else {
				flag = 1;
				cout << i + 1 << endl;
			}
			break;

		
		case '}':
			if (!store.empty()) {
				if (store.top().first == '{')
					store.pop();
				else {
					flag = 1;
					cout << i + 1 << endl;
				}

			}
			else {
				flag = 1;
				cout << i + 1 << endl;
			}
			break;

		default:
			break;
		}
		

	}

	if (!store.empty() && flag!=1){
		flag = 1;
		cout << store.top().second + 1 << endl;
	}

	if (flag == 0)
		cout << "Success" << endl;
		
}

int main() {
	string s;
	cin >> s;
	isBalanced(s);
 
	system("pause");
}
