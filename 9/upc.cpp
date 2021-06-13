#include <iostream>
#include <string>
using namespace std;

void leftch(string n);
void final(string k);
void change(string n);
string cord;

void check(string n){
  string str1="101";
  string mid="01010";
  if(n.length()!=95){
    cout<<"******_******"<<endl;
    exit(0);
  }
  else if(str1.compare(n.substr(0,3))!=0){
    cout<<"******_******"<<endl;
    exit(0);
  }
  else if(str1.compare(n.substr(92,3))!=0){
    cout<<"******_******"<<endl;
    exit(0);
  }
  else if(mid.compare(n.substr(45,5))!=0){
    cout<<"******_******"<<endl;
    exit(0);
  }
  else change(n);

}
string ReverseString(const string src, int len)
{
      string reverse;
      for(int i=0;i<len;i++)
            reverse+=src.substr(len-i-1,1);
      return reverse;
}

int checkr2=0;
int checkl2;
string num;
int checkr=0;
int checkl=0;
void rightch(string n){
  if (n=="1110010")  num.push_back('0');
  else if(n=="1100110")  num.push_back('1');
  else if(n=="1101100")  num.push_back('2');
  else if(n=="1000010")  num.push_back('3');
  else if(n=="1011100")  num.push_back('4');
  else if(n=="1001110")  num.push_back('5');
  else if(n=="1010000")  num.push_back('6');
  else if(n=="1000100")  num.push_back('7');
  else if(n=="1001000")  num.push_back('8');
  else if(n=="1110100")  num.push_back('9');
  else{
    if(checkr==1) checkr2=1;
    checkr=1;
    string k=ReverseString(cord,95);
    for(int i=50;i<92;i+=7){
      if(checkr==1&&checkr2==1) {
        cout<<"******_******"<<endl;
        exit(0);
      }
       rightch(k.substr(i,7));
     }
    }
}

void leftch(string n){
  if (n=="0001101") num.push_back('0');
  else if(n=="0011001")  num.push_back('1');
  else if(n=="0010011")  num.push_back('2');
  else if(n=="0111101")  num.push_back('3');
  else if(n=="0100011")  num.push_back('4');
  else if(n=="0110001")  num.push_back('5');
  else if(n=="0101111")  num.push_back('6');
  else if(n=="0111011")  num.push_back('7');
  else if(n=="0110111")  num.push_back('8');
  else if(n=="0001011")  num.push_back('9');
  else { //오른 쪽부터 읽음
  if(checkl==1) checkl2=1;
  checkl=1;
  string k=ReverseString(cord,95);
  for(int i=3;i<43;i+=7) {
    if(checkl==1&&checkl2==1) {
      cout<<"******_******"<<endl;
      exit(0);
    }
    leftch(k.substr(i,7));
  }

  }
}

void change(string n){
  for(int i=3;i<43;i+=7){
    leftch(n.substr(i,7));
    if(checkl==1) break;
  }

  for(int i=50;i<92;i+=7){
    rightch(n.substr(i,7));
    if(checkr==1) break;
  }
  final(num);
}

void final(string k){
  int check=0;
  int checknum=k[11]-48;
  for(int i=0;i<12;i+=2){
    check+=k[i]-48;
  }
  check*=3;
   for(int i=1;i<11;i+=2){
      check+=k[i]-48;
  }
  if (check%10==0) check=0;
  else check=(10-check%10);

  if(checknum==check) cout << num.substr(0,6) << "-" << num.substr(6,6)<<endl;
  else cout << num.substr(0,6) << "-" << num.substr(6,6) << "*"<<check<<endl;
}

int main(){
  cin>>cord;
  check(cord);
  return 0;
}
