// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
//
// // int parity1(vector<int> vect)
// // {
// //
// // }
//
//
// int main()
// {
//   int k,n;
//   vector<int> bit26(32);
//   vector<int> bit32(32);
//   cin>>k;
//   cin>>n;
//   if (k==0)
//   {
//     bitset<26> bit(n); //2진수변환
//     // int num;
//     // num=bit.to_ulong(); //int 형으로 바꾸기
//     string s = bit.to_string();
//     cout<<"s="<<s<<endl;
//     for (char c : s) {
//         cout << c << " ";
//         bit26.push_back(c);
//     }
//
//     // for(int i=0;i<bit26.size();i++)
//     //     bit26[i]=;
//         // &bit26[i]
//     // for(int i=0;i<bit26.size();i++)
//     //   cout<<bit26[i];
//   }
//   // else
//   // {
//   //   bitset<32> bit(n);
//   //   for(int i=0;i<bit26.size();i++)
//   //     scanf("%1d",&bit26[i]);
//   //
//   // }
//   return 0;
// }
#include "MyHammingCode.h"
// constructors

MyHammingCode::MyHammingCode()
	:value(0)
{
}
MyHammingCode::MyHammingCode(unsigned int val)
	: value(val)
{
}
// utility functions
unsigned int MyHammingCode::getEncodedValue()
{
	encodedValue = 0;
	encodedValue |= copyBits(value, 0, 1, 2);
	encodedValue |= copyBits(value, 1, 3, 4);
	encodedValue |= copyBits(value, 4, 7, 8);
	encodedValue |= copyBits(value, 11, 15, 16);
	encodedValue = setParityBit(encodedValue, 1);
	encodedValue = setParityBit(encodedValue, 2);
	encodedValue = setParityBit(encodedValue, 4);
	encodedValue = setParityBit(encodedValue, 8);
	encodedValue = setParityBit(encodedValue, 16);
	return encodedValue;
}
unsigned int MyHammingCode::getDecodedValue()
{
	int errorPos;
	decodedValue = 0;
	errorPos = checkParityBit(value);
	if (errorPos > 0)
		value = negateBit(value, errorPos - 1);
	decodedValue |= copyBits(value, 2, 1, 0);
	decodedValue |= copyBits(value, 4, 3, 1);
	decodedValue |= copyBits(value, 8, 7, 4);
	decodedValue |= copyBits(value, 16, 15, 11);
	return decodedValue;
}
/*
* 정수 n의 from-번째 비트부터 num개의 비트를
* 다른 정수 num의 to-번째 비트로 복사하는 함수
*/
unsigned int MyHammingCode::copyBits(unsigned int n, int from, int num, int to)
{
	unsigned int mask = 0;
	unsigned int code = 0;
	/* num 비트 만큼의 mask 를 만듬 */
	do
	{
		mask <<= 1;
		mask |= 0x01;
	} while (--num);
	/* n의 from-번째 비트부터 num개의 비트를 골라내어 복사함 */
	n >>= from;
	n &= mask;
	code |= n;
	code <<= to;
	return code;
}
/* 패리티 비트를 만드는 함수 */
unsigned int MyHammingCode::setParityBit(unsigned int n, int pos)
{
	unsigned int mask[5] = { 0x55555554, 0x66666664, 0x78787870,
	0x7F807F00, 0x7FFF0000 };
	int count;
	unsigned int checkBits;
	switch (pos)
	{
	case 1:
		checkBits = n & mask[0];
		break;
	case 2:
		checkBits = n & mask[1];
		break;
	case 4:
		checkBits = n & mask[2];
		break;
	case 8:
		checkBits = n & mask[3];
		break;
	case 16:
		checkBits = n & mask[4];
		break;
	}
	count = hammingWeight(checkBits);
	if (count % 2)
		n = setBit(n, pos - 1);
	return n;
}
/*
* 패리티 비트를 검사하는 함수
* 단, 에러가 발생하는 경우에는 한 비트에서만 오류가 발생한 것을 가정하여,
* 에러가 발생한 비트의 위치를 찾아서 리턴해준다.
*/
unsigned int MyHammingCode::checkParityBit(unsigned int n)
{
	int result = 0;

	int mask[5] = { 0x55555554 , 0x66666664 , 0x78787870 , 0x7F807F00 , 0x7FFF0000 };

	int pos1 = n & mask[0];
	int pos2 = n & mask[1];
	int pos4 = n & mask[2];
	int pos8 = n & mask[3];
	int pos16 = n & mask[4];

	int arr[5] = { pos1 , pos2 , pos4 , pos8 , pos16 };
	int bit[5] = { 1,2,4,8,16 };
	int bitmask[5] = { 0x00000001 , 0x00000002 ,0x00000008, 0x00000080 , 0x00008000 };


	for (int i = 0; i < 5; ++i) {
		int count = 0;
		int dummy = arr[i];
		while (dummy > 0) {
			if (dummy % 2 == 1) {
				count++;
			}
			dummy /= 2;
		}

		int binary = n & bitmask[i];

		int bitcount = 0;
		while (binary > 0) {
			if (binary % 2 == 1) {
				bitcount++;
			}
			binary /= 2;
		}


		if ((count % 2) == bitcount) {
			result += 0;
		}
		else {
			result += bit[i];
			//cout << bit[i] << endl;
		}
	}
	return result;
}
/* 정수에서 비트가 1인 자리수의 개수를 계산하는 함수 */
int MyHammingCode::hammingWeight(unsigned int n)
{
	int x = n;
	int count = 0;
	while (x)
	{
		if (x % 2 == 1) {
			count++;
		}

		x = x / 2;
	}
	return count;
}
/* 정수의 pos 자리수의 비트를 1로 만드는 함수 */
unsigned int MyHammingCode::setBit(unsigned int n, int pos)
{
	unsigned int x = n;
	x += (int)pow(2, pos);

	return x;
}
/* 정수의 pos 자리수의 비트를 0으로 만드는 함수 */
unsigned int MyHammingCode::clearBit(unsigned int n, int pos)
{
	unsigned int x = n;
	x -= (int)pow(2, pos);

	return x;
}
/* 정수의 pos 자리수가 0인지 1인지를 확인하는 함수 */
int MyHammingCode::checkBit(unsigned int n, int pos)
{
	int x = n;
	int idx = 0;
	int arr[32] = { 0 };
	while (x)
	{
		if (x % 2 == 1) {
			arr[idx++] = 1;
		}
		else {
			arr[idx++] = 0;
		}

		x = x / 2;
	}

	if (arr[pos - 1] == 1) return 1;
	else return 0;


}
/* 정수의 pos 자리수를 반대로 만드는 함수 */
unsigned int MyHammingCode::negateBit(unsigned int n, int pos)
{
	int position = (int)pow(2, pos);
	int result = n ^ position;

	//cout << n << "  " << result << endl;

	return result;
}
/* Exclusive OR 를 계산하는 함수 */
unsigned int MyHammingCode::_xor(unsigned int x, unsigned int y)
{
	return !x ^ !y;
}
