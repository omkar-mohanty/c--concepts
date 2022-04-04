// c++-concepts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<future>
void f(std::promise<int>& x) {
	try
	{
		x.set_value(100);
	}
	catch (const std::exception&)
	{
		x.set_exception(std::current_exception());
	}
}
int packaged_task_task(int a) {
	int ret = 100 * a;
	return ret;
}
void packaged_task_demo() {
	using Task_type = int(int);
	std::packaged_task<Task_type> p0{ packaged_task_task };
	std::packaged_task<Task_type> p1{ packaged_task_task };
	std::future<int> f1{ p0.get_future() };
	std::future<int> f2{ p1.get_future() };
	std::thread t1{std::move(p0),12 };
	std::thread t2{ std::move(p1),14 };
	std::cout << "\nF1 value: " << f1.get() << "\nF2 value: " << f2.get() << "\n";
	t1.join();
	t2.join();
}
int async_demo(int a) {
    int b = 10 * a;
    return b;
}
int main()
{
    auto f1 = std::async(async_demo, 100);
    std::cout << f1.get();
	packaged_task_demo();
}
