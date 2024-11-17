/* Traversal using BFS and DFS method*/

#include<stdio.h>
#include<conio.h>
int a[10][10], s[10],n;
void bfs(int u)
{
	int	f,r,q[10],v;
	int 	s[10]={0};           //initialize all elem in s to 0, no node visited
	printf("\nThe nodes reachable from %d:",u);
	f=0, r=-1;                  // Q empty
	q[++r]=u;                  // Insert u into Q
	s[u]=1;                      // Insert u to s
	printf("%d\t",u);             //print node visited
	while(f<=r)
	{
		u=q[f++];                                 //del an elem from Q
		for(v=0; v<n; v++)
		{
			if(a[u][v]==1)		          //If v is adjacent to u
			{
				if(s[v]==0)                  // If v is not in S i.e, V has not been visited
				{
					printf("%d\t",v);      // print the node visited
					s[v]=1;		           //add v to s,mark as visited
					q[++r]=v;	                 //insert v into Q
				}
			}
		}
	}
       //	printf("\n");
}

void read_AM( )
{
		int 	i,j;
		//read n value
		for( i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
}

void print_AM( )
{
		int 	i,j;
		//read n value
		for( i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				printf("%d\t", a[i][j]);
			}
			printf("\n");
		}
}

void dfs(int u)
{
		int 	v;
		s[u]=1;
		printf("%d\t",u);
		for(v=0; v<n; v++)
		{
			if(a[u][v]==1 && s[v]==0)
				dfs(v);
		}
}

void main()
{
		int 	i, source;
		clrscr();
		printf("Enter the number of nodes in the 	graph:");
		scanf("%d",&n);
		printf("Enter the adjacency matrix:");
		read_AM();
		printf("The adjacency matrix for the given graph:\n");
		print_AM();
		printf("\nBFS\n");
		for(source=0; source<n; source++)
		{
			bfs(source);
		}
		printf("\nDFS\n");
		for(source=0; source<n; source++)
		{
			for(i=0; i<n; i++)
				s[i]=0;
			printf("\nThe nodes reachable from %d:", source);
			dfs(source);
		}
getch();
}
