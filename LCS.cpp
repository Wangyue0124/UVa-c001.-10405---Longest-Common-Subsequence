#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string x,y;
	while (cin >> x, cin >> y) //輸入
	{
		int n = x.size(), m = y.size();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1));
		vector<char>ans;
		//LCS長度
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (x[i - 1] == y[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		//回朔
		while (n && m)
		{
			if (dp[n][m-1] == dp[n - 1][m] && dp[n][m] > dp[n-1][m - 1])
			{
				ans.push_back(x[n - 1]);
				n--;
				m--;
			}
			else if (dp[n][m] == dp[n - 1][m])
			{
				n--;
			}
			else
			{
				m--;
			}
		}
		//輸出
		int l = ans.size();
		cout << l << endl;
	}
	return 0;
}