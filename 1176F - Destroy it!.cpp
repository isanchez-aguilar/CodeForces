/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1176F - Destroy it!
*/
#include <bits/stdc++.h>

#define MIN_VAL -1000000000000000000ll

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int turns;
	cin >> turns;
	vector< vector< vector<Long> > > cards(turns, vector< vector<Long> >(4));

	for (int i = 0; i < turns; ++i)
	{
		int amountOfCards;
		cin >> amountOfCards;

		for (int j = 0; j < amountOfCards; ++j)
		{
			int cost;
			Long damage;
			cin >> cost >> damage;

			cards[i][cost].push_back(damage);
		}

		for (int j = 1; j <= 3; ++j)
			sort(begin(cards[i][j]), end(cards[i][j]), greater<Long>());
	}

	for (int i = 0; i < turns; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			int size;
			
			if (j == 1)
				size = min((int)cards[i][j].size(), 3);
			else
				size = min((int)cards[i][j].size(), 1);

			cards[i][j].resize(size);
		}
	}

	vector< vector<Long> > dp(turns + 1, vector<Long>(10, MIN_VAL));
	dp[0][0] = 0;

	for (int i = 0; i < turns; ++i)
	{
		vector< pair<int, Long> > currentTurn;

		for (int j = 1; j <= 3; ++j)
		{
			for (Long damage : cards[i][j])
				currentTurn.push_back(make_pair(j, damage));
		}

		vector< vector<Long> > dpAux(4, vector<Long>(2, MIN_VAL));
		sort(begin(currentTurn), end(currentTurn));
		dpAux[0][0] = 0;

		do
		{
			Long score = 0;
			Long maxDamage = 0;
			int takenCards = 0;
			int remainingCost = 3;

			for (pair<int, Long> card : currentTurn)
			{
				++takenCards;
				
				if (remainingCost < card.first)
					break;

				score += card.second;
				remainingCost -= card.first;
				maxDamage = max(maxDamage, card.second);

				dpAux[takenCards][0] = max(dpAux[takenCards][0], score);
				dpAux[takenCards][1] = max(dpAux[takenCards][1], score + maxDamage);
			}
		} while (next_permutation(begin(currentTurn), end(currentTurn)));

		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k <= 3; ++k)
			{
				int nextCard = (j + k) % 10;
				int isTenth = (j + k >= 10?1:0);

				dp[i + 1][nextCard] = max(dp[i + 1][nextCard], dp[i][j] + dpAux[k][isTenth]);
			}
		}
	}

	Long ans = *max_element(begin(dp[turns]), end(dp[turns]));

	cout << ans << "\n";

	return 0;
}