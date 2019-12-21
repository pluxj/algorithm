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

	virtual std::string getDescription()
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

//调料装饰器
class CondimentDecorator :public CBeverage
{
public:
	CondimentDecorator()
	{
		strDesc_ = "Condiment";
	}
	~CondimentDecorator() {}

	virtual std::string getDescription() = 0;
	
private:
	std::string strDesc_;
};

//Espress 饮料
class Espress : public CBeverage
{
public:
	Espress()
	{
		strDesc_ = "Espress";
	}
	~Espress() {}
	
	virtual std::string getDescription()
	{
		return strDesc_;
	}
	virtual double cost()
	{
		return 1.99;
	}
private:
	std::string strDesc_;
};

//HouseBlend 饮料
class HouseBlend:public CBeverage
{
	public:
	HouseBlend()
	{
		strDesc_ = "Mocha";
	}
	~HouseBlend() {}

	virtual std::string getDescription()
	{
		return strDesc_;
	}
	virtual double cost()
	{
		return 0.99;
	}
	private:
	std::string strDesc_;
};

//mocha 调料
class Mocha :public CondimentDecorator
{
public:
	Mocha(CBeverage *beverage)
	{
		pbeverage_ = beverage;
	}
	~Mocha (){

	}
	virtual std::string getDescription()
	{
		return pbeverage_->getDescription() + ",Mocha";
	}
	virtual double cost()
	{
		return 0.20 + pbeverage_->cost();
	}


private:
	CBeverage *pbeverage_;
};






