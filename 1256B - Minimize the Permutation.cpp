/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1256B - Minimize the Permutation
*/
#include <bits/stdc++.h>
 
using namespace std;
using Long = long long;
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int q;
	cin >> q;
 
	while (q--)
	{
		int n;
		cin >> n;
 
		vector<int> vals(n);
 
		for (int i = 0; i < n; ++i)
			cin >> vals[i];
 
		int ops = n - 1;
		int start = 0;

		while (ops > 0 and start < n - 1)
		{
			int minIndex = min_element(begin(vals) + start, end(vals)) - begin(vals);
			
			if (minIndex != start)	
			{
				int i = minIndex;


				while (ops and i > start)
				{
					swap(vals[i], vals[i - 1]);
					
					--i;
					--ops;
				}

				start = minIndex;
			}
			else
				++start;
		}

		for (int v : vals)
			cout << v << " ";
 
		cout << "\n";
	}
 
	return 0;
}