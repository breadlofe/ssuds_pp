#include <map>

namespace ssuds
{
    template <class N, class E>
    class Graph
    {
    protected:
        /// @brief Graph consisting of a value node (N_1), and a possible neighbor (std::map<N,E>).
        std::map<N, std::map<N,E>> the_graph;

    public:
        /// @brief Default constructor for Graph so C++ doesn't kill me.
        Graph() {}

        /// @brief Default destructor for Graph so C++ doesn't kill me.
        ~Graph() {}

        /// @brief Adds a value, or "node", to the Graph.
        /// @param node_val Value that is desired to be searched for or added.
        void add_node(const N& node_val)
        {
            the_graph[node_val];
        }

        /// @brief Adds edge to the map that tracks what it is connected to.
        /// @param edge_val Value of the connection between the two nodes.
        /// @param start_node Beginning node that will go to neighbor.
        /// @param end_node Node that is connected to starting node.
        void add_edge(const E& edge_val, const N& start_node, const N& end_node)
        {
            /// start_node = N, end_node = N_2, edge_val = E.
            the_graph[start_node][end_node] = edge_val;
            /// Looks like (with A = N_1, B = N_2, and 1.2 = E):
            /// (A) ----> (B)
            ///      1.2
        }

        void remove_node(const N& node_val)
        {
            //stuff
        }
        void remove_edge(const N& start_node, const N& end_node)
        {
            //stuff
        }
        bool has_edge(const N& start_node, const N& end_node)
        {
            //stuff
        }
        friend std::ostream& operator<<(std::ostream& os, const Graph& g)
        {
            //stuff
        }
    };
}
