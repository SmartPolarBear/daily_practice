#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

constexpr int NMAX = 125;
int d[NMAX][NMAX];

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] += d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1];
		}
	}

	int maximum = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = i; k <= n; k++)
			{
				for (int a = j; a <= n; a++)
				{
					int sum = d[k][a] - d[k][j - 1] - d[i - 1][a] + d[i - 1][j - 1];
					maximum = max(maximum, sum);
				}
			}
		}
	}

	cout << maximum;

	return 0;
}
