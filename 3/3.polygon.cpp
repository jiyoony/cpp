#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;

  int xarr[n],yarr[n];
  int space=0;
  for (int i=0;i<n;i++){
    cin>>xarr[i]>>yarr[i];
  }

  for (int i=0;i<n-1;i++){
    space+=(xarr[i]+xarr[i+1])*(yarr[i+1]-yarr[i]);
}
  space+=(xarr[n-1]+xarr[0])*(yarr[0]-yarr[n-1]);
if (space<0)
  cout<<(-1)*space<<" "<<"-1"<<endl;
else
  cout<<space<<" "<<"1"<<endl;
return 0;
}
