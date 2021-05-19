// Rafael Amauri Diniz Augusto --- 651047

// Prints all operations in DFS to stdout
#define LOGGING_DFS 0

// Prints all operations in Prim's to stdout
#define LOGGING_PRIM 0

// Prints all operations in the generator to stdout
#define LOGGING_GENERATOR 0

// Number of edges to be drawn by the generator
#define NUM_EDGES 50

// The max value that can be drawn by the generator 
#define MAX_RANGE 20

#include <chrono>

#include "headers/graph.hpp"
#include "headers/prim.hpp"
#include "headers/dfs.hpp"
#include "headers/generator.hpp"


int main(void)
{
    Graph *g = new Graph();

// Generates a neat graph with <NUM_EDGES> edges and <MAX_RANGE> as a theoretical max number of vertexes
    //graph_generator(g, NUM_EDGES, MAX_RANGE);

    
    // Some sample graphs
// Graph 1
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
// Graph 2
/*
    g->add_edge(0,1,1);
    g->add_edge(1,2,2);
    g->add_edge(2,3,3);
    g->add_edge(3,0,4);
    g->add_edge(0,2,0);
    g->add_edge(4,1,10);
    g->add_edge(2,4,1);
*/
// Graph 3
/*
    g->add_edge(0,9,3);
    g->add_edge(0,3,1);
    g->add_edge(3,7,46);
    g->add_edge(7,6,1);
    g->add_edge(6,10,4);
    g->add_edge(11,10,64);
    g->add_edge(9,11,12);
    g->add_edge(0,7,1);
    g->add_edge(0,1,4);
    g->add_edge(3,1,8);
    g->add_edge(7,5,12);
    g->add_edge(5,6,11);
    g->add_edge(8,9,6);
    g->add_edge(8,1,9);
    g->add_edge(1,5,7);
    g->add_edge(5,4,12);
    g->add_edge(5,11,10);
    g->add_edge(8,4,3);
    g->add_edge(4,1,9);
    g->add_edge(4,11,1);
    g->add_edge(5,10,0);
    g->add_edge(6,11,12);
    g->add_edge(4,7,67);
    g->add_edge(8,11,15);
*/
// Graph 4
/*
    g->add_edge(24,9,4);
    g->add_edge(20,9,32);
    g->add_edge(7,9,5);
    g->add_edge(18,11,8);
    g->add_edge(11,21,53);
    g->add_edge(4,11,3);
    g->add_edge(22,10,883);
    g->add_edge(19,10,10);
    g->add_edge(5,10,5);
    g->add_edge(23,8,2);
    g->add_edge(17,8,20);
    g->add_edge(8,6,7);
    g->add_edge(13,16,4);
    g->add_edge(16,14,64);
    g->add_edge(14,15,33);
    g->add_edge(15,13,85);
    g->add_edge(12,15,21);
    g->add_edge(12,14,6);
    g->add_edge(12,13,12);
    g->add_edge(19,14,96);
    g->add_edge(14,20,21);
    g->add_edge(17,13,22);
    g->add_edge(13,18,45);
    g->add_edge(0,13,17);
    g->add_edge(0,18,54);
    g->add_edge(0,17,9);
    g->add_edge(6,23,85);
    g->add_edge(6,17,15);
    g->add_edge(18,4,88);
    g->add_edge(4,21,4);
    g->add_edge(22,5,57);
    g->add_edge(5,19,17);
    g->add_edge(20,7,24);
    g->add_edge(24,7,453);
    g->add_edge(2,16,11);
    g->add_edge(2,24,57);
    g->add_edge(2,23,53);
    g->add_edge(8,2,32);
    g->add_edge(9,2,56);
    g->add_edge(21,3,15);
    g->add_edge(22,3,12);
    g->add_edge(10,3,2);
    g->add_edge(11,3,23);
    g->add_edge(3,15,79);
    g->add_edge(14,1,67);
    g->add_edge(1,19,56);
    g->add_edge(1,20,87);
    g->add_edge(10,12,35);
    g->add_edge(12,9,22);
    g->add_edge(12,8,46);
    g->add_edge(12,11,8);
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
