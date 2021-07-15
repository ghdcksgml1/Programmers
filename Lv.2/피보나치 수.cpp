#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dp[100001]={0,};
int fibonacci(int x){
    if(x==0) return 0;
    if(x==1) return 1;
    if(dp[x]!=0) return dp[x];
    return dp[x]=(fibonacci(x-1)+fibonacci(x-2))%1234567;
}

int solution(int n) {
    return fibonacci(n);
}