/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 228A - Is your horseshoe on the other hoof?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<int> colours;

	for (int i = 0; i < 4; ++i)
	{
		int colour;
		cin >> colour;

		colours.insert(colour);
	}

	int ans = 4 - int(colours.size());

	if (ans < 0)
		ans = 0;

	cout << ans << "\n";

	return 0;
}