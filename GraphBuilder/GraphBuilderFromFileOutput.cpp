#include "GraphBuilderFromFileOutput.hpp"
#include "GraphUnits/Vertex.hpp"

using namespace graphbuilder;
using namespace graphunits;

GraphBuilderFromFileOutput::GraphBuilderFromFileOutput()
    : m_StartCoordinates{0, 0}
    , m_RootVertex(std::make_shared<graphunits::Vertex>(m_StartCoordinates, nullptr))
    , m_Maze(nullptr) {}

GraphBuilderFromFileOutput::GraphBuilderFromFileOutput(InputMazeData mazeData, const graphunits::Coordinates &startCoordinates)
    : m_StartCoordinates(startCoordinates)
    , m_RootVertex(std::make_shared<graphunits::Vertex>(m_StartCoordinates, nullptr))
    , m_Maze(std::move(mazeData)) {}

bool GraphBuilderFromFileOutput::checkBorders(const unsigned long row, const unsigned long column) const noexcept {

    if ((row >= m_Maze->size()) || (column >= m_Maze->at(row).size())) {
        return false;
    }
    return true;
}

bool GraphBuilderFromFileOutput::checkCoordinates(const unsigned long row, const unsigned long column) const noexcept {

    if (!checkBorders(row, column)) {
        return false;
    }
    return (m_Maze->at(row).at(column) == 0);
}

void GraphBuilderFromFileOutput::build(OutputGraph &vrtx, const unsigned long &row, const unsigned long &column) noexcept {
    if (vrtx->m_Parent != nullptr && (row == 0 || row == m_Maze->size()-1 || column == 0 || column == m_Maze->at(row).size()-1 )) {
        vrtx->m_IsExit = true;
    }
    else {
        m_Maze->at(row).at(column) = 1;

        if (checkCoordinates(row - 1, column)) {
            vrtx->m_Vertices.push_back(std::make_shared<graphunits::Vertex>(Coordinates{row - 1, column}, vrtx->shared_from_this()));
            build(vrtx->m_Vertices.back(), row - 1, column);
        }

        if (checkCoordinates(row + 1, column)) {
            vrtx->m_Vertices.push_back(std::make_shared<graphunits::Vertex>(Coordinates{row + 1, column}, vrtx->shared_from_this()));
            build(vrtx->m_Vertices.back(), row + 1, column);
        }

        if (checkCoordinates(row, column - 1)) {
            vrtx->m_Vertices.push_back(std::make_shared<graphunits::Vertex>(Coordinates{row, column - 1}, vrtx->shared_from_this()));
            build(vrtx->m_Vertices.back(), row, column - 1);
        }

        if (checkCoordinates(row, column + 1)) {
            vrtx->m_Vertices.push_back(std::make_shared<graphunits::Vertex>(Coordinates{row, column + 1}, vrtx->shared_from_this()));
            build(vrtx->m_Vertices.back(), row, column + 1);
        }
    }
}

void GraphBuilderFromFileOutput::setMazeData(InputMazeData data, const graphunits::Coordinates startCoordinates) noexcept {
    m_Maze = std::move(data);
    m_StartCoordinates = startCoordinates;
    m_RootVertex = std::make_shared<graphunits::Vertex>(m_StartCoordinates, nullptr);
}

OutputGraph GraphBuilderFromFileOutput::buildGraph() {
    build(m_RootVertex, m_StartCoordinates.m_Row, m_StartCoordinates.m_Column);
    return m_RootVertex;
}
