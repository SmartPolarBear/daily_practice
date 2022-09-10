#include <iostream>

using namespace std;

constexpr int MMAX = 2000010;
int d[MMAX]{};

int main()
{
	int m = 0;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		d[i] = i;
	}

	for (int i = 1; i < m; i++)
	{
		d[i] += d[i - 1];
	}

	int l = 1, r = 1;

	while (l <= r && r < m)
	{
		int sum = d[r] - d[l - 1];
		if (sum < m)
		{
			r++;
		}
		else if (sum > m)
		{
			l++;
		}
		else
		{
			cout << l << " " << r << "\n";
			l++;
			r++;
		}
	}

	return 0;
}
