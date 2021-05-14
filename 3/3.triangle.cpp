#include <iostream>
using namespace std;

int main(){
  int ax,ay,bx,by,cx,cy,space;
  cin>>ax>>ay>>bx>>by>>cx>>cy;

  space=((bx-ax)*(cy-ay)-(cx-ax)*(by-ay));

  if (space >0)
  cout<<space<<" "<<1<<endl;
  else if(space <0)
  cout<<(-1)*space<<" "<<-1<<endl;
  else
  cout<<space<<" "<<0<<endl;

  return 0;


}
