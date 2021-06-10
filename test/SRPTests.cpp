#include "gtest/gtest.h"
#include "SingleResponsibilityPrinciple.h"

TEST(SRPTests, Journal)
{
    Journal j("Name");
    EXPECT_EQ("Name", j.getName());
}