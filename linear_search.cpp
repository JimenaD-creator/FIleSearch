#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector <int> vec, int target){
    for(int numero : vec){
        if(numero > target){
            return numero;
        }
    }
    return -1;
}

int main(){
    vector <int> vec = {5,2,9,7,4,6};
    int target = 5;

    int resultado = linearSearch(vec, target);
    if(resultado != -1){
        cout << "\nEl primer elemento mayor que " << target << " es: " << resultado;
    }else{
        cout << "No se enconntró un elemento mayor que " << target <<endl<<endl;
    }

}