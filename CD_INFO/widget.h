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
