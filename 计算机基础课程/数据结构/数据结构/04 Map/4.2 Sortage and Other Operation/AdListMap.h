//
// Created by sacomplex on 2018/12/1.
//

#ifndef BT_ADLISTMAP_H
#define BT_ADLISTMAP_H

using T = int;

// 边表顶点
struct ArcNode{
    int adjvex;
    ArcNode *next;
};

// 顶点表
struct VertexNode {
    T vertex;
    ArcNode *firstedge;
};

class AdListMap {
public:
    VertexNode* adList;
    int vertex;
    int edge;

public:

};


#endif //BT_ADLISTMAP_H
