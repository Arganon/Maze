#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <memory>
#include <vector>

namespace graphunits {
    struct Coordinates {
        unsigned long m_Row;
        unsigned long m_Column;
    };

    struct Vertex : public std::enable_shared_from_this<Vertex> {
        Vertex(const Coordinates &coordinates, const std::shared_ptr<Vertex> &parent);

        Coordinates m_Coordinates;
        bool m_IsExit;
        std::shared_ptr<Vertex> m_Parent;
        std::vector<std::shared_ptr<Vertex>> m_Vertices;
    };
}

#endif // VERTEX_HPP
