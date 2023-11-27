//
// Created by f on 2023/11/15.
//

#ifndef DS_H
#define DS_H
#include<iostream>
typedef int ElemType;
// #define ElemType char
//List//线性表
#define SqListMaxSize 50
typedef struct {
    ElemType data[SqListMaxSize];
}SqList;//静态分配线性表
typedef struct {
    ElemType *data;
    int MaxSize, length;
}SeqList;//动态分配线性表，SequenceList
typedef struct LNode {
    ElemType data;
    LNode *next;
}LNode, *LinkList;//单链表
typedef struct DNode {
    ElemType data;
    DNode *prior, *next;
}DNode, *DLinkList;//双链表
typedef LNode CLNode;//循环单链表
typedef LNode *CLinkList;//循环单链表
typedef DNode CDNode;//循环双链表
typedef DNode *CDLinkList;//循环双链表
#define SLinkListMaxSize 50
typedef struct {
    ElemType data;
    int cur;
}SLinkList[SLinkListMaxSize];//静态链表
//Stack
#define StackMaxSize 50
typedef struct {
    ElemType data[StackMaxSize];
    int top;
}SqStack;//顺序栈
typedef LNode *LiStack;//链栈
typedef struct {
    ElemType data[StackMaxSize];
    int top0, top1;
}SqDoubleStack;//双栈，共享栈
//Queue
#define QueueMaxSize 50
typedef struct {
    ElemType data[QueueMaxSize];
    int front, rear;
}SqQueue;//顺序队列
typedef struct {
    LNode *front, *rear;
}*LinkQueue;//链式队列
//特殊矩阵
typedef struct {
    int i, j;
    ElemType e;
}Triple;//三元组
//串
#define SStringMaxSize 50
typedef struct {
    char ch[SStringMaxSize];
    int length;
}SString;//顺序串
typedef struct {
    char *ch;
    int length;
}HString;//堆串
#define ChunkSize 80
typedef struct Chunk {
    ElemType ch[ChunkSize];
    Chunk *next;
}Chunk;//块链存储表示的一个块
typedef struct {
    Chunk *head, *tail;
    int curlen;//当前块的长度
}LString;//块链串


//Tree
typedef struct BiTNode {
    ElemType data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//线索二叉树
typedef enum {Link, Thread} PointerTag;
typedef struct BiThreadNode {
    ElemType data;
    BiThreadNode *lchild, *rchild;
    PointerTag LTag, RTag;
} BiThreadNode, *BiThreadTree;
//树，森林
#define PTreeMaxSize 50
typedef struct {
    ElemType data;
    int parent;
} PTNode;
typedef struct {
    PTNode nodes[PTreeMaxSize];
    int n;//根的位置，结点数
} PTree;//双亲表示法
typedef struct CSNode {
    ElemType data;
    CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;//孩子兄弟表示法
#define UFSetsMaxSize 50
typedef struct {
    ElemType data[UFSetsMaxSize];
    int parent[UFSetsMaxSize];
    int n;//结点数
} UFSets;//并查集


//Graph
typedef char VertexType;
typedef int EdgeType;
#define MaxVertexNum 50
typedef struct {
    VertexType vex[MaxVertexNum];//顶点向量
    EdgeType edge[MaxVertexNum][MaxVertexNum];//邻接矩阵
    int vexnum, arcnum;//顶点数，边数
} MGraph;//*邻接矩阵*，MatrixGraph
//邻接表
typedef LNode ArcNode;//边结点
typedef struct VNode {
    VertexType data;//顶点信息
    ArcNode *first;//指向第一条依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];//VertexNode, AdjacencyList
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;//顶点数，边数, arc弧
} ALGraph;//邻接表, AdjacencyListGraph
//十字链表
typedef struct ArcBox {
    int tailvex, headvex;//该弧的尾和头顶点的位置
    struct ArcBox *hlink, *tlink;//分别指向弧头相同和弧尾相同的弧的链域
    // InfoType info;//该弧相关信息的指针
} ArcBox;//弧结点
typedef struct VexNode {
    VertexType data;//顶点信息
    ArcBox *firstin, *firstout;//分别指向该顶点第一条入弧和出弧
} VexNode;//顶点结点
typedef struct {
    VexNode xlist[MaxVertexNum];//表头向量
    int vexnum, arcnum;//顶点数，弧数
} OLGraph;//有向图的十字链表，OrthogonalList
//邻接多重表
typedef struct AMArcNode {
    bool mark;//访问标记
    int ivex, jvex;//该边依附的两个顶点的位置
    AMArcNode *ilink, *jlink;//分别指向依附这两个顶点的下一条边
    // InfoType info;//该边信息的指针
} AMArcNode;//边结点
typedef struct AMVexNode {
    VertexType data;//顶点信息
    AMArcNode *firstedge;//指向第一条依附该顶点的边的指针
} AMVexNode;//顶点结点
typedef struct {
    AMArcNode adjmulist[MaxVertexNum];//邻接多重表的顶点数组
    int vexnum, arcnum;//顶点数，边数
} AMLGraph;//邻接多重表，AdjacencyMultiList
//边集数组
typedef struct {
    int begin, end;//该边依附的两个顶点的位置
    // InfoType info;//该边信息的指针
} Edge;//边结点
typedef struct {
    VertexType vex[MaxVertexNum];//顶点向量
    Edge edge[MaxVertexNum];//边集数组
    int vexnum, arcnum;//顶点数，边数
} EGraph;//边集数组，EdgeArray


//Search
typedef SeqList SSTable;//顺序表
typedef BiTNode BSTNode;//二叉排序树
//Sort


typedef BiTree Tree;
typedef MGraph Graph;
#endif //DS_H
