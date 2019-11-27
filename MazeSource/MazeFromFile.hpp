#ifndef MAZEFROMFILE_HPP
#define MAZEFROMFILE_HPP

#include <memory>
#include <string>
#include <vector>

#include "IMazeSource.hpp"
#include "GraphUnits/Vertex.hpp"

namespace mazesource {
    class MazeFromFile : public IMazeSource
    {
        private:
            std::string m_PathToFile;
            graphunits::Coordinates m_StartCoordinates;
        public:
            MazeFromFile();
            MazeFromFile(const std::string &pathToFile, const graphunits::Coordinates &startCoordinates);

            virtual ~MazeFromFile() = default;
            virtual SourceType getMaze() override;
            virtual graphunits::Coordinates getStartCoordinates() const noexcept override;
    };
}

#endif // MAZEFROMFILE1_HPP
