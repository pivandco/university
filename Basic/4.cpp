#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
	float a = 0.5, b = 0.5;

	//double main_frac_numerator = pow(a, pow(sin(b), 2.0) + cos(pow(b, 3.0))) + cbrt(pow(b, 2.0));
	//double second_frac_numerator = a * tan(b);
	//double second_frac_denominator = 1.0 - pow(M_E, sqrt(a));
	//double main_frac_denominator = pow(std::abs(second_frac_numerator / second_frac_denominator), 0.25);

	//double y = sqrt(std::abs(main_frac_numerator / main_frac_denominator));

	float y = sqrt(std::abs(
		(pow(a, pow(sin(b), 2.0) + cos(pow(b, 3.0))) + cbrt(pow(b, 2.0))) /
		pow(
		std::abs((a * tan(b)) /
		(1.0 - pow(M_E, sqrt(a)))),
		0.25)
		));

	return 0;
}
