#pragma once
#ifndef INCLUDED_CMD_H
#define INCLUDED_CMD_H


class Cmd {
public:
	Cmd();
	virtual ~Cmd();

	virtual void execute() = 0;
};

#endif