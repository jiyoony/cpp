#include <iostream>
using namespace std;

int main(){
    int r,s,t;
    cin>>r>>s>>t;
    int arr[r][s];
    int arr2[s][t];
    int res[r][t];

    for (int i=0;i<r;i++){
      for(int j=0;j<s;j++){
        cin>>arr[i][j];
      }
    }

      for (int i=0;i<s;i++){
        for(int j=0;j<t;j++){
          cin>>arr2[i][j];
        }
      }

        for(int i=0;i<r;i++)
          for(int j=0;j<t;j++){
            res[i][j]=0;
            for(int k=0;k<s;k++)
              res[i][j]+=arr[i][k]*arr2[k][j];
          }

      for (int i=0;i<r;i++){
          for(int j=0;j<t;j++){
            cout<<res[i][j]<<" ";
          }
          cout<<endl;
        }

          return 0;

}
