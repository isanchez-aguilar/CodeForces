/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1237C2 - Balanced Removals (Harder)
*/
#include <bits/stdc++.h>

using namespace std;

const int dimensions = 3;
vector< vector<int> > points;

int printSteps(int currDim, const vector<int>& idPoints)
{
	if (currDim == dimensions)
		return idPoints[0];

	map<int, vector<int> > axis;

	for (int i = 0; i < int(idPoints.size()); ++i)
	{
		int id = idPoints[i];
		axis[points[id][currDim]].push_back(id);
	}

	vector<int> idAns;

	for (const pair< int, vector<int> >& p : axis)
	{
		int currP = printSteps(currDim + 1, p.second);

		if (currP != -1)
			idAns.push_back(currP);
	}

	for (int i = 0; i + 1 < int(idAns.size()); i += 2)
		cout << idAns[i] + 1 << " " << idAns[i + 1] + 1 << "\n";

	return (int(idAns.size()) % 2 == 0?-1:idAns.back());
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> idPoints(n);
	points = vector< vector<int> >(n, vector<int>(dimensions));

	for (int i = 0; i < n; ++i)
	{
		idPoints[i] = i;
		for (int j = 0; j < dimensions; ++j)
			cin >> points[i][j];
	}


	printSteps(0, idPoints);

	return 0;
}