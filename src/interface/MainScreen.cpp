#include "MainScreen.h"
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QTabWidget>
#include <QLabel>
#include <QShortcut>
#include <QFileDialog>
#include <QStatusBar>
#include <QMessageBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include "../manager/Manager.h"

MainScreen::~MainScreen()
{
   delete navbar;
   delete status;
   delete tabs;
}

MainScreen::MainScreen(QMainWindow* parent) : QMainWindow(parent), manager(nullptr)
{
	setFixedSize(1920, 1020);
   setWindowTitle(QString("AudacesCAD"));
	showMaximized();

	navbar = menuBar();	

   status = statusBar();
   status->show();

   tabs = new QTabWidget(this);
   setCentralWidget(tabs);
   tabs->setTabsClosable(true);

   connect(tabs,&QTabWidget::tabCloseRequested,this,&MainScreen::closeTab);

	QMenu* file = new QMenu("File");
	QAction* line = new QAction("Line");
	QAction* bezier = new QAction("Bezier");
	QAction* arc = new QAction("Arc");	
	
   QAction* newFile = new QAction("New");
	QAction* open = new QAction("Open");
	QAction* save = new QAction("Save");
	QAction* clear = new QAction("Clear");
	QAction* close = new QAction("Close");

   file->addAction(newFile);
	file->addAction(open);
	file->addAction(save);
	file->addAction(clear);
	file->addAction(close);

   QIcon* iconNew = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/new.png");
	QIcon* iconSave = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/save.png");
	QIcon* iconClear = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/clean.png");
	QIcon* iconClose = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/close.png");
	QIcon* iconOpen = new QIcon("C:/Users/lucas.picollo/Documents/Projects/QT- Setup/icons/open.png");

   newFile->setIcon(*iconNew);
	open->setIcon(*iconOpen);
	save->setIcon(*iconSave);
	clear->setIcon(*iconClear);
	close->setIcon(*iconClose);

	navbar->addMenu(file);
	navbar->addAction(line);
	navbar->addAction(bezier);
	navbar->addAction(arc);

	connect(line, &QAction::triggered, this, &MainScreen::startLineCommand);
	connect(bezier, &QAction::triggered, this, &MainScreen::startBezierCommand);
	connect(arc, &QAction::triggered, this, &MainScreen::startArchCommand);	

   connect(newFile,&QAction::triggered,this,&MainScreen::newFile);
	connect(open, &QAction::triggered, this,  &MainScreen::openFile);
	connect(save, &QAction::triggered, this,  &MainScreen::saveFile);
	connect(clear, &QAction::triggered, this, &MainScreen::clearAllItems);
	connect(close, &QAction::triggered, this, &MainScreen::close);

	QShortcut* undone = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
	connect(undone, &QShortcut::activated, this, &MainScreen::clearLastItem);

   QShortcut* saveSc = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S),this);
   connect(saveSc,&QShortcut::activated,this,&MainScreen::saveFile);
}

void MainScreen::start()
{
	show();
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::startLineCommand() const
{
   manager->startLineCommand();
}

void MainScreen::startBezierCommand() const
{
   manager->startBezierCommand();
}

void MainScreen::startArchCommand() const
{
   manager->startArchCommand();
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::newFile()
{
   manager->newFile();
}

void MainScreen::openFile()
{
   manager->openFile();
}

void MainScreen::saveFile()
{
   manager->saveFile();
}

////////////////////////////////////////////////////////////////////////////////

void MainScreen::clearAllItems()
{
	manager->clearAllItems();
}

void MainScreen::close()
{
   manager->closeFile();
   QMainWindow::close();
}

void MainScreen::clearLastItem()
{
	manager->clearLastItem();
}

std::string MainScreen::getSaveFileName()
{
   return QFileDialog::getSaveFileName(currentView,QString("Save File"),"",QString("Dat files (*.dat)")).toStdString();

}

std::string MainScreen::getLoadFileName()
{
   return QFileDialog::getOpenFileName(currentView,QString("Open file"),"",QString("Dat files (*.dat)")).toStdString();
}

void MainScreen::addTab(View* view, std::string name)
{
   tabs->addTab(view,QString::fromStdString(name));
   tabs->show();
}

void MainScreen::closeTab(int tab)
{
   if ( !dynamic_cast<View*>(tabs->widget(tabs->tabPosition()))->getFile().getSaved())
   {
      QMessageBox::warning(this,tr("Warning"),tr("Changes made in this file isn't saved. Do you really want to close?"),QMessageBox::Cancel,QMessageBox::Apply);
   }
      
}

void MainScreen::errorMessage()
{
   QMessageBox::warning(this,tr("Fatal error"),tr("An error occurred while processing your request."),QMessageBox::Ok);
}

void MainScreen::successMessage()
{
   QMessageBox::information(this,tr("Good news"),tr("Successful request."),QMessageBox::Ok);
}

void MainScreen::newFileDialog()
{
   QDialog dialog(this);
   QFormLayout form(&dialog);

   form.addRow(new QLabel("Set the file's size: "));

   QString hLabel = QString("Height");
   QLineEdit* hEdit = new QLineEdit(&dialog);
   form.addRow(hLabel,hEdit);

   QString wLabel = QString("Widht");
   QLineEdit* wEdit = new QLineEdit(&dialog);
   form.addRow(wLabel,wEdit);

   QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,Qt::Horizontal,&dialog);
   form.addRow(&buttonBox);

   connect(&buttonBox,SIGNAL(accepted()),&dialog,SLOT(accept()));
   connect(&buttonBox,SIGNAL(rejected()),&dialog,SLOT(reject()));

   dialog.show();
}

void MainScreen::setStatusMessage(Instruction in)
{
   switch (in)
   {
   case 0: status->showMessage("Waiting for a click on the screen."); break;
   case 1: status->showMessage("Keep pressed and move the cursor. (Release to finish)"); break;
   case 2: status->showMessage("Click to set the draw's length."); break;
   }
}
