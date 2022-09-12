#include <iostream>
#include <cstdint>

using namespace std;

constexpr int NMAX = 100010;
int a[NMAX]{};
uint64_t f[NMAX * 4]{}, lazy[NMAX * 4]{};

void push_up(int root)
{
	f[root] = f[2 * root] + f[2 * root + 1];
}

void push_down(int root, int len)
{
	int rlen = len / 2, llen = len - len / 2;

	f[2 * root] += llen * lazy[root];
	lazy[2 * root] += lazy[root];

	f[2 * root + 1] += rlen * lazy[root];
	lazy[2 * root + 1] += lazy[root];

	lazy[root] = 0;
}

void build(int root, int s, int t)
{
	if (s == t)
	{
		f[root] = a[s];
		return;
	}

	int mid = (s + t) / 2;
	build(2 * root, s, mid);
	build(2 * root + 1, mid + 1, t);
	push_up(root);
}

void update_point(int root, int s, int t, int pt, uint64_t c)
{
	if (s == t)
	{
		f[pt] += c;
		return;
	}

	int mid = (s + t) / 2;
	if (pt < mid)
	{
		update_point(2 * root, s, mid, pt, c);
	}
	else
	{
		update_point(2 * root + 1, mid + 1, t, pt, c);
	}
	push_up(root);
}

void update_seg(int root, int s, int t, int l, int r, uint64_t c)
{
	if (l <= s && t <= r)
	{
		f[root] += (t - s + 1) * c;
		lazy[root] += c;
		return;
	}

	if (lazy[root])
	{
		push_down(root, t - s + 1);
	}

	int mid = (s + t) / 2;

	if (l <= mid)
	{
		update_seg(2 * root, s, mid, l, r, c);
	}

	if (mid + 1 <= r)
	{
		update_seg(2 * root + 1, mid + 1, t, l, r, c);
	}

	push_up(root);
}

uint64_t query(int root, int s, int t, int l, int r)
{
	if (l <= s && t <= r)
	{
		return f[root];
	}

	if (lazy[root])
	{
		push_down(root, t - s + 1);
	}

	int mid = (s + t) / 2;
	uint64_t ret = 0;
	if (mid >= l)
	{
		ret += query(2 * root, s, mid, l, r);
	}

	if (mid + 1 <= r)
	{
		ret += query(2 * root + 1, mid + 1, t, l, r);
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
	build(1, 1, n);

	while (m-- > 0)
	{
		int op = 0, x = 0, y = 0;
		cin >> op >> x >> y;
		if (op == 1)
		{
			int k = 0;
			cin >> k;
			update_seg(1, 1, n, x, y, k);
		}
		else
		{
			cout << query(1, 1, n, x, y) << "\n";
		}
	}
	return 0;
}
