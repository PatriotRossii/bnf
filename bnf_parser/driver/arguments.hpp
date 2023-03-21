#pragma once

namespace eoanermine {

namespace bnf_parser {

struct CLIArguments {
  /* Required arguments */
  std::string grammar;

  /* Optional arguments */
  std::string output;
};

} // namespace bnf_parser

} // namespace eoanermine