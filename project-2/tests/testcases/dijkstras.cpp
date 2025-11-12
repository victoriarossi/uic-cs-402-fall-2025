
#include <functional>
#include <random>

struct Edge {
    int from;
    int to;
    int weight; // default = 1 if unweighted graph
};

struct Node {
    int id;
    int path_cost;
    int pred;
    bool operator> (const Node&) const;
    bool operator>=(const Node&) const;
    bool operator==(const Node&) const;
    bool operator< (const Node&) const;
    bool operator<=(const Node&) const;
    bool operator!=(const Node&) const;
};


std::vector<Node> dijkstras_algorithm(int n, std::vector<Edge> edges, int source);


int main() {
    
    PASS();

    return 0;
}
