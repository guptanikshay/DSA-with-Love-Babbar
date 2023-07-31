#include <bits/stdc++.h>
using namespace std;

// PS: You are given an integer 'n' denoting the length of a rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of length of 'x', 'y' or 'z'

// RECURSIVE APPROACH (TC=expo  SC=expo)
int solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;
    return max(a, max(b, c));
}
int cutSegments(int n, int x, int y, int z)
{
    int ans = solve(n, x, y, z);
    if (ans < 0)
        return 0;
    return ans;
}

// RECURSIVE APPROACH WITH MEMOIZATOIN
// TC=O(n)   SC=O(n)
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    int a = solve(n - x, x, y, z, dp) + 1;
    int b = solve(n - y, x, y, z, dp) + 1;
    int c = solve(n - z, x, y, z, dp) + 1;
    dp[n] = max(a, max(b, c));
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}

// TABULATION METHOD TC=O(N)  SC=O(N)
int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    if (dp[n] < 0)
        return 0;
    return dp[n];
}

int main()
{

    return 0;
}