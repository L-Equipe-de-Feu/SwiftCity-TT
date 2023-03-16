#include "map.h"

random_device r;
default_random_engine generator(r());
uniform_int_distribution<int> range(0, 1000);

void randomized_map(int x, int map[m][n])
{
	int depart;
	if (n > m)
	{
		depart = x % n;
	}
	else
	{
		depart = x % m;
	}
	int position = depart;
	map[0][position] = 1;
	for (int i = 1; i < m; i++)
	{
		if (range(generator) % 3 == 0)
		{
			if (position > 0)
			{
				map[i][position - 1] = 1;
			}
			map[i][position] = 1;
			position--;
		}
		else if (range(generator) % 3 == 1)
		{
			map[i][position] = 1;
		}
		else if (range(generator) % 3 == 2)
		{
			if (position < 0)
			{
				map[i][position + 1] = 1;
			}
			map[i][position] = 1;
			position++;
		}
	}
	for (int p = 0; p < m; p++)
	{
		for (int q = 0; q < n; q++)
		{
			cout << map[p][q] << " ";
		}
		cout << endl;
	}
}