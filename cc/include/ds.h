//
// Created by f on 2023/11/18.
//

#ifndef DS_H
#define DS_H
class Graph {
public:
    virtual void CreateGraph() = 0;
    virtual void DestroyGraph() = 0;
    virtual int LocateVex() = 0;
    virtual int GetVex() = 0;
    virtual void PutVex() = 0;
    virtual int FirstAdjVex() = 0;
    virtual int NextAdjVex() = 0;
    virtual void InsertVex() = 0;
    virtual void DeleteVex() = 0;
    virtual void InsertArc() = 0;
    virtual void DeleteArc() = 0;
    virtual void DFSTraverse() = 0;
    virtual void BFSTraverse() = 0;
};
#endif //DS_H
