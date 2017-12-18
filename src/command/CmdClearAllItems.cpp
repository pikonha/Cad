#include "CmdClearAllItems.h"
#include "QGraphicsItem"
#include "Item.h"

void CmdClearAllItems::execute(Data& d, MainScreen& s)
{
   std::deque<Item*>* itens = d.getItens();
   std::deque<QGraphicsItem*> * items = s.getView()->getItems();

   while (itens->size() > 0) {
      delete itens->at(0);
      itens->pop_front();
   }

   while (items->size() > 0) {
      delete items->at(0);
      items->pop_front();
   }

	itens->clear();
	s.getView()->getScene()->clear();
}