#include <iostream>
#include <string>
using namespace std;

int q;
int checknum;
bool company(string k){
  q=k.size();
  switch (k.front()) {
    case '3':
    {
      if (q==15||q==14) return true;
      else return false;
    }
    case '4':
    {
      if (q==13||q==16) return true;
      else return false;
    }
    case '5':
    {
        if (q==16) return true;
      else return false;
    }
    case '6':
    {
      if (q==16) return true;
      else return false;
    }
    default: return false;
  }

}

bool checksum(string k){
  int sum=0;
  int last=0;
  int now=1;
  while(k.size()){
    last=k[k.length()-1]-48;
    k.pop_back();
    if(now==1&&(last*2)>=10) {
      sum+=(last*2)-9;
      now=0;
    }
    else if(now==1) {
      sum+=last*2;
      now=0;
    }
    else {
      sum+=last;
      now=1;
    }
  }
  if ((checknum+sum)%10==0) return true;
  else return false;

}

int main(){
  string strcard;
  cin>>strcard;
  if(company(strcard)) {
    checknum=strcard[strcard.length()-1]-48;
    strcard.pop_back();
    if(checksum(strcard))cout<<"1"<<endl;
    else cout<<"0"<<endl;
  }
  else cout<<"0"<<endl;

  return 0;


}
