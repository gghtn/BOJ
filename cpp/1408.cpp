#include <iostream>
#include <algorithm>  //remove()
#include <string>
using namespace std;

int main() {
	string now, start;
	cin >> now >> start;
	
	// 문자열에서 특정문자 제거
	now.erase(remove(now.begin(), now.end(), ':'), now.end());
	start.erase(remove(start.begin(), start.end(), ':'), start.end());

    //문자열 자르기
	int n, s, result = 0;
	n = stoi(now.substr(0, 2)) * 3600 + stoi(now.substr(2, 2)) * 60 + stoi(now.substr(4, 2));
	s = stoi(start.substr(0, 2)) * 3600 + stoi(start.substr(2, 2)) * 60 + stoi(start.substr(4, 2));


	if (n < s) result = s - n;
	else result = 24 * 3600 - (n - s);
	int hour = result / 3600, minute = (result % 3600) / 60, second = (result % 3600) % 60;
	printf("%02d:%02d:%02d", hour, minute, second);

	return 0;
}