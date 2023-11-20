#include "mainwindow.h"

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

QT_CHARTS_USE_NAMESPACE
class Ui_ThemeWidgetForm;
QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPieSeries *series = new QPieSeries();
    series->append("Vegetables", .40);
    series->append("Beans", .20);
    series->append("Fruit", .15);
    series->append("Seeds/Nuts", .10);
    series->append("Whole Grans", .15);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();
    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("What Derk ate this Week");
    chart->legend()->hide();

    ///test theme:
    /// ChartThemeLight,
    /// ChartThemeBlueCerulean,
    /// ChartThemeDark
    /// ChartThemeBrownSand
    /// ChartThemeBlueNcs
    /// ChartThemeHighContrast
    /// ChartThemeBlueIcy
    /// ChartThemeQt
    QChart::ChartTheme theme = QChart::ChartThemeDark;


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTheme(theme);

    ///set palette colors based on selected theme
    QPalette pal = qApp->palette();
            if (theme == QChart::ChartThemeLight) {
                pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
                pal.setColor(QPalette::WindowText, QRgb(0x404044));
            //![8]
            } else if (theme == QChart::ChartThemeDark) {
                pal.setColor(QPalette::Window, QRgb(0x121218));
                pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
            } else if (theme == QChart::ChartThemeBlueCerulean) {
                pal.setColor(QPalette::Window, QRgb(0x40434a));
                pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
            } else if (theme == QChart::ChartThemeBrownSand) {
                pal.setColor(QPalette::Window, QRgb(0x9e8965));
                pal.setColor(QPalette::WindowText, QRgb(0x404044));
            } else if (theme == QChart::ChartThemeBlueNcs) {
                pal.setColor(QPalette::Window, QRgb(0x018bba));
                pal.setColor(QPalette::WindowText, QRgb(0x404044));
            } else if (theme == QChart::ChartThemeHighContrast) {
                pal.setColor(QPalette::Window, QRgb(0xffab03));
                pal.setColor(QPalette::WindowText, QRgb(0x181818));
            } else if (theme == QChart::ChartThemeBlueIcy) {
                pal.setColor(QPalette::Window, QRgb(0xcee7f0));
                pal.setColor(QPalette::WindowText, QRgb(0x404044));
            } else {
                pal.setColor(QPalette::Window, QRgb(0xf0f0f0));
                pal.setColor(QPalette::WindowText, QRgb(0x404044));
            }

    qApp->setPalette(pal);


    w.setCentralWidget(chartView);
    w.resize(400, 350);
    w.show();
    return a.exec();
}
