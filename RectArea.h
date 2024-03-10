#pragma once
#include <vector>

/**
 * @brief Class representing a rectangular area in N-dimensional space.
 *
 * This class encapsulates the definition of a rectangular area, defined by its
 * lower and upper bounds in each dimension. It is intended for use in
 * optimization problems, where such an area specifies the bounds within which
 * the optimization is to be conducted.
 */
class RectArea
{
public:
    /**
     * @brief Constructs a RectArea object with specified size and boundary points.
     *
     * @param _AreaSize The dimensionality of the space in which the area is defined.
     * @param _lower_point A vector of doubles representing the lower boundary points of the area.
     * @param _upper_point A vector of doubles representing the upper boundary points of the area.
     */
    RectArea(int _AreaSize, const std::vector<double>& _lower_point, const std::vector<double>& _upper_point)
        : AreaSize(_AreaSize),
        lower_point(_lower_point),
        upper_point(_upper_point) {}


    /**
     * @brief Sets the properties of the rectangular area.
     *
     * This method allows for the resetting of the area's size and its boundary points.
     *
     * @param _AreaSize The new dimensionality of the space in which the area is defined.
     * @param _lower_point A new vector of doubles representing the lower boundary points of the area.
     * @param _upper_point A new vector of doubles representing the upper boundary points of the area.
     */
    void SetArea(int _AreaSize, const std::vector<double>& _lower_point, const std::vector<double>& _upper_point)
    {
        AreaSize = _AreaSize;
        lower_point.assign(_lower_point.begin(), _lower_point.end());
        upper_point.assign(_upper_point.begin(), _upper_point.end());
    }
    /**
     * @brief Gets the dimensionality of the area.
     *
     * @return The dimensionality of the space in which the area is defined.
     */
    int GetSize() const { return AreaSize; }

    /**
     * @brief Gets the lower boundary points of the area.
     *
     * @return A reference to a vector of doubles representing the lower boundary points.
     */
    std::vector<double>& GetLower() { return lower_point; }

    /**
     * @brief Gets the upper boundary points of the area.
     *
     * @return A reference to a vector of doubles representing the upper boundary points.
     */
    std::vector<double>& GetUpper() { return upper_point; }

private:
    int AreaSize; ///< The dimensionality of the area.
    std::vector<double> lower_point; ///< The lower boundary points of the area.
    std::vector<double> upper_point; ///< The upper boundary points of the area.
};
