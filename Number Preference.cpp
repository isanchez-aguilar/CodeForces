#include <bits/stdc++.h>

using namespace std;
using Number = unsigned long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int query;
	int integers;
	Number value;
	Number lovers = 0;
	Number hated = 0;
	int amountOfFriends;
	bool allHaters = true;
	Number totalIntegers = 0;
	map<Number, Number> values;

	cin >> amountOfFriends;

	while (amountOfFriends--)
	{
		cin >> query >> integers;
		
		if (query == 1)
			++lovers;

		while (integers--)
		{
			cin >> value;

			if (query == 1)
			{
				allHaters = false;

				if (values.count(value) == 0)
					values[value] = 1;
				else if (values[value] != 0)
					++values[value];

			}
			else
			{
				if (values.count(value) == 0)
					++hated;

				values[value] = 0;
			}
		}

	}

	Number maxValue = 1;
	
	if (allHaters)
		totalIntegers = 1000000000000000000ull - hated;
	else
	{
		map<Number, Number>::iterator i;

		for (i = begin(values); i != end(values); ++i)
		{
			if (i->second == lovers)
				++totalIntegers;
		}
	}
	
	cout << totalIntegers << "\n";

	return 0;
}