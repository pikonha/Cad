#pragma once
#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H

#include <vector>
#include <string>
#include "View.h"
#include "Geometry.h"

class Line;

class File
{
   std::string name;
   std::string path;
   
   std::vector<Geometry*> geometries;

   View* view;

   bool saved;
public:
   ~File() { deleteAllGeos(); }
   File(const std::string n, View* v) : name(n),saved(true) { view = v; }

   /////GETTERS AND SETTERS
   bool getSaved() const { return saved; }
   void setSaved(const bool status) { saved= status; }

   std::string getName() const { return name; }
   void setName(const std::string n) { name = n; }

   void setPath(std::string p) { path = p; }
   std::string getPath() const { return path; }

   std::vector<Geometry*> getGeos() const { return geometries; }
   Geometry* getLastGeometry(){ return geometries.back(); }

   View* getView() const { return view; }

   /////GEOMETRIES
   void deleteAllGeos();
   void addGeo(Geometry* geo);
   void removeGeo(Geometry* geo);

   /////DRAW
   void reprint();

};

#endif