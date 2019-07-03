/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 746F - Music in Car
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;
using SetIterator = set< pair<Number, int> >::iterator;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int songs;
	int wayTime;
	int amountOfPartialSongs;
	cin >> songs >> amountOfPartialSongs >> wayTime;

	vector<Number> pleasure(songs);
	vector<Number> duration(songs);

	Number total = 0;
	for (int i = 0; i < songs; ++i)
		cin >> pleasure[i];

	for (int i = 0; i < songs; ++i)
		cin >> duration[i];

	int usedTime = 0;
	int endIndex = -1;
	int startIndex = 0;
	Number maxPleasure = 0;
	Number currentPleasure = 0;
	map<int, bool> isPartialSong;
	set< pair<Number, int> > playList;
	set< pair<Number, int> > partialSongs;
	set< pair<Number, int> > completeSongs;
	vector<Number> durationBackup(duration);
	set< pair<int, pair<Number, int> > > playListIndexes;


	while (startIndex < songs and endIndex < songs)
	{
		if (usedTime <= wayTime)
		{
			++endIndex;
			maxPleasure = max(maxPleasure, currentPleasure);
			if (endIndex < songs)
			{
				pair<Number, int> dataSong(duration[endIndex], endIndex);

				if (not partialSongs.empty() and begin(partialSongs)->first < ceil((double)duration[endIndex] / 2.0))
				{
					SetIterator pointerShortestPartialSong = begin(partialSongs);
					pair<Number, int> shortestPartialSong = *pointerShortestPartialSong;
					duration[endIndex] = ceil((double)duration[endIndex] / 2.0);
					dataSong.first = duration[endIndex];

					playListIndexes.erase(playListIndexes.lower_bound(make_pair(shortestPartialSong.second, make_pair(LLONG_MIN, INT_MIN))));
					isPartialSong.erase(pointerShortestPartialSong->second);
					partialSongs.erase(pointerShortestPartialSong);
					playList.erase(shortestPartialSong);

					usedTime -= duration[shortestPartialSong.second];
					usedTime += durationBackup[shortestPartialSong.second];

					duration[shortestPartialSong.second] = durationBackup[shortestPartialSong.second];
					shortestPartialSong.first = duration[shortestPartialSong.second];

					playListIndexes.insert(make_pair(shortestPartialSong.second, shortestPartialSong));
					completeSongs.insert(shortestPartialSong);
					playList.insert(shortestPartialSong);

					partialSongs.insert(dataSong);
					isPartialSong[endIndex] = true;
				}
				else
					completeSongs.insert(dataSong);

				usedTime += dataSong.first;
				currentPleasure += pleasure[endIndex];
				
				playListIndexes.insert(make_pair(endIndex, dataSong));
				playList.insert(dataSong);
			}
		}
		else
		{
			if (not playList.empty() and usedTime - duration[endIndex] <= wayTime)
				maxPleasure = max(maxPleasure, currentPleasure - pleasure[endIndex]);

			if (amountOfPartialSongs > 0 and not completeSongs.empty())
			{
				SetIterator pointerLongestSong = --end(completeSongs);
				pair<Number, int> longestSong = *pointerLongestSong;

				playListIndexes.erase(playListIndexes.lower_bound(make_pair(longestSong.second, make_pair(LLONG_MIN, INT_MIN))));
				completeSongs.erase(pointerLongestSong);
				playList.erase(longestSong);

				usedTime -= longestSong.first;
				duration[longestSong.second] = ceil((double)longestSong.first / 2.0);
				usedTime += duration[longestSong.second];

				longestSong.first = duration[longestSong.second];
				
				playListIndexes.insert(make_pair(longestSong.second, longestSong));
				isPartialSong[longestSong.second] = true;	
				partialSongs.insert(longestSong);
				playList.insert(longestSong);

				--amountOfPartialSongs;
			}

			else
			{
				pair<Number, int> firstSong = begin(playListIndexes)->second;
				
				if (isPartialSong[startIndex])
				{
					++amountOfPartialSongs;
					partialSongs.erase(firstSong);
					isPartialSong.erase(startIndex);
				}
				else
					completeSongs.erase(firstSong);

				playList.erase(firstSong);
				playListIndexes.erase(begin(playListIndexes));

				usedTime -= duration[startIndex];
				currentPleasure -= pleasure[startIndex];

				++startIndex;
			}
		}
	}

	if (usedTime <= wayTime)
		maxPleasure = max(maxPleasure, currentPleasure);

	cout << maxPleasure << "\n";

	return 0;
}