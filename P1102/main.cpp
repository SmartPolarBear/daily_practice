#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

constexpr int NMAX = 200010;

int d[NMAX]{};

int main()
{
	unordered_map<int64_t, uint64_t> nums{};
	int n = 0;
	int64_t c = 0;
	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		nums[d[i]]++;
	}

	uint64_t count = 0;
	for (int i = 0; i < n; i++)
	{
		count += nums[c + d[i]];
	}

	cout << count;

	return 0;
}
