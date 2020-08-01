#include <iostream>
#include <vector>
#include <queue>
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

int distance(vector<vector<int> > &adj, int s, int t,int n) {
  vector<int> nodeDis(n,-1);
  vector<int> prevN(n,-1);
  nodeDis[s]=0;
  std::queue<int> orderQueue;
  orderQueue.push(s);
  bool isPath=false;
  while(!orderQueue.empty()){
      int u = orderQueue.front();
      orderQueue.pop();
      for(int i=0;i<adj[u].size();i++){
          if(nodeDis[adj[u][i]] == -1){
              if(adj[u][i] == t)
                isPath = true;
              orderQueue.push(adj[u][i]);
              nodeDis[adj[u][i]] = nodeDis[u]+1;
              prevN[adj[u][i]] = u;
          }
      }
  }
  
  int result=0;
  if(isPath == true){
      /*
      while(t!=s){
      result = result+nodeDis[t];
      t=prevN[t];
      }
      */
      result = nodeDis[t];
      return result;
  }
  
  return -1;
}

int max_flow(FlowGraph& graph, int from, int to) {
    int flow = 0;
    /* your code goes here */
    vector<int> parentI;
    //parentI.resize(n);
   for(int i=0;i<graph.edges.size();i++){
       std::cout<<"From:"<<graph.edges[i].from<<" To:"<<graph.edges[i].to<<" Capacity:"<<graph.edges[i].capacity<<" Flow:"<<graph.edges[i].flow<<"\n";
   }
   
   std::cout<<"F T C F done"<<"\n";
   
   for(int i=0;i<graph.graph.size();i++){
       for(int j=0;j<graph.graph[i].size();j++){
           std::cout<<"i:"<<i<<" j:"<<j<<" graph.graph[i][j]:"<<graph.graph[i][j]<<" ";
       }
       std::cout<<"\n";
   }
   
    return flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    FlowGraph graph = read_data();

    std::cout << max_flow(graph, 0, graph.size() - 1) << "\n";
    return 0;
}