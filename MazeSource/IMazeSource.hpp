#ifndef IMAZESOURCE_H
#define IMAZESOURCE_H

#include <vector>

namespace graphunits {
    struct Coordinates;
}

namespace mazesource {
    using SourceType = std::unique_ptr< std::vector<std::vector<int>> >;
    class IMazeSource {
        public:
            virtual SourceType getMaze() = 0;
            virtual graphunits::Coordinates getStartCoordinates() const noexcept = 0;
    };
} // mazesource

#endif // IMAZESOURCE_H
