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

   bool getSaved() const { return isSaved; }
   void setSaver(const bool status) { isSaved= status; }
   
   std::string getName() const { return name; }
   void setName(const std::string n) { name = n; }

   void setPath(std::string p) { path = p; }
   std::string getPath() { return path; }

   void deleteAllGeos();
   std::vector<Geometry*> getGeos() const { return geometries; }
};

#endif