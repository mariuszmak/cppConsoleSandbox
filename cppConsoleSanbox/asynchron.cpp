#include "pch.h"
#include <future>
#include <iostream>
#include <thread>


// Async
//==============================
int foo() {
	std::cout << "Foo is going to sleep.... " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	std::cout << "Foo woke up..... " << std::this_thread::get_id() << std::endl;
	return 1000;
}

void tryAsync() {
	auto handle = std::async(std::launch::async, foo);
	std::cout << "\ntryAsynch - Getting future value..." << std::endl;
	auto result = handle.get();
	std::cout << "\ntryAsynch - Got future value=" << result << std::endl;

	auto promise = std::promise<std::string>();

	auto producer = std::thread([&]
	{
		std::cout << "\nProducer - sleeping..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
		std::cout << "\nProducer - setting..." << std::endl;
		promise.set_value("Hello World");
		std::cout << "\nProducer - exitting..." << std::endl;
	});

	auto future = promise.get_future();

	auto consumer = std::thread([&]
	{
		std::cout << "Consumer getting... " << std::endl;
		std::string a = future.get();
		const char* aa = a.c_str();
		std::cout << "Consumer got... " << aa << std::endl;
	});

	producer.join();
	consumer.join();
}

