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
            if(j.first != parent_vertex && g->visited_vertexes[j.first] == 1 && g->visited_vertexes[current_vertex] == 1)
            {
                if(g->visited_vertexes[j.first] == 1)
                {
                    g->num_cycles++;
                }
                else if (j.first != parent_vertex)
                {
                    std::cout << "Saindo de " << current_vertex << " e indo pra " << j.first << "\n";
                    _dfs_count_cycles(g, j.first, current_vertex);
                    std::cout << "Voltei pro vértice " << current_vertex << "\n";
                }
            }
        }
    }

    g->visited_vertexes[current_vertex] = 2;

    return;
}


void dfs_count_cycles(Graph *g, int root)
{
    _dfs_count_cycles(g, 1, -1);
}

#endif