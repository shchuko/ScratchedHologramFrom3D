#include <gtest/gtest.h>
#include <CScratchProjectionBuilder.hpp>
#include <CObject3DData.hpp>
#include <CVector3D.hpp>
#include <CPoint3D.hpp>
#include <exception>

namespace CProjectionBuilderUnitTestsNS {
    using namespace ScratchProjectionMaths;
    using namespace File3DProcessingTools;
    using namespace File2DProcessingTools;
    using namespace Geometry3D;

    TEST(CScratchProjectionBuilder, CScratchProjectionBuilder_constructor_throws_Test) {
        CObject3DData in_data;
        EXPECT_NO_THROW(CScratchProjectionBuilder(in_data, {0, 0, 0}, 1.0));
        EXPECT_THROW(CScratchProjectionBuilder(in_data, {0, 0, 0}, -1.0), std::logic_error);
        EXPECT_THROW(CScratchProjectionBuilder(in_data, {0, 0, 0}, 0.0), std::logic_error);

    }

    TEST(CScratchProjectionBuilder, CScratchProjectionBuilder_setStepWidth_throws_Test) {
        CObject3DData in_data;
        CScratchProjectionBuilder builder(in_data, {0, 0, 0}, 1);

        EXPECT_NO_THROW(builder.setStepWidth(1.0));
        EXPECT_THROW(builder.setStepWidth(-1.0), std::logic_error);
        EXPECT_THROW(builder.setStepWidth(0.0), std::logic_error);
    }

    TEST(CScratchProjectionBuilder, CScratchProjectionBuilder_build_throws_Test) {
        CObject3DData in_data;
        CVectorGraphicsData out_data;
        CVector3D move_vector;
        CScratchProjectionBuilder builder(in_data, {0, 0, 0}, 1);

        EXPECT_NO_THROW(builder.build(move_vector, 0.1, 3.14, 0.3, 0.1));

        // 2nd arg
        EXPECT_THROW(builder.build(move_vector, -0.1, 3.14, 0.3, 0.1), std::logic_error);
        EXPECT_THROW(builder.build(move_vector, 6.284, 3.14, 0.3, 0.1), std::logic_error);

        // 3rd arg
        EXPECT_THROW(builder.build(move_vector, 0.1, -0.1, 0.3, 0.1), std::logic_error);
        EXPECT_THROW(builder.build(move_vector, 0.1, 6.284, 0.3, 0.1), std::logic_error);

        // 4th arg
        EXPECT_THROW(builder.build(move_vector, 0.1, 0.2, -0.1, 0.1), std::logic_error);
        EXPECT_THROW(builder.build(move_vector, 0.1, 0.3, 6.284, 0.1), std::logic_error);

        // 5th arg
        EXPECT_THROW(builder.build(move_vector, 0.1, 0.2, 0.2, -0.1), std::logic_error);
    }

}
