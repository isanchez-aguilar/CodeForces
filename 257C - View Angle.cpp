/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 257C - View Angle
*/
#include <bits/stdc++.h>

using namespace std;
using Double = double;

const Double EPS = 1e-9;
const Double PI = acos(-1);

inline Double getAngle(int x, int y)
{
	Double angle = 0;

	angle = atan2(y, x);

	if (angle < EPS)
		angle += 2 * PI;	

	return angle;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Double> angles(n);

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		angles[i] = getAngle(x, y);
	}

	sort(begin(angles), end(angles));

	Double ans = angles.back() - angles.front();
	

	for (int i = 0; i < n - 1; ++i)
		ans = min(ans, 2 * PI - angles[i + 1] + angles[i]);

	cout << fixed << setprecision(17) << ans * 180 / PI << "\n";

	return 0;
}