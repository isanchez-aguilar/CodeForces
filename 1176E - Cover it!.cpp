/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1176E - Cover it!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int n, m;
		cin >> n >> m;

		vector< vector<int> > graph(n);
		vector< pair<int, int> > degree(n);

		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;

			--u, --v;
			graph[u].push_back(v);
			graph[v].push_back(u);

			++degree[u].first;
			++degree[v].first;
			degree[u].second = u;
			degree[v].second = v;
		}

		sort(begin(degree), end(degree), greater< pair<int, int> >());
	
		int selected = 0;
		vector<bool> scattered(n);
		vector<bool> enable(n, true);

		for (int i = 0; i < n; ++i)
		{
			int u = degree[i].second;

			if (enable[u] and not scattered[u])
			{
				bool isCandidate = true;

				for (int v : graph[u])
				{
					if (not enable[v] or scattered[u])
					{
						isCandidate = false;
						break;
					}
				}

				if (isCandidate)
				{
					++selected;
					enable[u] = false;
					
					for (int v : graph[u])
						scattered[v] = true;
				}
			}
		}

		vector<int> ans;

		if (selected <= n / 2)
		{
			cout << selected << "\n";

			for (int i = 0; i < n; ++i)
			{
				if (not enable[i])
					ans.push_back(i + 1);
			}
		}
		else
		{
			cout << n - selected << "\n";

			for (int i = 0; i < n; ++i)
			{
				if (enable[i])
					ans.push_back(i + 1);
			}
		}

		cout << ans[0];

		for (int i = 1; i < (int)ans.size(); ++i)
			cout << " " << ans[i];

		cout << "\n";
	}


	return 0;
}