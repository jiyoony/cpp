#include <iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int or_num=num;
    int res=0;
    int sum=0;

    while(sum!=1){
    if(sum==or_num*or_num){
      cout<<"UNHAPPY"<<endl;
      break;}
      sum=0;
      while(num>0){
        res =int(num%10);
        sum+=res*res;
        num =int(num/10);
      }
      num=sum;
  }
    if (sum==1) cout<<"HAPPY"<<endl;
  return 0;
}
