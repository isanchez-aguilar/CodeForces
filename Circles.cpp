#include <cstdio>

using namespace std;
using Number = double;

int testCases;
Number a, b, d, ans;

int main(void)
{
	scanf("%d", &testCases);

	while (testCases--)
	{
		scanf("%lf %lf %lf", &a, &b, &d);
		ans = (d * d) / 2.0f;
		printf("%.7lf\n", ans);
	}

	return 0;
}