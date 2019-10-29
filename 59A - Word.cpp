/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 59A - Word
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int upper = 0;

	for (char v : s)
	{
		if (toupper(v) == v)
			++upper;
	}

	if (upper <= int(s.size()) - upper)
		transform(begin(s), end(s), begin(s), ::tolower);
	else
		transform(begin(s), end(s), begin(s), ::toupper);

	cout << s << "\n";

	return 0;
}