#ifndef INSTRUCTIONFROMBFSSTRRESULT_HPP
#define INSTRUCTIONFROMBFSSTRRESULT_HPP

#include <list>
#include <map>

#include "IGenerateInstruction.hpp"

namespace graphunits {
    struct Coordinates;
    struct Vertex;
}

namespace instruction {
    class InstructionFromBfsStrResult : public IGenerateInstruction<std::shared_ptr<graphunits::Vertex> > {
        private:
            std::shared_ptr<graphunits::Vertex> m_Vertex;
            std::map<std::string, int> m_InstructionFiller;
            std::list<std::string> m_Instruction;

            void addEscapeStepsToInstruction(std::string key) noexcept;
            void getDirection(const graphunits::Coordinates &current, const graphunits::Coordinates &parent) noexcept;

        public:
            InstructionFromBfsStrResult();
            explicit InstructionFromBfsStrResult(std::shared_ptr<graphunits::Vertex> vertex);

            virtual ~InstructionFromBfsStrResult() = default;
            virtual void setDataToMakeInstruction(const std::shared_ptr<graphunits::Vertex> data) noexcept override;
            virtual std::list<std::string> getInstruction() noexcept override;
    };
}

#endif // INSTRUCTIONFROMBFSSTRRESULT_HPP
