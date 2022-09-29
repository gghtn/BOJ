#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;

	cin.ignore();	//getline의 개행문자 입력 방지
	while (n--) {
		getline(cin, str);
		if(str[0] >= 97 && str[0] <= 122) cout << char(str[0] - 32);
		else cout << str[0];
		try
		{
			cout << str.substr(1);
		}
		catch (const std::exception&)
		{

		}
		cout << '\n';
	}

	return 0;
}