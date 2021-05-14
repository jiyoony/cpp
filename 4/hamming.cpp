// #include <iostream>
// #include <cmath>
// using namespace std;
//
// int chkHhamming (int n)
// {
// 	if (n == 1) return 1;
// 	if (n%2==0 || n%3==0 || n%5==0)
// 	{
// 		for (int i = 2; i < n; i++)
// 		{
// 			if (i%2 != 0 && i%3!=0 && i%5!=0) return 0;}
// 			// if (n%(n/i) == 0) {
// 			// 	if ((n/i)%2 != 0 and (n/i)%3!=0 and (n/i)%5!=0) return 0;
// 			// }
// 		}
// 		return n;
// 	}
//   else return 0;
// }
//
// int main (){
// 	  int n;
// 	  cin>>n;
// 		int count = 0;
// 		int i = 1;
//     int ham[7410]={0,};
//     int k = 0;
// 		while (count< n)
// 		{   k=chkHhamming(i);
// 			if (k){
//         ham[count]=k;
// 				++count;
// 			}
// 			++i;
//     }
// 	cout <<ham[n-1]<<endl;
// return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,i, j, k;
	vector<int> v;

	for (i = 1;; i = i * 2) {
		for (j = i;; j = j * 3) {
			for (k = j;; k = k * 5) {
				v.push_back(k);
				if (k > 2147483647 / 5) break;
			}
			if (j > 2147483647 / 3) break;
		}
		if (i > 2147483647 / 2) break;
	}

	sort(v.begin(), v.end());


		cin >> n;
		cout << v[n - 1] << "\n";
	return 0;
}
