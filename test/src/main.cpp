#include <stddef.h>

#include "Escr23.hpp"
#include "Escr23Params.hpp"
#include "File.hpp"
#include <iostream>

#define dataFile "./data/data.txt"
#define programFile "./data/a.escr23"

using Nigromante::Escr23;

std::string Work(Nigromante::Escr23Params params) {
  Nigromante::Escr23 *escr23 = new Nigromante::Escr23(params);
  escr23->LinesTrace();
  escr23->Transform();
  std::string result = escr23->Result();
  delete escr23;
  return result;
}

std::string LoadProgram(const std::string &name) {
  std::cout << "Load Program : " << name << std::endl;
  Nigromante::File file;
  return file.ReadFile(name);
}

std::string ReadData(std::string filename) {
  Nigromante::File file;
  std::cout << "Read File : " << filename << std::endl;
  std::string data = file.ReadFile(filename);
  std::cout << "Data: " << data << std::endl << std::endl;
  return data;
}

int main() {
  Nigromante::Escr23Params params;
  params.name = "Testing";
  params.description = "Testing program 1";
  params.program_path = programFile;
  params.program_content = LoadProgram(programFile);
  params.data = ReadData(dataFile);

  std::string salida = Work(params);

  std::cout << "Salida: " << std::endl << salida << std::endl;

  return 0;
}
