#include "CmdSetZoom.h"
#include "Bezier.h"
#include "Arch.h"

Point CmdSetZoom::getNewPoint(Point p, int oldScale)
{
   int x = p.x * scale / oldScale;
   int y = p.y * scale / oldScale;

   return Point(x,y);
}

void CmdSetZoom::execute(Data& d, MainScreen& s)
{
   int oldScale = d.getCurrentFile()->getView()->getScale();

    for ( auto g : d.getCurrentFile()->getGeos())
    {
       d.getCurrentFile()->getView()->eraseGeo(*g);

       g->setP1(getNewPoint(g->getP1(),oldScale));
       g->setP2(getNewPoint(g->getP2(),oldScale));

       if (Bezier* b = dynamic_cast<Bezier*>(g)) {
          b->setP3(getNewPoint(b->getP3(),oldScale));
          d.getCurrentFile()->getView()->draw(*b);
       }

       if (Arch* a = dynamic_cast<Arch*>(g)) {
          a->setP3(getNewPoint(a->getP3(),oldScale));
          d.getCurrentFile()->getView()->draw(*a);
       }

       else
          d.getCurrentFile()->getView()->draw(*g);
    }  

    d.getCurrentFile()->setSaved(false);
    d.getCurrentFile()->getView()->setScale(scale);
}
