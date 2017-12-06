#include "MyControlEngine.h"
#include "Case.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float x_ = Case::getCaseX(x);
        float y_ = Case::getCaseY(y);
        
        bool empty = true;
        
        for (auto i = 0; i < vaisseau->size(); i++) {
            if ((*vaisseau)[i]->getX() == x_ && (*vaisseau)[i]->getY() == y_){
                std::cout<<"Il y a déjà un vaisseau posé sur cette case. Changez !"<<std::endl;
                empty = false;
            }
        }
        if (empty) vaisseau->push_back(new Vaisseau(x_, y_));
    }
}
