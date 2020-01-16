/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 519D - A and B and Interesting Substrings
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long vals[26];

	for (int i = 0; i < 26; ++i)
		cin >> vals[i];

	string s;
	cin >> s;

	Long ans = 0;
	
	if (s.length() > 1)
	{
		vector< map<Long, Long> > prevData(26);
		Long currSum = vals[s[0] - 'a'] + vals[s[1] - 'a'];

		++prevData[s[0] - 'a'][vals[s[0] - 'a']];
		++prevData[s[1] - 'a'][currSum];

		if (s[0] == s[1])
			++ans;

		for (int i = 2; i < s.length(); ++i)
		{
			short idChar = s[i] - 'a';
			const Long prefixSum = currSum;
			currSum += vals[idChar];

			ans += prevData[idChar][prefixSum];

			++prevData[idChar][currSum];
		}
	}

	cout << ans << "\n";

	return 0;
}
