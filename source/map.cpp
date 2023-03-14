#include "map.h"

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
	int eau=0;
	int position=0;
	int equation=(pow(x, depart)/m)-n;
	if(equation%2==0)
	{
		map[0][depart] = 0;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(j>0)
				{
					for(int k=j-1; k<j+2; k++)
					{
						if(i>0 && map[i-1][k]==0 && map[i][j-2]!=0 && map[i][j-1]!=0)
						{
							eau++;
							position=k;
							if(eau==1 && map[i-1][j+2]==0)
							{
								eau=0;
								k=j+2;
							}
							if(eau>1)
							{
								for(int l=1; map[i-l][position-1]==0 && map[i-l][position]==0; l++)
								{
									if(map[i-l-1][position-1]!=0)
									{
										position=k-1;
									}
									else if(map[i-l-1][position]!=0)
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
							map[i][position-1]=0;
						}
						map[i][position]=0;
						map[i][position+1]=1;
					}
					else if(equation%3==1)
					{
						if(position-1>=0)
						{
							map[i][position-1]=1;
						}
						map[i][position]=0;
						map[i][position+1]=1;
					}
					else if(equation%3==2)
					{
						if(position-1>=0)
						{
							map[i][position-1]=1;
						}
						map[i][position]=0;
						map[i][position+1]=0;
					}
				}
				else if(eau>1)
				{
					equation=(pow(x, depart)/i)-position;
					if(position=j+1 && equation%2==0)
					{
						if(j-1>=0)
						{
							map[i][j-1]=1;
						}
						map[i][j]=1;
						map[i][j+1]=0;
					}
					else if(position=j+1 && equation%2==1)
					{
						if(j-1>=0)
						{
							map[i][j-1]=1;
						}
						map[i][j]=1;
						map[i][j+1]=0;
						map[i][j+2]=0;
					}
					else if(position=j && equation%2==0)
					{
						if(j-1>=0)
						{
							map[i][j-1]=1;
						}
						map[i][j]=0;
						map[i][j+1]=1;
					}
					else if(position=j && equation%2==1)
					{
						if(j-1>=0)
						{
							map[i][j-1]=0;
						}
						map[i][j]=0;
						map[i][j+1]=1;
					}
				}
				else
				{
					if(map[i][j]!=0)
					{
						map[i][j]=1;
					}
				}
			}
		}
	}
	else
	{
		map[depart][0]=0;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i>0)
				{
					for(int k=i-1; k<i+2; k++)
					{
						if(j>0 && map[k][j-1]==0 && map[i-2][j]!=0 && map[i-1][j]!=0)
						{
							eau++;
							position=k;
							if(eau==1 && map[i+2][j-1]==0)
							{
								eau=0;
								k=i+2;
							}
							if(eau>1)
							{
								for(int l=1; map[position-1][j-l]==0 && map[position][j-l]==0; l++)
								{
									if(map[position-1][j-l-1]!=0)
									{
										position=k-1;
									}
									else if(map[position][j-l-1]!=0)
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
							map[position-1][j]=0;
						}
						map[position][j]=0;
						map[position+1][j]=1;
					}
					else if(equation%3==1)
					{
						if(position-1>=0)
						{
							map[position-1][j]=1;
						}
						map[position][j]=0;
						map[position+1][j]=1;
					}
					else if(equation%3==2)
					{
						if(position-1>=0)
						{
							map[position-1][j]=1;
						}
						map[position][j]=0;
						map[position+1][j]=0;
					}
				}
				else if(eau>1)
				{
					equation=(pow(x, depart)/i)-position;
					if(position=i+1 && equation%2==0)
					{
						if(i-1>=0)
						{
							map[i-1][j]=1;
						}
						map[i][j]=1;
						map[i+1][j]=0;
					}
					else if(position=i+1 && equation%2==1)
					{
						if(i-1>=0)
						{
							map[i-1][j]=1;
						}
						map[i][j]=1;
						map[i+1][j]=0;
						map[i+2][j]=0;
					}
					else if(position=i && equation%2==0)
					{
						if(i-1>=0)
						{
							map[i-1][j]=1;
						}
						map[i][j]=0;
						map[i+1][j]=1;
					}
					else if(position=i && equation%2==1)
					{
						if(i-1>=0)
						{
							map[i-1][j]=0;
						}
						map[i][j]=0;
						map[i+1][j]=1;
					}
				}
				/*else
				{
					if(map[i][j]!=0)
					{
						map[i][j]=1;
					}
				}*/
			}
		}
	}
	for(int p=0; p<m; p++)
	{
		for(int q=0; q<n; q++)
		{
			/*if (map[p][q] != 0)
			{
				map[p][q] = 1;
			}*/
			cout << map[p][q] << " ";
		}
		cout << endl;
	}
}
