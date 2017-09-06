#include "Dialog.hpp"
#include "ui_Dialog.h"

#include "DrawableItem.hpp"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    auto drawable = new DrawableItem();
    drawable->setSize({300, 300});
    auto scene = new QGraphicsScene(this);
    scene->addItem(drawable);
    ui->graphicsView->setScene(scene);
}

Dialog::~Dialog()
{
    delete ui;
}
