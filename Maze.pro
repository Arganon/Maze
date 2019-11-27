TEMPLATE = app
CONFIG += c++14

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        GraphBuilder/GraphBuilderFromFileOutput.cpp \
        GraphUnits/Vertex.cpp \
        Instruction/InstructionFromBfsStrResult.cpp \
        MazeSource/MazeFromFile.cpp \
        Strategy/BfsStrategy.cpp \
        main.cpp

HEADERS += \
    Aggregator.hpp \
    GraphBuilder/GraphBuilderFromFileOutput.hpp \
    GraphBuilder/IGraphBuilder.hpp \
    GraphUnits/Vertex.hpp \
    Instruction/IGenerateInstruction.hpp \
    Instruction/InstructionFromBfsStrResult.hpp \
    MazeSource/IMazeSource.hpp \
    MazeSource/MazeFromFile.hpp \
    Strategy/BfsStrategy.hpp \
    Strategy/IFindWayStrategy.hpp
