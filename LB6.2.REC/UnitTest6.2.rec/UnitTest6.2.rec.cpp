#include "pch.h"
#include "CppUnitTest.h"
#include "../LB6.2.REC/MAIN.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rec
{
	TEST_CLASS(UnitTest62rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int SIZE = 5;
			int arr[SIZE] = { 6, 7, 8, 9, 10 };

			int expectedSum = 6 + 8 + 10 + 7 + 9; 
			int result = sum(arr, SIZE, 0, 0);
			Assert::AreEqual(expectedSum, result);
		}
	};
}
