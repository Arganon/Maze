#include "InstructionFromBfsStrResult.hpp"
#include <iostream>
#include <memory>
#include "GraphUnits/Vertex.hpp"

using namespace instruction;
using namespace graphunits;

InstructionFromBfsStrResult::InstructionFromBfsStrResult() {}

InstructionFromBfsStrResult::InstructionFromBfsStrResult(std::shared_ptr<graphunits::Vertex> vertex)
    : m_Vertex(vertex) {}

void InstructionFromBfsStrResult::addEscapeStepsToInstruction(std::string key) noexcept {

    if (m_InstructionFiller.find(key) == m_InstructionFiller.end() && !m_InstructionFiller.empty()) {
        std::string value = std::to_string(m_InstructionFiller.begin()->second) + " " + m_InstructionFiller.begin()->first;
        m_Instruction.push_front(value);
        m_InstructionFiller.clear();
        m_InstructionFiller[key] = 1;

    } else {
        m_InstructionFiller[key] += 1;

    }
}

void InstructionFromBfsStrResult::getDirection(const Coordinates &current, const Coordinates &parent) noexcept {
    int y = current.m_Row - parent.m_Row;
    int x = current.m_Column - parent.m_Column;

    if (y == 1 && x == 0) {
        addEscapeStepsToInstruction("step down");

    } else if (y == -1 && x == 0) {
        addEscapeStepsToInstruction("step top");

    } else if (y == 0 && x == -1) {
        addEscapeStepsToInstruction("step left");

    } else if (y == 0 && x == 1) {
        addEscapeStepsToInstruction("step right");

    }
}

void InstructionFromBfsStrResult::setDataToMakeInstruction(const std::shared_ptr<graphunits::Vertex> data) noexcept {
    m_Vertex = data->shared_from_this();
}

std::list<std::string> InstructionFromBfsStrResult::getInstruction() noexcept {
    if (!m_Vertex) {
        m_Instruction.push_front("We are stuck. There is no exit.");
        return m_Instruction;
    }

    auto parent = m_Vertex->shared_from_this();

    while (parent->m_Parent) {
        getDirection(parent->m_Coordinates, parent->m_Parent->m_Coordinates);
        parent = parent->m_Parent;
    }

    addEscapeStepsToInstruction("All people loves kitties");
    return m_Instruction;
}
