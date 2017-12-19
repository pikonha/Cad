#include "CmdClearLastItem.h"
#include "Geometry.h"
#include "QGraphicsItem"

void CmdClearLastItem::execute(Data& d, MainScreen& s)
{
   std::deque<QGraphicsItem*>& models = s.getView()->getItems();
   std::deque<Geometry*>& allGeos = d.getGeometries();


   if (models.size() > 0)
   {
      s.getView()->getScene()->removeItem( models.back() );

      allGeos.pop_back();

      delete models.back();
      models.pop_back();

      s.getView()->getScene()->update();
   }   
}