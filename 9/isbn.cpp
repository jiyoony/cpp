#include<iostream>
#include<string>
#include<cstdlib>
#include<cctype>
using namespace std;

int checkisbn(string str);
int main()
{
		string str;
		int cnt = 0;
		cin >> str;

		if (str[0] == '-' || str[str.size() - 1] == '-' || str[str.size() - 1] == 'x')
			cout << 0 << endl;

		else if (str.length() != 13)
			cout << 0 << endl;

		else if (str[str.size() - 2] != '-')     //네번째 부분의 자리수가 한 자리가 아닐경우
			cout << 0 << endl;

		else {

			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == '-')
					cnt++;
			}
			if (cnt == 3)
				cout << checkisbn(str) << endl;
			else
				cout << 0 << endl;

	}
}
int checkisbn(string str)
{
	int sum = 0, count = 0, check = 0;
	int arr[10] = { 0 };

	int mark1, mark2, mark3;
	mark1 = str.find('-');
	mark2 = str.find('-', mark1 + 1);
	mark3 = str.find('-', mark2 + 1);

	//'-'기준으로 나누기
	string nation, publish, book, checksum;
	nation = str.substr(0, mark1);
	publish = str.substr(mark1 + 1, mark2 - mark1 - 1);
	book = str.substr(mark2 + 1, mark3 - mark2 - 1);
	checksum = str.substr(mark3 + 1, str.size());

	//전체길이는 10
	string isbn = nation + publish + book + checksum;
	if (isbn.size() != 10)
		return 0;
	//각각 길이 check
	if (nation.size() > 5 || nation.size() < 1) {
		return 0;
	}
	else if (publish.size() > 7 || publish.size() < 1) {
		return 0;
	}
	else if (book.size() > 6 || book.size() < 1) {
		return 0;
	}
	else if (checksum.size() != 1) {
		return 0;
	}
	//올바른 문자인지 확인
	for (int i = 0; i < nation.size(); i++) {
		if (!(nation[i] >= '0' && nation[i] <= '9')) {
			return 0;
		}
	}
	for (int i = 0; i < publish.size(); i++) {
		if (!(publish[i] >= '0' && publish[i] <= '9')) {
			return 0;
		}
	}
	for (int i = 0; i < book.size(); i++) {
		if (!(book[i] >= '0' && book[i] <= '9')) {
			return 0;
		}
	}
	if (!((checksum[0] >= '0' && checksum[0] <= '9') || checksum[0] == 'X')) {
		return 0;
	}
	//checksum 확인
	int j = 0;
	for (int i = 0; i < isbn.size(); i++)
	{
		arr[j] = isbn[i] - '0';
		if (isbn[isbn.size() - 1] == 'X')
			arr[9] = 10;
		j++;
	}
	int total = 0;
	sum = arr[0] * 10 + arr[1] * 9 + arr[2] * 8 + arr[3] * 7 + arr[4] * 6 + arr[5] * 5 + arr[6] * 4 + arr[7] * 3 + arr[8] * 2;
	check = sum % 11;
	if (check != 0)
	{
		for (int n = 0; n < sum; n++)
		{
			total = n * 11;
			if (total > sum)
				break;
		}
		check = total - sum;
	}

	if (check == arr[9])
		return 1;
	else
		return 0;
}
