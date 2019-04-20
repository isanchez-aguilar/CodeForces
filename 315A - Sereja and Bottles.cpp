/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 315A - Sereja and Bottles
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector< vector<int> > canOpen;
	vector<int> closeBottles;
	map<int, int> indexOfBrand;


	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (indexOfBrand.count(a) == 0)
		{
			const int newIndex = (int)indexOfBrand.size();
			indexOfBrand[a] = newIndex;

			closeBottles.push_back(1);
			canOpen.resize(newIndex + 1);
		}
		else
		{
			const int index = indexOfBrand[a];
			
			++closeBottles[index];
		}

		if (indexOfBrand.count(b) == 0)
		{
			int newIndex = (int)indexOfBrand.size();
			indexOfBrand[b] = newIndex;

			closeBottles.push_back(0);
			canOpen.resize(newIndex + 1);
		}

		const int indexB = indexOfBrand[b];

		canOpen[indexB].push_back(a);
	}

	int totalClose = 0;

	for (const pair<int, int>& data : indexOfBrand)
	{
		const int brand = data.first;
		const int index = data.second;


 		if (closeBottles[index] > 0)
 		{
			int diferentBrand = -1;

			for (int currentBrand : canOpen[index])
			{
				if (brand != currentBrand)
				{
					diferentBrand = currentBrand;
					break;
				}
			}

			if (diferentBrand == -1)
			{
				if((int)canOpen[index].size() == 1)
					++totalClose;
				else
					totalClose += (closeBottles[index] - (int)canOpen[index].size());
			}
 		}
	}

	cout << totalClose << "\n";

	return 0;
}