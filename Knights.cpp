#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, c, k;
	cin >> r >> c >> k;
	vector< vector<int> > mat(r, vector<int>(c));


	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		mat[x - 1][y  - 1] = 1;
	}

	int totalOfKnights = 0;

	if (r == 1 and c == 1)
		totalOfKnights = 1 - k;
	else
	{
		if (c == 1)
		{
			if (mat[0][0] == 0 and mat[r - 1][0] ==  0)
				totalOfKnights = 2;
			else if (mat[0][0] != mat[r - 1][0])
				totalOfKnights = 1;
			else
				totalOfKnights = 0;	
		}

		else if (r == 1)
		{
			if (mat[0][0] == 0 and mat[0][c - 1] ==  0)
				totalOfKnights = 2;

			else if (mat[0][0] != mat[0][c - 1])
				totalOfKnights = 1;

			else
				totalOfKnights = 0;		
		}
		else
			totalOfKnights = 4 - mat[0][0] - mat[0][c - 1] - mat[r - 1][0] - mat[r - 1][c - 1];
	}

	cout << totalOfKnights << "\n";

	return 0;
}