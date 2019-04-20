#include <bits/stdc++.h>

using namespace std;

inline int countOccurrences(const string& s, const string& abbreviation)
{
	int occurrences = 0;
	int index = s.find(abbreviation);
	
	while (index != string::npos)
	{
		++occurrences;
		index = s.find(abbreviation, index + abbreviation.length());
	}

	return occurrences;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int occurrences[2] = {0, 0};
	string abbreviated[2] = {"LSC", "PCMS"};

	occurrences[0] = countOccurrences(s, abbreviated[0]);
	occurrences[1] = countOccurrences(s, abbreviated[1]);


	if (occurrences[0] < occurrences[1])
		cout << abbreviated[1] << "\n";
	else if (occurrences[1] < occurrences[0])
		cout << abbreviated[0] << "\n";
	else
		cout << "Tie\n";

	return 0;
}