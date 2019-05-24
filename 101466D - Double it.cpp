/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 101466D - Double it
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	string ans;
		
	cin >> n;
	
	while (n > 0)
	{
		if ((n - 2) % 2 == 0)
		{
			ans.push_back('B');
			n -= 2;
		}
		else if ((n - 1) % 2 == 0)
		{
			ans.push_back('A');
			n -= 1;
		}
		
		n /= 2;
	}

	reverse(ans.begin(), ans.end());
	
	cout << ans << "\n";
	
	return 0;
}