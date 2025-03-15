#define BOOST_TEST_MODULE GRAPH_TEST_MODULE
#include <boost/test/included/unit_test.hpp>

#include "../include/graph.hh"

// Test case
BOOST_AUTO_TEST_SUITE(GRAPH_TEST_MODULE_NODE)

BOOST_AUTO_TEST_CASE(test_node_add)
{
    GVI::Graph g;
    BOOST_TEST(g.add_node(1, "i like") == true);
    BOOST_TEST(g.add_node(2, "i don like") == true);

}

BOOST_AUTO_TEST_CASE(test_get_edge) {
    GVI::Graph g;

    g.add_node(1, "A");
    g.add_node(2, "B");
    g.add_node(3, "C");
    g.add_node(4, "D");


    g.get_node(4)->get().add_edge_to(3);
    g.get_node(4)->get().add_edge_to(1);
    g.get_node(3)->get().add_edge_to(1);
    g.get_node(2)->get().add_edge_to(1);
    g.get_node(3)->get().add_edge_to(4);
    std::cout << g.get_node(3)->get().num_edges() << "\n";

}

BOOST_AUTO_TEST_SUITE_END()
