/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1237A - Balanced Rating Changes
*/
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> minus;
	vector<int> participants(n);

	int sum = 0;
	
	for (int i = 0; i < n ; ++i)
	{
		cin >> participants[i];
	
		if (participants[i] % 2 == 0)
			participants[i] /= 2;
		else
		{
			minus.push_back(i);
			participants[i] = ceil(participants[i] / 2.0);
		}

		sum += participants[i];
	}

	if (sum != 0)
	{
		for (int i = 0; i < int(minus.size()) and sum != 0; ++i)
		{
			--sum;
			--participants[minus[i]];
		}
	}

	for (int v : participants)
		cout << v << "\n";	

	return 0;
}