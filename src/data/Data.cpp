#include "Data.h"

void Data::setCurrentFile(File* file)
{ 
   currentFile = file; 
}

void Data::deleteAllFiles()
{
   for (int i = 0; i < files.size(); i++)
      delete files[i];

   files.clear();
}
