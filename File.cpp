#include<bits/stdc++.h>
#include<stdlib.h>
#define SIZE 100105
#define SIZEo 200105
#define INF 1000000000
#define price 10
using namespace std;

int cmst,ds;
int total;
int ic;
int flag=0;
char name[110];
char ID[15];

void instdj()
{
    printf("\t\n\n\n\n Instructions to reach Destination: \n\n");
    printf("\t1.You have to enter every way to reach the destination \n");
    printf("\t2.The stops will have to be the value of 1 to the number of stops  \n");
    printf("\t3.The node of the number of stops will have to be the destination \n");

    printf("\n\n\nplease enter 1 to continue: ");

}


struct element{
    int node=0, weight=0;
    element(){}

    element(int n, int w){
        node=n;
        weight=w;
    }
    bool operator <(const element &a)const{
        return weight<a.weight;
    }
    bool operator >(const element &a)const{
        return weight>a.weight;
    }
};

priority_queue <element, vector <element>, greater <element> > pq;
int dis[SIZE];
bool vis[SIZE];
int prt[SIZE];
vector <int> adj[SIZE];
vector <int> adjw[SIZE];
int n, e,sto;
int ytd;
void in(int source){
    for(int i=1; i<=n; i++){
        dis[i]=INF;
        vis[i]=false;
    }
    dis[source]=0;
}

void dijkstra(int source){
    in(source);
    pq.push(element(source, 0));
    int u, v;
    while(!pq.empty()){
        u=pq.top().node;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0; i<(int)adj[u].size(); i++){
            v=adj[u][i];
            prt[v]=u;
            if(dis[v]>dis[u]+adjw[u][i]){
                dis[v]=dis[u]+adjw[u][i];
                pq.push(element(v, dis[v]));
            }
        }
        ytd=v;
    }
}


//*********************************************************************************************************************


void instmst()
{
    printf("\t\n\n\n\n Instructions to reach the sites: \n\n");
    printf(" [NOTE:] Here assume the destination %d as 1\n",ytd);
    printf("\t2.You have to enter the value of the stops and connecting paths\n");
    printf("\t2.You have to enter every way to reach the destination \n");
    printf("\t3.The stops will have to be the value of 1 to the number of stops  \n");
    printf("\t4.The node of the number of stops will have to be the destination \n");

    printf("\n\n\nplease enter 1 to continue: ");

}




struct edge{
    int u1, v1, w1;
}edges[SIZE];

bool cmp(edge a, edge b){
    return a.w1<b.w1;
}

int par[SIZEo], sz[SIZEo];
int pt[SIZEo];

void init(int n){
    for(int i=1; i<=n; i++){
        par[i]=-1;
        sz[i]=1;
    }
}




int findRoot(int u){
    if(par[u]==-1) return u;
    return findRoot(par[u]);
}

int merger(int u, int v){
    u=findRoot(u);
    v=findRoot(v);
    if(u==v) return 0;
    if(sz[u]<sz[v]) swap(u, v);
    par[v]=u;
    sz[u]=sz[v]+sz[u];
    return 1;
}


int mst(int n, int e){
    int sum=0;
    init(n);
    sort(edges, edges+e, cmp);
    for(int i=0; i<e; i++){
        if(merger(edges[i].u1, edges[i].v1)==1)
            {
            pt[edges[i].v1]=edges[i].u1;
            sum+=edges[i].w1;
        }
    }
    return sum;
}
int x;
int prnt1(int n1)
{


    for(int i=0;i<n1;i++)
    {
        if(x!=edges[i].v1);
        {printf("%d -> %d\n",pt[edges[i].v1],edges[i].v1);
        x=edges[i].v1;
        }
    }


}




void calldj()
{


    int u, v, w;
    printf("\t   Enter the number of stops(Including the starting point): ");
    scanf("%d", &n);
    printf("\t\t  Enter the number of connections between them: ");
    scanf("%d", &e);

    for(int i=0; i<e; i++){
        printf("\nEnter the two points: ");
        scanf("%d %d", &u, &v);
        printf("Enter the distance between them: ");
        scanf("%d", &w);
        if(u==v||u>n||v>n)
        {
            flag=100;
            break;
        }
        if(i==0)
        {
            sto=u;
        }
        adj[u].push_back(v);

        adjw[u].push_back(w);
    }
    printf("\n\n");

}



void callmst()
{
int u1, v1, w1;
int n1, e1;
    printf("\t   Enter the number of sites(Including the starting point): ");
    scanf("%d", &n1);
    printf("\t\t  Enter the number of connections between them: ");
    scanf("%d", &e1);
    for(int i=0; i<e1; i++){
        printf("\nEnter the two nodes: ");
        scanf("%d %d", &u1, &v1);
        printf("Enter the distance between them: ");
        scanf("%d",&w1);
        if(u1==v1||u1>n1||v1>n1)
        {
            flag=100;
            break;
        }
        edges[i]={u1, v1, w1};
    }
    if(flag==100)
        printf("\n\n\t\t[**System Crash**]\n\n");
    else
    {
    cmst=mst(n1, e1);
    //printf("%d\n",cmst);

    }

printf("\n\n");

}


void cst ()
{



    total = (((cmst+ds)*price)*7);

    if(total>1000)
    {
        ic=total*0.3;

    }
    else
    {
        ic=total*0.1;


    }
    total=total+ic;


}

void bill()
{

    printf("\n\n\n");
    printf("\tName: ");
    puts(name);
    printf("\n\tID: ");
    puts(ID);
    printf("\n\tThe distance for his/her daily transport: %d\n",ds);
    printf("\tThe distance for his/her visit to all the sites is : %d",cmst);
    printf("\n\tTransportation Cost: ");
    printf("%d",ds * price);
    printf("\n\tSite visiting Cost: ");
    printf("%d",cmst * price);
    printf("\n\tTotal Cost For The Week: ");
    printf("%d",((cmst+ds)*price)*7);
    printf("\n\tInconvenience Bill: ");
    printf("%d",ic);
    printf("\n\n\n--------------------------------------------------------------------------------");
    printf("\n\t:Total Bill: ");
    printf("%d\n\n\n\n\n\n",total);





}


void intro()
{
    printf("\t\t\t\t   Convo Billing\n");
    printf("\n\n\n");
    printf("\t\t\t      Welcome to Convo Billing \n");
    printf("\n\n\n");


}



int main()
{

    int p;
    intro();
    printf("\t\t\t\t Enter 1 to start: ");
    scanf("%d",&p);

    printf("\n\tEnter Name:  ");
    cin>>name;
    printf("\n\tEnter ID:  ");
    cin>>ID;

    system("cls");







    instdj();
    scanf("%d",&p);
    system("cls");
    calldj();
    if(flag==100)
    {
        printf("\n\n\t\t\t[**System Crash**]\n\n");
        printf("\n\n\t\t\t[**Restart Again**]\n\n");
    }

    else
    {
    dijkstra(sto);
    //printf("The cost for his daily transport: %d\n", dis[n]);
    //printf("Destination is: %d\n",ytd);
    ds =dis[n];


    printf("enter 1 to continue: ");
    scanf("%d",&p);
    system("cls");
    instmst();
    scanf("%d",&p);
    system("cls");
    callmst();
    printf("Enter 1 to continue:  ");
    scanf("%d",&p);
    system("cls");

    cst();

    bill();
    }


}
