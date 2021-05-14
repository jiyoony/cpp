#include<iostream>
#include<cmath>
using namespace std;

void nInput(int n, int arr[]);
void Compare(int a[], int b[], int tmp);
const int MAX = 132;

int main()
{
    int a, b;
    int A[MAX] = { 0 };
    int B[MAX] = { 0 };

    cin >> a;
    nInput(a, A);
    cin >> b;
    nInput(b, B);


    Compare(A, B, 1);
    Compare(A, B, 2);
    Compare(A, B, 3);

	return 0;
}

void nInput(int n, int arr[])
{
	int k;
	while (n--)
	{
		cin >> k;
		arr[k] = 1;
	}
}

void Compare(int a[], int b[], int tmp)
{
	int result[MAX] = { 0 };

	int count = 0;

	if (tmp == 1) {

		for (int i = 0; i < MAX; i++)
		{
			if (a[i] == 1 && b[i] == 1) {
				result[i] = 1;
				count++;
			}
		}
	}
	else if (tmp == 2)
	{

		for (int i = 0; i < MAX; i++)
		{
			if (a[i] == 1 || b[i] == 1) {
				result[i] = 1;
				count++;
			}
		}
	}
	else
	{

		for (int i = 0; i < MAX; i++)
		{
			if (a[i] == 1 && b[i] == 0) {
				result[i] = 1;
				count++;
			}
		}
	}

	cout << count << " ";
	for (int i = 0; i < MAX; i++)
	{
		if (result[i] == 1) cout << i << " ";
	}
	cout << '\n';
}
