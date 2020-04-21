#include "CAppRunner.hpp"

const std::string ScratchedHologramFrom3D::CAppRunner::HELP_OPTION_LONG = "help";
const std::string ScratchedHologramFrom3D::CAppRunner::HELP_OPTION_INFO = "Display this help, disables all options except this one";

const std::string ScratchedHologramFrom3D::CAppRunner::CONVEX_OBJECT_OPTION_LONG = "convex";
const std::string ScratchedHologramFrom3D::CAppRunner::CONVEX_OBJECT_OPTION_INFO = "Perform calculations for convex 3d-model (faster)";

const std::string ScratchedHologramFrom3D::CAppRunner::CANVAS_WIDTH_OPTION_LONG = "width";
const std::string ScratchedHologramFrom3D::CAppRunner::CANVAS_WIDTH_OPTION_INFO = "Set canvas width in px. Default: 1024px";

const std::string ScratchedHologramFrom3D::CAppRunner::CANVAS_HEIGHT_OPTION_LONG = "height";
const std::string ScratchedHologramFrom3D::CAppRunner::CANVAS_HEIGHT_OPTION_INFO = "Set canvas height in px. Default: 1024px";

const std::string ScratchedHologramFrom3D::CAppRunner::LINE_WIDTH_OPTION_LONG = "line-width";
const std::string ScratchedHologramFrom3D::CAppRunner::LINE_WIDTH_OPTION_INFO = "Set line width in px. Default: 1px";

const std::string ScratchedHologramFrom3D::CAppRunner::IN_FILE_OPTION_LONG = "in";
const std::string ScratchedHologramFrom3D::CAppRunner::IN_FILE_OPTION_INFO = "Set input file name";

const std::string ScratchedHologramFrom3D::CAppRunner::OUT_FILE_OPTION_LONG = "out";
const std::string ScratchedHologramFrom3D::CAppRunner::OUT_FILE_OPTION_INFO = "Set output file name. Default: scratch_out.svg";

const std::string ScratchedHologramFrom3D::CAppRunner::WRITE_FORCE_OPTION_LONG = "write-force";
const std::string ScratchedHologramFrom3D::CAppRunner::WRITE_FORCE_OPTION_INFO = "Overwrite output file if exists";

const std::string ScratchedHologramFrom3D::CAppRunner::VIEWER_DISTANCE_OPTION_LONG = "viewer-dist";
const std::string ScratchedHologramFrom3D::CAppRunner::VIEWER_DISTANCE_OPTION_INFO = "Distance between object and viewer in [length units]";

const std::string ScratchedHologramFrom3D::CAppRunner::PROJECTION_DISTANCE_OPTION_LONG = "plane-dist";
const std::string ScratchedHologramFrom3D::CAppRunner::PROJECTION_DISTANCE_OPTION_INFO = "Distance between object and projection plane [length units]";

const std::string ScratchedHologramFrom3D::CAppRunner::ANGLE_OPTION_LONG = "angle";
const std::string ScratchedHologramFrom3D::CAppRunner::ANGLE_OPTION_INFO = "Angle between viewer and object center (default: degrees)";

const std::string ScratchedHologramFrom3D::CAppRunner::ANGLE_RAD_OPTION_LONG = "rad";
const std::string ScratchedHologramFrom3D::CAppRunner::ANGLE_RAD_OPTION_INFO = "Read angle as radians";

const std::string ScratchedHologramFrom3D::CAppRunner::SCRATCH_STEP_LEN_OPTION_LONG = "step-len";
const std::string ScratchedHologramFrom3D::CAppRunner::SCRATCH_STEP_LEN_OPTION_INFO = "Step between two scratches on the edge projection [length units]";

const std::string ScratchedHologramFrom3D::CAppRunner::SCRATCH_LEN_OPTION_LONG = "scratch-len";
const std::string ScratchedHologramFrom3D::CAppRunner::SCRATCH_LEN_OPTION_INFO = "Scratch length [length units]";

const std::string ScratchedHologramFrom3D::CAppRunner::SPACING_WIDTH_OPTION_LONG = "spacing";
const std::string ScratchedHologramFrom3D::CAppRunner::SPACING_WIDTH_OPTION_INFO = "Spacing width in [length units]. Default 0.0";

const std::string ScratchedHologramFrom3D::CAppRunner::STEPS_OPTION_LONG = "steps";
const std::string ScratchedHologramFrom3D::CAppRunner::STEPS_OPTION_INFO = "Calculation steps number";

const std::string ScratchedHologramFrom3D::CAppRunner::NO_CONFIRM_OPTION_LONG = "no-confirm";
const std::string ScratchedHologramFrom3D::CAppRunner::NO_CONFIRM_OPTION_INFO = "Skip operations confirmation";

// File types info
const std::string ScratchedHologramFrom3D::CAppRunner::DEFAULT_OUTPUT_FILE_NAME = "scratch_out";
const std::string ScratchedHologramFrom3D::CAppRunner::SVG_FILE_TYPE_SUFFIX = ".svg";

const std::string ScratchedHologramFrom3D::CAppRunner::PROJECT_VERSION = PROJECT_VERSION_DEF;


std::string ScratchedHologramFrom3D::CAppRunner::getLogTimestamp() noexcept {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss.clear();

    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void ScratchedHologramFrom3D::CAppRunner::printCErr(const std::string &type, const std::string &cause,
                                                    const std::string &from, const std::string &msg) noexcept {
    std::lock_guard<std::mutex> cerr_lock_guart(cerr_mtx);

    std::cerr << getLogTimestamp() << " (" << type << ") " << cause;
    if (!msg.empty()) {
        std::cerr << " - " << msg;
    }

    if (from.empty()) {
        std::cerr << std::endl;
    } else {
        std::cerr << " from {" << from << "}" << std::endl;
    }
}

void ScratchedHologramFrom3D::CAppRunner::initParser() {
    CT::COptionBuilder builder;
    try {
        parser.addHelpOption(builder.addLongName(HELP_OPTION_LONG)
                                     .addDescription(HELP_OPTION_INFO).build());

        builder.reset();
        parser.addOption(builder.addLongName(IN_FILE_OPTION_LONG)
                                 .addShortName(IN_FILE_OPTION_SHORT)
                                 .addDescription(IN_FILE_OPTION_INFO)
                                 .setValue(true, IN_FILE_OPTION_REQUIRED_FLAG).build());

        builder.reset();
        parser.addOption(builder.addLongName(OUT_FILE_OPTION_LONG)
                                 .addShortName(OUT_FILE_OPTION_SHORT)
                                 .addDescription(OUT_FILE_OPTION_INFO)
                                 .setValue(true).build());

        builder.reset();
        parser.addOption(builder.addLongName(WRITE_FORCE_OPTION_LONG)
                                 .addShortName(WRITE_FORCE_OPTION_SHORT)
                                 .addDescription(WRITE_FORCE_OPTION_INFO).build());

        builder.reset();
        parser.addOption(builder.addLongName(VIEWER_DISTANCE_OPTION_LONG)
                                 .addShortName(VIEWER_DISTANCE_OPTION_SHORT)
                                 .addDescription(VIEWER_DISTANCE_OPTION_INFO)
                                 .setValue(true, VIEWER_DISTANCE_OPTION_REQUIRED_FLAG).build());

        builder.reset();
        parser.addOption(builder.addLongName(PROJECTION_DISTANCE_OPTION_LONG)
                                 .addShortName(PROJECTION_DISTANCE_OPTION_SHORT)
                                 .addDescription(PROJECTION_DISTANCE_OPTION_INFO)
                                 .setValue(true, PROJECTION_DISTANCE_OPTION_REQUIRED_FLAG).build());

        builder.reset();
        parser.addOption(builder.addLongName(ANGLE_OPTION_LONG)
                                 .addShortName(ANGLE_OPTION_SHORT)
                                 .addDescription(ANGLE_OPTION_INFO)
                                 .setValue(true, ANGLE_OPTION_REQUIRED_FLAG).build());

        builder.reset();
        parser.addOption(builder.addLongName(ANGLE_RAD_OPTION_LONG)
                                 .addDescription(ANGLE_RAD_OPTION_INFO).build());

        builder.reset();
        parser.addOption(builder.addLongName(SPACING_WIDTH_OPTION_LONG)
                                 .addShortName(SPACING_WIDTH_OPTION_SHORT)
                                 .addDescription(SPACING_WIDTH_OPTION_INFO)
                                 .setValue(true).build());

        builder.reset();
        parser.addOption(builder.addLongName(STEPS_OPTION_LONG)
                                 .addShortName(STEPS_OPTION_SHORT)
                                 .addDescription(STEPS_OPTION_INFO)
                                 .setValue(true, STEPS_OPTION_REQUIRED_FLAG).build());

        builder.reset();
        parser.addOption(builder.addLongName(CONVEX_OBJECT_OPTION_LONG)
                                 .addShortName(CONVEX_OBJECT_OPTION_SHORT)
                                 .addDescription(CONVEX_OBJECT_OPTION_INFO).build());
        builder.reset();
        parser.addOption(builder.addLongName(CANVAS_WIDTH_OPTION_LONG)
                                 .addDescription(CANVAS_WIDTH_OPTION_INFO)
                                 .setValue(true).build());

        builder.reset();
        parser.addOption(builder.addLongName(CANVAS_HEIGHT_OPTION_LONG)
                                 .addDescription(CANVAS_HEIGHT_OPTION_INFO)
                                 .setValue(true).build());

        builder.reset();
        parser.addOption(builder.addLongName(LINE_WIDTH_OPTION_LONG)
                                 .addDescription(LINE_WIDTH_OPTION_INFO)
                                 .setValue(true).build());

        builder.reset();
        parser.addOption(builder.addLongName(NO_CONFIRM_OPTION_LONG)
                                 .addDescription(NO_CONFIRM_OPTION_INFO).build());

        builder.reset();
        parser.addOption(builder.addLongName(SCRATCH_LEN_OPTION_LONG)
                                 .addShortName(SCRATCH_LEN_OPTION_SHORT)
                                 .addDescription(SCRATCH_LEN_OPTION_INFO)
                                 .setValue(true, SCRATCH_LEN_OPTION_REQUIRED_FLAG).build());

        builder.reset();
        parser.addOption(builder.addLongName(SCRATCH_STEP_LEN_OPTION_LONG)
                                 .addShortName(SCRATCH_STEP_LEN_OPTION_SHORT)
                                 .addDescription(SCRATCH_STEP_LEN_OPTION_INFO)
                                 .setValue(true, SCRATCH_STEP_LEN_OPTION_REQUIRED_FLAG).build());

    } catch (CT::Exceptions::EOptionBuildError &e) {
        printCErr("Internal Err", "EOptionBuildError", "ScratchedHologramFrom3D::CAppRunner::initParser", e.what());
        throw std::exception();
    } catch (...) {
        printCErr("Internal Err", "Unexpected exception", "ScratchedHologramFrom3D::CAppRunner::initParser");
        throw std::exception();
    }
}

void ScratchedHologramFrom3D::CAppRunner::initFileReader() {
    switch (input_file_t) {
        case SupportedInputFileT::OBJ:
            p_file_reader.reset(new F3D::CObjFileReader());
            break;
    }
}

void ScratchedHologramFrom3D::CAppRunner::initFileWriter() {
    switch (output_file_t) {
        case SupportedOutputFileT::SVG:
            p_file_writer.reset(new F2D::CSvgFileWriter());
            output_filename = DEFAULT_OUTPUT_FILE_NAME + SVG_FILE_TYPE_SUFFIX;
            break;
    }
}

void ScratchedHologramFrom3D::CAppRunner::saveParsedInfo() {
    // File3DProcessingTools
    input_filename = parser.getOptionValue(IN_FILE_OPTION_SHORT);

    // Maths
    // Degrees to radian factor
    double angle_normalize_factor = 0.017453292519;
    if (parser.isOptionPresent(ANGLE_RAD_OPTION_LONG)) {
        angle_normalize_factor = 1.0;
    }

    auto s_angle_rad = parser.getOptionValue(ANGLE_OPTION_SHORT);
    replaceComa(s_angle_rad);
    angle_rad = std::stod(s_angle_rad) * angle_normalize_factor;

    auto s_viewer_distance = parser.getOptionValue(VIEWER_DISTANCE_OPTION_SHORT);
    replaceComa(s_viewer_distance);
    viewer_distance = std::stod(s_viewer_distance);

    auto s_proj_distance = parser.getOptionValue(PROJECTION_DISTANCE_OPTION_SHORT);
    replaceComa(s_proj_distance);
    projection_distance = std::stod(s_proj_distance);

    if (parser.isOptionPresent(SPACING_WIDTH_OPTION_LONG)) {
        auto s_spacing = parser.getOptionValue(SPACING_WIDTH_OPTION_LONG);
        replaceComa(s_spacing);
        spacing = std::stod(s_spacing);
    }

    steps_number = std::stoi(parser.getOptionValue(STEPS_OPTION_SHORT));
    convex_flag = parser.isOptionPresent(CONVEX_OBJECT_OPTION_SHORT);

    if (parser.isOptionPresent(LINE_WIDTH_OPTION_LONG)) {
        line_width = std::stoi(parser.getOptionValue(LINE_WIDTH_OPTION_LONG));
    }

    auto s_scratch_len = parser.getOptionValue(SCRATCH_LEN_OPTION_SHORT);
    replaceComa(s_scratch_len);
    scratch_len = std::stod(s_scratch_len);

    auto s_step_width = parser.getOptionValue(SCRATCH_STEP_LEN_OPTION_SHORT);
    replaceComa(s_step_width);
    step_width = std::stod(s_step_width);

    // File2DProcessingTools
    if (parser.isOptionPresent(CANVAS_WIDTH_OPTION_LONG)) {
        width = std::stoi(parser.getOptionValue(CANVAS_WIDTH_OPTION_LONG));
        width_custom = true;
    }

    if (parser.isOptionPresent(CANVAS_HEIGHT_OPTION_LONG)) {
        height = std::stoi(parser.getOptionValue(CANVAS_HEIGHT_OPTION_LONG));
        height_custom = true;
    }

    if (parser.isOptionPresent(OUT_FILE_OPTION_SHORT)) {
        output_filename = parser.getOptionValue(OUT_FILE_OPTION_SHORT);
    }

    write_force = parser.isOptionPresent(WRITE_FORCE_OPTION_SHORT);

    // Other
    no_confirm = parser.isOptionPresent(NO_CONFIRM_OPTION_LONG);
}

void ScratchedHologramFrom3D::CAppRunner::replaceComa(std::string &s) noexcept {
    std::replace(std::begin(s), std::end(s), ',', '.');
}

void ScratchedHologramFrom3D::CAppRunner::readInputData() {
    input_data_3d = F3D::CObject3DData();
    p_file_reader->readFile(input_filename, input_data_3d);
}

void ScratchedHologramFrom3D::CAppRunner::printAnalysisInfo() {
    using namespace std;
    constexpr int w_val = 35;
    double angle_normalize_factor = 0.017453292519;

    cout << "----------------------" << endl;
    cout << "-- Analysis results --" << endl;
    cout << "----------------------" << endl;

    cout << setw(w_val) << left << "View angle (deg): " << angle_rad / angle_normalize_factor << endl;
    cout << setw(w_val) << left << "View angle (rad): " << angle_rad << endl;
    cout << setw(w_val) << left << "Object <-> viewer distance: " << viewer_distance << endl;
    cout << setw(w_val) << left << "Object <-> proj. plane distance: " << projection_distance << endl;
    cout << setw(w_val) << left << "Projection spacing: " << spacing << endl;
    cout << setw(w_val) << left << "Steps: " << steps_number << endl;
    cout << setw(w_val) << left << "Angle step (deg): " << angle_step_rad / angle_normalize_factor << endl;
    cout << setw(w_val) << left << "Angle step (rad): " << angle_step_rad << endl;
    cout << setw(w_val) << left << "3D-Model is convex: " << std::boolalpha << convex_flag << endl;
    cout << setw(w_val) << left << "Scratch length: " << scratch_len << endl;
    cout << setw(w_val) << left << "Scratches step: " << step_width << endl;

    cout << setw(w_val) << left << "Projection radius: " << p_analyzer->getProjectionWidth() << endl;
    cout << setw(w_val) << left << "Projection radius with spacing: " << p_analyzer->getProjectionWidth() + spacing
         << endl;
}

void ScratchedHologramFrom3D::CAppRunner::printHelp() noexcept {
    std::cout << "Scratched Hologram Builder v" + PROJECT_VERSION << std::endl;
    std::cout << "Supported input formats: *.obj (Z Up, -X Forward). "
              << "Supported output formats: *.svg. " << std::endl
              << "Note: [length units] are related to input 3D-object units." << std::endl;
    std::cout << "Options:" << std::endl << parser.getHelpMessage() << std::endl;
}

void ScratchedHologramFrom3D::CAppRunner::performMathsAnalysis() {
    p_analyzer.reset(new SPMath::CScratchProjectionAnalyzer(input_data_3d, viewer_distance, angle_rad,
                                                            projection_distance));
    angle_step_rad = 2 * PI_VAL / steps_number;
}

void ScratchedHologramFrom3D::CAppRunner::updateThreadsInfo() {
    threads_out_data_2d.clear();
    auto hw_cnc_current = std::thread::hardware_concurrency();
    if (hw_cnc_current == 0) {
        supported_threads_number = HW_CONCURRENCY_DEFAULT;
    } else {
        supported_threads_number = hw_cnc_current;
    }
}

void ScratchedHologramFrom3D::CAppRunner::prepareForCalculations() {
    threads_out_data_2d.clear();
    auto threads_num = std::min(supported_threads_number, steps_number);
    double thread_angle_part = 2 * PI_VAL / threads_num;

    threads_out_data_2d.resize(threads_num);

    threads_angles.clear();
    for (unsigned long i = 0; i < threads_num; ++i) {
        auto double_i = static_cast<double >(i);
        threads_angles.emplace_back(std::make_pair(thread_angle_part * double_i, thread_angle_part * (double_i + 1)));
    }

    threads_move_vectors.resize(threads_num, p_analyzer->getCalculationMoveVector(spacing));
    threads_viewers_points.resize(threads_num, p_analyzer->getViewerPoint(spacing));
    threads_object_copies.resize(threads_num - 1, input_data_3d);
}

bool ScratchedHologramFrom3D::CAppRunner::askUserConfirm() const {
    do {
        std::cout << "Continue? [Y]/[N]: ";
        if (no_confirm) {
            std::cout << "Confirmation skipped" << std::endl;
            return true;
        }

        char answer;
        std::cin >> answer;

        if (answer == 'n' || answer == 'N') {
            return false;
        }

        if (answer == 'y' || answer == 'Y') {
            return true;
        }

        std::cout << "Wrong answer: " << answer << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

}

void ScratchedHologramFrom3D::CAppRunner::performMathCalculations() {
    std::mutex thrown_exceptions_queue_mutex;
    std::queue<std::exception_ptr> thrown_exceptions;

    auto f_perform_calc_part = [&](unsigned long i) {
        try {
            auto &thread_object_copy = (i >= 1) ? threads_object_copies[i - 1] : input_data_3d;
            SPMath::CScratchProjectionBuilder builder(thread_object_copy,
                                                      threads_viewers_points[i],
                                                      step_width,
                                                      convex_flag);

            builder.setScratchLineWidthPixels(line_width);

            builder.build(threads_out_data_2d[i],
                          threads_move_vectors[i],
                          threads_angles[i].first,
                          threads_angles[i].second,
                          angle_step_rad,
                          scratch_len);
        } catch (std::logic_error &e) {
            std::lock_guard<std::mutex> thrown_exceptions_queue_lock_guard(thrown_exceptions_queue_mutex);

            thrown_exceptions.emplace(std::current_exception());
            printCErr("Logic Err", "std::logic_err",
                      "ScratchedHologramFrom3D::CAppRunner::performMathCalculations::{thread}", e.what());
        } catch (std::exception &e) {
            std::lock_guard<std::mutex> thrown_exceptions_queue_lock_guart(thrown_exceptions_queue_mutex);

            thrown_exceptions.emplace(std::current_exception());
            printCErr("Internal Err", "std::exception",
                      "ScratchedHologramFrom3D::CAppRunner::performMathCalculations::{thread}", e.what());
        }
    };

    std::vector<std::thread> threads;
    for (unsigned long i = 1; i < threads_out_data_2d.size(); ++i) {
        threads.emplace_back(f_perform_calc_part, i);
    }

    f_perform_calc_part(0);

    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    if (!thrown_exceptions.empty()) {
        std::rethrow_exception(thrown_exceptions.front());
    }
}

void ScratchedHologramFrom3D::CAppRunner::setUpWriter() {
    if ((height_custom && width_custom) || (!height_custom && !width_custom)) {
        p_file_writer->setCanvasSize(height, width);
    } else if (height_custom) {
        p_file_writer->setCanvasHeight(height);
    } else if (width_custom) {
        p_file_writer->setCanvasWidth(width);
    }

    // Align to center and add 10px paddings
    p_file_writer->setAlignmentCenter(std::make_pair(10U, 10U));
}

int ScratchedHologramFrom3D::CAppRunner::run(int argc, const char *const *argv) {
    try {
        if (argc == 1) {
            printHelp();
            return EXIT_SUCCESS;
        }

        parser.parse(argc, argv);
        if (parser.isHelpParsed()) {
            printHelp();
            return EXIT_SUCCESS;
        }
        saveParsedInfo();

        initFileReader();
        initFileWriter();

        std::cout << "Input file reading: " + input_filename << std::endl;
        readInputData();
        std::cout << "    SUCCEED" << std::endl;

        performMathsAnalysis();
        printAnalysisInfo();
        if (!askUserConfirm()) {
            std::cout << "Exiting..." << std::endl;
            return EXIT_SUCCESS;
        }

        std::cout << "Preparing for calculations:" << std::endl;
        prepareForCalculations();
        std::cout << "    SUCCEED" << std::endl;

        std::cout << "Calculation (may take up to 10 min for complex 3d-data):" << std::endl;
        performMathCalculations();
        std::cout << "    SUCCEED" << std::endl;

        setUpWriter();
        std::cout << "Results writing started: " + output_filename << std::endl;
        p_file_writer->writeMul(output_filename, threads_out_data_2d, write_force);
        std::cout << "    SUCCEED" << std::endl;

        std::cout << "All operations successful, exiting..." << std::endl;

    } catch (CT::Exceptions::ERequiredOptionNotPresent &e) {
        printCErr("Input Err", "Required Option Not Present", "", e.what());
        return EXIT_FAILURE;
    } catch (CT::Exceptions::EUnrecognizedOptionParsed &e) {
        printCErr("Input Err", "Unrecognized Option Parsed", "", e.what());
        return EXIT_FAILURE;
    } catch (CT::Exceptions::EValuedOptionWithoutValue &e) {
        printCErr("Input Err", "Valued Option Without Value", "", e.what());
        return EXIT_FAILURE;
    } catch (CT::Exceptions::EOptionNotPresentInDictionary &e) {
        printCErr("Internal Err", "EOptionNotPresentInDictionary", "ScratchedHologramFrom3D::CAppRunner::run",
                  e.what());
        return EXIT_FAILURE;
    } catch (std::invalid_argument &e) {
        printCErr("Logic Err", "Invalid arguments numbers format", "", e.what());
        return EXIT_FAILURE;
    } catch (std::out_of_range &e) {
        printCErr("Logic Err", "Input argument is out of range", "", e.what());
        return EXIT_FAILURE;
    } catch (std::logic_error &e) {
        printCErr("Logic Err", "std::logic_err",
                  "ScratchedHologramFrom3D::CAppRunner::run", e.what());
        return EXIT_FAILURE;
    } catch (F3D::Exceptions::EFile3DReadError &e) {
        printCErr("File Read Err", "File3D Read Error", "", e.what());
        return EXIT_FAILURE;
    } catch (SPMath::Exceptions::EWrongObjectsPosition &e) {
        printCErr("Logic Err", "Wrong object position", "", e.what());
        return EXIT_FAILURE;
    } catch (F2D::Exceptions::EFileAlreadyExistsException &e) {
        printCErr("File Write Err", "File Already Exists", "", e.what());
        return EXIT_FAILURE;
    } catch (F2D::Exceptions::EFileCannotBeOverwritten &e) {
        printCErr("File Write Err", "File Cannot Be Overwritten", "", e.what());
        return EXIT_FAILURE;
    } catch (std::bad_alloc &e) {
        printCErr("Internal Err", "std::bad_alloc", "ScratchedHologramFrom3D::CAppRunner::run", e.what());
    } catch (std::exception &e) {
        printCErr("Internal Err", "std::exception", "ScratchedHologramFrom3D::CAppRunner::run", e.what());
        return EXIT_FAILURE;
    } catch (...) {
        printCErr("Internal Err", "Unrecognized exception", "ScratchedHologramFrom3D::CAppRunner::run");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
