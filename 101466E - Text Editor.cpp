/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 101466E - Text Editor
*/
#include <bits/stdc++.h>

using namespace std;
using Number  = int;

inline int LSOne(int i)
{
	return i & (-i);
}

class FenwickTree {
public:
	int size;
	vector<Number> tree; 

	FenwickTree(){}
	FenwickTree(int _size):size(_size), tree(_size + 1)
	{
	}

	inline void add(int index, Number val)
	{		
		++index;
		while (index <= size)
		{
			tree[index] += val;
			index += LSOne(index);
		}
	}

	inline Number getSum(int index)
	{
		++index;
		Number total = 0;
		
		while (index > 0)
		{
			total += tree[index];
			index -= LSOne(index);
		}

		return total;
	}

	inline Number getSum(int left, int right)
	{
		Number total = getSum(right);
		
		if (left <= 0)
			return total;
		
		return total - getSum(left - 1);
	}
};

string t, p;
FenwickTree freq;

inline vector<int> zAlgorithm(const string& s)
{
	const int length = (int)s.length();
	vector<int> z(length);

	for (int i = 1, left = 0, right = 0; i < length; ++i)
	{
		if (i <= right)
			z[i] = min(right - i + 1, z[i - left]);
		
		while (i + z[i] < length and s[z[i]] == s[i + z[i]])
			++z[i];

		if (right < i + z[i] - 1)
		{
			left = i;
			right = i + z[i] - 1;
		}
		
		if (z[i] > 0 and i > (int)p.length())
		{
			freq.add(z[i], 1);
		}	
	}

	return z;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int minOccurs;
	
	getline(cin, t);
	getline(cin, p);
	cin >> minOccurs;
	
	const int pLength = (int)p.length();
	freq = FenwickTree(pLength + 1);

	vector<int> z = zAlgorithm(p + "$" + t);
	
	

	int left = 0;
	int ans = -1;
	int right = p.length();

	while (left < right)
	{
		int middle = (left + right) / 2;

		int totalOccurs = freq.getSum(middle, pLength);

		if (totalOccurs < minOccurs)
			right = middle - 1;
		else
		{
			ans = middle;
			left = middle + 1;
		}
	}

	if (freq.getSum(left, pLength) >= minOccurs)
		ans = max(ans, left);	

	if (freq.getSum(right, pLength) >= minOccurs)
		ans = max(ans, right);	

	if (ans <= 0)
		cout << "IMPOSSIBLE\n";
	else
		cout << p.substr(0, ans) << "\n";	

	return 0;
}