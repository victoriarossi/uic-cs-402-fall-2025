
#include <functional>
#include <random>

using namespace std;

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


vector<Node> dijkstras_algorithm(int n, vector<Edge> edges, int source);

bool verifyPath(const vector<Node>& result, int node_id, int expected_cost, int expected_pred) {
    if (result[node_id].id != node_id) return false;
    if (result[node_id].path_cost != expected_cost) {
        return false;
    }
    if (result[node_id].pred != expected_pred) {
        return false;
    }
    return true;
}

double test_simple(){
    // Test 1: Simple graph
    /*
        0 -> 1 (weight 1)
        1 -> 2 (weight 2)
        0 -> 2 (weight 4)
    */
    vector<Edge> test1 = {Edge{0,1,1}, Edge{1,2,2}, Edge{0,2,4}};
    vector<Node> res1 = dijkstras_algorithm(3, test1,0);
    vector<Node> ans1 = {Node{0,0,-1}, Node{1,1,0}, Node{2,3,1}};

    if(res1.size() == ans1.size()) {
        bool correct = true;
        for(size_t i = 0; i < res1.size(); i++) {
            if(res1[i].id != ans1[i].id || res1[i].path_cost != ans1[i].path_cost || res1[i].pred != ans1[i].pred) {
                correct = false;
                break;
            }
        }
        if(correct) return 2.0;
    }

    return 0.0;
}

double test_disconnected(){
    /*
        0 -> 1 (weight 1)
        2 is disconnected
        1 -> 3 (weight 2)
    */
    vector<Edge> test2 = {Edge{0,1,1}, Edge{1,3,2}};
    vector<Node> res2 = dijkstras_algorithm(4, test2,0);
    vector<Node> ans2 = {Node{0,0,-1}, Node{1,1,0}};

    verifyPath(ans2, 0, 0, -1);
    verifyPath(ans2, 1, 1, 0);
    verifyPath(ans2, 3, 3, 1);

    if (res2[2].path_cost > 1000000){
        // Effectively infinite
        return 3.0;
    }

    return 0.0;
}

double test_multiple_paths(){
    //     1 ---(2)---> 3
    //    / |           ^
    //  (1) |           |
    //  /   (4)        (1)
    // 0    |           |
    //  \   v           |
    //  (5) 2 -------->/
    // 

    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 5},
        {1, 2, 4},
        {1, 3, 2},
        {2, 3, 1}
    };
    
    vector<Node> result = dijkstras_algorithm(4, edges, 0);
    
    if (verifyPath(result, 0, 0, -1) &&
        verifyPath(result, 1, 1, 0) &&
        verifyPath(result, 2, 5, 0) &&  // Direct path is optimal
        verifyPath(result, 3, 3, 1))  // Via node 1, not via node 2
    {
        return 3.0;
    }
    
    return 0.0;
}

double test_single_node(){
    // Test 4: Single node graph
    vector<Edge> test4 = {};
    vector<Node> res4 = dijkstras_algorithm(1, test4,0);
    vector<Node> ans4 = {Node{0,0,-1}};

    if (verifyPath(res4, 0, 0, -1)) {
        return 3.0;
    }

    return 0.0;
}

double test_dense_graph(){
    //   0 ---(1)---> 1 <-
    //   |  \       / ^   \
    //  (4)  (2)  (3) |   | 
    //   |    \ /     (6) |
    //   v     \      |   (7)
    //   3 <-(5)- 2 --/   |  
    //   \________________|
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 2},
        {0, 3, 4},
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 6},
        {2, 3, 5},
        {3, 1, 7}
    };

    vector<Node> result = dijkstras_algorithm(4, edges, 0);
    if (verifyPath(result, 0, 0, -1) &&
        verifyPath(result, 1, 1, 0) &&
        verifyPath(result, 2, 2, 0) &&
        verifyPath(result, 3, 3, 1))
    {
        return 3.0;
    }
    return 0.0;
}

double test_zero_weight_edges(){
    // Graph with zero-weight edges
    // 0 --(0)--> 1 --(5)--> 2
    vector<Edge> edges = {
        {0, 1, 0},
        {1, 2, 5}
    };

    vector<Node> result = dijkstras_algorithm(3, edges, 0);
    if (verifyPath(result, 0, 0, -1) &&
        verifyPath(result, 1, 0, 0) &&
        verifyPath(result, 2, 5, 1))
    {
        return 3.0;
    }
    return 0.0;
}

double test_longest_path_cheapest(){
    // (0) --1--> (1) --1--> (2) --1--> (3)
    //  \                             ^
    //   \-----------5---------------/
    vector<Edge> edges = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 1},
        {0, 3, 5}
    };

    vector<Node> result = dijkstras_algorithm(4, edges, 0);
    if (verifyPath(result, 0, 0, -1) &&
        verifyPath(result, 1, 1, 0) &&
        verifyPath(result, 2, 2, 1) &&
        verifyPath(result, 3, 3, 2))
    {
        return 3.0;
    }
    return 0.0;
}

int main() {
    double total_score = 20.0;
    double score = 0.0;

    // Test 1: Simple graph
    score += test_simple();
    // if (score >= 2.0) {
    //     printf("Passed Test 1\n");
    // }

    // Test 2: Disconnected graph
    score += test_disconnected();
    // if (score >= 4.0) {
    //     printf("Passed Test 2\n");
    // }

    // Test 3: Multiple paths
    score += test_multiple_paths();
    // if (score >= 6.0) {
    //     printf("Passed Test 3\n");
    // }

    // Test 4: Single node graph
    score += test_single_node();
    // if (score >= 8.0) {
    //     printf("Passed Test 4\n");
    // }

    // Test 5: Dense graph
    score += test_dense_graph();
    // if (score >= 10.0) {
    //     printf("Passed Test 5\n");
    // }

    // Test 6: Zero-weight edges
    score += test_zero_weight_edges();
    // if (score >= 12.0) {
    //     printf("Passed Test 6\n");
    // }

    // Test 7: Longest path is cheapest
    score += test_longest_path_cheapest();
    // if (score >= 14.0) {
    //     printf("Passed Test 7\n");
    // }

    // printf("Final Score: %f out of %f\n", score, total_score);

    // printf("%f", 100*(score / total_score));

    RESULT(100*(score / total_score));

    return 0;
}
