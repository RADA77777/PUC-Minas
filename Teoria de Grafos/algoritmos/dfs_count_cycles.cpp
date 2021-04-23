#include <iostream>
#include <list>
#include <map>

class Graph
{
    public:
        std::map<int, int> visited_vertexes; // 0 = nao visitado ... 1 = parcialmente visitado ... 2 = totalmente visitado
        std::map<int, std::list<int>> adjacent_vertexes;

        int cycles = 0;

        void add_edge(int vertex1, int vertex2);
        void count_cycles(int current_vertex, int parent_vertex);
};


void Graph::add_edge(int vertex1, int vertex2)
{
    this->adjacent_vertexes[vertex1].push_back(vertex2);
    this->adjacent_vertexes[vertex2].push_back(vertex1);
}


void Graph::count_cycles(int current_vertex, int parent_vertex)
{

    // Se ja for totalmente visitado, voltar pro vertice anterior
    if(visited_vertexes[current_vertex] == 2)
        return;

    // Marcando current_vertex como parcialmente visitado
    this->visited_vertexes[current_vertex] = 1;


    // Percorrer o grafo com um DFS modificado e contar a quantidade de ciclos
    for(auto i = this->adjacent_vertexes[current_vertex].begin(); i != this->adjacent_vertexes[current_vertex].end(); i++)
    {
        if(*i != parent_vertex && this->visited_vertexes[*i] == 1 && this->visited_vertexes[current_vertex] == 1)
        {
            std::cout << "Ligacao " << *i << " a partir de " << current_vertex << "... Parent = " << parent_vertex << "\n";
            this->cycles++;
        }

        else if(*i != parent_vertex)
        {
            std::cout << "Saindo de " << current_vertex << " e indo pra " << *i << "\n";
            count_cycles(*i, current_vertex);

            std::cout << "Voltei pro vértice " << current_vertex << "\n";
        }
    }

    this->visited_vertexes[current_vertex] = 2;

    return;
}


int main(void)
{
    Graph *g = new Graph();

    g->add_edge(1,2);
    g->add_edge(1,3);
    g->add_edge(2,4);
    g->add_edge(3,4);
    g->add_edge(3,2);
    g->add_edge(5,2);
    g->add_edge(6,5);
    g->add_edge(6,2);

/*
    g->add_edge(0,2);
    g->add_edge(0,1);
    g->add_edge(2,3);
    g->add_edge(2,4);
    g->add_edge(3,4);
*/

    g->count_cycles(1, -1);

    std::cout << g->cycles;
}