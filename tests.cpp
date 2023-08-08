#include "tests.h"

namespace tests{

    void TestDerivative(){
        ASSERT_EQUAL("2*x+1", module_2::derivative("x^2+x"))
        ASSERT_EQUAL("200*x^99+200*x", module_2::derivative("2*x^100+100*x^2"))
        ASSERT_EQUAL("10000*x^9999+1", module_2::derivative("x^10000+x+1"))
        ASSERT_EQUAL("-3*x^2-2*x", module_2::derivative("-x^2-x^3"))
        ASSERT_EQUAL("10", module_2::derivative("x+x+x+x+x+x+x+x+x+x"))
        ASSERT_EQUAL("-21*x^2-6", module_2::derivative("-7*x^3-6*x"))
    }

    void Tests(){
        TestRunner tr;
        RUN_TEST(tr, TestDerivative);
    }
}