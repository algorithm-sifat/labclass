#include<stdio.h>
#include<stdlib.h>
#define s 100
#define WHITE 1
#define GRAY 2
#define BLACK 3
void DFS();
void DFS_visit();
void push(int r);
void pop();
int adj[s][s],v,m_e,e1,e2,r,top=-1,count=0,i,state[s],stack[s],u;
int main()
{
    printf("Enter the number of Vertices: ");
    scanf("%d",&v);
    m_e=v*(v-1);
    printf("Enter the edges(v1 v2)\n");
    printf("Enter -1 -1 for exit\n");
    for(i=0;i<m_e;i++)
    {
        scanf("%d %d",&e1,&e2);
        if(e1==-1 && e2==-1)
        {
            break;
        }
        if((e1<1 || e1>v) || (e2<1 || e2>v))
        {
            printf("Invalid! try again\n");
            i--;
        }
        else
        {
            adj[e1][e2]=1;
        }
    }
    DFS();
}
void DFS()
{
    for(i=1;i<=v;i++)
    {
        state[i]=WHITE;
    }
    printf("Enter the root: ");
    scanf("%d",&r);
    push(r);
    DFS_visit();
}
void DFS_visit()
{
    while(top!=-1)
    {
        u=stack[top];
        state[u]=GRAY;
        for(i=1;i<=v;i++)
        {
            if(adj[u][i]==1 && state[i]==WHITE)
            {
                push(i);
                u=i;
                //state[u]=GRAY;
            }
        }
        state[u]=BLACK;
        pop();
    }
    for(i=1;i<=v;i++)
    {
        if(state[i]== WHITE)
        {
            push(i);
            DFS_visit();
        }
    }
}
void push(int r)
{
    if(top==v)
    {
        printf("The stack is full\n");
    }
    else
    {
        top++;
        stack[top]=r;
        count++;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("%d ",stack[top]);
        top--;
        count--;
    }
}
