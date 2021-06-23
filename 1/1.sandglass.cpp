#include <iostream>
using namespace std;

int main(){
    int nNum;
    cin>>nNum;


   int i = 0, j = 0, k = 0;
       for (i = 0; i < nNum; i+=2){
           for (k = 0; k < i; k+=2){
             cout<<"-";}
           for (j = 0; j < nNum-i; j++){
           if (j%2){
                 cout<<"+";
               }
               else cout<<"*";
             }
             for(j=1;j<i;j+=2){
               cout<<"-";
                }
           cout<<"\n";
       }

       for (i = nNum-2; i > 0; i-=2){
           for (k = 1; k < i; k+=2){
             cout<<"-";}
           for (j = 0; j <= nNum-i; j++){
           if (j%2){
                 cout<<"+";
               }
               else cout<<"*";
             }
          for(j=1;j<i;j+=2){
            cout<<"-";
             }
           cout<<"\n";
         }

  return 0;

}
