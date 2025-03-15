#ifndef GVI_EDGE_HH
#define GVI_EDGE_HH

#include <stdint.h>
#include <ostream>

namespace GVI {

    namespace EDGE::IMPL {
        struct edge {
            explicit edge(int32_t to, int32_t from, float weight) : to_id(to), from_id(from), weight(weight) {}

            int32_t to_id;
            int32_t from_id;
            float weight;

            friend std::ostream& operator<<(std::ostream& os, const edge& edg) {
                os << "FROM: " << edg.from_id << " TO: " << edg.to_id << "\n";
                return os;
            }

            bool set_directed() {
                return directed = true;
            }

        private:
            bool directed;
        };
    }

    namespace EDGE {
        using namespace EDGE::IMPL;
    }
}

#endif
