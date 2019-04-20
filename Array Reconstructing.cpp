#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	int testCases;
	scanf("%d", &testCases);

	while (testCases--)
	{
		int n;
		Number m;
		scanf("%d %I64d", &n, &m);
		
		Number a[n];
		int firstMinus1 = -1;
		int firstNonNegative = -1;

		for (int i = 0; i < n; ++i)
		{
			scanf("%I64d", &a[i]);

			if (firstNonNegative == -1 and a[i] > -1)
				firstNonNegative = i;

			else if (firstMinus1 == -1 and a[i] == -1)
				firstMinus1 = i;
		}

		if (firstMinus1 == -1)
		{
			printf("%I64d", a[0]);
			for (int i = 1; i < n; ++i)
				printf(" %I64d", a[i]);
		}
		else
		{
			if (firstMinus1 == 0)
			{
				int i = firstNonNegative + 1;

				while (i < n)
				{
					a[i] = (a[i - 1] + 1) % m;
					++i;
				}

				Number currentValue = (a[firstNonNegative] == 0?m - 1:a[firstNonNegative] - 1);
				i = firstNonNegative - 1;
				while (i >= 0)
				{
					a[i] = currentValue;
					
					--i;
					--currentValue;

					if (currentValue < 0)
						currentValue = m - 1;
				}
			}
			else
			{
				int i = firstMinus1;
				while (i < n)
				{
					a[i] = (a[i - 1] + 1) % m;
					++i;
				}
			}

			printf("%I64d", a[0]);
			for (int i = 1; i < n; ++i)
				printf(" %I64d", a[i]);
		}


		printf("\n");
	}


	return 0;
}