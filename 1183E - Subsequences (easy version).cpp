/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1183E - Subsequences (easy version)
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;

	int cost = 0;
	queue<string> remaining;
	set<string> subsequences;

	remaining.push(s);
	subsequences.insert(s);

	while (not remaining.empty() and subsequences.size() < k)
	{
		string w = remaining.front();
		remaining.pop();
		
		for (int i = 0; i < (int)w.length() and subsequences.size() < k; ++i)
		{
			string subW = w;
			subW.erase(i, 1);
			
			if (subsequences.count(subW) == 0)
			{
				cost += n - (int)subW.length();
				subsequences.insert(subW);
				remaining.push(subW);
			}
		}
	}

	if (subsequences.size() < k)
		cout << "-1\n";
	else
		cout << cost << "\n";

	return 0;
}