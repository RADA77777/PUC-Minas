#include "headers/graph.hpp"
#include "headers/dfs.hpp"

int main()
{
    Graph *g = new Graph();
    g->add_edge(0,1,1);
    g->add_edge(1,2,2);
    g->add_edge(2,3,3);
    g->add_edge(3,0,4);
    g->add_edge(0,2,0);
    g->add_edge(4,1,10);
    g->add_edge(2,4,1);

    dfs_find(g, 0, 13);

    return 0;
}