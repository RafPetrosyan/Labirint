#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int size=0;
	cout << "Please input labirint size: ";
	cin >> size;

	char** labirint = new char*[size];
	for (int i = 0; i < size; ++i)
	{
		labirint[i] = new char[size];
	}

	int** lab = new int*[size];
	for (int i = 0; i < size; ++i)
	{
		lab[i] = new int[size] {};
	}
	cout << "Please input labirint: " << endl;

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			std::cin >> labirint[x][y];
		}
	}

	queue<pair<int, int>> a;
	pair<int, int> loc,temp;
	cout << "Please enter location info (x y): ";
	cin >> loc.second >> loc.first;
	lab[loc.second][loc.first] = 0;
	labirint[loc.second][loc.first] = '0';
	a.push(loc);
	while (!a.empty())
	{
		if (a.front().first > 0 && labirint[a.front().second][a.front().first - 1] == '.')
		{
			labirint[a.front().second][a.front().first - 1] = '0';
			lab[a.front().second][a.front().first - 1] = lab[a.front().second][a.front().first] + 1;
			temp.second = a.front().second; temp.first = a.front().first - 1;
			a.push(temp);
		}
		if (a.front().first+1 < size && labirint[a.front().second][a.front().first + 1] == '.')
		{
			labirint[a.front().second][a.front().first + 1] = '0';
			lab[a.front().second][a.front().first + 1] = lab[a.front().second][a.front().first] + 1;
			temp.second = a.front().second; temp.first = a.front().first + 1;
			a.push(temp);
		}
		if (a.front().second > 0 && labirint[a.front().second-1][a.front().first] == '.')
		{
			labirint[a.front().second-1][a.front().first] = '0';
			lab[a.front().second - 1][a.front().first] = lab[a.front().second][a.front().first] + 1;
			temp.second = a.front().second-1; temp.first = a.front().first;
			a.push(temp);
		}
		if (a.front().second + 1 < size && labirint[a.front().second+1][a.front().first] == '.')
		{
			labirint[a.front().second+1][a.front().first] = '0';
			lab[a.front().second+1][a.front().first] = lab[a.front().second][a.front().first] + 1;
			temp.second = a.front().second+1; temp.first = a.front().first;
			a.push(temp);
		}
		a.pop();
	}

	int temp1 = size*size;
	for (int y = 0; y < size; ++y)
	{
		if (lab[y][0] > 0 && lab[y][0]<temp1)
		{
			temp1 = lab[y][0];
		}
		if (lab[y][size - 1] > 0 && lab[y][size-1]<temp1)
		{
			temp1 = lab[y][size-1];
		}
		if (lab[0][y] > 0 && lab[0][y]<temp1)
		{
			temp1 = lab[0][y];
		}
		if (lab[size - 1][y] > 0 && lab[size-1][y]<temp1)
		{
			temp1 = lab[size-1][y];
		}
	}
	cout << temp1;
	return 0;
}