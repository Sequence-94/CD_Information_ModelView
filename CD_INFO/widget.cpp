#include "widget.h"
#include<QGridLayout>
#include<QLabel>
#include <QHeaderView>
#include<QModelIndexList>
#include<QMessageBox>
#include"bardelegate.h"
#include<QPainter>
#include<QStyleOptionProgressBar>


Widget::Widget(QWidget *parent)
    :
    QWidget(parent),composerInput(new QLineEdit),
    titleInput(new QLineEdit),replacementInput(new QDoubleSpinBox),
    ratingInput(new QSpinBox),addButton(new QPushButton("Add")),
    deleteButton(new QPushButton("Delete")),model(new CDModel),view(new QTableView)
{
    CDGui();
    setWindowTitle("Music");
    setFixedSize(650,400);

    replacementInput->setRange(0,9999);
    ratingInput->setRange(0,100);


}

Widget::~Widget() {}

void Widget::handleAddButtonClicked()
{

    QString composer = composerInput->text();
    QString title = titleInput->text();
    double replacementValue = replacementInput->value();
    int rating = ratingInput->value();


    model->addAlbum(composer, title, replacementValue, rating);

    // Erase input
    composerInput->clear();
    titleInput->clear();
    replacementInput->setValue(0.00);
    ratingInput->setValue(0);
}

void Widget::handleDeleteButtonClicked()
{
    QModelIndexList selectedIndex = view->selectionModel()->selectedRows();
    if(!selectedIndex.isEmpty()){
        model->deleteAlbum(selectedIndex);
    }
    else{
        QMessageBox::warning(this, "Warning", "No row selected.");
    }
}



void Widget::CDGui()
{
    QGridLayout *layout(new QGridLayout(this));
    QLabel *composerLabel(new QLabel("Composer"));
    QLabel *titleLabel(new QLabel("Album title"));
    QLabel *replacementLabel(new QLabel("Replacement cost (R)"));
    QLabel *ratingLabel(new QLabel("Rating"));



    layout->addWidget(composerLabel,0,0);
    layout->addWidget(titleLabel,0,1);
    layout->addWidget(replacementLabel,0,2);
    layout->addWidget(ratingLabel,0,3);


    layout->addWidget(composerInput,1,0);
    layout->addWidget(titleInput,1,1);
    layout->addWidget(replacementInput,1,2);
    layout->addWidget(ratingInput,1,3);
    layout->addWidget(addButton,1,4);

    //the view
    view->setModel(model);

    // last header stretch
    view->horizontalHeader()->setStretchLastSection(true);

    //sort by clicking header
    view->setSortingEnabled(true); // Enable sorting by clicking on the header

    //allow edting of column 2
    view->setEditTriggers(QTableView::DoubleClicked| QTableView::EditKeyPressed);

    //show the delegate
    BarDelegate *delegate = new BarDelegate(this);

    view->setItemDelegateForColumn(3,delegate);


    layout->addWidget(view,2,0,1,5);

    layout->addWidget(deleteButton,3,4);

    connect(addButton, &QPushButton::clicked, this, &Widget::handleAddButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &Widget::handleDeleteButtonClicked);
    connect(model,&CDModel::costExceeded, this, &Widget::changeRowColor);


}
