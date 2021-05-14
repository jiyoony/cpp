#include <iostream>
using namespace std;

int main(){
    int a,b,n,w,x,y;
    cin>>a>>b>>n>>w;

    if (a==b){
      if (n*a==w && n==2){
        x=1;
        y=1;
        cout<<x<<" "<<y<<endl;
        exit(0);
      }
      else{
        cout<<"-1"<<endl;
        exit(0);
      }

    }

    else{x=(w-b*n)/(a-b);
    y=n-x;}

    if ((w-b*n)%(a-b)!=0||x<=0||y<=0){
      cout<<"-1"<<endl;
    }
    else cout<<x<<" "<<y<<endl;

    return 0;

}
