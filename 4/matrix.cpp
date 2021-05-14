#include <iostream>
using namespace std;

int main(){
  int r,c;
  cin>>r>>c;
  int arr3[r][c];
  int arr1[r][c];
  for (int i=0;i<r;i++)
    for(int j=0;j<c;j++){
      cin>>arr1[i][j];
    }

    int arr2[r][c];
    for (int i=0;i<r;i++)
      for(int j=0;j<c;j++){
        cin>>arr2[i][j];
      }

    for (int i=0;i<r;i++)
      for(int j=0;j<c;j++){
        arr3[i][j]=arr1[i][j]+arr2[i][j];
        }


    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
          cout<<arr3[i][j]<<" ";
          }
          cout<<endl;
        }


    return 0;
}
