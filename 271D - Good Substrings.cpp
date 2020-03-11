#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 27;
const int MAX_SIZE = 3000000;

int k, n;
string s, info;
bool isGood[ALPHABET_SIZE];

struct Trie {
	int trieSize = 0;
	
	vector<int> leaf;
	vector< vector<int> > child;
	
	Trie():leaf(MAX_SIZE), child(ALPHABET_SIZE, vector<int>(MAX_SIZE, -1)) {}
	
	/*
	** Complexity: O(|s|)
	** Insert new string.
	*/
	inline int insert(int i)
	{
		int ans = 0;
		int bad = 0;
		int currentNode = 0;

		const int start = i;

		while (i < n)
		{
			char c = s[i];
			int value = int(c - 'a');
				
			bad += not isGood[value];
			int& nextNode = child[value][currentNode];

			if (nextNode == -1)
				nextNode = ++trieSize;

			if (bad <= k and leaf[nextNode] == 0)
				++ans;

			currentNode = nextNode;
			++leaf[currentNode];
			++i;
		}


		return ans;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> info >> k;

	n = s.size();

	for (int i = 0; i < info.size(); ++i)
		isGood[i] = info[i] == '1';


	Trie helper;
	int ans = 0;

	for (int i = 0; i < n; ++i)
		ans += helper.insert(i);
	
	cout << ans << "\n";

	return 0;
}