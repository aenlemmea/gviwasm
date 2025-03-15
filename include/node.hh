#ifndef GVI_NODE_HH
#define GVI_NODE_HH

#include <string>
#include <map>
#include <optional>

#include "edge.hh"

namespace GVI {
    namespace NODE::IMPL {

        enum class color: int32_t {
            RED,
            GREEN,
            BLUE,
            YELLOW
        };


        template<typename T = std::string>
        struct node final {
        public:

            node(int32_t _id, std::string name) : index(_id), name(name) {}


            int32_t num_edges() {
                return neighbours.size();
            }

            std::optional<EDGE::edge> get_edge(int32_t sib) {
                if (neighbours.find(sib) != neighbours.end()) {
                    return neighbours[sib];
                }
                return std::nullopt;
            }

            bool remove_edge(int32_t sib) {
                if (neighbours.find(sib) != neighbours.end()) {
                    neighbours.erase(sib);
                    return true;
                } else return false;
            }

            bool add_edge_to(int32_t sib, float weight = 1.0F) {
                neighbours.emplace(sib, EDGE::edge(sib, index, weight));
                return true;
            }

            int32_t index;
            std::string name;
            color col;
            std::map<int32_t, EDGE::edge> neighbours;
        };
    }

    namespace NODE {
        using namespace NODE::IMPL;
    }
}

#endif
