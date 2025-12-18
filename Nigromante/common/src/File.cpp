#include "File.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

using Nigromante::File;

std::string File::ReadFile(const std::string &filename) const {

  std::stringstream content_stream;
  {
    std::fstream input(filename, std::ios::in);
    content_stream << input.rdbuf();
  }
  std::string contenido = content_stream.str();

  return contenido;
}
