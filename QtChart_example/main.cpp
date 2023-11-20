#include "mainwindowchart.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif
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


QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowChart w;

    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Altuve1");
    QBarSet *set2 = new QBarSet("Altuve2");
    QBarSet *set3 = new QBarSet("Altuve3");
    QBarSet *set4 = new QBarSet("Altuve4");

    *set0 << 323 << 434 << 434 << 121 << 434 << 234;
//    *set1 << 323 << 434 << 434 << 121 << 434 << 234;
//    *set2 << 323 << 434 << 434 << 121 << 434 << 234;
//    *set3 << 323 << 434 << 434 << 121 << 434 << 234;
//    *set4 << 323 << 434 << 434 << 121 << 434 << 234;

    //show vertically the bar
    QBarSeries *series = new QBarSeries();

    //QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
//    series->append(set1);
//    series->append(set2);
//    series->append(set3);
//    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Batting Avg by Year");

    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    //for vertial
    chart->setAxisX(axis, series);
    //for horizontal
    //chart->setAxisY(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));

    qApp->setPalette(pal);

    w.setCentralWidget(chartView);
    w.resize(420, 300);
    w.show();
    return a.exec();
}
