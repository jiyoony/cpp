#include <iostream>
using namespace std;

int main(){
        int k;
        cin>>k;
        for(int j = 1; j < (k+1) / 2; j++) {
                for(int i = k/2; i >= j; i--) {
                        cout<<"*";
                }
                for(int i=1; i<=j; i++) {
                        cout<<"+";
                }
                for(int i=1; i<j; i++) {
                        cout<<"+";
                }
                for(int i = k/2; i >= j; i--) {
                        cout<<"*";
                }

                cout<<endl;
        }

        for(int i = 0; i <k; i++) {
                cout<<"+";
        }
        cout<<endl;

        for(int j = 1; j <(k+1) / 2; j++) {
                for(int i = 0; i < j; i++) {
                        cout<<"*";
                }
                for(int i = k/2; i >= j; i--) {
                        cout<<"+";
                }
                for(int i=k/2; i>j; i--) {
                        cout<<"+";
                }
                for(int i = 0; i <j; i++) {
                        cout<<"*";
                }

                cout<<endl;
        }

        return 0;
}
