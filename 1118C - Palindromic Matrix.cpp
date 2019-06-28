/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1118C - Palindromic Matrix
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, int> freq;

	for (int i = 0; i < n * n; ++i)
	{
		int val;
		cin >> val;
		++freq[val];
	}

	set< pair<int, int>, greater< pair<int, int> > > vals;

	for (map<int, int>::iterator i = begin(freq); i != end(freq); ++i)
		vals.insert(make_pair(i->second, i->first));

	bool isPossible = true;
	vector< vector<int> > ans(n, vector<int>(n));

	int middle = n / 2;

	for (int i = 0; i < middle and isPossible; ++i)
	{
		for (int j = 0; j < middle; ++j)
		{
			set< pair<int, int> >::iterator k = begin(vals);

			if (k->first < 4)
			{
				isPossible = false;
				break;
			}

			ans[i][j] = k->second;
			ans[i][n - j - 1] = k->second;
			
			ans[n - i - 1][j] = k->second;
			ans[n - i - 1][n - j - 1] = k->second;
			
			pair<int, int> aux(*k);
			vals.erase(k);

			if (aux.first - 4 > 0)
			{
				aux.first -= 4;
				vals.insert(aux);
			}
		}
	}

	if (isPossible and n % 2 != 0)
	{
		for (int i = 0; i < middle; ++i)
		{
			set< pair<int, int> >::iterator k = begin(vals);

			if (k->first < 2)
			{
				isPossible = false;
				break;
			}

			ans[i][middle] = k->second;
			ans[n - i - 1][middle] = k->second;

			pair<int, int> aux(*k);
			vals.erase(k);

			if (aux.first - 2 > 0)
			{
				aux.first -= 2;
				vals.insert(aux);
			}
		}


		if (isPossible)
		{
			for (int i = 0; i < middle; ++i)
			{
				set< pair<int, int> >::iterator k = begin(vals);

				if (k ->first < 2)
				{
					isPossible = false;
					break;
				}

				ans[middle][i] = k->second;
				ans[middle][n - i - 1] = k->second;

				pair<int, int> aux(*k);
				vals.erase(k);

				if (aux.first - 2 > 0)
				{
					aux.first -= 2;
					vals.insert(aux);
				}
			}
				
			ans[middle][middle] = begin(vals)->second;
		}
	}

	if (isPossible)
	{
		cout << "YES\n";

		for (const vector<int>& r : ans)
		{
			cout << r[0];

			for (int i = 1; i < n; ++i)
				cout << " " << r[i];
			
			cout << "\n";
		}
	}
	else
		cout << "NO\n";

	return 0;
}