/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 350C - Bombs
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long;
using Point = pair<Long, Long>;

typedef struct INSTRUCTION{
	int k;
	char dir;
	short type;
}Instruction;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Point> coordinates(n);

	for (int i = 0; i < n; ++i)
		cin >> coordinates[i].first >> coordinates[i].second;

	vector<Instruction> ans;

	sort(begin(coordinates), end(coordinates), [](const Point& a, const Point& b){
		return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
	});

	for (const Point& p : coordinates)
	{
		Long x = p.first;
		Long y = p.second;
		Instruction rightMove;

		char l = 'L';
		char r = 'R';

		if (x < 0)
			swap(l, r);

		rightMove.k = abs(x);
		rightMove.type = 1;
		rightMove.dir = r;
		

		if (x != 0)
			ans.push_back(rightMove);
		

		char u = 'U';
		char d = 'D';

		if (y < 0)
			swap(u, d);

		Instruction upMove;

		if (y != 0)
		{
			upMove.type = 1;
			upMove.k = abs(y);
			upMove.dir = u;

			ans.push_back(upMove);
		}
		
		Instruction aux;
		aux.type = 2;

		ans.push_back(aux);
		
		upMove.dir = d;
		rightMove.dir = l;
		
		if (y != 0)
			ans.push_back(upMove);

		if (x != 0)
			ans.push_back(rightMove);

		aux.type = 3;
		ans.push_back(aux);

		
	}

	cout << int(ans.size()) << "\n";

	for (int i = 0; i < int(ans.size()); ++i)
	{
		cout << ans[i].type;

		if (ans[i].type == 1)
			cout << " " << ans[i].k << " " << ans[i].dir;

		cout << "\n";
	}

	return 0;
}
