#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int plus1,plus2;
  int n;
  cin>>n;
  int arr[n][n];
  vector <int> plus(n*2,0);
  for (int i=0;i<n;i++){
      for (int j=0;j<n;j++)
        cin>>arr[i][j];
  }

//주 대각선
  // plus.push_back(0);
  for (int i=0;i<n;i++){
      plus[0]+=arr[i][i];
  }
// 역 주 대각선

  for (int i=0,j=n-1;i<n;i++,j--){
    plus[n]+=arr[i][j];
  }
//절단 대각선
  int k=n;
while(--k){
  for(int i=0,j=k;i<n;i++,j++){
        if (j==n) j=0;
        plus[k]+=arr[i][j];
  }
}
//역 절단 대각선
k=n;
while(--k){
  for(int i=0,j=k-1;i<n;i++,j--){
        if (j==-1) j=n-1;
        plus[k+n]+=arr[i][j];
        // cout<<"i="<<i<<" "<<"j="<<j<<" "<<plus[k+n]<<endl;
  }
}

  // for (int i=0;i<n*2;i++){
  //   cout<<plus[i]<<endl;
  // }
  sort(plus.begin(),plus.end(),greater<int>());
  cout<<plus[0]<<endl;

  return 0;

}
