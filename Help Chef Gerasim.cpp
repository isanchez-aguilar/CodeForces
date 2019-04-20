#include <bits/stdc++.h>

using namespace std;
using Number = unsigned long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	Number cups[n];
	Number total = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> cups[i];
		total += cups[i];
	}

	if (total % n != 0)
		cout << "Unrecoverable configuration.\n";
	else
	{
		vector<int> differents;
		Number vol = total / n;

		for (int i = 0; i < n; ++i)
		{
			if (cups[i] != vol)
				differents.push_back(i);
		}

		if ((int)differents.size() == 0)
			cout << "Exemplary pages.\n";
		else if ((int)differents.size() == 2)
		{
			if (cups[differents[0]] > cups[differents[1]])
				swap(differents[0], differents[1]);

			cout << vol - cups[differents[0]] << " ml. from cup #" << differents[0] + 1 << " to cup #" << differents[1] + 1 << ".\n";
		}
		else
			cout << "Unrecoverable configuration.\n";
	}

	return 0;
}