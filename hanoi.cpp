#include <iostream>
using namespace std;

void jugar(int disco, int torre1, int torre2, int torre3){
    if(disco == 1){
        cout << "Mover disco de la torre " << torre1 << " hacia la torre " << torre3 <<endl;
    }else{
        jugar(disco-1, torre1, torre3, torre2);
        cout << "Mover disco de la torre " << torre1 << " hacia la torre " << torre3 <<endl;
        jugar(disco-1, torre2, torre1, torre3);
    }
}
int main(){
    char res;
    do{
        int torre1=1, torre2=2, torre3 = 3, disco=0;
        cout << "\n¿Con cuántos discos quieres jugar? ";
        cin >> disco;
        jugar(disco, torre1, torre2, torre3);
        cout << "\n¿Desea volver a jugar? ";
        cin >> res;
        cout << endl;

    }while(res == 's');
    
}