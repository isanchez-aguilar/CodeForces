/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1165C - Good String
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int changes = 0;
	int position = 1;
	vector<char> ans;

	for (int i = 0; i < n - 1; ++i)
	{
		if (position % 2 == 1 and s[i] == s[i + 1])
			++changes;
		else
		{
			++position;
			ans.push_back(s[i]);
		}
	}

	if (s[n - 2] != s[n - 1])
		ans.push_back(s[n - 1]);
	else
		++changes;

	if ((int)ans.size() % 2 == 1)
	{
		++changes;
		ans.pop_back();
	}

	cout << changes << "\n";

	for (int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i];

	return 0;
}