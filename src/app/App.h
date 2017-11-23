#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#include "Cmd.h"
#include "CmdNew.h"
#include "CmdSave.h"
#include "CmdZoom.h"
#include "CmdLoad.h"
#include "CmdClear.h"
#include "CmdClose.h"
#include "CmdDrawLine.h"
#include "CmdDrawArch.h"
#include "CmdMouseMove.h"
#include "CmdDrawBezier.h"
#include "CmdMouseClick.h"
#include "CmdMousePress.h"
#include "CmdSetStatusBar.h"


class App
{
	static App* app;
	Cmd* cmd;

public:

	static App* getInstance();
	void start();
};

#endif 