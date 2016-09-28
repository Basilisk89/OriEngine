#pragma once
class BaseManager
{
public:
	BaseManager();
	~BaseManager();
	BaseManager* getManager();

private:
	BaseManager* managerInstance;
};

