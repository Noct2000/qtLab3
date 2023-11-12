#ifndef CUSTOMSIZEDELEGATE_H
#define CUSTOMSIZEDELEGATE_H

#include <QStyledItemDelegate>
#include <QComboBox>

class CustomSizeDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CustomSizeDelegate(QObject *parent = nullptr);

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};

#endif // CUSTOMSIZEDELEGATE_H
