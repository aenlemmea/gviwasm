#ifndef GVI_GRAPH_HH
#define GVI_GRAPH_HH

#include <vector>
#include <ostream>
#include "node.hh"

namespace GVI {

    enum class Kind {
        DIRECTED,
        UNDIRECTED,
        MIXED,
        ILLEGAL
    };

    class Graph final {
    public:
        Kind kind = Kind::UNDIRECTED;

        friend std::ostream& operator<<(std::ostream& os, const Graph& gr) {
            for (auto& node : gr.nodes) {
                os << node.name << " ";
                os << "\t";
                for (auto& e : node.neighbours) {
                    os << e.second << "\n";
                }
                os << "\n";
            }
            return os;
        }

        bool add_node(int32_t id, const std::string& name) {
            nodes.emplace_back(id, name);
            return true;
        }

        std::optional<std::reference_wrapper<NODE::node<std::string>>> get_node(int32_t who) {
            for (auto& node : nodes) {
                if (node.index == who) {
                    return node;
                }
            }
            return std::nullopt;
        }

    private:
        std::vector<NODE::node<std::string>> nodes;
    };
}
#endif
