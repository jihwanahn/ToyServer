﻿#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>

void HelloThread()
{
	cout <<  "Hello Thread" << endl;
}

void HelloThread_2(int32 num)
{
	cout << num << endl;
}

int main()
{
	std::thread t;
	
	//int32 count = t.hardware_concurrency();
	//auto id = t.get_id();

	vector<std::thread> v;
	
	for (int32 i = 0; i < 10; i++)
	{
		v.push_back(std::thread(HelloThread_2, i));
	}

	for (int32 i = 0; i < 10; i++)
	{
		if (v[i].joinable())
			v[i].join();
	}

	cout << "Hello Main" << endl;
}