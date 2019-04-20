/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 451B - Sort the Array
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	vector<int> sortedA(a);
	sort(begin(sortedA), end(sortedA));

	bool isGood = true;
	pair<int, int> ans(1, 1);
	
	if (a != sortedA)
	{
		Number previousVal = LONG_MIN;

		if (n > 1 and a[0] > a[1])
		{
			previousVal = a[0];

			for (int j = 1; j < n; ++j)
			{
				if (previousVal < a[j] or j + 1 == n)
				{
					if (previousVal >= a[j])
						++j;

					ans = make_pair(1, j);

					break;
				}

				previousVal = a[j];
			}
		}
		else
		{	
			for (int i = 0; i < n; ++i)
			{
				if (previousVal > a[i])
				{
					previousVal = a[i];

					for (int j = i + 1; j < n; ++j)
					{
						if (previousVal < a[j] or j + 1 == n)
						{
							if (previousVal >= a[j])
								++j;
							
							ans = make_pair(i, j);

							break;
						}

						previousVal = a[j];
					}

					break;
				}

				previousVal = a[i];
			}
		}

		sort(begin(a) + ans.first - 1, begin(a) + ans.second);

		if (a != sortedA)
			isGood = false;
	}


	if (isGood)
		cout << "yes\n" << ans.first << " " << ans.second << "\n"; 
	else
		cout << "no\n";

	return 0;
}