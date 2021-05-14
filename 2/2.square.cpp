#include <iostream>
#include <cmath>
using namespace std;

int main(){
        int x1,y1,x2,y2,x,y,sx,sy;
        cin>>x1>>y1>>x2>>y2>>x>>y;
        int d1,d2;

        if (y1<=y&&y<=y2) {
                sy=y;
                if (x1<=x&&x<=x2) {
                        cout<<"0"<<" 0"<<endl;
                        exit(0);
                }
        }
        else if (y2<=y) sy=y2;
        else sy=y1;

        if (x1<=x&&x<=x2) sx=x;
        else if (x2<=x) sx=x2;
        else sx=x1;

        d2=(sx-x)*(sx-x)+(sy-y)*(sy-y);
        d1=abs(sx-x)+abs(sy-y);

        cout<<d2<<" "<<d1<<endl;

        return 0;

}
