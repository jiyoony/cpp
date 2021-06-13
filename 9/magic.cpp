#include <iostream>
using namespace std;

int main(){
  int Number,i, j;
  int MS[21][21] = {0, };
  int n;
  cin >> n;
  Number = 1;
  i = 1;
  j = (n / 2) + 1;
  MS[i][j] = Number;
  Number++;

  while (Number <= n*n){
      if ((Number-1)%n == 0){
        i++;
        MS[i][j] = Number;
        Number++;
      }
      else{
        if (i - 1 < 1){
          i = n;
          j++;
          MS[i][j] = Number;
          Number++;
        }
        else if (j + 1 > n){
          i--;
          j = 1;
          MS[i][j] = Number;
          Number++;
        }
        else{
          i--;
          j++;
          MS[i][j] = Number;
          Number++;
          }
      }
    }
// 결과 출력
for (i = 1; i <= n;i++){
  for (j = 1; j <= n;j++){
    cout << MS[i][j]<< " ";
    }
    cout << endl;
  }
return 0;
}
