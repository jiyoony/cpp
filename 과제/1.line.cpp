#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int k=n;
  for (int j=1;j<(n+1)/2;j++){
    for(int i=1;i<n+1;i++){
      if(i==(n+1)/2){
        cout<<"I";
      }
      else if(i==k){
        cout<<"*";
        k-=1;
      }
      else cout<<".";
    }
    cout<<"\n";
}
  for (int i=1;i<n+1;i++){
    if(i==(n+1)/2){
      cout<<"O";
    }
    else cout<<"+";

    }
    cout<<endl;

    k=(n-1)/2;
    for (int j=1;j<(n+1)/2;j++){
      for(int i=1;i<n+1;i++){
        if(i==(n+1)/2){
          cout<<"I";
        }
        else if(i==k){
          cout<<"*";
          k-=1;
        }
        else cout<<".";
      }
      cout<<"\n";
  }
    return 0;
}
