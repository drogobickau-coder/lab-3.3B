#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-3.3B/FuzzyNumber.h"

#include "../lab-3.3B/Triad.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSubtraction)
		{

			FuzzyNumber a(10.0, 2.0, 3.0); 
			FuzzyNumber b(5.0, 1.0, 2.0);  

			
			FuzzyNumber c = a - b;

			
			Assert::AreEqual(5.0, c.getFirst());   
			Assert::AreEqual(3.0, c.getSecond());  
			Assert::AreEqual(5.0, c.getThird());   
		}

		TEST_METHOD(TestDivision)
		{
	
			FuzzyNumber a(10.0, 2.0, 2.0); 
			FuzzyNumber b(2.0, 1.0, 1.0);  

		
			FuzzyNumber c = a / b;

	

			Assert::AreEqual(5.0, c.getFirst());
			Assert::AreEqual(5.0 - (8.0 / 3.0), c.getSecond(), 0.001); 
			Assert::AreEqual(7.0, c.getThird());
		}

		TEST_METHOD(TestComparison)
		{
		
			FuzzyNumber a(10.0, 2.0, 3.0);
			FuzzyNumber b(5.0, 1.0, 2.0);
			FuzzyNumber c(10.0, 1.0, 3.0);

			
			Assert::IsTrue(a > b);
			Assert::IsTrue(b < a);
			Assert::IsTrue(a > c); 
			Assert::IsFalse(a == b);
		}
	};
}