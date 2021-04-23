#include <iostream>
#include <list>
#include <map>


class Graph
{
    public:
        std::map<int, bool> visitados;
        std::map<int, std::list<int>> adjacentes;

        bool is_found = false;

        void add_edge(int vertex1, int vertex2);
        void search(int root, int value);
};


void Graph::add_edge(int vertex1, int vertex2)
{
    this->adjacentes[vertex1].push_back(vertex2);
}


void Graph::search(int current_vertex, int value)
{
    for(auto i = adjacentes[current_vertex].begin(); i != adjacentes[current_vertex].end(); i++)
    {
        std::cout << current_vertex << "->" << *i << "\n";

        if(*i == value)
        {
            std::cout << "Achado: " << value << std::endl;
            this->is_found = true;
        }
    }
    
    for(auto i = adjacentes[current_vertex].begin(); i != adjacentes[current_vertex].end() && !is_found; i++)
        search(*i, value);
    
    return;
}


int main(void)
{
    Graph *g = new Graph();
    
    g->add_edge(0,1);
    g->add_edge(0,2);
    g->add_edge(2,4);
    g->add_edge(4,1);
    g->add_edge(4,6);
    g->add_edge(4,5);
    g->add_edge(6,7);
    g->add_edge(7,8);
    g->add_edge(8,9);

    g->search(0, 9);
}