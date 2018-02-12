#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/vector2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rodeo::math;

namespace rodeoTests
{
	TEST_CLASS(Vector2UnitTest)
	{
	public:

		typedef std::unique_ptr<Vector2> up;
		Vector2UnitTest()
			:_vec2(nullptr)
		{}

		// Testing Default Constructor
		TEST_METHOD(TestConstructorVector2)
		{
			_vec2 = up(new Vector2);
			Assert::AreEqual(0.0f, _vec2->getX());
			Assert::AreEqual(0.0f, _vec2->getY());
		}

		// Testing Constructor with two parameters
		TEST_METHOD(TestConstructorTwoParamsVector2)
		{
			_vec2 = up(new Vector2(-1.34f, 0.456f));
			Assert::AreEqual(-1.34f, _vec2->getX());
			Assert::AreEqual(0.456f, _vec2->getY());
		}

		// Testing Copy Constructor
		TEST_METHOD(TestCopyConstructorVector2)
		{
			_vec2 = up(new Vector2(-1.0f, 3.0f));
			up vec2 = up(new Vector2(*_vec2));

			Assert::AreEqual(-1.0f, vec2->getX());
			Assert::AreEqual(3.0f, vec2->getY());
		}

		// Testing length of a vector
		TEST_METHOD(TestVector2Length)
		{
			_vec2 = up(new Vector2(3.0f, 2.0f));
			Assert::AreEqual(3.6f, _vec2->length(), 0.5f);
		}

        // Testing Normalization of a vector
        TEST_METHOD(TestVector2Normalization)
        {
            _vec2 = up(new Vector2(3.0f, 2.0f));
            _vec2->normalize();

            Assert::AreEqual(0.8f, _vec2->getX(), 0.2f);
            Assert::AreEqual(0.5f, _vec2->getY(), 0.1f);

        }

        // Testing Operator += of a Vector2
        TEST_METHOD(TestVector2OperatorPlusEquals)
        {
            _vec2 = up(new Vector2(1.0f, 3.0f));
            up v2 = up(new Vector2(3.0f, 3.0f));

            *_vec2 += *v2;

            Assert::AreEqual(4.0f, _vec2->getX());
            Assert::AreEqual(6.0f, _vec2->getY());

            Vector2 v2_1(3.0f, 3.0f);
            Vector2 v2_2(2.0f, 5.0f);

            v2_1 += v2_2;

            Assert::AreEqual(5.0f, v2_1.getX());
            Assert::AreEqual(8.0f, v2_1.getY());

            v2_2 += 5.0f;

            Assert::AreEqual(7.0f, v2_2.getX());
            Assert::AreEqual(10.0f, v2_2.getY());
        }

        // Testing Divide Equals Operator of a Vector2
        TEST_METHOD(TestVector2DivideEqualsOperator)
        {
            _vec2 = up(new Vector2(4.0f, 8.0f));
            *_vec2 /= 2.0f;

            Assert::AreEqual(2.0f, _vec2->getX());
            Assert::AreEqual(4.0f, _vec2->getY());

            Vector2 v2_1(200.0f, 1024.0f);

            v2_1 /= 2.0f;

            Assert::AreEqual(100.0f, v2_1.getX());
            Assert::AreEqual(512.0f, v2_1.getY());

            *_vec2 /= v2_1;

            Assert::AreEqual(0.02f, _vec2->getX());
            Assert::AreEqual(0.0078f, _vec2->getY(), 0.02f);
        }

        //Testing Operator + of a Vector2
        TEST_METHOD(TestVector2OperatorPlus)
        {
             _vec2 = up(new Vector2(3.0f, 2.0f));
             up v2_1 = up(new Vector2(2.0f, -1.0f));

             Vector2 v2_2 = *_vec2 + *v2_1;

             Assert::AreEqual(5.0f, v2_2.getX());
             Assert::AreEqual(1.0f, v2_2.getY());

             *_vec2 = *_vec2 + 4.0f;

             Assert::AreEqual(7.0f, _vec2->getX());
             Assert::AreEqual(6.0f, _vec2->getY());

             *v2_1 = *v2_1 + (-10.0f);

             Assert::AreEqual(-8.0f, v2_1->getX());
             Assert::AreEqual(-11.0f, v2_1->getY());
        }

        // Testing Operator *= of a Vector2
        TEST_METHOD(TestVector2OperatorMultiplyEquals)
        {
            _vec2 = up(new Vector2(3.0f, 3.0f));

            *_vec2 *= 4.0f;

            Assert::AreEqual(12.0f, _vec2->getX());
            Assert::AreEqual(12.0f, _vec2->getY());

            Vector2 v2_1(7.0f, -124.0f);

            v2_1 *= 3.0f;

            Assert::AreEqual(21.0f, v2_1.getX());
            Assert::AreEqual(-372.0f, v2_1.getY());

            Vector2 v2_2;

            v2_1 *= v2_2;

            Assert::AreEqual(0.0f, v2_1.getX());
            Assert::AreEqual(0.0f, v2_1.getY());

        }

        // Testing Operator -= of a Vector2
        TEST_METHOD(TestVector2OperatorSubtractEquals)
        {
             _vec2 = up(new Vector2(18.0f, 1.0f));

             up v2_1 = up(new Vector2(18.0f, -2.0f));

             *_vec2 -= *v2_1;

             Assert::AreEqual(0.0f, _vec2->getX());
             Assert::AreEqual(3.0f, _vec2->getY());

             *_vec2 -= 3.0f;

             Assert::AreEqual(-3.0f, _vec2->getX());
             Assert::AreEqual(0.0f, _vec2->getY());

             Vector2 v2_2(5.0f, 3.0f);
             
             v2_2 -= *_vec2;

             Assert::AreEqual(8.0f, v2_2.getX());
             Assert::AreEqual(3.0f, v2_2.getY());
        }

        // Testing Operator * of a Vector2
        TEST_METHOD(TestVector2OperatorMultiply)
        {
             _vec2 = up(new Vector2(4.0f, 2.0f));

             *_vec2 = *_vec2 * 3.0f;

             Assert::AreEqual(12.0f, _vec2->getX());
             Assert::AreEqual(6.0f, _vec2->getY());

             Vector2 v2_1;

             *_vec2 = *_vec2 * v2_1;

             Assert::AreEqual(0.0f, _vec2->getX());
             Assert::AreEqual(0.0f, _vec2->getY());

        }

        // Testing Operator / of a Vector2
        TEST_METHOD(TestVector2OperatorDivide)
        {
            _vec2 = up(new Vector2(3.0f, 2.0f));
            
            Vector2 v(3.0f, 2.0f);
            *_vec2 = v / 2.0f;

            Assert::AreEqual(1.5f, _vec2->getX());
            Assert::AreEqual(1.0f, _vec2->getY());
        }

        // Testing Operator - of a Vector2 (Negation)
        TEST_METHOD(TestVector2Negation)
        {
             _vec2 = up(new Vector2(4.0f, 1.0f));

             *_vec2 = -*_vec2;

             Assert::AreEqual(-4.0f, _vec2->getX());
             Assert::AreEqual(-1.0f, _vec2->getY());

             Vector2 v(-3.0f, -6.0f);

             v = -v;

             Assert::AreEqual(3.0f, v.getX());
             Assert::AreEqual(6.0f, v.getY());
        }

        // Testing Operator - of a Vector2
        TEST_METHOD(TestVector2OperatorMinus)
        {
             _vec2 = up(new Vector2(-3.0f, 4.0f));

             Vector2 v(3.0f, -4.0f);

             *_vec2 = *_vec2 - v;

             Assert::AreEqual(-6.0f, _vec2->getX());
             Assert::AreEqual(8.0f, _vec2->getY());
        }

        // Testing getX method
        TEST_METHOD(TestGetXMethod)
        {
             _vec2 = up(new Vector2(43.0f, 3.0f));

             Assert::AreEqual(40.0f, _vec2->getX());
        }

        // Testing setY method
        TEST_METHOD(TestSetYMethod)
        {
             _vec2 = up(new Vector2);

             _vec2->setY(-3.0f);

             Assert::AreEqual(-3.0f, _vec2->getY());
        }

	private:
		std::unique_ptr<Vector2> _vec2;
	};
}