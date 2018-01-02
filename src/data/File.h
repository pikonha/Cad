#pragma once
#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H

#include <vector>
#include <string>
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
   ~File() { deleteAllGeos(); }
   File(const std::string name) : name(name), isSaved(false) {}

   /////SAVED
   bool getSaved() const { return isSaved; }
   void setSaved(const bool status) { isSaved= status; }
   
   /////NAME
   std::string getName() const { return name; }
   void setName(const std::string n) { name = n; }
   
   /////PATH
   void setPath(std::string p) { path = p; }
   std::string getPath() { return path; }

   /////GEOMETRIES
   void deleteAllGeos();
   void addGeo(Geometry* geo) { geometries.push_back(geo); }
   std::vector<Geometry*> getGeos() const { return geometries; }
};

#endif