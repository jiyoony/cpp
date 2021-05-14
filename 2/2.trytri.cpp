#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;

  if (c>=a+b){
    cout<<"0";
  }
  else if(a==b&&b==c){
    cout<<"1";
  }
  else if((a*a+b*b)==c*c){
    cout<<"2";
  }
  else if(a==b||a==c||b==c){
    cout<<"3";
  }
  else cout<<"4";

  return 0;

}
