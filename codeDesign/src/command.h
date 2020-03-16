#pragma once
#include <string>
#include <iostream>

using namespace std;

class CCommand
{
public:
	CCommand() {};
	~CCommand() {};

	virtual void Execute() = 0;

};

class CLight
{
public:
	CLight() {};
	~CLight() {};
	void LightOn()
	{
		cout << "light on" << endl;
	}
	void LightOff()
	{
		cout << "Light off" << endl;
	}
};

class CLightOnCommand :public CCommand
{
public:
	CLightOnCommand(CLight *light)
	{
		light_ = light;
	}

	~CLightOnCommand() {};

	virtual void Execute()
	{
		light_->LightOn();
	}

private:
	CLight *light_;
};

class CButton
{
public:
	CButton() {};
	~CButton() {};

	void SetCommand(CCommand *command)
	{
		command_ = command;
	}

	void Press()
	{
		command_->Execute();
	}
private:
	CCommand * command_;
};
