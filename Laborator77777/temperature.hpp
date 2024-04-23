constexpr double operator"" _Kelvin(long double kelvin)
{
	return static_cast<float>(kelvin - 273.15);
}

constexpr double operator"" _Fahrenheit(long double fah)
{
	return static_cast<float>((fah - 32) * 5 / 9);
}