/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 476B - Dreamoon and WiFi
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string p, q;
	cin >> p >> q;

	pair<Long, Long> freqP = {0, 0};
	pair<Long, Long> freqQ = {0, 0};

	for (char c : p)
	{
		if (c == '+')
			++freqP.first;
		else
			++freqP.second;
	}

	for (char c : q)
	{
		if (c == '+')
			++freqQ.first;
		else if (c == '-')
			++freqQ.second;
	}

	double probability = 0.0;

	if (freqQ.first <= freqP.first and freqQ.second <= freqP.second)
	{
		Long unknown = int(q.length()) - freqQ.first - freqQ.second;
		double total = pow(2, unknown);

		vector<Long> factorial(unknown + 1, 1);


		for (Long i = 1; i <= unknown; ++i)
			factorial[i] = i * factorial[i - 1];

		Long plus = freqP.first - freqQ.first;
		double good = (factorial[unknown] / (factorial[unknown - plus] * factorial[plus]));
		
		probability = good / total;
	}

	cout << fixed << setprecision(9) << probability << "\n";

	return 0;
}