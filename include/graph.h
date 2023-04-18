#include <map>

namespace ssuds
{
    template <class N, class E>
    class Graph
    {
    protected:
        std::map<N, std::map<N,E>> the_graph;
    public:
        Graph() {}
        ~Graph() {}
        void add_node(const N& node_val)
        {
            //stuff
        }
        void add_edge(const E& edge_val, const N& start_node, const N& end_node)
        {
            //stuff
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
        
    };
}
