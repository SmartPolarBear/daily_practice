#include <iostream>

using namespace std;

static inline constexpr int lowbit(int x)
{
	return x & -x;
}

constexpr int NMAX = 500010;
int c[NMAX * 4]{}, a[NMAX];

void build(int n)
{
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] = a[i] - a[i - lowbit(i)];
	}
}

void add(int n, int k, int v)
{
	for (int i = k; i <= n; i += lowbit(i))
	{
		c[i] += v;
	}
}

int query(int r)
{
	int ret = 0;
	for (int i = r; i >= 1; i -= lowbit(i))
	{
		ret += c[i];
	}
	return ret;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(n);
	while (m-- > 0)
	{
		int k = 0, x = 0, y = 0;
		cin >> k >> x >> y;
		if (k == 1)
		{
			add(n, x, y);
		}
		else if (k == 2)
		{
			cout << query(y) - query(x - 1) << "\n";
		}
	}
	return 0;
}
