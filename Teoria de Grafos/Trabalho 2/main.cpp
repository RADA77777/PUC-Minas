// Rafael Amauri Diniz Augusto --- 651047


#include <iostream>

#include "graph.hpp"
#include "prim.hpp"
#include "dfs.hpp"


int main(void)
{
    Graph *g = new Graph();
    Graph *mst = new Graph();
    Prim *p = new Prim();


// Some sample graphs

/*
    g->add_edge(1,2,1);
    g->add_edge(2,3,2);
    g->add_edge(3,4,3);
    g->add_edge(4,1,4);
    g->add_edge(1,3,0);
    g->add_edge(5,2,10);
    g->add_edge(3,5,1);
    g->add_edge(4,5,0);
*/


/*
    g->add_edge(1,2,19);
    g->add_edge(1,3,11);
    g->add_edge(2,4,7);
    g->add_edge(1,4,3);
    g->add_edge(3,4,3);
    g->add_edge(3,2,0);
    g->add_edge(5,2,6);
    g->add_edge(6,5,5);
    g->add_edge(6,2,3);
*/

/*
    g->add_edge(0,2,7);
    g->add_edge(0,1,2);
    g->add_edge(2,3,4);
    g->add_edge(2,4,6);
    g->add_edge(3,4,8);
*/


    p->prim_generate_mst(g, mst, 3);
    std::cout << "Existem " << g->num_cycles << " ciclos\n";

    g->clear_visited_vertexes();

    dfs_count_cycles(g, 3);
    std::cout << "Existem " << g->num_cycles << " ciclos\n";

}