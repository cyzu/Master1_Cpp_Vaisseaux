
#include "MyGameEngine.h"

/* méthode qui anime tous les objects dans la fenêtre */
void MyGameEngine::idle(){
    for (int i = 0; i < paps->size(); i++) {
        (*paps)[i]->tick();
    }
//    for (int i = 0; i < four->size(); i++) {
//        (*four)[i]->tick();
//    }
}
