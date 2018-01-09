#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include "File.h"

class Data
{
   std::vector<File*> files;

   File* currentFile;

public:
   /////FILE
   void setCurrentFile(File* file);

   File* getCurrentFile(){ return currentFile; }

   void addFIle(File* file) { files.push_back(file); }

   void deleteFile(File* file) { delete file; files.clear(); }

   std::vector<File*> getFiles() const { return files; }   

   void deleteAllFiles();

   File* getFileByView(View* view);
};

#endif