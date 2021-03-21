#include <iostream>
using namespace std;

int main(){
    int k;
    int p=1;
    cin>>k;

    for (int i=1;i<k+1;i++){
      for (int q=i;q>=1;q--){
        cout<<p++<<" ";

    }
    cout<<"\n";
  }
  return 0;
}
