#include "Escr23.hpp"
#include <iostream>
#include <sstream>

using Nigromante::Escr23;

std::string Escr23::Name() const { return ESCR23_NAME; }

std::string Escr23::Version() const { return ESCR23_VERSION; }

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

  for (int i = 0; i < m_program.length(); ++i) {
    if (m_program[i] == '\n') {
      markend = i;
      if (markend != markbegin && m_program.at(markbegin) != '#') {
        std::string line_content =
            m_program.substr(markbegin, markend - markbegin);
        m_lines.push_back({line_content, line, LineToTokens(line_content)});
      }
      markbegin = (i + 1);
      line++;
    }
  }
}

void Escr23::SetName(std::string name, std::string programDescription) {
  m_name = name;
  m_description = programDescription;
}

void Escr23::SetProgram(std::string content) {
  m_program = content;
  StringToLines();
}

void Escr23::SetData(const std::string &data) { m_data = data; }

void Escr23::LinesTrace() {
  std::cout << "File : " << m_name << " (" << m_description << ")" << std::endl;
  for (Line line : m_lines) {
    std::cout << "Processed Line(" << line.numberLine << "): " << line.content
              << std::endl;
    for (Token token : line.tokens) {
      std::cout << "\tToken: " << token.value << std::endl;
    }
  }
}

std::string Escr23::Result() { return m_salida; }

void Escr23::Transform() { m_salida = m_program; }
