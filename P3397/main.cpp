#include <iostream>
#include <algorithm>

using namespace std;

constexpr int NMAX = 1010;

int diffs[NMAX][NMAX]{};

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;

		int xs = min(x1, x2), xt = max(x1, x2);
		int ys = min(y1, y2), yt = max(y1, y2);

		for (int x = xs; x <= xt; x++)
		{
			diffs[x][ys]++;
			diffs[x][yt + 1]--;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			diffs[i][j] += diffs[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << diffs[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
