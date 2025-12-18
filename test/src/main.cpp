#include <stddef.h>

#include "Escr23.hpp"
#include "Escr23Params.hpp"
#include "File.hpp"
#include <iostream>

#define dataFile "./data/data.txt"
#define programFile "./data/a.escr23"

using Nigromante::Escr23;

std::string Work(Nigromante::Escr23Params *params) {
  Escr23 *escr23 = new Escr23(params);
  escr23->LinesTrace();
  escr23->Transform();
  std::string result = escr23->Result();
  delete escr23;
  delete params;
  return result;
}

std::string LoadFile(const std::string &name) {
  Nigromante::File file;
  return file.ReadFile(name);
}

Nigromante::Escr23Params *LoadTest(char *arg) {
  Nigromante::Escr23Params *params = new Nigromante::Escr23Params();
  params->name = "Testing";
  params->description = "Testing program 1";
  params->program_path = programFile;
  params->program_content = LoadFile(programFile);
  params->data = LoadFile(dataFile);
  return params;
}

int main(int argc, char **argv) {
  std::string salida = Work(LoadTest(argv[1]));
  std::cout << "Salida: " << std::endl << salida << std::endl;
  return 0;
}
