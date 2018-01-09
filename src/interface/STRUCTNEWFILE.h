#pragma once
#ifndef INCLUDED_STRUCTNEWFILE_H
#define INCLUDED_STRUCTNEWFILE_H

#include <string>

struct STRUCTNEWFILE
{
   int dialogExec;
   std::string name;
   int width;
   int height;

   STRUCTNEWFILE(int exec, std::string n, int w, int h)
   {
      dialogExec = exec;

      if (n.size() > 0)
         name = n;
      else
         name = "NewFile";

      if (w >= 0 && w <= 1920 && h >= 0 && h <= 1080) {
         width = w;
         height = h;
      }
      else {
         width = 600;
         height = 800;
      }

      
   }
};

#endif