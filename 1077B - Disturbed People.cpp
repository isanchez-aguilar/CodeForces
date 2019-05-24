/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1077B - Disturbed People
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int status[n];
	
	for (int i = 0; i < n; ++i)
		cin >> status[i];

	int k = 0;
	
	for (int i = 1; i < n - 1; ++i)
	{
		if (status[i] == 0 and status[i - 1] == 1 and status[i + 1] == 1)
		{
			++k;
			status[i - 1] = 0;
			status[i + 1] = 0;
		}
	}

	cout << k << endl;

	return 0;
}