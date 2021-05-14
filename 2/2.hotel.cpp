#include <iostream>
using namespace std;

int main(){
        int h,w,n,floor,room;
        cin>>h>>w>>n;

        floor=n%h;
        if (floor==0) {
          floor=h;
          room=n/h;
        }else room=n/h+1;


        if (room<11)
        cout<<floor<<"0"<<room<<endl;
        else
        cout<<floor<<room<<endl;

        return 0;
}
