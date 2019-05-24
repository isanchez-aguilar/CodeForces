#include <bits/stdc++.h>

#define EPS 1e-5

using namespace std;
using Number = double;
using Point = pair<Number, Number>;

inline bool isEqual(const Number& a, const Number& b)
{
	return fabs(a - b) < EPS;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<Point> p1(n);
	vector<Point> p2(m);

	for (int i = 0; i < n; ++i)
		cin >> p1[i].first >> p1[i].second;

	for (int i = 0; i < m; ++i)
		cin >> p2[i].first >> p2[i].second;

	int index1 = 1;
	int index2 = 1;
	int addedPoints = 0;
	Number currentDistance1 = 0.0;
	Number currentDistance2 = 0.0;

	while (index1 < n and index2 < m)
	{
		Number dx1 = p1[index1 - 1].first - p1[index1].first;
		Number dy1 = p1[index1 - 1].second - p1[index1].second;
		Number dist1 = hypot(dx1, dy1);

		currentDistance1 += dist1;
		
		Number dx2 = p2[index2 - 1].first - p2[index2].first;
		Number dy2 = p2[index2 - 1].second - p2[index2].second;
		Number dist2 = hypot(dx2, dy2);

		currentDistance2 += dist2;
		
		if (isEqual(currentDistance1, currentDistance2))
			++index1, ++index2;
		else if (currentDistance1 < currentDistance2)
		{
			++index1;
			++addedPoints;
			currentDistance2 -= dist2;
		}
		else
		{
			++index2;
			++addedPoints;
			currentDistance1 -= dist1;
		}
	}

	addedPoints += (n - index1) + (m - index2);

	cout << addedPoints << "\n";

	return 0;
}