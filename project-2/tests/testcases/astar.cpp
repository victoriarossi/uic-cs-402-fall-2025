
#include <functional>
#include <random>

struct GridNode {
    int x;
    int y;
    double path_cost;
    int pred_x;
    int pred_y;
    bool operator> (const GridNode&) const;
    bool operator>=(const GridNode&) const;
    bool operator==(const GridNode&) const;
    bool operator< (const GridNode&) const;
    bool operator<=(const GridNode&) const;
    bool operator!=(const GridNode&) const;
};

inline bool GridNode::operator> (const GridNode& node) const { return path_cost > node.path_cost; }
inline bool GridNode::operator>=(const GridNode& node) const { return path_cost >= node.path_cost; }
inline bool GridNode::operator==(const GridNode& node) const { return path_cost == node.path_cost; }
inline bool GridNode::operator< (const GridNode& node) const { return path_cost < node.path_cost; }
inline bool GridNode::operator<=(const GridNode& node) const { return path_cost <= node.path_cost; }
inline bool GridNode::operator!=(const GridNode& node) const { return path_cost != node.path_cost; }

struct GridEdge {
    int from_x;
    int from_y;
    int to_x;
    int to_y;
};

std::vector<unsigned int> a_star_algorithm(int m, 
    int n, 
    std::vector<GridEdge> edges, 
    GridNode source, 
    GridNode target,
    std::function<double(GridNode,GridNode)> h
);


int main() {
    
    PASS();

    return 0;
}
