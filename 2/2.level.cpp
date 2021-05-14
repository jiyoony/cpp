#include <iostream>
using namespace std;

int main(){
        int x1,x2,y1,y2,x3,x4,y3,y4;
        cin>>x1>>x2>>y1>>y2>>x3>>x4>>y3>>y4;

        if (x3<x1&&x1<y3||y3<x1&&x1<x3||x1<x3&&x3<y1||y1<x3&&x3<x1) {
                if(x2<y4&&y4<y2||x2>y4&&y4>y2||x4<x2&&x2<y4||y4<x2&&x2<x4) {
                        cout<<"1";
                }
                else if(x2==y4||y3==y4||x2==y3)
                        cout<<"2";
                else cout<<"0";
        }
        else if (x1==x3||x1==y3||y1==x3) {
                if(x2<x4&&x4<y2||x2>x4&&x4>y2||x4<x2&&x2<y4||x4<y2&&y2<y4) {
                        cout<<"2";
                }
                else if(x2==x4||y2==x4||x2==y4)
                        cout<<"2";
                else cout<<"0";
        }
        else cout<<"0";
        return 0;


}
