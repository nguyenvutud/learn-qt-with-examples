#include <QDebug>

#include "countdown_dialog.h"
#include "ui_countdown_dialog.h"

CountDownDialog::CountDownDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CountDownDialog)
{
    ui->setupUi(this);
}

CountDownDialog::~CountDownDialog()
{
    delete ui;
}

void CountDownDialog::start(int count)
{
    qInfo() << "Count down from: " << count;
    timer = new QTimer(this);
    m_count = count;
    connect(timer, SIGNAL(timeout()), this, SLOT(countDown()));
    timer->start(1000);
    QString imageFile = QString(":/images/numData/%1.png").arg(m_count);
    setImage(imageFile);
}

void CountDownDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CountDownDialog::countDown()
{
    m_count -= 1;
    if (m_count < 0)
    {
        timer->stop();
        this->close();
    }
    QString imageFile = QString(":/images/numData/%1.png").arg(m_count);
    if (m_count < 1)
        imageFile = QString(":/images/numData/start.png");
    setImage(imageFile);
}

void CountDownDialog::setImage(QString path)
{
    QPixmap pixmap(path);
    ui->lblDisplay->setPixmap(pixmap);
    ui->lblDisplay->setScaledContents(true);
    ui->lblDisplay->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}
