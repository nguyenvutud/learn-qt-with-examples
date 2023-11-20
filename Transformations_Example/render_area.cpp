#include "render_area.h"
#include "ui_render_area.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RenderArea)
{
    ui->setupUi(this);
}

RenderArea::~RenderArea()
{
    delete ui;
}

