#pragma once


int Fibonacci(int i)
{
	if (i < 2)
	{
		return i == 0 ? 0:1;
	}
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}