#include <gtest/gtest.h> 
#include "graph.h"

#define GRAPH_TEST 1

#if GRAPH_TEST

class GraphTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_graph.add_node("A");
        test_graph.add_node("B");
        test_graph.add_node("C");
        test_graph.add_edge(2.1f, "A", "B");
        test_graph.add_edge(3.3f, "A", "C");
        test_graph.add_edge(5.8f, "B", "C");
    }

    ssuds::Graph<std::string,float> test_graph;
};

TEST_F(GraphTestFixture, Create1)
{
    ssuds::Graph<float,unsigned int> test_graph_local;
}

TEST_F(GraphTestFixture, AddNode1)
{
    ssuds::Graph<float,unsigned int> test_graph_local;
    test_graph_local.add_node(1.1f);
}

TEST_F(GraphTestFixture, AddEdge1)
{
    ssuds::Graph<std::string,float> test_graph_local;
    test_graph_local.add_node("A");
    test_graph_local.add_node("B");
    test_graph_local.add_edge(2.1f, "A", "B");
}

TEST_F(GraphTestFixture, HasNode1)
{
    EXPECT_TRUE(test_graph.has_node("A"));
    EXPECT_FALSE(test_graph.has_node("Z"));
}

TEST_F(GraphTestFixture, HasEdge1)
{
    // Connection from A to C exists.
    EXPECT_TRUE(test_graph.has_edge("A", "C"));

    // Connection from C to A does not exist.
    EXPECT_FALSE(test_graph.has_edge("C", "A"));

    // Z does not exist, so connection can't exist.
    EXPECT_FALSE(test_graph.has_edge("Z", "A"));
}

TEST_F(GraphTestFixture, RemoveEdge1)
{
    test_graph.remove_edge("A", "C");
    EXPECT_FALSE(test_graph.has_edge("A", "C"));
}

TEST_F(GraphTestFixture, RemoveNode1)
{
    test_graph.remove_node("A");
    EXPECT_FALSE(test_graph.has_node("A"));
}

TEST_F(GraphTestFixture, RemoveNode2)
{
    test_graph.remove_node("C");
    EXPECT_FALSE(test_graph.has_node("C"));
    EXPECT_FALSE(test_graph.has_edge("A", "C"));
    EXPECT_FALSE(test_graph.has_edge("B", "C"));
}

TEST_F(GraphTestFixture, OStream1)
{
    std::cout << test_graph;
}

TEST_F(GraphTestFixture, OStream2)
{
    test_graph.remove_edge("A", "C");
    std::cout << test_graph;
}

TEST_F(GraphTestFixture, OStream3)
{
    test_graph.remove_node("C");
    std::cout << test_graph;
}

#endif