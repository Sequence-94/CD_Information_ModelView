#ifndef WIDGET_H
#define WIDGET_H
#include"cdmodel.h"
#include<QStandardItemModel>
#include<QTableView>
#include<QWidget>
#include<QLineEdit>
#include<QDoubleSpinBox>
#include<QSpinBox>
#include<QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void handleAddButtonClicked();
    void handleDeleteButtonClicked();
    void changeRowColor(int row,bool isGreaterThan200) const
    {
        if (isGreaterThan200) {
            // change to red
            QBrush redBrush(Qt::red);
            for (int i = 0; i < model->columnCount()-1; ++i) {
                model->item(row, i)->setBackground(redBrush);
            }
        } else{
            // change to white
            QBrush greenBrush(Qt::white);
            for (int i = 0; i < model->columnCount()-1; ++i) {
                model->item(row, i)->setBackground(greenBrush);
            }
        }
    }

private:
    void CDGui();
    CDModel *model;
    QTableView *view;
    QLineEdit *composerInput;
    QLineEdit *titleInput;
    QDoubleSpinBox *replacementInput;
    QSpinBox *ratingInput;
    QPushButton *addButton;
    QPushButton *deleteButton;

};
#endif // WIDGET_H
