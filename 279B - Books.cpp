/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 279B - Books
*/
#include <bits/stdc++.h>

using namespace std;
using Number = int;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	Number freeTime;
	cin >> n >> freeTime;

	vector<Number> spendTime(n);

	for (int i = 0; i < n; ++i)
	{
		Number bookTime;
		cin >> bookTime;

		if (i > 0)
			spendTime[i] = spendTime[i - 1];

		spendTime[i] += bookTime;
	}

	int amountOfBooks = 0;

	for (int i = 0; i < n; ++i)
	{
		Number deletedTime = (i > 0?spendTime[i - 1]:0);

		vector<Number>::iterator lastBook = lower_bound(begin(spendTime), end(spendTime), freeTime + deletedTime);
		Number readBooks = 0;

		readBooks = distance(begin(spendTime) + i, lastBook);
		
		if (lastBook != end(spendTime) and freeTime + deletedTime == *lastBook)
			++readBooks;

		amountOfBooks = max(amountOfBooks, readBooks);
	}

	cout << amountOfBooks << "\n";

	return 0;
}