#include "MainView.h"
#include "Arch.h"
#include "QWidget"
#include "Line.h"
#include "Bezier.h"
#include "QPixmap"
#include "MainScreen.h"
#include <QFileDialog>
#include <QFile>

MainView::MainView()
{
	firstClick = true;
	auxDraw =  drawingArch = false;
	shape = LINE;
	currentItem = new Line();

	setMinimumSize(1920, 1020);
	showMaximized();

	scene = new QGraphicsScene(this);
	setScene(scene);

	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}


std::string MainView::getCurrentShape()
{
	switch (shape)
	{
	case LINE: return "Line";
	case BEZIER: return "Bezier";
	case ARCH: return "Arc";
	}
}

void MainView::saveFile()
{
	QString file = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("Draw (*.png);; All files(*)"));

	if (file.isEmpty())
		return;
	
	QFile outFile(file);
	map = grab();
	map.save(file);
	
}

void MainView::openFile()
{
	/*QString file = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Draw (*.png);; All files(*)"));

	if (file.isEmpty())
		return;

	QFile inFile(file);
	
	inFile.open(QIODevice::WriteOnly | QIODevice::Append);

	map = grab();
	map.load(file);

	scene->update();*/
}


void MainView::clearItens()
{
	itens.clear();
}

void MainView::clearLastItem()
{
	if (itens.empty())
		return;

	scene->removeItem(itens.back());
	itens.pop_back();
	scene->update();	
}


void MainView::draw()
{
	if (currentItem)
		delete currentItem;

	if (shape == LINE)
		currentItem = new Line(x, y);
	
	else if (shape == BEZIER) 
		currentItem = new Bezier(x, y, z);
		
	else if (shape == ARCH)
		currentItem = new Arch(x,y,z);

	scene->addItem(currentItem);
	scene->update();
}

void MainView::drawAuxiliarLine() {	
	
	if (auxDraw) {
		scene->removeItem(auxLine);
	}

	auxLine = new Line(x, y);
	scene->addItem(auxLine);
	scene->update();

	auxDraw = true;	
}

void MainView::mousePressEvent(QMouseEvent* event)
{
	if ( currentItem )
		delete currentItem;	

	if (shape == LINE)
		currentItem = new Line();

	if (shape == BEZIER)
		currentItem = new Bezier();

	if (shape == ARCH)
		currentItem = new Arch();


	if (firstClick) {
		x = event->pos();

		if ( shape != LINE)
			firstClick = false;
	}
	else
	{
		if (shape == BEZIER)
		{
			z = event->pos();	
			auxDraw = false;

			scene->removeItem(auxLine);

		}
		
		draw();
		itens.push_back(currentItem);
		currentItem = nullptr;
		drawingArch = false;

		firstClick = true;
	}

	if (currentItem) 
		setMouseTracking(true);

	else
		setMouseTracking(false);

	event->accept();
}

void MainView::mouseReleaseEvent(QMouseEvent* event)
{
	auxDraw = false;
	setMouseTracking(false);

	if ( shape == LINE ) {
		itens.push_back(currentItem);
		currentItem = nullptr;
	}

	if (shape == ARCH && currentItem && !firstClick) {
		drawingArch = true;
		setMouseTracking(true);
	}

	event->accept();
}

void MainView::mouseMoveEvent(QMouseEvent* event)
{
	if (!currentItem)
		return;

	if ( !drawingArch)
		y = event->pos();

	
	if (shape == LINE)
		draw();

	else if (!drawingArch)
		drawAuxiliarLine();

	if (drawingArch) {	

		z = event->pos();

		scene->removeItem(auxLine);

		draw();
	}
	
	event->accept();
}

void MainView::wheelEvent(QWheelEvent* event)
{
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	double scaleF = 1.15;

	if (event->delta() > 0)
		scale(scaleF, scaleF);
	else
		scale(1 / scaleF, 1 / scaleF);

	event->accept();
}














