/*************************************************************************
	> File Name: GraphVisitByDfs.cpp
	> Author: bw98 
	> Mail: 786016476@qq.com
	> Created Time: 2017年12月13日 星期三 10时42分49秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<queue>
#define MAX 100
using namespace std;

typedef struct {
    int adjx[MAX][MAX]; //邻接矩阵
    int v; //顶点数
    int e; //边数
}Graph;

void createGraph (Graph *); //创建无向图
void dfs_Recursion (Graph& , int ); //dfs递归
void dfs_NotRecursion (Graph& , int ); //dfs非递归
void bfs (Graph& , int ); //bfs
void printAdjx (Graph& ); //打印无向图

bool visited2[MAX] = {0};

int main (void) {
    int vertexNumber, eNumber;
    cout << "please input vertex total Number and e total Number" << endl;
    cin >> vertexNumber >> eNumber;
    if (vertexNumber > 0) {
        Graph G;
        G.v = vertexNumber;
        G.e = eNumber;
        createGraph (&G);
        printAdjx(G); 
        int startVertex;
        cout << "please input first visiting vertex you want" << endl;
        cin >> startVertex;
        //dfs bfs 加在这
        //若考虑图不为连通图，想得到连通分量，可在此行判断是否所有点都被访问
    }
    
    cout << endl;
    return 0;
}

void createGraph (Graph *G) {
    int i,j;
    int v1,v2,val; //<v1, v2> 用于存储边的权值
    for (i = 0; i < G->v; i++) {
        for (j = 0; j < G->v; j++) {
            G->adjx[i][j] = 0;
        }
    }
    for (i = 0; i < G->e; i++) {
        cout << "v1, v2, and value is: " << endl;
        cin >> v1 >> v2 >> val;
        G->adjx[v1][v2] = val;
        G->adjx[v2][v1] = val;
    }
}

void printAdjx (Graph& G) {
    int i,j;
    for (i = 0; i < G.v; i++) {
        for (j = 0; j< G.v; j++) {
            cout << G.adjx[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs_Recursion (Graph& G, int v0) {
    //递归算法，只能通过全局的访问数组进行标记 
    visited2[v0] = true;
    cout << v0 << " ";
    //移动到第一个相邻的邻接点
    int i;
    for (i = 0; i < G.v; ++i) {
        if (G.adjx[v0][i] && !visited2[i]) {
            break;
        }
    }
    //没有未被标记且与v相邻的顶点
    if (i == G.v) {
        return;
    };
    //找到与 v 相邻的顶点
    dfs_Recursion (G, i);
}

void dfs_NotRecursion (Graph &G, int n) {
    bool visited[G.v];
    int i;
    for (i = 0; i < G.v; ++i) {
        visited[i] = false;
    }
    
    stack<int> s;
    cout << n << " ";
    visited[n] = true;
    s.push(n);
    while (!s.empty()) {
        int topVertexIndex;
        topVertexIndex = s.top();
        
        for (i = 0; i < G.v; ++i) {
            if ((G.adjx[topVertexIndex][i] != 0) && (visited[i] == false) ) {
                cout << topVertexIndex << " ";
                visited[i] = true;
                s.push(i);
                break;
            }
        }
        if (i == G.v) { s.pop(); } //所有相邻点都被访问
    }
}

void bfs (Graph& G, int v0){
    //访问结点并标记
    cout << v0 << " ";
    visited2[v0] = true;

    queue<int> q;
    q.push(v0);

    while (!q.empty()) { //队列为空说明所有有路的点都已访问
        int v;
        v = q.front();
        q.pop();
        int i;
        for (i = 0; i < G.v; ++i) {
            if (G.adjx[v][i] && !visited2[i]) {
                cout << i << " ";
                visited2[i] = true;
                q.push(i);
            }
        }
    }
    
}
