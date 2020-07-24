#include "drawScreen.h"
#include "XML_Parser.h"
#include "loader.h"
#include "triangulo.h"

int main(int argc, char **argv) {
    std::vector<std::string> ficheiros = startParsing("esfera.xml");
    std::vector<std::vector<triangulo>> figuras = getVertices(ficheiros);
    
    /*
    for(unsigned int i = 0; i<figuras.size() ;i++){
      std::vector<triangulo> figura = figuras.at(i);

      std::cout << "Figura " << i << std::endl;

      for(unsigned int k = 0; k<figura.size() ;k++){

        triangulo tr = figura.at(k);

        std::cout << "Ponto 1-> X:"<< tr.getVerticeX1() <<" Y:"<< tr.getVerticeY1() <<" Z:" << tr.getVerticeZ1() << std::endl;
        std::cout << "Ponto 2-> X:"<< tr.getVerticeX2() <<" Y:"<< tr.getVerticeY2() <<" Z:" << tr.getVerticeZ2() << std::endl;
        std::cout << "Ponto 3-> X:"<< tr.getVerticeX3() <<" Y:"<< tr.getVerticeY3() <<" Z:" << tr.getVerticeZ3() << std::endl;
      }
    }
    */

    startDrawing(argc,argv,figuras);
}
