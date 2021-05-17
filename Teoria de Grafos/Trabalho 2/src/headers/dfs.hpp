// Rafael Amauri Diniz Augusto --- 651047

#include <iostream>

#include "graph.hpp"

#ifndef DFS_HPP
#define DFS_HPP


void _dfs_count_cycles(Graph *g, int current_vertex, int parent_vertex)
{

    // Se ja for totalmente visitado, voltar pro vertice anterior
    if(g->visited_vertexes[current_vertex] == 2)
        return;

    // Marcando current_vertex como parcialmente visitado
    g->visited_vertexes[current_vertex] = 1;


    // Percorrer o grafo com um DFS modificado e contar a quantidade de ciclos
    for(auto i : g->adjacent_vertexes[current_vertex]){
        for(auto j : i)
        {
            if(j.first != parent_vertex)
            {
                if(g->visited_vertexes[j.first] == 1)
                {
                    if(LOGGING_DFS == 1)
                        std::cout << "\nFound a cycle: " << current_vertex << " - " << j.first << "\n\n"; 

                    g->num_cycles++;
                }

                else
                {
                    if(LOGGING_DFS == 1)
                        std::cout << "Now visiting: " << j.first << "\n";

                    _dfs_count_cycles(g, j.first, current_vertex);

                    if(LOGGING_DFS == 1)
                        std::cout << "Returning to: " << current_vertex << "\n";
                }
            }
        }
    }

    g->visited_vertexes[current_vertex] = 2;

    return;
}


void dfs_count_cycles(Graph *g, int root)
{
    if(LOGGING_DFS == 1)
        std::cout << "Starting vertex is " << root << "\n\n";

    _dfs_count_cycles(g, root, -1);
}

#endif