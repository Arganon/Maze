#include "MazeFromFile.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace mazesource;

MazeFromFile::MazeFromFile() {}

MazeFromFile::MazeFromFile(const std::string &pathToFile, const graphunits::Coordinates &startCoordinates)
    : m_PathToFile(pathToFile)
    , m_StartCoordinates(startCoordinates) {}

SourceType MazeFromFile::getMaze() {
    std::ifstream file(m_PathToFile);
    std::vector<std::vector<int>> maze;

    if (!file.is_open()) {
        return std::make_unique< std::vector<std::vector<int>> >(std::move(maze));
    }

    std::string line;
    unsigned long i = 0;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        maze.emplace_back(int());
        for (unsigned long j = 0; j < line.size(); ++j) {
            maze[i].push_back(line[j] - '0');
        }
        ++i;
    }

    file.close();

    return std::make_unique< std::vector<std::vector<int>> >(std::move(maze));
}

graphunits::Coordinates MazeFromFile::getStartCoordinates() const noexcept {
    return m_StartCoordinates;
}
