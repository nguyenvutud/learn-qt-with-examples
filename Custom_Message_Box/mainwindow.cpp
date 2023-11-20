#include <QDebug>
#include "custom_dialog.h"
#include "mainwindow.h"
#include "form.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    dialog = new CustomDialog(this);
    dialog->setPureGeometry(QRect(100, 100, 300, 100));
    dialog->setRelativePosition(this->pos());
    dialog->setButtonName("End program","");
    //dialog->visibleClosingButton(false);
    //dialog->setTitle("Are you sure you want \n to quit the application?");
    dialog->setTitle("Testing?");
    dialog->setText("Do you want to stop the program?");
    dialog->setDisplayTime(10);
    dialog->setBackground("");//QFrame#frameDialog{background-color: #f2f2f2;}
    if(dialog->showDialog(false) == QDialog::Accepted)
    {
        qInfo() << "Chose accepted!";
    }
    else
    {
        qInfo() << "Chose cancel!";
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    Form* form = new Form();
    form->setWindowFlag(Qt::FramelessWindowHint);
    form->show();

}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_Diff = event->pos();
    setCursor(QCursor(Qt::SizeAllCursor));

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(QCursor(Qt::ArrowCursor));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos();
    window()->move(p - m_Diff);
    qInfo() << "Mouse moved";
    if(dialog)
    {
        dialog->setRelativePosition(this->pos());
        qInfo() << "Geometry: x =" << QString::number(this->geometry().x()) << " y=" << QString::number(this->geometry().x());
        qInfo() << "POS: x =" << QString::number(this->pos().x()) << " y=" << QString::number(this->pos().x());
    }
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event){

//    if(event->type() == QEvent::Move)
//    {
//        dialog->setGeometry(QRect(this->geometry().x()+100, this->geometry().y()+100, 300, 100));
//        qInfo() << "Mouse is moving ";
//    }
//    else{
//        qInfo() << "Event type:" ;//<< QString::number(event->type());
//    }
//    return QMainWindow::eventFilter(watched, event);
}
