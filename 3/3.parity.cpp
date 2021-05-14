#include <iostream>

using namespace std;

int main(){
  int cnt=0;
  long long int n;
  cin>>n;

  long long int tmp = n;


  while(tmp)
  {
    if(tmp % 2 == 1 ) cnt++;

    tmp = tmp / 2;
    cout<<tmp<<endl;
  }


  if(cnt % 2 == 0) cout << n<<" "<<cnt;
  else cout << n + 2147483648<<" "<<cnt;

  return 0;

}
