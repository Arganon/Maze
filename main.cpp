#include <iostream>
#include <vector>
#include <string>

#include "MazeSource/MazeFromFile.hpp"
#include "GraphUnits/Vertex.hpp"
#include "Strategy/BfsStrategy.hpp"
#include "GraphBuilder/GraphBuilderFromFileOutput.hpp"
#include "Instruction/InstructionFromBfsStrResult.hpp"

#include "Aggregator.hpp"

using namespace std;
using namespace graphunits;
using namespace mazesource;
using namespace graphbuilder;

using InputMazeData = std::unique_ptr< std::vector<std::vector<int>> >;
using ShPtrVertexData = std::shared_ptr<graphunits::Vertex>;

int main()
{
    std::string pathToMazeFile = "<Path_to_maze>/maze.txt";
    std::string pathToSaveInstruction = "<Path_to_save_instruction>/";
    graphunits::Coordinates startCoordinates {1, 0};

    {
        Aggregator<InputMazeData, ShPtrVertexData> aggregator
                (
                    std::make_unique<mazesource::MazeFromFile>(pathToMazeFile, startCoordinates),
                    std::make_unique<graphbuilder::GraphBuilderFromFileOutput>(),
                    std::make_unique<strategy::BfsStrategy>(),
                    std::make_unique<instruction::InstructionFromBfsStrResult>(),
                    pathToSaveInstruction
                );

        aggregator.start();
    }

    return 0;
}
