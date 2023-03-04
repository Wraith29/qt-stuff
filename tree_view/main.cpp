#include <iostream>

#include <QTreeView>
#include <QFileSystemModel>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTreeWidgetItem>

#include "main.h"

TreeView::TreeView()
{
    model = new QFileSystemModel;
    model->setRootPath("/home/iacna/src/qt");

    setModel(model);
    setRootIndex(model->index("/home/iacna/src/qt"));
    for (auto i = 1; i <= model->columnCount(); i++)
        setColumnHidden(i, true);

    connect(
        this,
        SIGNAL(clicked(QModelIndex)),
        SLOT(handleItemClicked(QModelIndex))
    );
}

void TreeView::handleItemClicked(QModelIndex index)
{
    auto fp = model->filePath(index);
    std::cout << fp.toStdString() << std::endl;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow mw;
    mw.setGeometry(QRect {1100, 90, 500, 900});
    auto cw = new QWidget;
    auto layout = new QVBoxLayout;
    cw->setLayout(layout);

    auto tree = new TreeView;

    layout->addWidget(tree);

    mw.setCentralWidget(cw);

    mw.show();
    return app.exec();
}