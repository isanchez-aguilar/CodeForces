/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 126B - Password
*/
#include <bits/stdc++.h>

using namespace std;

inline vector<int> zAlgorithm(const string& s)
{
	const int size = (int)s.length();
	vector<int> z(size);

	for (int i = 1, left = 0, right = 0; i < size; ++i)
	{
		if (i <= right)
			z[i] = min(right - i + 1, z[i - left]);

		while (i + z[i] < size and s[z[i]] == s[i + z[i]])
			++z[i];

		if (z[i] + i - 1 > right)
		{
			left = i;
			right = z[i] + i - 1;
		}
	}

	return z;
}

inline string getSolution(const string& s)
{
	const int size = (int)s.length();
	vector<int> z = zAlgorithm(s);
	int maxLength = 0;

	for (int i = 1; i < size; ++i)
	{
		if (i + z[i] == size)
			maxLength = max(maxLength, z[i] - 1);
		else
			maxLength = max(maxLength, z[i]);
	}

	string ans = "";

	for (int i = size - maxLength; i < size; ++i)
	{
		if (i + z[i] == size)
		{
			ans = s.substr(0, z[i]);
			break;
		}
	}

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	string ans = getSolution(s);

	if (ans.empty())
		cout << "Just a legend\n";
	else
		cout << ans << "\n";

	return 0;
}