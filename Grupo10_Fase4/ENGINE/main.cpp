#include "drawScreen.h"
#include "XML_Parser.h"
#include "loader.h"
#include "triangulo.h"

int figura = 1;

void toPrint(xmlData pai) {
    std::vector<xmlData> ficheiros = pai.getFilhos();
    for (unsigned int i = 0; i < ficheiros.size(); i++) {
        figura++;
        xmlData ficheiro = ficheiros.at(i);

        std::cout << "%-------------------------------------------------------------------------%" << std::endl;
        std::cout << "Figura " << figura << std::endl;
        std::vector<std::string> nomes = ficheiro.getFileName();
        std::vector<obj_Light> mats = ficheiro.getMateriais();
        for (unsigned int k = 0; k < nomes.size(); k++) {
            std::cout << "Ficheiro " << k + 1 << ": " << nomes.at(k) << std::endl;
            std::cout << "Textura " << k + 1 << ": " << mats.at(k).getTexture() << std::endl;
            std::cout << "Textura Size " << k + 1 << ": " << ficheiro.getCoords().size() << std::endl;
        }
        std::cout << "Translate Information: X=" << ficheiro.getTranslateX() << " Y=" << ficheiro.getTranslateY() << " Z=" << ficheiro.getTranslateZ() << " Ordem=" << ficheiro.getOrdemTr() << " Tempo=" << ficheiro.getTempoTr()  << std::endl;
        if ((ficheiro.getNumControlPoints()) > 0) {
            std::vector<float> cp = ficheiro.getControlPoints();
            int p = 0;
            for (unsigned int k = 0; k < cp.size(); k += 3) {
                std::cout << "Ponto de Controlo " << p << ": X=" << cp.at(k) << " Y=" << cp.at(k + 1) << " Z=" << cp.at(k + 2) << std::endl;
                p++;
            }
        }
        std::cout << "Rotate Information: Angulo=" << ficheiro.getRotateAngulo() << " Time=" << ficheiro.getTempoRt() << " X=" << ficheiro.getRotateX() << " Y=" << ficheiro.getRotateY() << " Z=" << ficheiro.getRotateZ() << " Ordem=" << ficheiro.getOrdemRt() << std::endl;
        std::cout << "Scale Information: X=" << ficheiro.getScaleX() << " Y=" << ficheiro.getScaleY() << " Z=" << ficheiro.getScaleZ() << " Ordem=" << ficheiro.getOrdemSc() << std::endl;
        std::cout << "%-------------------------------------------------------------------------%" << std::endl;
        toPrint(ficheiro);
    }
}
void toPrint(std::vector<xmlData> ficheiros) {
    for (unsigned int i = 0; i < ficheiros.size(); i++,figura++) {
        xmlData ficheiro = ficheiros.at(i);

        std::cout << "%-------------------------------------------------------------------------%" << std::endl;
        std::cout << "Figura " << figura << std::endl;
        std::vector<std::string> nomes = ficheiro.getFileName();
        std::vector<obj_Light> mats = ficheiro.getMateriais();
        for (unsigned int k = 0; k < nomes.size(); k++) {
            std::cout << "Ficheiro " << k + 1 << ": " << nomes.at(k) << std::endl;
            std::cout << "Textura " << k + 1 << ": " << mats.at(k).getTexture() << std::endl;
        }
        std::cout << "Translate Information: X=" << ficheiro.getTranslateX() << " Y=" << ficheiro.getTranslateY() << " Z=" << ficheiro.getTranslateZ() << " Ordem=" << ficheiro.getOrdemTr() << " Tempo=" << ficheiro.getTempoTr() << std::endl;
        if ((ficheiro.getNumControlPoints()) > 0) {
            std::vector<float> cp = ficheiro.getControlPoints();
            int p = 0;
            for (unsigned int k = 0; k < cp.size(); k += 3) {
                std::cout << "Ponto de Controlo " << p << ": X=" << cp.at(k) << " Y=" << cp.at(k + 1) << " Z=" << cp.at(k + 2) << std::endl;
                p++;
            }
        }
        std::cout << "Rotate Information: Angulo=" << ficheiro.getRotateAngulo() << " Time=" << ficheiro.getTempoRt() << " X=" << ficheiro.getRotateX() << " Y=" << ficheiro.getRotateY() << " Z=" << ficheiro.getRotateZ() << " Ordem=" << ficheiro.getOrdemRt() << std::endl;
        std::cout << "Scale Information: X=" << ficheiro.getScaleX() << " Y=" << ficheiro.getScaleY() << " Z=" << ficheiro.getScaleZ() << " Ordem=" << ficheiro.getOrdemSc() << std::endl;
        std::cout << "%-------------------------------------------------------------------------%" << std::endl;    
        toPrint(ficheiro);
    }

    figura = 1;
}

int main(int argc, char **argv) {
    std::string file_name = argv[1];
    std::cout << file_name << std::endl;

    std::vector<light> information = getXMLight(file_name);
    std::vector<xmlData> ficheiros = initParsing(file_name);
    ficheiros = initLoad(ficheiros);    
    //toPrint(ficheiros);
    std::cout << "starting draw" << std::endl;
    startDrawing(argc,argv,ficheiros,information);
}
