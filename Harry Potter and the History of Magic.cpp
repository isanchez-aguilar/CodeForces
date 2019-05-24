#include <bits/stdc++.h>

using namespace std;

string getLowestDate(const string& lowLimit, const string& date)
{
	string lowestDate = date;

	if (lowestDate != lowLimit)
	{
		for (int i = 3; i >= 0; --i)
		{	
			for (int j = 0; j <= 9; ++j)
			{
				if (j != 0 or (j == 0 and i != 0))
				{
					string currentDate = date.substr(0, i) + to_string(j) + date.substr(i + 1, (int)date.length() - i - 1);


					if (lowLimit <= currentDate)
					{
						if ((date < lowLimit and date == lowestDate) or currentDate < lowestDate)
							lowestDate = currentDate;
					}
				}
			}
		}
	}

	if (lowestDate < lowLimit)
		lowestDate = "9999";

	return lowestDate;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> dates(n);
	string previousDate = "1000";

	for (int i = 0; i < n; ++i)
	{
		cin >> dates[i];

		dates[i] = getLowestDate(previousDate, dates[i]);
		previousDate = dates[i];
	}

	if (dates[n - 1] <= "2011")
	{
		for (const string& date : dates)
			cout << date << "\n";
	}
	else
		cout << "No solution\n";

	return 0;
}