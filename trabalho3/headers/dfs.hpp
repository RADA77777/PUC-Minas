// Rafael Amauri Diniz Augusto --- 651047

#include <iostream>

#include "graph.hpp"

#ifndef DFS_HPP
#define DFS_HPP
#define LOGGING_DFS 1


bool _dfs_find(Graph *g, int current_vertex, int parent_vertex, int value)
{
    bool is_found = false;

    if(current_vertex == value)
        is_found = true;

    // Percorrer o grafo com o DFS e encontar o vértice <value>
    else
    {
        g->visited_vertexes[current_vertex] = 2;
        
        for(auto i : g->adjacent_vertexes[current_vertex])
            for(auto j : i)
            {        
                if(j.first == parent_vertex || g->visited_vertexes[j.first] == 2)
                    continue;

                if(LOGGING_DFS == 1)
                    std::cout << "Caminhando do vertice " << current_vertex << " para o vertice " << j.first << "\n";
                    
                is_found = _dfs_find(g, j.first, current_vertex, value);
            }
    }

    return is_found;
}


void dfs_find(Graph *g, int root, int value)
{
    if(LOGGING_DFS == 1)
        std::cout << "Starting vertex is " << root << "\n\n";

    bool is_found = _dfs_find(g, root, -1, value);

    if(is_found)
        std::cout << "O vertice " << value << " existe no grafo\n";
    else
        std::cout << "O vertice " << value << " não existe no grafo\n";
}

#endif
