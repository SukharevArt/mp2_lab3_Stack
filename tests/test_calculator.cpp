#include "gtest.h"

#include "..\Calculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator v("4+4"));
}

TEST(TCalculator, can_set_expresion_in_calculator)
{
	TCalculator v;
	ASSERT_NO_THROW(v.SetExpr("56*32-5+(8-3)*7"));
}

TEST(TCalculator, can_get_expresion_in_calculator)
{
	TCalculator v;
	v.SetExpr("56*32-5+(8-3)*7");
	ASSERT_NO_THROW(v.GetExpr());
}

TEST(TCalculator, save_set_expresion_in_calculator)
{
	TCalculator v;
	v.SetExpr("56*32-5+(8-3)*7");
	ASSERT_NO_THROW(v.GetExpr()=="56*32-5+(8-3)*7");
}

TEST(TCalculator, check_correct_sequence_of_parentheses)
{
	TCalculator v("(2+5)*(3-5)*(2*3)/(((3+4)/(1+1)+5)*2)");
	ASSERT_NO_THROW(v.CheckExpr());
	EXPECT_TRUE(v.CheckExpr());
}

TEST(TCalculator, check_uncorrect_sequence_of_parentheses_too_many_open)
{
	TCalculator v("(2+5)*(3-5)*(2*3)/(((3+4)/(1+1)+5)*2");
	ASSERT_NO_THROW(v.CheckExpr());
	EXPECT_FALSE(v.CheckExpr());
}

TEST(TCalculator, check_uncorrect_sequence_of_parentheses_too_many_close)
{
	TCalculator v("(2+5)*(3-5)*(2*3))/(((3+4)/(1+1)+5)*2)");
	ASSERT_NO_THROW(v.CheckExpr());
	EXPECT_FALSE(v.CheckExpr());
}

TEST(TCalculator, can_calc_postfix_form) {
	TCalculator v("3+6-8*9+3^(2-1)");
	ASSERT_NO_THROW(v.ToPostfix());
}

TEST(TCalculator, can_get_postfix_form) {
	TCalculator v("3+6-8*9+3^(2-1)");
	v.ToPostfix();
	ASSERT_NO_THROW(v.GetPostfix());
}

TEST(TCalculator, right_calc_postfix_form) {
	TCalculator v("3+6-8*9+3^(2-1)");
	v.ToPostfix();
	EXPECT_EQ(v.GetPostfix(),"3 6 + 8 9 * - 3 2 1 - ^ +");
}

TEST(TCalculator, right_calc_postfix_form2) {
	TCalculator v("(2-3)*(5+6)+0.5*2 + 8-7^(3-2*1)");
	v.ToPostfix();
	EXPECT_EQ(v.GetPostfix(),"2 3 - 5 6 + * 0.5 2 * + 8 + 7 3 2 1 * - ^ -");
}

TEST(TCalculator, cant_calc_uncorect_expr) {
	TCalculator v("3++6-8*9+3^(2-1)");
	ASSERT_ANY_THROW(v.Calc());
	v.SetExpr("++4");
	ASSERT_ANY_THROW(v.Calc());
	v.SetExpr("4**5-3");
	ASSERT_ANY_THROW(v.Calc());
	v.SetExpr("36/5/2--5");
	ASSERT_ANY_THROW(v.Calc());

}

TEST(TCalculator, can_calculate_expresion)
{
	TCalculator v("3*(2-3)+8-2*7+2^3");
	ASSERT_NO_THROW(v.Calc());
}

TEST(TCalculator, can_right_calculate_expresion_with_plus)
{
	TCalculator v("3+2+23+45");
	EXPECT_EQ(v.Calc(),73);
}

TEST(TCalculator, can_right_calculate_expresion_with_minus)
{
	TCalculator v("32-2-565-32");
	EXPECT_EQ(v.Calc(),-567);
}

TEST(TCalculator, can_right_calculate_expresion_with_product)
{
	TCalculator v("3*2*4*7");
	EXPECT_EQ(v.Calc(),168);
	v.SetExpr("3*(0-2)*4");
	EXPECT_EQ(v.Calc(),-24);
}

TEST(TCalculator, can_right_calculate_expresion_with_division)
{
	TCalculator v("64/8");
	EXPECT_EQ(v.Calc(),8);
	v.SetExpr("3/3/2");
	EXPECT_EQ(v.Calc(),0.5);
}

TEST(TCalculator, can_right_calculate_long_expresion)
{
	TCalculator v("(3-5)*(1+2^3-5)-32+(1+2-5)^3");//(-2)*(4)-32+(-8)=-48
	EXPECT_EQ(v.Calc(),-48);
	v.SetExpr("3*(1^4+1^0)");
	EXPECT_EQ(v.Calc(),6);
	v.SetExpr("3*22*1*(1-2)/2");
	EXPECT_EQ(v.Calc(),-33);
	v.SetExpr("32-5*6+5-(5+6*3)-8/2");
	EXPECT_EQ(v.Calc(), 32 - 5 * 6 + 5 - (5 + 6 * 3) - 8 / 2);
}
