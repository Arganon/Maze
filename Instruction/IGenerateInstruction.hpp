#ifndef IGENERATEINSTRUCTION_H
#define IGENERATEINSTRUCTION_H

#include <string>
#include <list>

namespace instruction {

    template <typename InputData>
    class IGenerateInstruction
    {
        public:
            virtual void setDataToMakeInstruction(const InputData data) noexcept = 0;
            virtual std::list<std::string> getInstruction() noexcept = 0;
    };
}

#endif // IGENERATEINSTRUCTION_H
