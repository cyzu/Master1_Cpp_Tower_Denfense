
#include "MyControlEngine.h"
#include "Case.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      // paps->push_back(new Papillon((x-400) / 400.f, (y-300)/ -300.f ));
        //four->push_back(new Fourmis((x-400) / 400.f, (y-300)/ -300.f ));
        
        float x_ = Case::getCaseX(x);
        float y_ = Case::getCaseY(y);
       
        vaisseau->push_back(new Vaisseau(x_, y_));
    }
}
