#include <iostream>
using namespace std;

int main(){
  string bracket;
  int fron=0;
  cin>>bracket;
  // cout<<bracket;

  // cout<<bracket.length()<<endl;


  for (int i=0;i<bracket.length();i++){
      if (bracket.at(i)=='('){
        fron+=1;
      }
      else {
        fron-=1;
        if (fron<0) {
          cout<<"0"<<endl;
          exit(0);
        }
  }
}
  if (fron==0)
  cout<<"1"<<endl;
  else
  cout<<"0"<<endl;
  return 0;
}
