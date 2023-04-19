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

        /// @brief Deletes whole node, including the connections between other nodes.
        /// @param node_val Desired node to be deleted.
        void remove_node(const N& node_val)
        {
            // Case 1: removal of node and connections to all the nodes it goes to.
            auto it = the_graph.find(node_val);
            if(it != the_graph.end())
                it = the_graph.erase(it);

            // Case 2: removal of connection between other nodes to removed node.
            it = the_graph.begin();
            while(it != the_graph.end())
            {
                auto inner_it = it->second.find(node_val);
                if(inner_it != it->second.end())
                    inner_it = it->second.erase(inner_it);
                ++it;
            }
        }

        /// @brief Removes connection between two nodes.
        /// @param start_node Node that is connecting to (-->) the end_node.
        /// @param end_node Edge node that is taking in the connection.
        void remove_edge(const N& start_node, const N& end_node)
        {
            auto it = the_graph.find(start_node);
            if(it != the_graph.end())
            {
                auto inner_it = it->second.find(end_node);
                if(inner_it != it->second.end())
                    inner_it = it->second.erase(inner_it);
            }
        }

        /// @brief Checks to see if there is a connection between two nodes.
        /// @param start_node Node that is connection to end node.
        /// @param end_node Node that is receiving connection.
        /// @return True if there is a connection between nodes, false if not.
        bool has_edge(const N& start_node, const N& end_node)
        {
            auto it = the_graph.find(start_node);
            if(it != the_graph.end())
            {
                auto inner_it = it->second.find(end_node);
                if(inner_it != it->second.end())
                    return true;
                else
                    return false;
            }
            else
                return false;
        }

        /// @brief Finds if node exists in graph.
        /// @param node_val Given node to be searched for.
        /// @return Returns true if graph has node, false if not.
        bool has_node(const N& node_val)
        {
            auto it = the_graph.find(node_val);
            if(it != the_graph.end())
                return true;
            else
                return false;
        }

        friend std::ostream& operator<<(std::ostream& os, const Graph& g)
        {
            auto it = g.the_graph.begin();
            while(it != g.the_graph.end())
            {
                os << it->first << " || ";
                auto inner_it = it->second.begin();
                while(inner_it != it->second.end())
                {
                    os << "(" << inner_it->first << ": " << inner_it->second << ") ";
                    ++inner_it;
                }
                os << std::endl;
                ++it;
            }
        }
    };
}
