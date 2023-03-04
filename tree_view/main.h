#pragma once

#include <QTreeView>
#include <QFileSystemModel>
#include <QTreeWidgetItem>

class TreeView : public QTreeView
{
Q_OBJECT
public:
    TreeView();

private:
    QFileSystemModel *model;

private slots:
    void handleItemClicked(QModelIndex index);
};