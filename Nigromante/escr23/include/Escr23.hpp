#ifndef ESCR23_HPP_
#define ESCR23_HPP_

#include "Escr23Params.hpp"
#include <string>
#include <vector>

#define ESCR23_NAME "Nigromante.Escr23"
#define ESCR23_VERSION "v_1.0"

namespace Nigromante {

struct Token {
  std::string value;
};

struct Line {
  std::string content;
  int numberLine;
  std::vector<Token> tokens;
};

class Escr23 {
public:
  std::string Name() const;
  std::string Version() const;

  Escr23(Escr23Params *params);
  void Transform();
  void LinesTrace();
  std::string Result();

private:
  std::vector<Token> LineToTokens(const std::string &content);
  void StringToLines();
  Escr23Params *m_params;

  std::vector<Line> m_lines;
  std::string m_salida;
};

} // namespace Nigromante

#endif // ESCR23_HPP_
