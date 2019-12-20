#include <string>
#include <iostream>

//基类
class CBeverage
{
public:
	CBeverage() 
	{
		strDesc_ = "unknow Beverage";
	}
	~CBeverage() {}

	std::string getDescription()
	{
		return strDesc_;
	}
	virtual double cost()
	{
		return 0;
	};
private:
	std::string strDesc_;

};

//调料
class Condiment :public CBeverage
{
public:
	Condiment()
	{
		strDesc_ = "Condiment";
	}
	~Condiment() {}

	std::string getDescription()
	{
		return strDesc_;
	}
	
private:
	std::string strDesc_;
};
