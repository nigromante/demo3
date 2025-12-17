
#ifndef ESCR23PARAMS_HPP_
#define ESCR23PARAMS_HPP_

#include <string>

namespace Nigromante {

class Escr23Params {
public:
  std::string name;
  std::string description;
  std::string program_path;
  std::string program_content;

  std::string data;
};

} // namespace Nigromante

#endif // ESCR23PARAMS_HPP_
