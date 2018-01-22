#include "NewFileWidget.h"
#include "QLineEdit.h"
#include "QPushButton.h"
#include "QLabel.h"

NewFileWidget::NewFileWidget(QWidget *parent) : QToolBar(parent)
{
   label = new QLabel(QString("File "),this);
   lineEdit = new QLineEdit(this);
   confirm = new QPushButton(QString("Confirm"),this);
   cancel = new QPushButton(QString("Cancel"),this);

   addWidget(label);
   addSeparator();
   addWidget(lineEdit);
   addWidget(confirm);
   addWidget(cancel);

   confirm->setAutoDefault(true);
   confirm->setDefault(true);

   setAllowedAreas(Qt::BottomToolBarArea);
   setMovable(false);
   setVisible(false);
}

std::string NewFileWidget::getText() const
{
   std::string name = lineEdit->text().toStdString();

   if (name.empty())
      return "NewFile";

   return name;
}

void NewFileWidget::clearEdit()
{
   lineEdit->clear();
}


NewFileWidget::~NewFileWidget()
{
   delete label;
   delete lineEdit;
   delete confirm;
}
