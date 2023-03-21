#pragma once

#include <boost/program_options.hpp>

#include <driver/arguments.hpp>

namespace po = boost::program_options;

namespace eoanermine {

namespace bnf_parser {

class driver {
	CLIArguments args;
	po::options_description desc{"Allowed options"};
	po::variables_map vm;

	void setup_command_line(int argc, char *argv[]);
	bool validate_arguments() const;

public:
	driver(int argc, char *argv[]);
	int run();
};

} // namespace bnf_parser

} // namespace eoanermine
