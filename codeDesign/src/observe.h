#include <string>
#include <iostream>
#include <vector>


class CObservers
{
public:
	CObservers() {}
	~CObservers() {}
	virtual void update() = 0;
};

class WeatherData
{
public:
	WeatherData()
	{
	}
	~WeatherData() {}
	void registerObserver(CObservers *o) {
		observers_.push_back(o);
	}
	void removeObserver(CObservers *o) {
		std::vector<CObservers*>::iterator iter = observers_.begin();
		for (; iter != observers_.end(); iter++) {
			if (*iter != o)
			{
				iter = observers_.erase(iter);
			}
		}
	}
	void notifyObserver()
	{
		for (std::vector<CObservers*>::iterator iter = observers_.begin(); iter != observers_.end(); iter++)
		{
			(*iter)->update();
		}
	}
private:
	std::vector<CObservers*> observers_;

};
