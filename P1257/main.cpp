#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <cmath>
#include <cstdint>

using namespace std;

constexpr int NMAX = 10010;

using point_type = pair<double, double>;

point_type points[NMAX]{};

double dist(const point_type &a, const point_type &b)
{
	return std::sqrt(
		(double)(a.first - b.first) * (a.first - b.first) + (double)(a.second - b.second) * (a.second - b.second));
}

double dfs(int l, int r)
{
	double ret = INT_MAX;
	if (l == r)
	{
		return ret;
	}

	if (r == l + 1)
	{
		return dist(points[l], points[r]);
	}

	int mid = (l + r) >> 1;
	auto lval = dfs(l, mid);
	auto rval = dfs(mid + 1, r);

	ret = min(ret, lval);
	ret = min(ret, rval);

	for (int i = l; i < r; i++)
	{
		for (int j = i + 1; j <= r; j++)
		{
			ret = min(ret, dist(points[i], points[j]));
		}
	}

	return ret;
}

int main()
{
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> points[i].first >> points[i].second;
	}

	sort(points, points + n, [](const auto &a, const auto &b)
	{
		return a.first < b.first;
	});

	auto ret = dfs(0, n - 1);
	cout << fixed << setprecision(4) << ret;

	return 0;
}
