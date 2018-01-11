#pragma once
#ifndef INCLUDED_CMDSAVE_H
#define INCLUDED_CMDSAVE_H

#include "Cmd.h"

class Line;
class Arch;
class Bezier;


class CmdSave : public Cmd
{
   void saveLine(std::ofstream& stream,Line& line);
   void saveBezier(std::ofstream& stream,Bezier& bezier);
   void saveArch(std::ofstream& stream,Arch& arch);
public:
	CmdSave(){}
	~CmdSave() {}

	void execute(Data& d, MainScreen& s) override;
};

#endif
