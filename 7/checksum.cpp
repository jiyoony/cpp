#include <iostream>
#include <bitset>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
int twoConvertTen(int num)
{
  int result=0,mul=1;
  while(num>0)
  {
    if(num%2)
    result+=mul;
    mul*=2;
    num/=10;
  }
  return result;
}

int main(){
  unsigned n;
  int hap=0;
  cin>>n;
  bitset<32> bit(n);

  string str;
  str=bit.to_string();
  string k;
  for(int i=0;i<4;i++){
    k=str.substr(i*8,8);
    if (i!=3){
      int q=stoi(k);
      int p=twoConvertTen(q);
      hap+=p;
    }
    else{
      int q=stoi(k);
      int p=twoConvertTen(q);
      while(hap>=256)
      {
          hap-=256;
      }
      hap=255-hap;
      if(hap==p) cout<<"1"<<endl;
      else cout<<"0"<<endl;
    }
  }

  return 0;
}
