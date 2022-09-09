#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct node
{
	int pos, val;
};

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	deque<node> q{};
	vector<node> ret{};

	ret.emplace_back(node{0, 0});

	for (int i = 1; i < n; i++)
	{
		node nd{i, 0};
		cin >> nd.val;

		while (!q.empty() && q.back().val >= nd.val)
			q.pop_back();

		q.emplace_back(nd);

		while (!q.empty() && i - q.front().pos >= m)
			q.pop_front();

		ret.emplace_back(q.front());
	}

	int tmp = 0;
	cin >> tmp;

	for (const auto &val: ret)
	{
		cout << val.val << "\n";
	}

	return 0;
}
