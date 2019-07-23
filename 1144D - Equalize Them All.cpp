/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1144D - Equalize Them All
*/
#include <bits/stdc++.h>

#define MAX_VAL 200001

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Long> a(n);
	vector<int> freq(MAX_VAL);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		++freq[a[i]];
	}

	int mostFreq = max_element(begin(freq), end(freq)) - begin(freq);
	int indexMostFreq = find(begin(a), end(a), mostFreq) - begin(a);

	cout << n - freq[mostFreq] << "\n";

	for (int i = indexMostFreq - 1; i >= 0; --i)
	{
		if (a[i] != a[i + 1])
		{
			short type = (a[i] < a[i + 1]?1:2);
			cout << type << " " << i + 1 << " " << i + 2 << endl;
		}

		a[i] = a[i + 1];
	}

	for (int i = 1; i < n; ++i)
	{
		if (a[i] != mostFreq)
		{
			short type = (a[i] < a[i - 1]?1:2);
			cout << type << " " << i + 1 << " " << i << "\n";
		}

		a[i] = mostFreq;
	}

	return 0;
}