#include "mainwindow.h"

#include <QtCore/qglobal.h>

#include <QtWidgets/QApplication>


#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    series->append(0, 16);
    series->append(1, 25);
    series->append(2, 24);
    series->append(3, 19);
    series->append(4, 18);
    series->append(5, 33);
    series->append(6, 24);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Barry bonds HRs as Pirate");

    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    series->setPen(pen);

    chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

    QtCharts::QCategoryAxis *axisX = new QtCharts::QCategoryAxis();
    axisX->append("1986", 0);
    axisX->append("1987", 1);
    axisX->append("1988", 2);
    axisX->append("1989", 3);
    axisX->append("1990", 4);
    axisX->append("1991", 5);
    axisX->append("1992", 6);
    chart->addAxis(axisX, Qt::AlignBottom);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    w.setCentralWidget(chartView);
    w.resize(420, 300);
    w.show();
    w.show();
    return a.exec();
}
