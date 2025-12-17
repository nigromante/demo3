#include "Escr23.hpp"
#include <iostream>
#include <sstream>

using Nigromante::Escr23;

std::string Escr23::Name() const { return ESCR23_NAME; }

std::string Escr23::Version() const { return ESCR23_VERSION; }

Escr23::Escr23(Escr23Params params) {
  m_params = params;
  StringToLines();
}

// private method
std::vector<Nigromante::Token>
Escr23::LineToTokens(const std::string &content) {
  std::vector<Nigromante::Token> tokens;

  std::stringstream ss(content);
  std::string word;
  while (ss >> word) {
    if (word.at(0) == '#')
      break;
    tokens.push_back(Token{word});
  }
  return tokens;
}

// private method
void Escr23::StringToLines() {
  std::string temp;
  int markbegin = 0;
  int markend = 0;
  int line = 1;

  for (int i = 0; i < m_params.program_content.length(); ++i) {
    if (m_params.program_content[i] == '\n') {
      markend = i;
      if (markend != markbegin &&
          m_params.program_content.at(markbegin) != '#') {
        std::string line_content =
            m_params.program_content.substr(markbegin, markend - markbegin);
        m_lines.push_back({line_content, line, LineToTokens(line_content)});
      }
      markbegin = (i + 1);
      line++;
    }
  }
}

void Escr23::LinesTrace() {
  std::cout << "File !! : " << m_params.name << " (" << m_params.description
            << ")" << std::endl;
  for (Line line : m_lines) {
    std::cout << "Processed Line(" << line.numberLine << "): " << line.content
              << std::endl;
    for (Token token : line.tokens) {
      std::cout << "\tToken: " << token.value << std::endl;
    }
  }
}

std::string Escr23::Result() { return m_salida; }

void Escr23::Transform() { m_salida = m_params.program_content; }
