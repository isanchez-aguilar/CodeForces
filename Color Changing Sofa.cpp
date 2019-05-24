#include <bits/stdc++.h>

using namespace std;

inline bool isGood(const string& colours, const vector<int>& firstColour, const vector<int>& secondColour)
{
	bool isSolution = true;
		
	if ((int)firstColour.size() > 0)
	{
		char colour1 = colours[firstColour[0]];

		for (int i = 0; i < (int)firstColour.size(); ++i)
		{
			if (colours[firstColour[i]] != colour1)
			{
				isSolution = false;
				break;
			}
		}
	}

	if ((int)secondColour.size() > 0)
	{
		char colour2 = colours[secondColour[0]];

		for (int i = 0; i < (int)secondColour.size(); ++i)
		{
			if (colours[secondColour[i]] != colour2)
			{
				isSolution = false;
				break;
			}
		}
	}

	return isSolution;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string room, sofa;
	cin >> room >> sofa;

	vector<int> firstColour;
	vector<int> secondColour;
	int sofaSize = sofa.length();
	vector<int> firstColourReverse;
	vector<int> secondColourReverse;

	for (int i = 0; i < sofaSize; ++i)
	{
		if (sofa[i] == '1')
		{
			firstColour.push_back(i);
			firstColourReverse.push_back(sofaSize - 1 - i);
		}
		else
		{
			secondColour.push_back(i);
			secondColourReverse.push_back(sofaSize - 1 - i);
		}
	}

	int goodPositions = 0;

	for (int i = 0; i <= (int)room.length() - sofaSize; ++i)
	{
		bool isSolution = isGood(room.substr(i, sofaSize), firstColour, secondColour);

		if (not isSolution)
			isSolution = isGood(room.substr(i, sofaSize), firstColourReverse, secondColourReverse);
			
		if (isSolution)
			++goodPositions;
	}

	cout << goodPositions << "\n";

	return 0;
}