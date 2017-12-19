#include "CmdClearAllItems.h"
#include "QGraphicsItem"
#include "Geometry.h"

void CmdClearAllItems::execute(Data& d, MainScreen& s)
{
   std::deque<Geometry*>& allGeos = d.getGeometries();
   std::deque<QGraphicsItem*>& models = s.getView()->getItems();

   while (allGeos.size() > 0) {
      delete allGeos.at(0);
      allGeos.pop_front();
   }

   while (models.size() > 0) {
      delete models.at(0);
      models.pop_front();
   }
   	
	s.getView()->getScene()->clear();
}