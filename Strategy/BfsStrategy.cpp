#include "BfsStrategy.hpp"
#include "GraphUnits/Vertex.hpp"
#include <queue>
#include <iostream>

using namespace strategy;

BfsStrategy::BfsStrategy() {}

BfsStrategy::BfsStrategy(DataType rootGraphElement)
    : m_RootVertex(std::move(rootGraphElement))
{}

void BfsStrategy::setDataToCalculateStrategy(DataType data) noexcept {
    m_RootVertex = std::move(data);
}

DataType BfsStrategy::useStrategy() {
    DataType result;
    std::queue<DataType> vertices;
    vertices.push(m_RootVertex->shared_from_this());

    while (!vertices.empty()) {
        auto vertex = vertices.front();
        vertices.pop();

        if (vertex->m_IsExit) {
            result = vertex->shared_from_this();
        }

        for (unsigned long i = 0; i < vertex->m_Vertices.size(); ++i) {
            vertices.push(vertex->m_Vertices[i]);
        }
    }

    return result;
}
