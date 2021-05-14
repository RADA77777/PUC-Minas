// Rafael Amauri Diniz Augusto --- 651047


#include <iostream>
#include "graph.hpp"


int main(void)
{
    Graph *g = new Graph();

    g->add_edge(1,2,1);
    g->add_edge(2,3,2);
    g->add_edge(3,4,3);
    g->add_edge(4,1,4);
    g->add_edge(1,3,0);
    g->add_edge(5,2,10);
    g->add_edge(3,5,1);
    g->add_edge(4,5,0);

    Graph *mst = new Graph();

    //std::cout << g->adjacent_vertexes.size();

    g->prim_count_cycles(1, mst, 0);

    std::cout <<"\n\n";

    for(auto i : mst->adjacent_vertexes)
        for(auto j : i.second)
            for(auto k: j)
            {
                std::cout << i.first << " <---" << k.second << "---> " << k.first << "\n";
            }

    int cycles = g->num_edges - mst->num_edges;
    std::cout << "Existem " << cycles << " ciclos\n";

}