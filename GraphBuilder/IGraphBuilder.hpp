#ifndef IGRAPHBUILDER_H
#define IGRAPHBUILDER_H

#include <GraphUnits/Vertex.hpp>

namespace graphbuilder {
    using OutputGraph = std::shared_ptr<graphunits::Vertex>;

    template <typename InputMazeData>
    class IGraphBuilder
    {
        public:
            virtual void setMazeData(InputMazeData data, const graphunits::Coordinates startCoordinates) noexcept = 0;
            virtual OutputGraph buildGraph() = 0;
    };
}

#endif // IGRAPHBUILDER_H
