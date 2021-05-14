// Rafael Amauri Diniz Augusto --- 651047

#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <stdlib.h>

#include "graph.hpp"

void graph_generator(Graph *g, int num_edges, int range)
{
    srand(time(NULL));
    int vertex1, vertex2, edge_weight, aux;
    vertex1 = aux = 0;
    bool repeated;
    std::vector<std::map<int, int>> combinations;

    for(int i = 0; i < num_edges; i++)
    {
        do
        {
            repeated = false;

            if(LOGGING == 1)
                std::cout << "Resorteando...\n" ;
            
            vertex2 = rand()%range;

            for(auto i : combinations)
                for(auto j : i)
                    if( (j.first == vertex1 && j.second == vertex2) || 
                        (j.first == vertex2 && j.second == vertex1)||
                        (vertex2 == aux)||
                        (vertex2 == vertex1))
                            repeated = true;

        }while(repeated);

        aux = vertex1;
        edge_weight = rand()%range;

        g->add_edge(vertex1, vertex2, edge_weight);
        
        combinations.push_back({{vertex1, vertex2}});

        if(LOGGING == 1)
            std::cout << "Inserido: " << vertex1 << " - " << vertex2 << " - " << edge_weight << "\n";
        vertex1 = vertex2;
    }
}


#endif