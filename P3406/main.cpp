#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int NMAX = 100010;

int diff[NMAX]{};

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	int s = 0;
	cin >> s;
	for (int i = 0; i < m - 1; i++)
	{
		int t = 0;
		cin >> t;

		diff[min(s, t)]++;
		diff[max(s, t)]--;

		s = t;
	}

	for (int i = 1; i <= n; i++)
	{
		diff[i] += diff[i - 1];
	}

	uint64_t sum = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		uint64_t a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		sum += min(diff[i] * a, c + diff[i] * b);
	}

	cout << sum;

	return 0;
}
