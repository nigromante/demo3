#ifndef ESCR23_HPP_
#define ESCR23_HPP_

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

class Escr23Params {
public:
  std::string name;
  std::string description;
  std::string program_path;
  std::string program_content;

  std::string data;
};

class Escr23 {
public:
  std::string Name() const;
  std::string Version() const;

  void SetName(std::string name, std::string programDesciption);
  void SetProgram(std::string content);
  void SetData(const std::string &data);
  void Transform();
  void LinesTrace();
  std::string Result();

private:
  std::vector<Token> LineToTokens(const std::string &content);
  void StringToLines();
  Escr23Params param;

  std::string m_name;
  std::string m_description;
  std::string m_data;
  std::string m_program;
  std::vector<Line> m_lines;
  std::string m_salida;
};

} // namespace Nigromante

#endif // ESCR23_HPP_
