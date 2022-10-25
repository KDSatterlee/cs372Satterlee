//
//  File:   AdjListGraph.hpp
//  Author: Your Glorious Instructor
//  Purpose:
//  Implementation of the adjacency list implementation of the graph ADT
//

#include "Graph.hpp"
#include <map>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

template <class N>
class AdjListGraph: public Graph<N>  {
private:
  using Edges = list<pair<N, N>>;
  map<N, Edges > vertexMap;
public:
  // Default constuctor, create empty
  AdjListGraph() : Graph<N>() { };

  // Get the vertex map from the Graph we're copying
  AdjListGraph(const AdjListGraph& other) : Graph<N>()
    {
      vertexMap = other->vertexMap;
    }

  // Don't forget to overload the assignment operator
  AdjListGraph& operator= (const AdjListGraph &source)
    {
      vertexMap = source->vertexMap;
      return *this;
    }

  // Add the nodes in the list to graph
  AdjListGraph(vector<N> newNodes, vector<pair<N,N>> newEdges) :
    Graph<N>(newNodes, newEdges)
    {
      for (auto it = newNodes.begin();
           it < newNodes.end();
           ++it)
      {
        N node = *it;
        vertexMap[node].push_back(newEdges);
      }
    }


  // Clean up behind ourselves
  ~AdjListGraph() { }

  virtual bool adjacent(N x, N y){
    Edges edges = vertexMap.at(x);
    pair<N,N> *searchEdge = new pair<N,N>(x,y);
    typename Edges::const_iterator begin = edges.begin();
    typename Edges::const_iterator end = edges.end();
    auto pos = std::find_if(begin,end,
                            [&](pair<N,N> const &b) {
                              bool match =  (b.first == searchEdge->first
                                              && b.second == searchEdge->second);
                              return match;
                            });
    bool match = false;
    if (pos != end) { match = true; }
    return (match);
  }

  virtual vector<N> neighbors(N x) {
    vector<N> *nodes = new vector<N>();
    Edges edges = vertexMap.at(x);
    for (typename Edges :: const_iterator it = edges.begin(); it != edges.end(); it++) {
      pair<N,N> e = *it;
      nodes->push_back(e.first);
    }
    return *nodes;
  }

  virtual void addNode(N node){
    Edges * newEdgeList = new Edges();
    vertexMap[node] = *newEdgeList;
  }

  virtual void addEdge(N x, N y){
    pair<N,N> forwardEdge = make_pair(x,y);
    pair<N,N> backwardEdge = make_pair(y,x);
    Edges edgeList = vertexMap[x];
    edgeList.push_back(forwardEdge);
    vertexMap[y].push_back(backwardEdge);
  }

  virtual void deleteEdge(N x, N y){
    pair<N,N> forwardEdge = make_pair(x,y);
    pair<N,N> backwardEdge = make_pair(y,x);
    vertexMap[x].remove(forwardEdge);
    vertexMap[y].remove(backwardEdge);
  }
    void dfs(int start, vector<bool>& visited)
    {
     
        // Print the current node
        cout << start << " ";
     
        // Set current node as visited
        visited[start] = true;
     
        // For every node of the graph
        for (int i = 0; i < adj[start].size(); i++) {
     
            // If some node is adjacent to the current node
            // and it has not already been visited
            if (adj[start][i] == 1 && (!visited[i])) {
                dfs(i, visited);
            }
        }
    }
    void bfs(int start)
    {
        // Visited vector to so that
        // a vertex is not visited more than once
        // Initializing the vector to false as no
        // vertex is visited at the beginning
        vector<bool> visited(adj.size(), false);
        vector<int> q;
        q.push_back(start);
      
        // Set source as visited
        visited[start] = true;
      
        int vis;
        while (!q.empty()) {
            vis = q[0];
      
            // Print the current node
            cout << vis << " ";
            q.erase(q.begin());
      
            // For every adjacent vertex to the current vertex
            for (int i = 0; i < adj[vis].size(); i++) {
                if (adj[vis][i] == 1 && (!visited[i])) {
      
                    // Push the adjacent node to the queue
                    q.push_back(i);
      
                    // Set
                    visited[i] = true;
                }
            }
        }
    }


};
