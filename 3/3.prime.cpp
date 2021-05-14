#include <iostream>
using namespace std;

int main(){
  int n,k;
  cin>>n;

  for (int i=2;i<n;i++){
    k=n%i;
    if (k==0){
      cout<<"0"<<endl;
      exit(0);
    }
  }
  cout<<"1"<<endl;

  return 0;


}
