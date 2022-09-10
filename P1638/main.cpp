#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

constexpr int NMAX = 1000010;
int a[NMAX]{};

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	unordered_map<int, int> masters{};
	masters[a[0]] = 1;
	int l = 0, r = 0, count = 1;
	int len = INT_MAX, lmin = 0, rmin = 0;

	while (l <= r && r < n)
	{
		if (count == m)
		{
			if (len > r - l + 1)
			{
				len = r - l + 1;
				lmin = l;
				rmin = r;
			}
			if (--masters[a[l++]] == 0)
			{
				count--;
			}
		}
		else
		{
			if (++masters[a[++r]] == 1)
			{
				count++;
			}
		}
	}

	cout << lmin + 1 << " " << rmin + 1;

	return 0;
}
