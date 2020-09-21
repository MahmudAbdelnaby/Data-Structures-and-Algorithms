#include<iostream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string leftShiftCircular(string in, int shifts) {
	string out = in.substr(shifts, in.size() - shifts);
	for (int i = 0; i < shifts; i++) {
		out += in[i];
	}
	return out;
}

string hex2bin(string input_hex) {
	string input_binary = "";

	for (int i = 0; i < input_hex.size(); i++) {
		switch (input_hex[i])
		{
		case'0':
			input_binary += "0000";
			break;

		case'1':
			input_binary += "0001";
			break;

		case'2':
			input_binary += "0010";
			break;

		case'3':
			input_binary += "0011";
			break;

		case'4':
			input_binary += "0100";
			break;

		case'5':
			input_binary += "0101";
			break;

		case'6':
			input_binary += "0110";
			break;

		case'7':
			input_binary += "0111";
			break;

		case'8':
			input_binary += "1000";
			break;

		case'9':
			input_binary += "1001";
			break;

		case'A':
			input_binary += "1010";
			break;

		case'B':
			input_binary += "1011";
			break;

		case'C':
			input_binary += "1100";
			break;

		case'D':
			input_binary += "1101";
			break;

		case'E':
			input_binary += "1110";
			break;

		case'F':
			input_binary += "1111";
			break;

		default:
			break;
		}
	}
	return input_binary;
}

string bin2hex(string input_binary) {
	vector<string> temp;
	string out_hex = "";
	for (int i = 0; i < input_binary.size(); i += 4) {
		temp.push_back(input_binary.substr(i, 4));
	}

	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == "0000")
			out_hex += '0';
		else if (temp[i] == "0001")
			out_hex += '1';
		else if (temp[i] == "0010")
			out_hex += '2';
		else if (temp[i] == "0011")
			out_hex += '3';
		else if (temp[i] == "0100")
			out_hex += '4';
		else if (temp[i] == "0101")
			out_hex += '5';
		else if (temp[i] == "0110")
			out_hex += '6';
		else if (temp[i] == "0111")
			out_hex += '7';
		else if (temp[i] == "1000")
			out_hex += '8';
		else if (temp[i] == "1001")
			out_hex += '9';
		else if (temp[i] == "1010")
			out_hex += 'A';
		else if (temp[i] == "1011")
			out_hex += 'B';
		else if (temp[i] == "1100")
			out_hex += 'C';
		else if (temp[i] == "1101")
			out_hex += 'D';
		else if (temp[i] == "1110")
			out_hex += 'E';
		else //(temp[i] == "1111")
			out_hex += 'F';
	}
	return out_hex;
}

string hex2binPermutation(string input_hex) {
	string input_binary = "0";

	for (int i = 0; i < input_hex.size(); i++) {
		switch (input_hex[i])
		{
		case'0':
			input_binary += "0000";
			break;

		case'1':
			input_binary += "0001";
			break;

		case'2':
			input_binary += "0010";
			break;

		case'3':
			input_binary += "0011";
			break;

		case'4':
			input_binary += "0100";
			break;

		case'5':
			input_binary += "0101";
			break;

		case'6':
			input_binary += "0110";
			break;

		case'7':
			input_binary += "0111";
			break;

		case'8':
			input_binary += "1000";
			break;

		case'9':
			input_binary += "1001";
			break;

		case'A':
			input_binary += "1010";
			break;

		case'B':
			input_binary += "1011";
			break;

		case'C':
			input_binary += "1100";
			break;

		case'D':
			input_binary += "1101";
			break;

		case'E':
			input_binary += "1110";
			break;

		case'F':
			input_binary += "1111";
			break;

		default:
			break;
		}
	}
	return input_binary;
}

string _56straightPermutation(int table[], string input_hex) {
	string input_binary = hex2binPermutation(input_hex);
	string out_binary = "";
	for (int i = 1; i <= 56; i++) {
		out_binary += input_binary[table[i]];
	}
	return out_binary;
}

string _48straightPermutation(int table[], string input_hex) {
	string input_binary = hex2binPermutation(input_hex);
	string out_binary = "";
	for (int i = 1; i <= 48; i++) {
		out_binary += input_binary[table[i]];
	}
	return out_binary;
}

int main() {
	
	int PC1 [] = {0, 57, 49, 41, 33, 25, 17, 9, 1, 
				58, 50, 42, 34, 26, 18, 10, 2,
				59, 51, 43, 35, 27, 19, 11, 3, 
				60, 52, 44, 36, 63, 55, 47, 39,
				31, 23, 15, 7, 62, 54, 46, 38, 
				30, 22, 14, 6, 61, 53, 45, 37, 
				29, 21, 13, 5, 28, 20, 12, 4 };

	int PC2[] = { 0, 14, 17, 11, 24, 1, 5, 3, 28,
				  15, 6, 21, 10, 23, 19, 12, 4,
				  26, 8, 16, 7, 27, 20, 13, 2, 
				  41, 52, 31, 37, 47, 55, 30, 40,
				  51, 45, 33, 48, 44, 49, 39, 56, 
				  34, 53, 46, 42, 50, 36, 29, 32 };

	int shifts[] = { 1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28 };

	vector<string> output;
	
	string keyHex;
	cin >> keyHex;

	string keyBin = hex2bin(keyHex);
	string _56key = _56straightPermutation(PC1, keyHex);
	string leftKey, rightKey;
	leftKey = _56key.substr(0, _56key.size() / 2);
	rightKey = _56key.substr(_56key.size() / 2, _56key.size() / 2);

	for (int i = 0; i < 16; i++) {
		string temp1, temp2, temp3, temp4, temp5, temp6;
		temp1 = leftShiftCircular(leftKey, shifts[i]);
		temp2 = leftShiftCircular(rightKey, shifts[i]);
		temp3 = temp1 + temp2;
		temp4 = bin2hex(temp3);
		temp5 = _48straightPermutation(PC2, temp4);
		temp6 = bin2hex(temp5);
		output.push_back(temp6);
	}

	for (int i = 0; i < 16; i++) {
		cout << output[i] << endl;
	}



	//system("pause");
}