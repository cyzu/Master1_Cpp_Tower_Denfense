#include "MyControlEngine.h"
#include "Case.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float x_ = Case::getCaseX(x);
        float y_ = Case::getCaseY(y);
       
        vaisseau->push_back(new Vaisseau(x_, y_));
    }
}
