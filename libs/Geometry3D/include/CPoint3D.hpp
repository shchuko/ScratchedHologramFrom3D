#pragma once

namespace Geometry3D {

    /**
     * @author Danil Nasibullin 2020
     * email:
     */
    class CPoint3D {
    private:
        double x = 0.0;
        double y = 0.0;
        double z = 0.0;

    public:

        CPoint3D() = default;

        CPoint3D(const CPoint3D& cPoint3D) noexcept;

        CPoint3D(CPoint3D&& cPoint3D) noexcept;

        CPoint3D(double x, double y, double z) noexcept;

        /**
         * Get x coordinate
         * @return x coordinate
         */
        double getX() const noexcept;

        double getY() const noexcept;

        double getZ() const noexcept;

    };
}
