// Rafael Amauri Diniz Augusto --- 651047

#include <vector>
#include <map>
#include <limits>


class Graph
{
    public:
        // vertex // visited -------- 0 = not visited ... 1 = partially visited ... 2 = visited
        std::map<int, short> visited_vertexes;
        // vertex 1 // connected_vertex // weight
        std::map<int, std::vector<std::map<int, int>>> adjacent_vertexes;
        // vertex 1 // connected_vertex // weight
        std::map<int, std::vector<std::map<int, int>>> priority_queue;

        // number of edges in the graph
        short num_edges = 0;

        void add_edge(int vertex1, int vertex2, int weight);

        /////// 
        // Functions exclusive to Prim's algorithm
        ///////
        void add_edge_priority_queue(int vertex1, int vertex2, int weight);
        void prim_count_cycles(int current_vertex, Graph *mst, int c);
        int mst_add_lowest_edge(Graph *mst);
};


int Graph::mst_add_lowest_edge(Graph *mst)
{
    int lowest_edge_v1;
    int lowest_edge_v2;
    int lowest_edge_value = std::numeric_limits<int>::max();

    std::cout << "Peso inicial = " << lowest_edge_value << "\n";

    std::cout << "Essa é a PQ:\n";
    for(auto i : this->priority_queue)
        for(auto j : i.second)
            for(auto k: j)
            {
                std::cout << i.first << " <---" << k.second << "---> " << k.first << "\n";
            }
    std::cout << "Acabou a PQ\n";

    for(auto i : this->priority_queue)
        for(auto j : i.second)
            for(auto k: j)
            {
                // Skip already visited vertexes
                if(this->visited_vertexes[k.first] == 2)
                {
                    continue;
                }
                // finding lowest value of all edges in the PQ
                if(k.second < lowest_edge_value)
                {
                    std::cout << k.second << " eh menor que " << lowest_edge_value << "\n";
                    lowest_edge_v1    =  i.first;
                    lowest_edge_v2    =  k.first;
                    lowest_edge_value =  k.second;
                }
            }

    std::cout << "Selecionei " << lowest_edge_v1 << " com " << lowest_edge_v2 << "\n";
    mst->add_edge(lowest_edge_v1, lowest_edge_v2, lowest_edge_value);

    // Removing added edge from PQ
    for(int i = 0; i < priority_queue.find(lowest_edge_v1)->second.size(); i++)
        if(priority_queue.find(lowest_edge_v1)->second.at(i).find(lowest_edge_v2)->first == lowest_edge_v2)
            priority_queue.find(lowest_edge_v1)->second.at(i).erase(lowest_edge_v2);


    return lowest_edge_v2;
}


// Adds an edge to the priority queue (used only in Prim's algorithm) 
void Graph::add_edge_priority_queue(int vertex1, int vertex2, int weight)
{
    std::map<int, int> temp;
    
    temp = {{vertex2, weight}}; 
    this->priority_queue[vertex1].push_back(temp);
}


// Adds an edge to the graph
void Graph::add_edge(int vertex1, int vertex2, int weight)
{
    // temporary map to be inserted onto the list
    std::map<int, int> temp;
    
    temp = {{vertex2, weight}}; 
    this->adjacent_vertexes[vertex1].push_back(temp);

    temp = {{vertex1, weight}};
    this->adjacent_vertexes[vertex2].push_back(temp);

    num_edges++;
}


// Counts cycles using Prim's algorithm
void Graph::prim_count_cycles(int current_vertex, Graph *mst, int c)
{
    if(c == 5)
        return;

    this->visited_vertexes[current_vertex] = 1;

    // Add vertexes adjacent to <current vertex> to the PQ
    for(auto i : adjacent_vertexes[current_vertex])
        for(auto j : i)
        {
            // Skipping visited vertexes so they don't get added to the PQ
            if(this->visited_vertexes[j.first] != 2)
            {
                this->visited_vertexes[j.first] = 1;
                add_edge_priority_queue(current_vertex, j.first, j.second);
            }
        }
    

    if(mst->adjacent_vertexes.size() != this->adjacent_vertexes.size())
    {
        this->visited_vertexes[current_vertex] = 2;
        int selected_destination_vertex = mst_add_lowest_edge(mst);
        std::cout << "entrando no " << selected_destination_vertex << "\n";
        this->prim_count_cycles(selected_destination_vertex, mst, c+1);
    }

    return ;
}
