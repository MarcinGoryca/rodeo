#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/math/vector3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace laura::math;

namespace LauraTests
{
    TEST_CLASS(Vector3UnitTest)
    {
    public:
        typedef std::unique_ptr<Vector3> up;
        Vector3UnitTest()
            :_v3(nullptr)
        {}

        // Testing default constructor
        TEST_METHOD(TestConstructorVector3)
        {
            _v3 = up(new Vector3);

            Assert::AreEqual(0.0f, _v3->getX());
            Assert::AreEqual(0.0f, _v3->getY());
            Assert::AreEqual(0.0f, _v3->getZ());
        }

        // Testing constructor with parameters
        TEST_METHOD(TestConstructorWithParamsVector3)
        {
            _v3 = up(new Vector3(-3.0f, 2.765f, 0.03f));

            Assert::AreEqual(0.03f, _v3->getZ());
            Assert::AreEqual(2.765f, _v3->getY());
            Assert::AreEqual(-3.0f, _v3->getX());
        }

        // Testing copy constructor
        TEST_METHOD(TestCopyConstructorVector3)
        {
            _v3 = up(new Vector3(1.0f, 2.0f, 3.0f));
            up v1 = up(new Vector3(*_v3));

            Assert::AreEqual(1.0f, v1->getX());
            Assert::AreEqual(2.0f, v1->getY());
            Assert::AreEqual(3.0f, v1->getZ());
        }

        // Testing Zero Vector
        TEST_METHOD(TestZeroVector3)
        {
            Assert::AreEqual(0.0f, Vector3::S_VECTOR3_ZERO_.getX());
            Assert::AreEqual(0.0f, Vector3::S_VECTOR3_ZERO_.getY());
            Assert::AreEqual(0.0f, Vector3::S_VECTOR3_ZERO_.getZ());
        }

        // Testing Length of a Vector
        TEST_METHOD(TestLengthVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 1.2f));

            float l = _v3->length();

            Assert::AreEqual(3.8f, l);

        }

        // Testing DOT PRODUCT
        TEST_METHOD(TestDotProductVector3)
        {
            _v3 = up(new Vector3(1.0f, 2.0f, 4.0f));
            Vector3 x(2.0f, 3.0f, 2.0f);

            float a = _v3->dot(x);

            Assert::AreEqual(16.0f, a);
        }

        // Testing Negate Method
        TEST_METHOD(TestNegateMethodVector3)
        {
            _v3 = up(new Vector3(2.0f, 3.0f, 4.0f));
            _v3->negate();

            Assert::AreEqual(-2.0f, _v3->getX());
            Assert::AreEqual(-3.0f, _v3->getY());
            Assert::AreEqual(-4.0f, _v3->getZ());

            Vector3 a(*_v3);

            a.negate();

            Assert::AreEqual(2.0f, a.getX());
            Assert::AreEqual(3.0f, a.getY());
            Assert::AreEqual(4.0f, a.getZ());
        }

        // Testing Cross Product 
        TEST_METHOD(TestCrossProductVector3)
        {
            _v3 = up(new Vector3(2.0f, 1.0f, 4.0f));
            up x = up(new Vector3(4.0f, 2.0f, -2.0f));
            Vector3 y;
            y = y.cross(*_v3, *x);

            // x = -10
            // y =  20
            // z = 0
            Assert::AreEqual(-10.0f, y.getX());
            Assert::AreEqual(20.0f, y.getY());
            Assert::AreEqual(0.0f, y.getZ());
        }

        // Testing operator+
        TEST_METHOD(TestOperatorPlusVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 5.0f));
            up a = up(new Vector3(2.0f, -2.0f, -6.0f));

            Vector3 b = *_v3 + *a;
            Assert::AreEqual(5.0f, b.getX());
            Assert::AreEqual(0.0f, b.getY());
            Assert::AreEqual(-1.0f, b.getZ());
        }

        // Testing operator-
        TEST_METHOD(TestOperatorMinusVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, 5.0f));
            up a = up(new Vector3(2.0f, -2.0f, -6.0f));

            Vector3 b = *_v3 - *a;
            Assert::AreEqual(1.0f, b.getX());
            Assert::AreEqual(4.0f, b.getY());
            Assert::AreEqual(11.0f, b.getZ());
        }

        //Testing operator+ for scalar
        TEST_METHOD(TestOperatorPlusScalarVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, -4.0f));

            *_v3 = *_v3 + 4.0f;

            Assert::AreEqual(7.0f, _v3->getX());
            Assert::AreEqual(6.0f, _v3->getY());
            Assert::AreEqual(0.0f, _v3->getZ());
        }
    private:
        up _v3;
    };
}