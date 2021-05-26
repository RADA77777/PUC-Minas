// Rafael Amauri Diniz Augusto --- 651047

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <map>


class Graph
{
    public:
        // This data structure uses a short to say whether a given vertex is not visited, partially visited or completely visited
        // vertex // visited -------- 0 = not visited ... 1 = partially visited ... 2 = visited
        std::map<int, short> visited_vertexes;
        
        // This data structure is used to store all edges and their values connected to a given vertex 
        // vertex 1 // connected_vertex // weight
        std::map<int, std::vector<std::map<int, int>>> adjacent_vertexes;
        
        // number of edges in the graph
        short num_edges = 0;

        // number of cycles
        short num_cycles;

        void add_edge(int vertex1, int vertex2, int weight);
        void clear_visited_vertexes();
};


// Adds an edge to the graph
void Graph::add_edge(int vertex1, int vertex2, int weight)
{
    // temporary map to be inserted onto the list
    std::map<int, int> temp;
    
    temp = {{vertex2, weight}}; 
    this->adjacent_vertexes[vertex1].push_back(temp);

    temp = {{vertex1, weight}};
    this->adjacent_vertexes[vertex2].push_back(temp);

    num_edges++;
}

// Clears the list of visited vertexes
void Graph::clear_visited_vertexes()
{
    this->visited_vertexes.clear();
}

#endif