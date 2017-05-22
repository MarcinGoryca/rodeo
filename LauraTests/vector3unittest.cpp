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

        //Testing operator- for scalar
        TEST_METHOD(TestOperatorMinusScalarVector3)
        {
            _v3 = up(new Vector3(3.0f, -2.0f, 0.0f));
            float scalar = -4.0f;

            *_v3 = *_v3 - scalar;

            Assert::AreEqual(7.0f, _v3->getX());
            Assert::AreEqual(2.0f, _v3->getY());
            Assert::AreEqual(4.0f, _v3->getZ());
        }

        //Testing operator* for scalar
        TEST_METHOD(TestOperatorMultiplyScalarVector3)
        {
            _v3 = up(new Vector3(3.0f, 2.0f, -1.0f));

            float scalar = 8.0f;

            *_v3 = *_v3 * scalar;

            Assert::AreEqual(24.0f, _v3->getX());
            Assert::AreEqual(16.0f, _v3->getY());
            Assert::AreEqual(-8.0f, _v3->getZ());

        }

        //Testing operator* for Vector3
        TEST_METHOD(TestOperatorMultiplyVector3_Vector3)
        {
            _v3 = up(new Vector3(3.0f, -2.0f, 3.0f));
            up v3_2 = up(new Vector3(3.0f, 2.0f, 1.0f));

            *_v3 = *_v3 * *v3_2;

            Assert::AreEqual(9.0f, _v3->getX());
            Assert::AreEqual(-4.0f, _v3->getY());
            Assert::AreEqual(3.0f, _v3->getZ());

            up v3_3 = up(new Vector3(1.223f, 7.1342f, 0.5612f));

            *_v3 = *_v3 * *v3_3;

            Assert::AreEqual(11.007f, _v3->getX());
            Assert::AreEqual(-28.5368f, _v3->getY());
            Assert::AreEqual(1.6836f, _v3->getZ());

        }

        //Testing operator/ for scalar
        TEST_METHOD(TestOperatorDivideScalarVector3)
        {
            _v3 = up(new Vector3(2.0f, 1.22f, 3.0f));
            float scalar = 0.432f;

            *_v3 = *_v3 / scalar;

            Assert::AreEqual(4.629f, _v3->getX(),0.1f);
            Assert::AreEqual(2.824f, _v3->getY(), 0.1f);
            Assert::AreEqual(6.94f, _v3->getZ(), 0.1f);
        }

        //Testing operator+= Vector3
        TEST_METHOD(TestOperatorPlusEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(4.0f, -6.0f, 2.5f));
            up v = up(new Vector3(-4.0f, 6.0f, 2.5f));

            *_v3 += *v;

            Assert::AreEqual(0.0f, _v3->getX());
            Assert::AreEqual(0.0f, _v3->getY());
            Assert::AreEqual(5.0f, _v3->getZ());
        }

        //Testing Operator-= Vector3
        TEST_METHOD(TestOperatorMinusEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(4.0f, 1.0f, 4.0f));
            up v = up(new Vector3(7.0f, 4.0f, 1.2f));

            *_v3 -= *v;

            Assert::AreEqual(-3.0f, _v3->getX());
            Assert::AreEqual(-3.0f, _v3->getY());
            Assert::AreEqual(2.8f, _v3->getZ());
        }

        //Testing Operator*= Vector3
        TEST_METHOD(TestOperatorMultiplyEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(2.0f, 7.3f, 0.4f));
            up v = up(new Vector3(1.1f, 8.4f, 9.3f));

            *_v3 *= *v;

            Assert::AreEqual(2.2f, _v3->getX());
            Assert::AreEqual(61.32f, _v3->getY());
            Assert::AreEqual(3.72f, _v3->getZ());
        }

        //Testing Operator/= Vector3
        TEST_METHOD(TestOperatorDivideEqualVector3_Vector3)
        {
            _v3 = up(new Vector3(5.0f, 4.0f, 3.0f));
            up v = up(new Vector3())
        }
    private:
        up _v3;
    };
}