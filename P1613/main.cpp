#include <iostream>
#include <cstring>

using namespace std;

constexpr int NMAX = 55;
constexpr int RMAX = 65;

int g[NMAX][NMAX]{};
bool f[NMAX][NMAX][RMAX]{};

int main()
{
	memset(g, 0x3f, sizeof(g));

	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u = 0, v = 0;
		cin >> u >> v;
		g[u][v] = 1;
		f[u][v][0] = true;
	}

	for (int t = 1; t <= 64; t++)
	{
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (f[i][k][t - 1] && f[k][j][t - 1])
					{
						f[i][j][t] = true;
						g[i][j] = 1;
					}
				}
			}
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	cout << g[1][n];

	return 0;
}
