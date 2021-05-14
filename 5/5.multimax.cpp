#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> arr;
  vector<int> hap;

  int num,x,hap1;
  cin>>num;
  for(int i=0;i<num;i++){
      cin>>x;
      arr.push_back(x);
  }

  sort(arr.begin(),arr.end(),greater<int>());

  if(arr[0]!=0){
    hap1=arr[0]*arr[num-2]*arr[num-1];
    hap.push_back(hap1);
  }
  hap1=arr[num-2]*arr[num-1];
  hap.push_back(hap1);
  hap1=arr[0]*arr[1]*arr[2];
  hap.push_back(hap1);
  hap1=arr[0]*arr[1];
  hap.push_back(hap1);

  sort(hap.begin(),hap.end(),greater<int>());
  cout<<hap[0];

    return 0;
}
