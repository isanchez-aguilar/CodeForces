#include <bits/stdc++.h>

#define MAX_B 1001
#define MAX_N 1000001
#define MAX_INDEX 3001
#define MOD 1000000007

using namespace std;
using Number = long long;

int n;
Number b, v;
int totalPrimes;
vector<Number> powerOfPrimes;
Number memo[MAX_B][MAX_INDEX];

Number countSolutions(Number currentProduct, int currentprimeP)
{
	if (currentProduct == b)
		return 1ll;
	if (currentProduct > b or totalPrimes <= currentprimeP)
		return 0ll;

	Number& m = memo[currentProduct][currentprimeP];

	if (m == -1ll)
	{
		m = 0ll;

		for (Number i = 0; i <= powerOfPrimes[currentprimeP]; ++i)
		{
			m += countSolutions(currentProduct * (i + 1ll), currentprimeP + 1);
			m %= MOD;
		}
	}

	return m;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> b >> n;
	map<Number, Number> primeP;

	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		
		Number power = 0;
		Number sqrtV = (Number)sqrt(v);
	
		while ((v & 1ll) == 0)
		{
			++power;
			v >>= 1ll;
		}

		if (power > 0ll)
			primeP[2ll] += power;

		for (Number j = 3ll; j <= sqrtV and v > 1ll; j += 2ll)
		{
			power = 0;	

			while (v % j == 0ll)
			{
				++power;
				v /= j;
			}

			if (power > 0ll)
				primeP[j] += power;
		}

		if (v > 1ll)
			++primeP[v];
	}

	if (b == 1ll)
		cout << "1\n";
	else
	{
		for (int i = 0; i < MAX_B; ++i)
		{
			for (int j = 0; j < MAX_INDEX; ++j)
				memo[i][j] = -1LL;
		}

		for (const pair<Number, Number>& c : primeP)
			powerOfPrimes.push_back(c.second);
		
		totalPrimes = (int)powerOfPrimes.size();		
		Number ans = countSolutions(1ll, 0);

		cout << ans << "\n";
	}

	return 0;
}
