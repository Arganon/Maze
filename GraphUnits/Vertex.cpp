#include "Vertex.hpp"

using namespace graphunits;

Vertex::Vertex(const Coordinates &coordinates, const std::shared_ptr<Vertex> &parent)
    : m_Coordinates(std::move(coordinates))
    , m_IsExit(false)
    , m_Parent(std::move(parent)) {}
