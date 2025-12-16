#include <stddef.h>

#include "Escr23.hpp"
#include "File.hpp"
#include <iostream>

void Init() {

  Nigromante::Escr23 escr23;

  std::cout << "Lib: " << escr23.Name() << " " << escr23.Version() << std::endl
            << std::endl;
}

std::string LoadProgram(const std::string &name) {
  std::cout << "Load Program : " << name << std::endl;

  Nigromante::File file;
  return file.ReadFile(name);
}

std::string Work(std::string programName, std::string programDescription,
                 std::string program, std::string data) {

  Nigromante::Escr23 escr23;

  escr23.SetName(programName, programDescription);
  escr23.SetProgram(program);
  escr23.SetData(data);
  escr23.LinesTrace();
  escr23.Transform();

  return escr23.Result();
}

std::string ReadData(std::string filename) {

  Nigromante::File file;

  std::cout << "Read File : " << filename << std::endl;
  std::string data = file.ReadFile(filename);
  std::cout << "Data: " << data << std::endl << std::endl;
  return data;
}

int main() {

  std::string dataFile = "./data/data.txt";
  std::string programFile = "./data/a.escr23";
  std::string programName = "a";
  std::string programDescription = "testing a.escr23";

  Init();

  std::string programContent = LoadProgram(programFile);
  std::string data = ReadData(dataFile);
  std::string salida =
      Work(programName, programDescription, programContent, data);

  std::cout << "Salida: " << std::endl << salida << std::endl;

  return 0;
}
