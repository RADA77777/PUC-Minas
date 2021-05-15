// Rafael Amauri Diniz Augusto --- 651047

// Prints all operations in DFS to stdout
#define LOGGING_DFS 0

// Prints all operations in Prim's to stdout
#define LOGGING_PRIM 0

// Prints all operations in the generator to stdout
#define LOGGING_GENERATOR 0

// Number of edges to be drawn by the generator
#define NUM_EDGES 500

// The max value that can be drawn by the generator 
#define MAX_RANGE 200

#include <chrono>

#include "graph.hpp"
#include "prim.hpp"
#include "dfs.hpp"
#include "generator.hpp"


int main(void)
{
    Graph *g = new Graph();

// Generates a neat graph with <NUM_EDGES> edges and <MAX_RANGE> as a theoretical max number of vertexes
    graph_generator(g, NUM_EDGES, MAX_RANGE);

// Some sample graphs
/*
    g->add_edge(0,1,2);
    g->add_edge(0,3,3);
    g->add_edge(4,0,0);
    g->add_edge(4,1,1);
    g->add_edge(1,3,0);
    g->add_edge(3,4,1);
    g->add_edge(1,2,1);
    g->add_edge(3,2,1);
*/
/*
    g->add_edge(0,1,1);
    g->add_edge(1,2,2);
    g->add_edge(2,3,3);
    g->add_edge(3,0,4);
    g->add_edge(0,2,0);
    g->add_edge(4,1,10);
    g->add_edge(2,4,1);
    g->add_edge(3,4,0);
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
/*
    g->add_edge(0,1,7);
    g->add_edge(0,2,0);
    g->add_edge(1,2,2);
    g->add_edge(2,3,1);
*/

    using clock = std::chrono::system_clock;
    using sec = std::chrono::duration<double>;


    std::cout << "Iniciando Algoritmo de Prim...\n";


    // How much time it took for Prim's algorithm to find the cycles
    const auto prim = clock::now();
    prim_count_cycles(g, 0);
    sec duration = clock::now() - prim;
    std::cout << "Prim demorou " << duration.count() << "s\n";

    // How many cycles Prim's algorithm found
    std::cout << "Prim: existem " << g->num_cycles << " ciclos\n\n";

    // Clearing the list for another run
    g->clear_visited_vertexes();
    g->num_cycles = 0;


    std::cout << "Iniciando DFS...\n";


    // How much time it took for DFS to find the cycles
    const auto dfs = clock::now();
    dfs_count_cycles(g, 0);
    duration = clock::now() - dfs;
    std::cout << "DFS demorou " << duration.count() << "s" << std::endl;

    // How many cycles DFS found
    std::cout << "DFS: existem " << g->num_cycles << " ciclos\n";
}
