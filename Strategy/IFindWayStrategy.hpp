#ifndef IFINDWAYSTRATEGY_H
#define IFINDWAYSTRATEGY_H

#include "GraphUnits/Vertex.hpp"

namespace strategy {
    template<typename DataType>
    class IFindWayStrategy
    {
    public:
        virtual void setDataToCalculateStrategy(DataType data) noexcept = 0;
        virtual DataType useStrategy() = 0;
    };
}

#endif // IFINDWAYSTRATEGY_H
