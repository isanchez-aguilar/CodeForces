/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 339A - Helpful Maths
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char c; 
	bool last = false;
	int frequency[3] = {0};
	while((c = getchar()) != '\n')
	{
		if(c != '+')
			++frequency[c - '1'];
	}
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < frequency[i]; ++j)
		{
			if((i && last) || j)
				printf("+");
			printf("%d", i + 1);
			last = true;
		}
	}
	return 0;
}