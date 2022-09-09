#include <iostream>
#include <deque>
#include <vector>

using namespace std;

constexpr int NMAX = 1000010;

struct node
{
	int pos, val;
};
node d[NMAX]{};

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		d[i].pos = i;
		cin >> d[i].val;
	}

	deque<node> q{};

	vector<int> mins{};
	for (int i = 0; i < n; i++)
	{
		while (!q.empty() && q.back().val >= d[i].val)
			q.pop_back();

		q.push_back(d[i]);

		while (!q.empty() && i - q.front().pos >= k)
			q.pop_front();

		if (i >= k - 1)
		{
			mins.push_back(q.front().val);
		}
	}

	for (auto val: mins)
	{
		cout << val << " ";
	}
	cout << "\n";
	q.clear();

	vector<int> maxs{};
	for (int i = 0; i < n; i++)
	{
		while (!q.empty() && q.back().val <= d[i].val)
			q.pop_back();

		q.push_back(d[i]);

		while (!q.empty() && i - q.front().pos >= k)
			q.pop_front();

		if (i >= k - 1)
		{
			maxs.push_back(q.front().val);
		}
	}

	for (auto val: maxs)
	{
		cout << val << " ";
	}

	return 0;
}
