//
// Created by f on 2023/11/15.
//

#ifndef GRAPH_H
#define GRAPH_H
#include "ds.h"
//Adjacent(G, x, y);
//NextNeighbor(G, x, y);
//InsertVertex(G, x);
//DeleteVertex(G, x);
//AddEdge(G, x, y);
//RemoveEdge(G, x, y);
//FirstNeighbor(G, x);
//NextNeighbor(G, x, y);
//GetEdgeValue(G, x, y);
//SetEdgeValue(G, x, y, v);
//InsertArc(G, x, y);
//DeleteArc(G, x, y);
//DFS(G, v);
//BFS(G, v);
void BFS(Graph G);
void BFS(Graph G, int v);
void BFSminDistance(Graph G, int v);
void DFS(Graph G);
void DFS(Graph G, int v);
//applications
void Prim(Graph G, Tree&T);
void Kruskal(Graph G, Tree&T);
void Dijkstra(Graph G, int v, int *dist, int *path);//+
void Floyd(Graph G, int **dist, int **path);//+
bool TopologicalSort(Graph G);
#endif //GRAPH_H
