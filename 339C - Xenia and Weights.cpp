/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 339C - Xenia and Weights
*/
#include <bits/stdc++.h>

using namespace std;

int m;
vector<int> w;
vector<int> weights;

bool dfs(int elements, int diff)
{
	if (elements == m)
		return true;

	bool ans = false;

	for (int i = 0; i < int(w.size()); ++i)
	{
		if (elements == 0 or (weights[elements - 1] != w[i] and w[i] > diff))
		{
			weights[elements] = w[i];
			ans = dfs(elements + 1, w[i] - diff);

			if (ans)
				break; 
		}
	}

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s >> m;


	for (int i = 0; i < int(s.length()); ++i)
	{
		if (s[i] == '1')
			w.push_back(i + 1);
	}


	string ans = "YES";
	weights.resize(m);

	if (not dfs(0, 0))
		ans = "NO";



	cout << ans << "\n";

	if (ans[0] == 'Y')
	{
		for (int v : weights)
			cout << v << " ";
	}

	return 0;
} 