#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <memory>
#include <cstdlib>
#include <exception>
#include <thread>
#include <cctype>
#include <mutex>
#include <atomic>
#include <queue>

#include <CPoint3D.hpp>
#include <AVector3D.hpp>
#include <CVector3D.hpp>

#include <CArgsParser.hpp>
#include <COptionBuilder.hpp>
#include <EOptionBuildError.hpp>
#include <EOptionNotPresentInDictionary.hpp>
#include <EParserError.hpp>
#include <ERequiredOptionNotPresent.hpp>
#include <EValuedOptionWithoutValue.hpp>

#include <IFile3DReader.hpp>
#include <CObjFileReader.hpp>
#include <CObject3DData.hpp>
#include <EFile3DReadError.hpp>

#include <CScratchProjectionAnalyzer.hpp>
#include <CScratchProjectionBuilder.hpp>
#include <EWrongObjectsPosition.hpp>

#include <IVectorGraphicsDataWriter.hpp>
#include <CSvgFileWriter.hpp>
#include <CVectorGraphicsData.hpp>
#include <EFileAlreadyExistsException.hpp>
#include <EFileCannotBeOverwritten.hpp>


namespace ScratchedHologramFrom3D {
    namespace CT = ::CliTools;
    namespace F3D = ::File3DProcessingTools;
    namespace F2D = ::File2DProcessingTools;
    namespace SPMath = ::ScratchProjectionMaths;

    class CAppRunner {
    private:
        enum class SupportedInputFileT {
            OBJ
        };
        enum class SupportedOutputFileT {
            SVG
        };

        SupportedInputFileT input_file_t = SupportedInputFileT::OBJ;
        SupportedOutputFileT output_file_t = SupportedOutputFileT::SVG;

        CT::CArgsParser parser;
        std::unique_ptr<F3D::IFile3DReader> p_file_reader;
        std::unique_ptr<F2D::IVectorGraphicsDataWriter> p_file_writer;

        std::string input_filename;
        std::unique_ptr<SPMath::CScratchProjectionAnalyzer> p_analyzer;

        double angle_rad = 0.0;
        double viewer_distance = 0.0;
        double projection_distance = 0.0;
        double spacing = 0.0;
        unsigned int steps_number = 0;
        unsigned int line_width = 1U;
        bool convex_flag = false;
        double step_width = 0.8;
        double scratch_len = 0.9;

        std::string output_filename;
        bool write_force = false;
        unsigned int width = 1024U;
        unsigned int height = 1024U;
        bool width_custom = false;
        bool height_custom = false;

        bool no_confirm = false;

        F3D::CObject3DData input_data_3d;
        std::vector<F2D::CVectorGraphicsData> threads_out_data_2d;

        unsigned int supported_threads_number = HW_CONCURRENCY_DEFAULT;
        std::vector<std::pair<double, double>> threads_angles;
        std::vector<F3D::CObject3DData> threads_object_copies;
        std::vector<Geometry3D::CVector3D> threads_move_vectors;
        std::vector<Geometry3D::CPoint3D> threads_viewers_points;
        double angle_step_rad = 0.0;

        std::mutex cerr_mtx;

    public:
        CAppRunner() {
            initParser();
            updateThreadsInfo();
        }

        ~CAppRunner() = default;

        void performMathCalculations();

        int run(int argc, const char *const *argv);

    private:
        static std::string getLogTimestamp() noexcept;

        void printCErr(const std::string &type, const std::string &cause,
                       const std::string &from = "", const std::string &msg = "") noexcept;

        void initParser();

        void initFileReader();

        void initFileWriter();

        void printHelp() noexcept;

        static inline void replaceComa(std::string &s) noexcept;

        void saveParsedInfo();

        void readInputData();

        void performMathsAnalysis();

        void printAnalysisInfo();

        void updateThreadsInfo();

        void prepareForCalculations();

        bool askUserConfirm() const;

        void setUpWriter();

        // Parser options info
        static const std::string HELP_OPTION_LONG;
        static const std::string HELP_OPTION_INFO;

        static const std::string CONVEX_OBJECT_OPTION_LONG;
        static constexpr char CONVEX_OBJECT_OPTION_SHORT = 'c';
        static const std::string CONVEX_OBJECT_OPTION_INFO;

        static const std::string CANVAS_WIDTH_OPTION_LONG;
        static const std::string CANVAS_WIDTH_OPTION_INFO;

        static const std::string CANVAS_HEIGHT_OPTION_LONG;
        static const std::string CANVAS_HEIGHT_OPTION_INFO;

        static const std::string LINE_WIDTH_OPTION_LONG;
        static const std::string LINE_WIDTH_OPTION_INFO;

        static const std::string IN_FILE_OPTION_LONG;
        static constexpr char IN_FILE_OPTION_SHORT = 'i';
        static constexpr bool IN_FILE_OPTION_REQUIRED_FLAG = true;
        static const std::string IN_FILE_OPTION_INFO;

        static const std::string SCRATCH_STEP_LEN_OPTION_LONG;
        static constexpr char SCRATCH_STEP_LEN_OPTION_SHORT = 'k';
        static constexpr bool SCRATCH_STEP_LEN_OPTION_REQUIRED_FLAG = true;
        static const std::string SCRATCH_STEP_LEN_OPTION_INFO;

        static const std::string SCRATCH_LEN_OPTION_LONG;
        static constexpr char SCRATCH_LEN_OPTION_SHORT = 'x';
        static constexpr bool SCRATCH_LEN_OPTION_REQUIRED_FLAG = true;
        static const std::string SCRATCH_LEN_OPTION_INFO;

        static const std::string OUT_FILE_OPTION_LONG;
        static constexpr char OUT_FILE_OPTION_SHORT = 'o';
        static const std::string OUT_FILE_OPTION_INFO;

        static const std::string WRITE_FORCE_OPTION_LONG;
        static constexpr char WRITE_FORCE_OPTION_SHORT = 'f';
        static const std::string WRITE_FORCE_OPTION_INFO;

        static const std::string VIEWER_DISTANCE_OPTION_LONG;
        static constexpr char VIEWER_DISTANCE_OPTION_SHORT = 'd';
        static const std::string VIEWER_DISTANCE_OPTION_INFO;
        static constexpr bool VIEWER_DISTANCE_OPTION_REQUIRED_FLAG = true;

        static const std::string PROJECTION_DISTANCE_OPTION_LONG;
        static constexpr char PROJECTION_DISTANCE_OPTION_SHORT = 'h';
        static const std::string PROJECTION_DISTANCE_OPTION_INFO;
        static constexpr bool PROJECTION_DISTANCE_OPTION_REQUIRED_FLAG = true;

        static const std::string ANGLE_OPTION_LONG;
        static constexpr char ANGLE_OPTION_SHORT = 'a';
        static const std::string ANGLE_OPTION_INFO;
        static constexpr bool ANGLE_OPTION_REQUIRED_FLAG = true;

        static const std::string ANGLE_RAD_OPTION_LONG;
        static const std::string ANGLE_RAD_OPTION_INFO;

        static const std::string SPACING_WIDTH_OPTION_LONG;
        static constexpr char SPACING_WIDTH_OPTION_SHORT = 's';
        static const std::string SPACING_WIDTH_OPTION_INFO;

        static const std::string STEPS_OPTION_LONG;
        static constexpr char STEPS_OPTION_SHORT = 'n';
        static const std::string STEPS_OPTION_INFO;
        static constexpr bool STEPS_OPTION_REQUIRED_FLAG = true;

        static const std::string NO_CONFIRM_OPTION_LONG;
        static const std::string NO_CONFIRM_OPTION_INFO;

        // File types info
        static const std::string DEFAULT_OUTPUT_FILE_NAME;
        static const std::string SVG_FILE_TYPE_SUFFIX;

        static const std::string PROJECT_VERSION;
        static constexpr double PI_VAL = 3.141592653589793238462;
        static constexpr unsigned int HW_CONCURRENCY_DEFAULT = 2;
    };

}