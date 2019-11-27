#ifndef GRAPHBUILDERFROMFILEOUTPUT_HPP
#define GRAPHBUILDERFROMFILEOUTPUT_HPP

#include <vector>

#include "IGraphBuilder.hpp"

namespace graphbuilder {
    using InputMazeData = std::unique_ptr< std::vector<std::vector<int>> >;

    class GraphBuilderFromFileOutput : public IGraphBuilder<InputMazeData> {
        private:
            graphunits::Coordinates m_StartCoordinates;
            OutputGraph m_RootVertex;
            InputMazeData m_Maze;

            bool checkBorders(const unsigned long row, const unsigned long column) const noexcept;
            bool checkCoordinates(const unsigned long row, const unsigned long column) const noexcept;
            void build(OutputGraph &vrtx, const unsigned long &row, const unsigned long &column) noexcept;

        public:
            GraphBuilderFromFileOutput();
            GraphBuilderFromFileOutput(InputMazeData mazeData, const graphunits::Coordinates &startCoordinates);

            virtual ~GraphBuilderFromFileOutput() = default;
            virtual void setMazeData(InputMazeData data, const graphunits::Coordinates startCoordinates) noexcept override;
            virtual OutputGraph buildGraph() override;
    };
}

#endif // GRAPHBUILDERFROMFILEOUTPUT_HPP
