#include <iostream>
#include <string>
#include <regex>
using namespace std;

// 1로 시작하면 무조건 다음에 0이 2개이상 나와야한다.
// 1로 시작하고 다음 1이 나오면 1이 0개 이상 나온다.
// 그 다음 00인 경우, 01인 경우

// 0으로 시작하면 다음은 무조건 1.

bool __regex(string str) {
	int len = str.size(), index;

	for (int i = 0; i < len; i++) {

		switch (str[i]) {
		case '0':
			i++;
			if (i == len || str[i] == '0') return false;
			break;

		case '1':
			i++;
			index = str.find('1', i);
			if (index == -1 || index - i < 2) return false;

			i = index;
			index = str.find('0', i);
			if (index == len - 1) return false;
			if (index == -1) return true;
			
			if (index - i > 1 && str[index + 1] == '0') i = index - 2;
			else i = index - 1;
			break;
		}

	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	string str;
	cin >> T;
	/*while (T--) {
		cin >> str;
		cout <<( __regex(str) ? "YES" : "NO" )<< '\n';
	}*/
	regex pattern("(100+1+|01)+");
	while (T--) {
		cin >> str;
		if (regex_match(str, pattern)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}