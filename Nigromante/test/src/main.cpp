#include <stddef.h>

#include "Escr23.hpp"
#include "Escr23Params.hpp"
#include "File.hpp"
#include "ini.hpp"
#include <cstring>
#include <iostream>

using Nigromante::Escr23;

std::string LoadFile(const std::string &name) {
  Nigromante::File file;
  return file.ReadFile(name);
}

Nigromante::Escr23Params *LoadTest(std::string path, mINI::INIStructure tini) {
  Nigromante::Escr23Params *params = new Nigromante::Escr23Params();

  params->name = tini["proyecto"]["name"];
  params->description = tini["proyecto"]["description"];
  params->program_path = path + tini["proyecto"]["program"];
  params->program_content = LoadFile(params->program_path);
  params->data = LoadFile(path + tini["proyecto"]["data"]);

  std::cout << "Entrada: " << std::endl << params->data << std::endl;
  std::cout << "-------------------------" << std::endl;

  return params;
}

mINI::INIStructure ReadIni(std::string path) {
  std::string iniFileName = path + "/info.ini";

  mINI::INIFile file(iniFileName);
  mINI::INIStructure ini;
  file.read(ini);
  return ini;
}

int main(int argc, char **argv) {

  std::string file = argv[1];
  std::string path = "./data/" + file + "/";

  Nigromante::Escr23Params *params = LoadTest(path, ReadIni(path));

  Escr23 *escr23 = new Escr23(params);
  escr23->LinesTrace();
  escr23->Transform();
  std::string salida = escr23->Result();
  delete escr23;
  delete params;

  std::cout << "-------------------------" << std::endl;
  std::cout << "Salida: " << std::endl << salida << std::endl;

  return 0;
}
