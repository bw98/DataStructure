/*************************************************************************
	> File Name: GraphVisitByDfs.cpp
	> Author: bw98 
	> Mail: 786016476@qq.com
	> Created Time: 2017年12月13日 星期三 10时42分49秒
 ************************************************************************/

#include<iostream>
#include<stack>
#define MAX 100
using namespace std;

typedef struct {
    int adjx[MAX][MAX]; //邻接矩阵
    int v; //顶点数
    int e; //边数
}Graph;

void createGraph (Graph *);
void dfs (Graph& , int );
void printAdjx (Graph& );

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
     /*   int startVertex;
        cout << "please input first visiting vertex you want" << endl;
        cin >> startVertex;
        dfs (G, startVertex);
     */   
    }
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

void printAdjx (Graph &G) {
    int i,j;
    for (i = 0; i < G.v; i++) {
        for (j = 0; j< G.v; j++) {
            cout << G.adjx[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs (Graph &G, int n) {
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

