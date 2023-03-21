#include <iostream>

#include <driver/driver.hpp>

namespace eoanermine {

namespace bnf_parser {

void driver::setup_command_line(int argc, char *argv[]) {
  po::positional_options_description pd;
  pd.add("grammar", 1).add("output", 1);

  // clang-format off
  desc.add_options()
    ("help", "produce help message")
    ("grammar", po::value<std::string>(&args.grammar), "path of grammar file")
    ("output", po::value<std::string>(&args.output), "path of output file")
  ;
  // clang-format on

  po::store(po::command_line_parser(argc, argv).options(desc).positional(pd).run(), vm);
  po::notify(vm);
}

bool driver::validate_arguments() const {
  if (!vm.count("grammar"))
    return false;
  return true;
}

driver::driver(int argc, char *argv[]) { setup_command_line(argc, argv); }

int driver::run() {
  if (vm.count("help") || !validate_arguments()) {
    std::cout << "Usage: bnf GRAMMAR_FILE [OUTPUT_FILE]" << '\n';
    std::cout << desc;
  }

  return EXIT_SUCCESS;
}

} // namespace bnf_parser

} // namespace eoanermine
