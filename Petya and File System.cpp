#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string path;
	map<string, bool> isCreated;
	map< string, map<string, Number> > storage;
	map< string, map<string, Number> > freqFolders;
	map< string, map<string, bool> > folderRecorded;

	while (cin >> path)
	{
		if (isCreated.count(path) == 0)
		{
			isCreated[path] = true;
			istringstream in(path);

			string disk;
			getline(in, disk, ':');

			in.ignore(256, '\\');

			string dir;
			getline(in, dir);

			string root = "";

			int insertedFile = 0;
			const int length = (int)dir.length();

			if (storage.count(disk) == 0)
			{
				storage.insert(make_pair(disk, map<string, Number>()));
				freqFolders.insert(make_pair(disk, map<string, Number>()));
				folderRecorded.insert(make_pair(disk, map<string, bool>()));
			}

			for (int i = 0; i < length; ++i)
			{
				root += dir[i];

				if (dir[i] == '\\')
				{
					string currentFolder = root + "\\";
					map<string, Number>& currentRoot = freqFolders[disk];
					map<string, bool>& currentRootRecord = folderRecorded[disk];

					if (storage[disk].count(root) == 0)
					{
						currentRoot.insert(make_pair(root, 0));
						storage[disk].insert(make_pair(root, 0));
					}

					++storage[disk][root];

					for (int j = i + 1; j < length; ++j)
					{ 
						currentFolder += dir[j];
						
						if (dir[j] == '\\' and currentRootRecord.count(currentFolder) == 0)
						{
							++currentRoot[root];
							currentRootRecord[currentFolder] = true;
						}
					}

					break;
				}
			}
		}
	}

	Number maxFiles = 0;
	Number maxFolders = 0;

	for (const pair< string, map<string, Number> >& p : storage)
	{
		for (const pair<string, Number>& freq : p.second)
			maxFiles = max(maxFiles, freq.second);
	}

	for (const pair< string, map<string, Number> >& freqDisk : freqFolders)
	{
		for (const pair<string, Number>& freq : freqDisk.second)
			maxFolders = max(maxFolders, freq.second);
	}

	cout << maxFolders << " " << maxFiles << "\n";

	return 0;
}