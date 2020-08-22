#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;

/* This class implements a bit unusual scheme for storing edges of the graph,
 * in order to retrieve the backward edge for a given edge quickly. */
class FlowGraph {
public:
    struct Edge {
        int from, to, capacity, flow;
    };

    /* List of all - forward and backward - edges */
    vector<Edge> edges;

    /* These adjacency lists store only indices of edges in the edges list */
    vector<vector<size_t> > graph;

public:
    explicit FlowGraph(size_t n): graph(n) {}

    void add_edge(int from, int to, int capacity) {
        /* Note that we first append a forward edge and then a backward edge,
         * so all forward edges are stored at even indices (starting from 0),
         * whereas backward edges are stored at odd indices in the list edges */
        Edge forward_edge = {from, to, capacity, 0};
        Edge backward_edge = {to, from, 0, 0};
        graph[from].push_back(edges.size());
        edges.push_back(forward_edge);
        graph[to].push_back(edges.size());
        edges.push_back(backward_edge);
    }

    size_t size() const {
        return graph.size();
    }

    const vector<size_t>& get_ids(int from) const {
        return graph[from];
    }

    const Edge& get_edge(size_t id) const {
        return edges[id];
    }

    void add_flow(size_t id, int flow) {
        /* To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
         * due to the described above scheme. On the other hand, when we have to get a "backward"
         * edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
         * should be taken.
         *
         * It turns out that id ^ 1 works for both cases. Think this through! */
        edges[id].flow += flow;
        edges[id ^ 1].flow -= flow;
    }
};

FlowGraph read_data() {
    int vertex_count, edge_count;
    std::cin >> vertex_count >> edge_count;
    FlowGraph graph(vertex_count);
    for (int i = 0; i < edge_count; ++i) {
        int u, v, capacity;
        std::cin >> u >> v >> capacity;
        graph.add_edge(u - 1, v - 1, capacity);
    }
    return graph;
}

void BFS(const FlowGraph &graph,int s,int t,vector<int> &pre){
    std::queue<int> recordQ;
    recordQ.push(s);
    
    std::fill(pre.begin(),pre.end(),-1);
    
    while(!recordQ.empty()){
        int u = recordQ.front();
        recordQ.pop();
        
        for(auto id:graph.get_ids(u)){
            const FlowGraph::Edge& e = graph.get_edge(id);
            if(pre[e.to] == -1 && e.capacity>e.flow && e.to!=s){
                pre[e.to] = id;
                recordQ.push(e.to);
            }   
        }
    }
}

int max_flow(FlowGraph& graph, int from, int to) {
   int flow = 0;
   vector<int> pre(graph.size());
   
   do{
       BFS(graph,from,to,pre);
       if(pre[to] != -1){
           int min_flow = std::numeric_limits<int>::max();
           for(int u=pre[to]; u!= -1; u=pre[graph.get_edge(u).from]){
               min_flow = std::min(min_flow,graph.get_edge(u).capacity-graph.get_edge(u).flow);
           }
           for(int u=pre[to];u!=-1;u=pre[graph.get_edge(u).from]){
                graph.add_flow(u,min_flow);
            }
            flow+=min_flow;   
           }
   }
   while(pre[to]!=-1);

    return flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    FlowGraph graph = read_data();

    std::cout << max_flow(graph, 0, graph.size() - 1) << "\n";
    return 0;
}