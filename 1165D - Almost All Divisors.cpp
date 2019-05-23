/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1165D - Almost All Divisors
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int amountOfDivisors;
		cin >> amountOfDivisors;

		vector<Long> guessDivisors(amountOfDivisors);

		for (int i = 0; i < amountOfDivisors; ++i)
			cin >> guessDivisors[i];

		sort(begin(guessDivisors), end(guessDivisors));

		Long guessNumber = guessDivisors[0] * guessDivisors.back();

		vector<Long> divisors;
		const Long sqrtGuessNumber = sqrt(guessNumber);

		for (Long i = 2; i <= sqrtGuessNumber; ++i)
		{
			if (guessNumber % i == 0)
			{
				divisors.push_back(i);

				if (i != guessNumber / i)
					divisors.push_back(guessNumber / i);
			}
		}

		sort(begin(divisors), end(divisors));

		if (divisors == guessDivisors)
			cout << guessNumber << "\n";
		else
			cout << "-1\n";
	}

	return 0;
}
