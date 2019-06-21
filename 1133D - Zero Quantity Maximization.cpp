/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1133D - Zero Quantity Maximization
*/
#include <bits/stdc++.h>

using namespace std;
using Long = int;
using Fraction = pair<Long, Long>;

inline Fraction reduceFraction(const Fraction& f)
{
	Fraction reduction = f;

	if (reduction.first < 0)
	{
		reduction.first *= -1;
		reduction.second *= -1;
	}
	else if(reduction.first == 0 and reduction.second < 0)
		reduction.second *= -1;

	Long gcd = __gcd(abs(reduction.first), abs(reduction.second));

	reduction.first /= gcd;
	reduction.second /= gcd;

	return reduction;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Long> a(n);
	vector<Long> b(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];

	int ans = 0;
	int maxFreq = 0;
	map<Fraction, int> freq;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0)
		{
			if (b[i] == 0)
				++ans;
		}
		else
		{
			Fraction d = reduceFraction(Fraction(-b[i], a[i]));
			++freq[d];

			maxFreq = max(maxFreq, freq[d]);
		}
	}

	cout << ans + maxFreq << "\n";

	return 0;
}