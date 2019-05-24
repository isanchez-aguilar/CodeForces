/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 101466F - Polygon Triangles
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;

inline bool isTriangle(Number& a, Number& b, Number& c)
{
	return a < b + c and b < a + c and c < a + b;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	Number a, b, c;
	bool possible = true;

	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		
		if (not isTriangle(a, b, c))
		{
			possible = false;
			break;		
		}
	}

	if (possible)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}