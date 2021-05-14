#include <iostream>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int cell[51]={0,};
  int cellnew[51]={0,};
  for(int i=1;i<n+1;i++){
    cin>>cell[i];
  }

while(k--){
  for(int i=1;i<n+1;i++){
    int q=cell[i-1]+cell[i+1];
    if (q>7){
        cellnew[i]=cell[i]-1;
  }
    else if (q<3){
      cellnew[i]=cell[i]-1;
}
    else if (q==3){
      cellnew[i]=cell[i];
    }
    else if (q>=4 &&q<=7){
      cellnew[i]=cell[i]+1;
}
    if (cellnew[i]<0) cellnew[i]=0;
    else if (cellnew[i]>9) cellnew[i]=9;
}
  for(int p=1;p<n+1;p++){
    cell[p]=cellnew[p];
}
}

  for(int i=1;i<n+1;i++){
    cout<<cellnew[i]<<" ";
  }
  cout<<endl;

return 0;

}

//
// #include<iostream>
// using namespace std;
// void lifegame(int arr[], int length,int time);
// int main() {
// 		int length, time;
// 		int arr[50] = { 0, };
// 		cin >> length >> time;
// 		for (int j = 0; j < length; j++) {
// 			int data;
// 			cin >> data;
// 			arr[j] = data;
// 		}
// 		lifegame(arr, length, time);
//
// }
//
// void lifegame(int arr[], int length,int time) {
// 	int change[50] = { 0, };
// 	int num;
// 	while (time--) {
// 		for (int i = 0; i < length; i++) {
// 			if (i == 0) {
// 				num = arr[i + 1];
// 			}
// 			else if (i == length - 1) {
// 				num = arr[i - 1];
// 			}
// 			else {
// 				num = arr[i - 1] + arr[i + 1];
// 			}
// 			if (num < 3) {
// 				change[i] = arr[i]-1;
// 			}
// 			else if (num > 3 && num <= 7) {
// 				change[i] = arr[i]+1;
// 			}
// 			else if (num == 3) {
// 				change[i] = arr[i];
// 			}
// 			else change[i] = arr[i]-1;
//
// 			if (change[i] > 9) change[i] = 9;
// 			else if (change[i] < 0) change[i] = 0;
// 		}
// 		for (int j = 0; j < length; j++) {
// 			arr[j] = change[j];
// 		}
//
// 	}
// 	for (int i = 0; i < length; i++) {
// 		cout << change[i] << " ";
// 	}
// 	cout << endl;
// }
