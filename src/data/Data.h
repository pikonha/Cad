#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <vector>
#include "File.h"
#include "Geometry.h"

class Data
{
   std::vector<File*> files;

   File* currentFile;
public:
	~Data() {}
	Data() {  }

	/////ITENS	
	void clearGeometries();
	std::vector<Geometry*> getCurrentGeometries() { return currentFile->getGeos(); }
	Geometry* getLastGeometry() { return currentFile->getGeos().back(); }

   /////FILE
   void setCurrentFile(File* file) { currentFile = file; }
   File* getCurrentFile() const { return currentFile; }
   void deleteFile(File* file) { delete file; files.clear(); }
   std::vector<File*> getFiles() const { return files; }   
};

#endif