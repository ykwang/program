#include<stdio.h>
long long ClimbStairs(int n)
{
    long long dp[3] = { 1, 1 };
    if (n < 2)
    {
        return n;
    }
    for (int i = 2; i <= n; i++)
    {
        dp[2] = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}
int main()
{
       int n;
       while(scanf("%d",&n)!=EOF){
               printf("%lld\n",ClimbStairs(n));
       }
    return 0;
}