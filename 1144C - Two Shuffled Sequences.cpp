/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1144C - Two Shuffled Sequences
*/
#include <bits/stdc++.h>

using namespace std;
using Long = int;

inline void printArray(const vector<Long>& a)
{
	cout << a.size() << "\n";

	for (int i = 0; i < a.size(); ++i)
		cout << (i > 0?" ":"") << a[i];

	cout << "\n";

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Long> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(begin(a), end(a));

	vector<Long> x;
	vector<Long> y;
	bool possible = true;

	vector<Long> aux = a;
	aux.resize(unique(begin(aux), end(aux)) - begin(aux));

	if (aux.size() == n)
		x = a;
	else
	{
		for (int i = 2; i < n; ++i)
		{
			if (a[i - 2] == a[i])
			{
				possible = false;
				break;
			}
		}

		if (possible)
		{
			for (int i = 0; i < n; ++i)
			{
				if (i % 2 == 0)
					x.push_back(a[i]);
				else
					y.push_back(a[i]);
			}

			reverse(begin(y), end(y));
		} 
	}


	if (not possible)
		cout << "NO\n";
	else
	{
		cout << "YES\n";

		printArray(x);
		printArray(y);
	}

	return 0;
}