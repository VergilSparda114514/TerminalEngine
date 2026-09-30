#pragma once

template <typename T>
class Singleton
{
public:
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;

	static T& Get()
	{
		static T instance;
		return instance;
	}

	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;
private:
	Singleton() = default;
	~Singleton() = default;
};