#include "widget.h"
#include<QGridLayout>
#include<QLabel>
#include <QHeaderView>


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
    // Retrieve data from line edits
    QString composer = composerInput->text();
    QString title = titleInput->text();
    double replacementValue = replacementInput->value();
    int rating = ratingInput->value();

    // Pass data to the addAlbum function in CDModel
    model->addAlbum(composer, title, replacementValue, rating);
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


    layout->addWidget(view,2,0,1,5);

    layout->addWidget(deleteButton,3,4);

    connect(addButton, &QPushButton::clicked, this, &Widget::handleAddButtonClicked);


}
