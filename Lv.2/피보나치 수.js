var dp = Array(100001).fill(0);
function solution(n) {
    dp[0]=0;dp[1]=1;
    for(let i=2;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    }
    return dp[n];
}