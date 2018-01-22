#ifndef NEWFILESTATUSBAR_H
#define NEWFILESTATUSBAR_H

#include <QToolBar>
#include <QLineEdit>
class QLabel;
class QPushButton;

class NewFileWidget : public QToolBar
{
public:
   ~NewFileWidget();
   NewFileWidget(QWidget *parent = 0);   

   QLabel* label;
   QLineEdit* lineEdit;   
   QPushButton* confirm;
   QPushButton* cancel;

   std::string getText() const;

   void clearEdit();

};

#endif
