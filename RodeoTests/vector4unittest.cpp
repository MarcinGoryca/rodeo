#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/vector4.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace rodeo::math;



namespace rodeoTests
{
    typedef std::unique_ptr<Vector4> up;

    TEST_CLASS(Vector4UnitTest)
    {
    public:
        Vector4UnitTest()
            :_a(nullptr), _b(nullptr), _c(nullptr), _d(nullptr)
        {}

        //Testing Default Constructor
        TEST_METHOD(TestDefaultConstructor_Vector4)
        {
            _a = up(new Vector4);
            _b = up(new Vector4);
            _c = up(new Vector4);
            _d = up(new Vector4);

            Assert::AreEqual(0.0f, _a->getX());
            Assert::AreEqual(0.0f, _a->getY());
            Assert::AreEqual(0.0f, _a->getZ());
            Assert::AreEqual(0.0f, _a->getW());

            Assert::AreEqual(0.0f, _b->getX());
            Assert::AreEqual(0.0f, _b->getY());
            Assert::AreEqual(0.0f, _b->getZ());
            Assert::AreEqual(0.0f, _b->getW());

            Assert::AreEqual(0.0f, _c->getX());
            Assert::AreEqual(0.0f, _c->getY());
            Assert::AreEqual(0.0f, _c->getZ());
            Assert::AreEqual(0.0f, _c->getW());

            Assert::AreEqual(0.0f, _d->getX());
            Assert::AreEqual(0.0f, _d->getY());
            Assert::AreEqual(0.0f, _d->getZ());
            Assert::AreEqual(0.0f, _d->getW());
        }

        //Testing Default Constructor with arguments
        TEST_METHOD(TestDefaultContstructorArguments_Vector4)
        {
            _a = up(new Vector4(9.0f, 1.0f, 3.0f, -1.0f));
            _b = up(new Vector4(-4.1f, 2.09f, 9.45f, 1.0f));
            _c = up(new Vector4(654.03f, 234.098f, -0.003f, 1.0f));
            _d = up(new Vector4(1.0f, 0.0f, 1.0f, 1.0f));

            Assert::AreEqual(9.0f, _a->getX());
            Assert::AreEqual(1.0f, _a->getY());
            Assert::AreEqual(3.0f, _a->getZ());
            Assert::AreEqual(-1.0f, _a->getW());

            Assert::AreEqual(-4.1f, _b->getX());
            Assert::AreEqual(2.09f, _b->getY());
            Assert::AreEqual(9.45f, _b->getZ());
            Assert::AreEqual(1.0f, _b->getW());

            Assert::AreEqual(654.03f, _c->getX());
            Assert::AreEqual(234.098f, _c->getY());
            Assert::AreEqual(-0.003f, _c->getZ());
            Assert::AreEqual(1.0f, _c->getW());

            Assert::AreEqual(1.0f, _d->getX());
            Assert::AreEqual(0.0f, _d->getY());
            Assert::AreEqual(1.0f, _d->getZ());
            Assert::AreEqual(1.0f, _d->getW());
        }

        //Testing Copy Constructor
        TEST_METHOD(TestCopyConstructor_Vector4)
        {
            _a = up(new Vector4(3.0f, 2.0f/2.0f, 1.0f, -2.0f));
            _b = up(new Vector4(*_a));

            _c = up(new Vector4(-3.87f, 2.0f, -0.9f, 1.0f));
            _d = up(new Vector4(*_c));

            Assert::AreEqual(3.0f, _a->getX());
            Assert::AreEqual(1.0f, _a->getY());
            Assert::AreEqual(1.0f, _a->getZ());
            Assert::AreEqual(-2.0f, _a->getW());

            Assert::AreEqual(3.0f, _b->getX());
            Assert::AreEqual(1.0f, _b->getY());
            Assert::AreEqual(1.0f, _b->getZ());
            Assert::AreEqual(-2.0f, _b->getW());

            Assert::AreEqual(-3.87f, _c->getX());
            Assert::AreEqual(2.0f, _c->getY());
            Assert::AreEqual(-0.9f, _c->getZ());
            Assert::AreEqual(1.0f, _c->getW());

            Assert::AreEqual(-3.87f, _d->getX());
            Assert::AreEqual(2.0f, _d->getY());
            Assert::AreEqual(-0.9f, _d->getZ());
            Assert::AreEqual(1.0f, _d->getW());
        }

        //Testing Set Method
        TEST_METHOD(TestSetMethod_Vector4)
        {
            _a = up(new Vector4);

            _a->set(3.0f, -5.0f, -2.0f, 1.0f);

            Assert::AreEqual(3.0f, _a->getX());
            Assert::AreEqual(-5.0f, _a->getY());
            Assert::AreEqual(-2.0f, _a->getZ());
            Assert::AreEqual(1.0f, _a->getW());
        }

        //Testing Set Method Vector4 argument
        TEST_METHOD(TestSetMethodVector4Argument_Vector4)
        {
            _a = up(new Vector4(0.0f, 2.0f, 1.0f, -1.0f));
            _b = up(new Vector4);

            _b->set(*_a);

            Assert::AreEqual(0.0f, _b->getX());
            Assert::AreEqual(2.0f, _b->getY());
            Assert::AreEqual(1.0f, _b->getZ());
            Assert::AreEqual(-1.0f, _b->getW());
        }

        //Testing Set Method Vector3 as argument
        TEST_METHOD(TestSetMethodVector3Argument_Vector4)
        {
            _a = up(new Vector4);
            Vector3* v = new Vector3(1.0f, 3.0f, 2.0f);
            _a->set(*v);

            Assert::AreEqual(1.0f, _a->getX());
            Assert::AreEqual(3.0f, _a->getY());
            Assert::AreEqual(2.0f, _a->getZ());
            Assert::AreEqual(1.0f, _a->getW());

            delete v;
        }

        //Testing Dot Product for Vector4
        TEST_METHOD(TestDotProduct_Vector4)
        {
            _a = up(new Vector4(7.0f, 1.05f, 1.0f, 1.0f));
            _b = up(new Vector4(-3.0f, 2.0f, 3.0f, -1.0f));
            _c = up(new Vector4(0.0f, 1.8f, 9.32f, 1.0f));
            _d = up(new Vector4(9.008f, 0.5543f, 0.0002f, -1.0f));

            up a = up(new Vector4(1.0f, 2.0f, 2.0f, 1.0f));
            up b = up(new Vector4(*a));
            up c = up(new Vector4(*b));
            up d = up(new Vector4(*c));

            float x = _a->dot(*a); // 12.1
            float y = _b->dot(*b);
            float z = _c->dot(*c);
            float w = _d->dot(*d);

            Assert::AreEqual(12.1f, x);
            Assert::AreEqual(6.0f, y);
            Assert::AreEqual(23.24f, z);
            Assert::AreEqual(9.117f, w);
        }

        //Testing Length Method of Vector4
        TEST_METHOD(TestLengthMethod_Vector4)
        {
            _a = up(new Vector4(7.0f, 1.05f, 1.0f, 1.0f));
            _b = up(new Vector4(-3.0f, 2.0f, 3.0f, -1.0f));
            _c = up(new Vector4(0.0f, 1.8f, 9.32f, 1.0f));
            _d = up(new Vector4(9.008f, 0.5543f, 0.0002f, -1.0f));

            float al = _a->length();
            float bl = _b->length();
            float cl = _c->length();
            float dl = _d->length();

            Assert::AreEqual(7.2182f, al, 0.01f);
            Assert::AreEqual(1.7320f, bl, 0.01f);
            Assert::AreEqual(9.5447f, cl, 0.01f);
            Assert::AreEqual(80.4513f, dl, 0.01f);
        }

        //Testing Operator+ Vector4
        TEST_METHOD(TestOperatorPlus_Vector4)
        {
            _a = up(new Vector4(3.0f, 1.0f, 5.0f, 1.0f));
            _b = up(new Vector4(3.1f, 3.0f, 0.5f, -1.0f));

            Vector4 a = *_a + *_b;

            Assert::AreEqual(6.1f, a.getX());
            Assert::AreEqual(4.0f, a.getY());
            Assert::AreEqual(5.5f, a.getZ());
            Assert::AreEqual(0.0f, a.getW());
        }

        //Testing Operator- Vector4
        TEST_METHOD(TestOperatorMinus_Vector4)
        {
            _a = up(new Vector4(3.0f, 1.0f, 5.0f, 1.0f));
            _b = up(new Vector4(3.1f, 3.0f, 0.5f, -1.0f));

            Vector4 a = *_a - *_b;

            Assert::AreEqual(-0.1f, a.getX(), 0.01f);
            Assert::AreEqual(-2.0f, a.getY());
            Assert::AreEqual(4.5f, a.getZ());
            Assert::AreEqual(0.0f, a.getW());
        }

        //Testing Operator* by Scalar Vector4
        TEST_METHOD(TestOperatorMultiplyByScalar_Vector4)
        {
            _a = up(new Vector4(-1.0f, 3.0f, 0.3f, 1.0f));

            Vector4 a = *_a * 8.0f;

            Assert::AreEqual(-8.0f, a.getX());
            Assert::AreEqual(24.0f, a.getY());
            Assert::AreEqual(2.4f, a.getZ());
            Assert::AreEqual(8.0f, a.getW());
        }

        //Testing Operator* by Vector Vector4
        TEST_METHOD(TestOperatorMultiplyByVector_Vector4)
        {
            _a = up(new Vector4(2.0f, 1.0f, 2.0f, -1.0f));
            _b = up(new Vector4(3.0f, -0.5f, 2.0f, 4.0f));

            Vector4 a = *_a * *_b;

            Assert::AreEqual(6.0f, a.getX());
            Assert::AreEqual(-0.5f, a.getY());
            Assert::AreEqual(4.0f, a.getZ());
            Assert::AreEqual(-4.0f, a.getW());
        }

		//Testing Operator/ by scalar
		TEST_METHOD(TestOperatorDivide_ByScalar)
		{
			_a = up(new Vector4(2.0f, 12.0f, 2.0f, 5.0f));
			float scalar = 2.0f;

			*_a = *_a / scalar;

			Assert::AreEqual(1.0f, _a->getX());
			Assert::AreEqual(6.0f, _a->getY());
			Assert::AreEqual(1.0f, _a->getZ());
			Assert::AreEqual(2.5f, _a->getW());
		}

		//Testing Operator += by Vector Vector4
		TEST_METHOD(TestOperatorPlusEquals_Vector_V4)
		{
			_a = up(new Vector4(3.0f, 7.0f, 4.0f, 1.0f));
			_b = up(new Vector4(7.0f, 0.0f, 3.0f, 6.0f));

			*_a += *_b;

			Assert::AreEqual(10.0f, _a->getX());
			Assert::AreEqual(7.0f, _a->getY());
			Assert::AreEqual(7.0f, _a->getZ());
			Assert::AreEqual(7.0f, _a->getW());
		}

		//Testing Operator-= by Vector Vector4
		TEST_METHOD(TestOperatorMinusEquals_Vector_V4)
		{
			_a = up(new Vector4(3.0f, -3.0f, 5.0f, 0.0f));
			_b = up(new Vector4(5.0f, -4.0f, 3.0f, -3.0f));

			*_a -= *_b;

			Assert::AreEqual(-2.0f, _a->getX());
			Assert::AreEqual(1.0f, _a->getY());
			Assert::AreEqual(2.0f, _a->getZ());
			Assert::AreEqual(3.0f, _a->getW());
		}

		//Testing Operator*= Vector4
		TEST_METHOD(TestOperatorMultiply_Vector_V4)
		{
			_a = up(new Vector4(3.0f, 4.0f, 2.0f, 9.0f));
			_b = up(new Vector4(3.0f, 8.0f, 2.0f, 1.0f));

			*_a *= *_b;

			Assert::AreEqual(9.0f, _a->getX());
			Assert::AreEqual(32.0f, _a->getY());
			Assert::AreEqual(4.0f, _a->getZ());
			Assert::AreEqual(9.0f, _a->getW());
		}

		//Testing Operator/= Vector4
		TEST_METHOD(TestOperatorDivideEquals_Vector_V4)
		{
			_a = up(new Vector4(5.0f, 3.0f, 7.0f, 9.0f));
			_b = up(new Vector4(2.5f, 1.5f, 3.5f, 4.5f));

			*_a /= *_b;

			Assert::AreEqual(2.0f, _a->getX());
			Assert::AreEqual(2.0f, _a->getY());
			Assert::AreEqual(2.0f, _a->getZ());
			Assert::AreEqual(2.0f, _a->getW());
		}

		//Testing Operator= Vector4
		TEST_METHOD(TestOperatorAsign_Vector4)
		{
			_a = up(new Vector4(3.0f, -4.0f, 2.0f, 0.0f));
			_b = up(new Vector4);
			
			*_b = *_a;

			Assert::AreEqual(3.0f, _b->getX());
			Assert::AreEqual(-4.0f, _b->getY());
			Assert::AreEqual(2.0f, _b->getZ());
			Assert::AreEqual(0.0f, _b->getW());
		}

		//Testing Operator== Vector4
		TEST_METHOD(TestOperatorEquals_Vector4)
		{
			_a = up(new Vector4(4.0f, 1.0f, 4.0f, 1.0f));
			_b = up(new Vector4(4.0f, 1.0f, 4.0f, 1.0f));

			bool eq = false;

			if (*_b == *_a)
			{
				eq = true;
			}

			Assert::IsTrue(eq);
		}

		//Testing Operator!= Vector4
		TEST_METHOD(TestOperatorNotEquals_Vector4)
		{
			_a = up(new Vector4(4.0f, 1.0f, 4.0f, 1.0f));
			_b = up(new Vector4(4.0f, -1.0f, 4.0f, 1.0f));

			bool eq = false;

			if (*_b != *_a)
			{
				eq = true;
			}

			Assert::IsTrue(eq);
		}
    private:
        up _a;
        up _b;
        up _c;
        up _d;
    };
}