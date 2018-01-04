#include "CmdSetCurrentFile.h"

void CmdSetCurrentFile::execute(Data& d, MainScreen& s)
{
   d.setCurrentFile(file);
}
