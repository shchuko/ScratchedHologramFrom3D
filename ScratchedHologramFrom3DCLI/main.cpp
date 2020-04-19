

#include <CSvgFileWriter.hpp>
#include "CAppRunner.hpp"

int main(int argv, char** args) {


    File2DProcessingTools::CVectorGraphicsData cVectorGraphicsData;


    File2DProcessingTools::CVectorGraphicsData::CColor_T color(File2DProcessingTools::CVectorGraphicsData::CColor_T::COLOR::GREEN);
    cVectorGraphicsData.setNextColor(color);

    //Д
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1100,100), Geometry2D::CPoint2D(-1150,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1150,200), Geometry2D::CPoint2D(-1150,250)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1150,250), Geometry2D::CPoint2D(-1000,250)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1000,250), Geometry2D::CPoint2D(-950,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-950,500), Geometry2D::CPoint2D(-850,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-850,500), Geometry2D::CPoint2D(-800,250)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-800,250), Geometry2D::CPoint2D(-650,250)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-650,250), Geometry2D::CPoint2D(-650,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-650,200), Geometry2D::CPoint2D(-700,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-700,100), Geometry2D::CPoint2D(-800,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-800,100), Geometry2D::CPoint2D(-750,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-750,200), Geometry2D::CPoint2D(-1050,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1050,200), Geometry2D::CPoint2D(-1000,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1000,100), Geometry2D::CPoint2D(-1100,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-850,250), Geometry2D::CPoint2D(-950,250)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-950,250), Geometry2D::CPoint2D(-920,450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-920,450), Geometry2D::CPoint2D(-880,450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-880,450), Geometry2D::CPoint2D(-850,250)), 10);

    //А
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-500,100), Geometry2D::CPoint2D(-350,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-350,500), Geometry2D::CPoint2D(-250,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-250,500), Geometry2D::CPoint2D(-100,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-100,100), Geometry2D::CPoint2D(-200,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-200,100), Geometry2D::CPoint2D(-250,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-250,200), Geometry2D::CPoint2D(-350,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-350,200), Geometry2D::CPoint2D(-400,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-400,100), Geometry2D::CPoint2D(-500,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-250,250), Geometry2D::CPoint2D(-350,250)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-350,250), Geometry2D::CPoint2D(-320,350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-320,350), Geometry2D::CPoint2D(-280,350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-280,350), Geometry2D::CPoint2D(-250,250)), 10);

    //Н
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(100,500), Geometry2D::CPoint2D(200,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(200,500), Geometry2D::CPoint2D(200,300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(200,300), Geometry2D::CPoint2D(400,300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(400,300), Geometry2D::CPoint2D(400,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(400,500), Geometry2D::CPoint2D(500,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(500,500), Geometry2D::CPoint2D(500,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(500,100), Geometry2D::CPoint2D(400,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(400,100), Geometry2D::CPoint2D(400,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(400,200), Geometry2D::CPoint2D(200,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(200,200), Geometry2D::CPoint2D(200,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(200,100), Geometry2D::CPoint2D(100,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(100,100), Geometry2D::CPoint2D(100,500)), 10);

    //Я
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(700,100), Geometry2D::CPoint2D(700,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(700,200), Geometry2D::CPoint2D(800,300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(800,300), Geometry2D::CPoint2D(700,350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(700,350), Geometry2D::CPoint2D(700,450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(700,450), Geometry2D::CPoint2D(800,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(800,500), Geometry2D::CPoint2D(1100,500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1100,500), Geometry2D::CPoint2D(1100,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1100,100), Geometry2D::CPoint2D(1000,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1000,100), Geometry2D::CPoint2D(1000,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1000,200), Geometry2D::CPoint2D(850,200)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(850,200), Geometry2D::CPoint2D(800,150)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(800,150), Geometry2D::CPoint2D(800,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(800,100), Geometry2D::CPoint2D(700,100)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(850,350), Geometry2D::CPoint2D(850,450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(850,450), Geometry2D::CPoint2D(950,450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(950,450), Geometry2D::CPoint2D(950,350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(950,350), Geometry2D::CPoint2D(850,350)), 10);

    //П
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1100,-700), Geometry2D::CPoint2D(-1100,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1100,-300), Geometry2D::CPoint2D(-700,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-700,-300), Geometry2D::CPoint2D(-700,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-700,-700), Geometry2D::CPoint2D(-800,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-800,-700), Geometry2D::CPoint2D(-800,-400)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-800,-400), Geometry2D::CPoint2D(-1000,-400)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1000,-400), Geometry2D::CPoint2D(-1000,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-1000,-700), Geometry2D::CPoint2D(-1100,-700)), 10);

    //И
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-500,-700), Geometry2D::CPoint2D(-500,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-500,-300), Geometry2D::CPoint2D(-400,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-400,-300), Geometry2D::CPoint2D(-400,-600)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-400,-600), Geometry2D::CPoint2D(-200,-450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-200,-450), Geometry2D::CPoint2D(-200,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-200,-300), Geometry2D::CPoint2D(-100,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-100,-300), Geometry2D::CPoint2D(-100,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-100,-700), Geometry2D::CPoint2D(-200,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-200,-700), Geometry2D::CPoint2D(-200,-550)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-200,-550), Geometry2D::CPoint2D(-400,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(-400,-700), Geometry2D::CPoint2D(-500,-700)), 10);

    //Д
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(100,-700), Geometry2D::CPoint2D(50,-600)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(50,-600), Geometry2D::CPoint2D(200,-600)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(200,-600), Geometry2D::CPoint2D(250,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(250,-300), Geometry2D::CPoint2D(350,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(350,-300), Geometry2D::CPoint2D(400,-600)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(400,-600), Geometry2D::CPoint2D(550,-600)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(550,-600), Geometry2D::CPoint2D(500,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(500,-700), Geometry2D::CPoint2D(400,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(400,-700), Geometry2D::CPoint2D(450,-650)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(450,-650), Geometry2D::CPoint2D(150,-650)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(150,-650), Geometry2D::CPoint2D(200,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(200,-700), Geometry2D::CPoint2D(100,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(250,-600), Geometry2D::CPoint2D(280,-350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(280,-350), Geometry2D::CPoint2D(320,-350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(320,-350), Geometry2D::CPoint2D(350,-600)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(350,-600), Geometry2D::CPoint2D(250,-600)), 10);

    //Р
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(700,-700), Geometry2D::CPoint2D(700,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(700,-300), Geometry2D::CPoint2D(1000,-300)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1000,-300), Geometry2D::CPoint2D(1050,-350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1050,-350), Geometry2D::CPoint2D(1050,-450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1050,-450), Geometry2D::CPoint2D(1000,-500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(1000,-500), Geometry2D::CPoint2D(800,-500)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(800,-500), Geometry2D::CPoint2D(800,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(800,-700), Geometry2D::CPoint2D(700,-700)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(850,-350), Geometry2D::CPoint2D(950,-350)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(950,-350), Geometry2D::CPoint2D(950,-450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(950,-450), Geometry2D::CPoint2D(850,-450)), 10);
    cVectorGraphicsData.addLineSegments(Geometry2D::CLineSegment2D(    Geometry2D::CPoint2D(850,-450), Geometry2D::CPoint2D(850,-350)), 10);

    File2DProcessingTools::CSvgFileWriter cSvgFileWriter(1024, 1024);
    cSvgFileWriter.setAlignmentCenter(std::pair<unsigned  int, unsigned int>(0, 500));
    cSvgFileWriter.write(R"(C:\Users\mrNer\CLionProjects/files/test.svg)", cVectorGraphicsData, true);

    CAppRunner appRunner;
    return appRunner.run();
}
