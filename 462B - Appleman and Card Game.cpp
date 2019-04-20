/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 462B - Appleman and Card Game
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Number n, k;
	cin >> n >> k;

	map<char, Number> freq;

	for (Number i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		++freq[c];
	}

	vector<Number> frequency;

	for (const pair<char, Number> c : freq)
		frequency.push_back(c.second);

	sort(begin(frequency), end(frequency), greater<Number>());

	Number totalCost = 0;
	Number currentCards = 0;

	for (Number i = 0; i < n and currentCards < k; ++i)
	{
		Number takenCards = min(k - currentCards, frequency[i]);

		currentCards += takenCards;
		totalCost += (takenCards * takenCards);
	}

	cout << totalCost << "\n";

	return 0;
}