#include <driver/driver.hpp>

int main(int argc, char *argv[]) {
	eoanermine::bnf_parser::driver driver{argc, argv};
	const int result_code = driver.run();
	return result_code;
}
