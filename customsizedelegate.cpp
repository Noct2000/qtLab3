#include "customsizedelegate.h"

CustomSizeDelegate::CustomSizeDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget* CustomSizeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2) {
        QComboBox *editor = new QComboBox(parent);
        editor->addItem("4");
        editor->addItem("6");
        editor->addItem("10");
        editor->addItem("12");
        return editor;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void CustomSizeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 2) {
        QComboBox *comboBox = qobject_cast<QComboBox*>(editor);
        if (comboBox) {
            const QString value = index.model()->data(index, Qt::EditRole).toString();
            int currentIndex = comboBox->findText(value);
            if (currentIndex == -1) {
                currentIndex = 0; // Default to the first item if not found
            }
            comboBox->setCurrentIndex(currentIndex);
        }
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void CustomSizeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == 2) {
        QComboBox *comboBox = qobject_cast<QComboBox*>(editor);
        if (comboBox) {
            const QString value = comboBox->currentText();
            model->setData(index, value, Qt::EditRole);
        }
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}
