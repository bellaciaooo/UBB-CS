#pragma once
class ActiuneUndo
{
public:
	virtual void DoUndo() = 0;
	virtual ~ActiuneUndo() {}
};