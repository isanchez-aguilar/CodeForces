/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1269C - Long Beautiful Integer
*/
#include <bits/stdc++.h>

using namespace std;
using Long =  long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	string s;

	cin >> s;

	string ans = s;
	
	for (int i = k; i < n; ++i)
		ans[i] = ans[i - k];

	if (ans < s)
	{
		for (int i = k - 1; i >= 0; --i)
		{
			if (ans[i] != '9')
			{
				cerr << i << ":" << ans[i] << endl;
				for (int j = i; j < k; ++j)
				{
					if (ans[j] == '9')
						ans[j] = '0';
				}

				++ans[i];

				for (int j = i + k; j < n; j += k)
					ans[j] = ans[i];


				break;
			}
		}

		for (int i = k; i < n; ++i)
			ans[i] = ans[i - k];
	}

	cout << n << "\n" << ans << "\n";
	
	return 0;
}