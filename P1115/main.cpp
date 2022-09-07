#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

constexpr int NMAX = 200010;

int d[NMAX]{}, f[NMAX]{};

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	// Method1: Greedy
//	int sum = 0, maximum = INT_MIN;
//	for (int i = 0; i < n; i++)
//	{
//		sum += d[i];
//		maximum = max(maximum, sum);
//		if (sum < 0)
//		{
//			sum = 0;
//		}
//	}

	// Method2: DP
	f[1] = d[0];
	int maximum = INT_MIN;
	for (int i = 2; i <= n; i++)
	{
		f[i] = max(d[i - 1], f[i - 1] + d[i - 1]);
		maximum = max(maximum, f[i]);
	}

	cout << maximum;
	return 0;
}
