#include "CmdClearLastItem.h"
#include "Item.h"
#include "QGraphicsItem"

void CmdClearLastItem::execute(Data& d, MainScreen& s)
{
   if (d.getItens()->size() > 0)
   {
      delete d.getItens()->back();
      d.getItens()->pop_back();
   }
   
   if (s.getView()->getItems()->size() > 0)
   {
      delete s.getView()->getItems()->back();
      s.getView()->getItems()->pop_back();
   }

   s.getView()->getScene()->update();
}