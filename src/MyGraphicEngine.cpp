
#include "MyGraphicEngine.h"
#include "Case.h"
#include <string.h>

using namespace std;

void MyGraphicEngine::Draw(){
    
    GraphicPrimitives::drawLine2D(0.5, 0.5, 0.9, 0.9, 1.0f, 0.0f, 0.0f);//x1,0.5f,x2,-0.5f,1.0f,0.0f,1.0f);
    GraphicPrimitives::drawText2D(str,-0.9f,0.9f,1.0f,0.3f, 0.8f);
    
    //std::string strCountP =  std::to_string(paps->size()) + " papillons";
    //GraphicPrimitives::drawText2D(&strCountP[0],-0.9f,0.8f,1.0f,1.0f, 0.5f);
//    std::string strCountF =  std::to_string(four->size()) + " fourmis";
//    GraphicPrimitives::drawText2D(&strCountF[0],-0.9f,0.7f,1.0f,1.0f, 0.5f);

    //for (int i = 0; i < paps->size(); i++) {
        //(*paps)[i]->draw();
    //}
//    for (int i = 0; i < four->size(); i++) {
//        (*four)[i]->draw();
//    }

    
    
    
    /*
     FAIRE PIVOTER LE SEGMENT 
     
    x1 += vx1;
    if (x1 > 0.9f || x1 < -0.9f) {
        vx1 = -vx1;
        x1 += vx1;
    }
    
    x2 += vx2;
    if (x2 > 0.9f || x2 < -0.9f) {
        vx2 = -vx2;
        x2 += vx2;
    }
     */
    
    
    
    /* Quadrillage blanc */
    //const float lignes = Case.nb_lignes; // le nombre de lignes qu'on veut avoir
    const float horizontal_scale  = 2.0/Case::nb_lignes;
    for (float i = -1; i < 1; i += 0.2) { //vertical
        for (float j = -1; j < 1; j += horizontal_scale) { //horizontal
            GraphicPrimitives::drawLine2D(i, 1, i, -1, 1.0f, 1.0f, 1.0f);
            GraphicPrimitives::drawLine2D(-1, j, 1, j, 1.0f, 1.0f, 1.0f);
        }
    }
    
}

