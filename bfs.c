#include <stdio.h>
#include<stdlib.h>
#define MAX 100
#define white 1
#define grey 2
#define black 3

int n;
int queue[MAX], front = -1,rear = -1;
int adj[MAX][MAX];
int state[MAX];
void creatgraph();
void bftravs();
void bfs(int v);
void insert_queue(int vertex);
int isEmpty_queue();
int delete_queue();

int main ()
{
    creatgraph();
    bftravs();
}

void bftravs()
{
    int j;
    for (j=1;j<=n;j++)
    {
        state[j]=white;
    }
    printf("Enter the root\n");
    scanf("%d",&j);
    bfs(j);
}
void bfs(int j)
{
    int i;
    insert_queue(j);
	state[j] = grey;

	while(!isEmpty_queue())
	{
		j = delete_queue( );
		printf("%d ",j);
		state[j] = black;
      for(i=1; i<=n; i++)
		{

        if(adj[j][i] == 1 && state[i] == white)
			{
				insert_queue(i);
				state[i] = grey;
				printf("%d\n",state[i]);
			}
		}
	}
	printf("\n");
}
void insert_queue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue is full\n");
	else
	{
		if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}

int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue is empty\n");
		exit(1);
	}

	delete_item = queue[front];
	front = front+1;
	return delete_item;
}

void creatgraph()
{
    int origin,destin;
    int edge, i;
    printf("Enter the no of vertices\n");
    scanf("%d",&n);
    edge= n*(n-1);
    for (i=0; i<edge; i++)
    {
       printf("Enter the edge(type -1 -1 to quit\n");
       scanf("%d %d",&origin,&destin);
       if (origin == -1 && destin == -1)
       {
           break;
       }
       else if (origin < 0 || origin >n || destin >n || destin <0 )
       {
           printf ("Invalid edge\n");
           i--;
       }
       else
       {
           adj[origin][destin] = 1;

       }
    }
}

