#include <iostream>
#include <cmath>
using namespace std;

int main(){
        int ax,ay,bx,by,cx,cy,a,b,c;
        int max=0,mid=0,sma=0;
        cin>>ax>>ay>>bx>>by>>cx>>cy;

        a=(bx-ax)*(bx-ax)+(by-ay)*(by-ay);
        b=(cx-ax)*(cx-ax)+(cy-ay)*(cy-ay);
        c=(bx-cx)*(bx-cx)+(by-cy)*(by-cy);

        if ( a < b ) {
                if ( b < c ) {
                        max = c;
                        mid =a;
                        sma=b;
                }
                else{
                        max = b;
                        mid =a;
                        sma=c;
                }
        }else {
                if ( a < c) {
                        max = c;
                        mid =a;
                        sma=b;
                }
                else{
                        max = a;
                        mid =c;
                        sma=b;
                }
        }

        if (sqrt(max)>=sqrt(mid)+sqrt(sma)) {
                cout<<"0";
        }
        else{
                if (max==(mid+sma)) {
                        cout<<"1";
                }
                else if(max>(mid+sma)) {
                        cout<<"2";
                }
                else if(max<(mid+sma)) {
                        cout<<"3";
                }
        }

        return 0;


}
