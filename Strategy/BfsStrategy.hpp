#ifndef BFSSTRATEGY_HPP
#define BFSSTRATEGY_HPP

#include "Strategy/IFindWayStrategy.hpp"
#include <memory>

namespace strategy {
    using DataType = std::shared_ptr<graphunits::Vertex>;

    class BfsStrategy : public IFindWayStrategy<DataType>
    {
        private:
            DataType m_RootVertex;

        public:
            BfsStrategy();
            BfsStrategy(DataType rootGraphElement);

            virtual ~BfsStrategy() = default;
            virtual void setDataToCalculateStrategy(DataType data) noexcept override;
            virtual DataType useStrategy() override;
    };
}

#endif // BFSSTRATEGY_HPP
