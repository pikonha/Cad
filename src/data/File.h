#pragma once
#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H

#include <vector>
#include "Geometry.h"

class File
{
   std::string name;
   std::string path;
   
   std::vector<Geometry*> geometries;

   bool isSaved;

   double width;
   double height;
public:
   ~File() {}
   File(const std::string name) : name(name), isSaved(false) {}

//   void addGeo(const Geometry& geo) { geometries.push_back(geo);  }

   bool getSaved() { return isSaved; }

   void load();
   void save();
   void saveAs();   
};

#endif