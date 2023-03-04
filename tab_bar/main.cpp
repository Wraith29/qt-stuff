#include <string>
#include <QApplication>
#include <QMainWindow>
#include <QRect>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>

#include "main.h"

Page::Page()
{
    setLayout(new QVBoxLayout);
    layout()->addWidget(new QLabel("Label"));
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow mw;
    mw.setGeometry(QRect {160, 90, 1600, 900});
    auto widget = new QWidget;
    auto layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);
    widget->setLayout(layout);

    auto tw = new QTabWidget;

    tw->addTab(new Page, "Hi");
    tw->addTab(new Page, "Hello");

    layout->addWidget(tw);

    mw.setCentralWidget(widget);
    mw.show();
    return app.exec();
}