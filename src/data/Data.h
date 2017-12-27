#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <vector>
#include "File.h"
#include "FormType.h"
#include "Geometry.h"

class Data
{
	FormType currentForm;

   std::vector<File*> files;

   File* currentFile;
public:
	~Data() {  }
	Data() { currentForm= LINE; }

	/////FORM
	FormType getForm() { return currentForm; }
	void setForm(const FormType fType) { currentForm = fType; }

	/////ITENS	
	void addGeometry(Geometry* geo) { currentFile->getGeos().push_back(geo); }
	void clearGeometries();
	std::vector<Geometry*> getCurrentGeometries() { return currentFile->getGeos(); }
	Geometry* getLastGeometry() { return currentFile->getGeos().back(); }

   /////FILE
   void setCurrentFile(File* file) { currentFile = file; }
   File* getCurrentFile() { return currentFile; }

   std::vector<File*> getFiles() const { return files; }

   void deleteFile(File* file) { delete file; files.clear(); }
};

#endif