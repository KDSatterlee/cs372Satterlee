//
//  graph.hpp
//  ass6
//
//  Created by Kurtis Satterlee on 10/17/22.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <utility>
template <class N>
class Graph{
public:
    Graph() {};
    Graph(std::vector<N> nodes, std::vector<std::pair<N, N>> edges){};
    virtual ~Graph(){};
    
    virtual void adjecent(N x,  N y);
    virtual std::vector<N> nenighbors() = 0;
    virtual void addNode(N x) = 0;
    virtual void addEdge(N x, N y) = 0;
    virtual void deleateEdge(N x, N y) = 0;
    void dfs(N startNode);
    void bfs(N startNode);
    
};
#endif /* graph_hpp */
