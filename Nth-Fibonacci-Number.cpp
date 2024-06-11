#include<bits/stdc++.h>
using namespace std;
// fibonnaci
int func(int n){
   if(n == 0 || n == 1){
        return 1;
   }
   return func(n-1)+ func(n-2);
}


int main(){
    int n;
    cin>>n;
    cout << func(n);
}
