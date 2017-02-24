#include <stdio.h>
#include <queue>
using namespace std;
#define oo (1<<29)
const int maxn = 110;
int n , m;
int RE[maxn][maxn] , EF[maxn] , H[maxn];
int S , T , Max_Flow;
queue<int> Q;

int min(int a , int b)
{
    return a < b ? a : b;
}

void init()
{
    Max_Flow = 0;
    S = 1; T = n;
    H[S] = n;
    EF[S] = oo;
    EF[T] = -oo;
}

void Push(int Si)
{
    int i , Tmp;
    for(i=1;i<=n;i++)
    {
        Tmp = min(RE[Si][i] , EF[Si]);
        if(Tmp > 0 && (Si == S || H[Si] - H[i] == 1))
        {
            RE[Si][i] -= Tmp; RE[i][Si] += Tmp;
            EF[Si] -= Tmp; EF[i] += Tmp;
            if(i == T) Max_Flow +=Tmp;
            if(i != T && i != S) Q.push(i);
        }
    }
    return;
}

void Relabel(int Si)
{
    if(Si != S && Si != T && EF[Si] > 0)
    {
        H[Si] ++;
        Q.push(Si);
    }
    return;
}

void Push_Relabel()
{
    int Si;
    init();
    Q.push(S);
    while(!Q.empty())
    {
        Si = Q.front();
        Q.pop();
        Push(Si);
        Relabel(Si);
    }
    printf("%d\n",Max_Flow);
}

int main()
{
    //freopen("pushrelabelin.txt","r",stdin);
    //freopen("pushrelabelout.txt","w",stdout);
    scanf("%d%d",&m,&n);
    init();
    int i;
    int u , v , w;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        RE[u][v] += w;
    }
    Push_Relabel();
    return 0;
}
