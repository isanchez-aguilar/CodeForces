/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 101466J - Jeronimo's List
*/
#include <bits/stdc++.h>

#define SIZE 30000001
#define MOD 30000000

using namespace std;
using Number = long long;

Number val;
Number data[SIZE];
Number vals[SIZE];
Number sortedData[SIZE];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	Number maxValue = -1;
	fill(vals, vals + n, 0);
	fill(sortedData, sortedData + n, 0);

	for (int i = 0; i < m; ++i)
	{
		cin >> data[i];
		++vals[data[i]];
		maxValue = max(maxValue, val);
	}

	for (int i = m; i < n; ++i)
	{
		val = (data[i - m] + data[i - m + 1]) % MOD;
		maxValue = max(maxValue, val);
		++vals[val];
		data[i] = val;
	}

	sortedData[0] = vals[0];

	for (int i = 1; i < SIZE; ++i)
		sortedData[i] = vals[i] + sortedData[i - 1];

	while (q--)
	{
		int index;
		cin >> index;

		Number* it = lower_bound(sortedData, sortedData + maxValue + 1, index);

		cout << (int)(it - sortedData) << "\n";
	}

	return 0;
}