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
	int virage = 0;
	int equation = range(generator);
	if(equation%2==0)
	{
		if (m > n)
		{
			position = floor(position * n / m);
		}
		map[0][position] = 1;
		if (position > 20)
		{
			for (int l = position - n/5 - n/3; l < position - n/5; l++)
			{
				map[0][l] = 3;
			}
		}
		else if (position > 8)
		{
			for (int l = 0; l < position - n/5; l++)
			{
				map[0][l] = 3;
			}
		}
		for (int l = position + n/5 + 1; l < position + n/5 + n/3 && l < m; l++)
		{
			map[0][l] = 3;
		}
		if (position > 7)
		{
			for (int l = position - n/5; l < position; l++)
			{
				map[0][l] = 2;
			}
		}
		else
		{
			for (int l = 0; l < position; l++)
			{
				map[0][l] = 2;
			}
		}
		for (int l = position + 1; l < position + n/5 + 1 && l < n; l++)
		{
			map[0][l] = 2;
		}
		for (int i = 1; i < m; i++)
		{
			equation = range(generator);
			if (equation % 3 == 0)
			{
				map[i][position] = 1;
				if (position > 0 && virage != 1)
				{
					map[i][position - 1] = 1;
					position--;
					virage = 2;
				}
			}
			else if (equation % 3 == 1)
			{
				map[i][position] = 1;
				virage = 0;
			}
			else if (equation % 3 == 2)
			{
				map[i][position] = 1;
				if (position < n - 1 && virage != 2)
				{
					map[i][position + 1] = 1;
					position++;
					virage = 1;
				}
			}
		}
	}
	else
	{
		if (n > m)
		{
			position = floor(position * m / n);
		}
		map[position][0] = 1;
		for (int j = 1; j < n; j++)
		{
			equation = range(generator);
			if (equation % 3 == 0)
			{
				map[position][j] = 1;
				if (position > 0 && virage != 1)
				{
					map[position-1][j] = 1;
					position--;
					virage = 2;
				}
			}
			else if (equation % 3 == 1)
			{
				map[position][j] = 1;
				virage = 0;
			}
			else if (equation % 3 == 2)
			{
				map[position][j] = 1;
				if (position < m - 1 && virage != 2)
				{
					map[position+1][j] = 1;
					position++;
					virage = 1;
				}
			}
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