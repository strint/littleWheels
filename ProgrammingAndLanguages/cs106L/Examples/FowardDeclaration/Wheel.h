#pragma once
class Car; //前置声明
class Wheel
{
private:
	int id;
	static int count;
public:
	Wheel(void);
	~Wheel(void);
	void Run();

	Car * car; //使用类指针
};

