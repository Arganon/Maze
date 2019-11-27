#ifndef AGGREGATOR_HPP
#define AGGREGATOR_HPP

#include <iostream>
#include <fstream>

#include "MazeSource/IMazeSource.hpp"
#include "GraphBuilder/IGraphBuilder.hpp"
#include "Strategy/IFindWayStrategy.hpp"
#include "Instruction/IGenerateInstruction.hpp"

template <typename InputMazeDataForBuilder, typename VertexData>
class Aggregator {
    private:
        std::unique_ptr<mazesource::IMazeSource> m_MazeSource;
        std::unique_ptr<graphbuilder::IGraphBuilder<InputMazeDataForBuilder>> m_GraphBuilder;
        std::unique_ptr<strategy::IFindWayStrategy<VertexData>> m_Strategy;
        std::unique_ptr<instruction::IGenerateInstruction<VertexData>> m_InstructionToExit;
        std::string m_PathToSaveInstruction;

    public:
        Aggregator(std::unique_ptr<mazesource::IMazeSource> mazeSource,
                   std::unique_ptr<graphbuilder::IGraphBuilder<InputMazeDataForBuilder>> graphBuilder,
                   std::unique_ptr<strategy::IFindWayStrategy<VertexData>> strategy,
                   std::unique_ptr<instruction::IGenerateInstruction<VertexData>> instructionToExit,
                   std::string pathToSaveInstruction)

            : m_MazeSource(std::move(mazeSource))
            , m_GraphBuilder(std::move(graphBuilder))
            , m_Strategy(std::move(strategy))
            , m_InstructionToExit(std::move(instructionToExit))
            , m_PathToSaveInstruction(std::move(pathToSaveInstruction)) {}

        void start() {
                auto maze = m_MazeSource->getMaze();

                m_GraphBuilder->setMazeData(std::move(maze), m_MazeSource->getStartCoordinates());
                auto graph = m_GraphBuilder->buildGraph();

                m_Strategy->setDataToCalculateStrategy(graph);
                auto result = m_Strategy->useStrategy();

                m_InstructionToExit->setDataToMakeInstruction(result);
                std::list<std::string> mazeInst = m_InstructionToExit->getInstruction();

                std::ofstream outfile(m_PathToSaveInstruction + "Instruction.txt");

                for (auto e : mazeInst) {
                    outfile << e << std::endl;
                }

                outfile.close();
        }
};

#endif // AGGREGATOR_HPP
