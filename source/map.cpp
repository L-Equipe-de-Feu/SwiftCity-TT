#include "map.h"

void randomized_map(int x, char map[m][n])
{
	int depart=x%m;
	int eau=0;
	int position=0;
	int equation=(pow(x, depart)/m)-n;
	if(equation%2==0)
	{
		map[0][depart]='R';
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(j>0)
				{
					for(int k=j-1; k<j+2; k++)
					{
						if(i>0 && map[i-1][k]=='R' && map[i][j-2]!='R' && map[i][j-1]!='R')
						{
							eau++;
							position=k;
							if(eau==1 && map[i-1][j+2]=='R')
							{
								eau=0;
								k=j+2;
							}
							if(eau>1)
							{
								for(int l=1; map[i-l][position-1]=='R' && map[i-l][position]=='R'; l++)
								{
									if(map[i-l-1][position-1]=!'R')
									{
										position=k-1;
									}
									else if(map[i-l-1][position]=!'R')
									{
										position=k;
									}
								}
							}
						}
					}
				}
				if(eau==1)
				{
					equation=(pow(x, depart)/i)-position;
					if(equation%3==0)
					{
						if(position-1>=0)
						{
							map[i][position-1]='R';
						}
						map[i][position]='R';
						map[i][position+1]='H';
					}
					else if(equation%3==1)
					{
						if(position-1>=0)
						{
							map[i][position-1]='H';
						}
						map[i][position]='R';
						map[i][position+1]='H';
					}
					else if(equation%3==2)
					{
						if(position-1>=0)
						{
							map[i][position-1]='H';
						}
						map[i][position]='R';
						map[i][position+1]='R';
					}
				}
				else if(eau>1)
				{
					equation=(pow(x, depart)/i)-position;
					if(position=j+1 && equation%2==0)
					{
						if(j-1>=0)
						{
							map[i][j-1]='H';
						}
						map[i][j]='H';
						map[i][j+1]='R';
					}
					else if(position=j+1 && equation%2==1)
					{
						if(j-1>=0)
						{
							map[i][j-1]='H';
						}
						map[i][j]='H';
						map[i][j+1]='R';
						map[i][j+2]='R';
					}
					else if(position=j && equation%2==0)
					{
						if(j-1>=0)
						{
							map[i][j-1]='H';
						}
						map[i][j]='R';
						map[i][j+1]='H';
					}
					else if(position=j && equation%2==1)
					{
						if(j-1>=0)
						{
							map[i][j-1]='R';
						}
						map[i][j]='R';
						map[i][j+1]='H';
					}
				}
				else
				{
					if(map[i][j]=!'R')
					{
						map[i][j]='H';
					}
				}
			}
		}
	}
	else
	{
		map[depart][0]='R';
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i>0)
				{
					for(int k=i-1; k<i+2; k++)
					{
						if(j>0 && map[k][j-1]=='R' && map[i-2][j]!='R' && map[i-1][j]!='R')
						{
							eau++;
							position=k;
							if(eau==1 && map[i+2][j-1]=='R')
							{
								eau=0;
								k=i+2;
							}
							if(eau>1)
							{
								for(int l=1; map[position-1][j-l]=='R' && map[position][j-l]=='R'; l++)
								{
									if(map[position-1][j-l-1]=!'R')
									{
										position=k-1;
									}
									else if(map[position][j-l-1]=!'R')
									{
										position=k;
									}
								}
							}
						}
					}
				}
				if(eau==1)
				{
					equation=(pow(x, depart)/i)-position;
					if(equation%3==0)
					{
						if(position-1>=0)
						{
							map[position-1][j]='R';
						}
						map[position][j]='R';
						map[position+1][j]='H';
					}
					else if(equation%3==1)
					{
						if(position-1>=0)
						{
							map[position-1][j]='H';
						}
						map[position][j]='R';
						map[position+1][j]='H';
					}
					else if(equation%3==2)
					{
						if(position-1>=0)
						{
							map[position-1][j]='H';
						}
						map[position][j]='R';
						map[position+1][j]='R';
					}
				}
				else if(eau>1)
				{
					equation=(pow(x, depart)/i)-position;
					if(position=i+1 && equation%2==0)
					{
						if(i-1>=0)
						{
							map[i-1][j]='H';
						}
						map[i][j]='H';
						map[i+1][j]='R';
					}
					else if(position=i+1 && equation%2==1)
					{
						if(i-1>=0)
						{
							map[i-1][j]='H';
						}
						map[i][j]='H';
						map[i+1][j]='R';
						map[i+2][j]='R';
					}
					else if(position=i && equation%2==0)
					{
						if(i-1>=0)
						{
							map[i-1][j]='H';
						}
						map[i][j]='R';
						map[i+1][j]='H';
					}
					else if(position=i && equation%2==1)
					{
						if(i-1>=0)
						{
							map[i-1][j]='R';
						}
						map[i][j]='R';
						map[i+1][j]='H';
					}
				}
				else
				{
					if(map[i][j]=!'R')
					{
						map[i][j]='H';
					}
				}
			}
		}
	}
	for(int p=0; p<m; p++)
	{
		for(int q=0; q<n; q++)
		{
			cout << map[p][q] << endl;
		}
	}
}
