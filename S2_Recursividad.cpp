#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Archivo{
    string name;
};

struct Directorio{
    string name;
    vector<Archivo>archivos; //No sabemos cuántos son los directorios
    vector<Directorio>subdirectorio;

};

bool findFile(string path, string target, Directorio& dir){ //Referencias de memoria. Dirección de memoria para hacer cambios
    
    //caso base -> se define para detener la recursividad, iteramos sobre la raíz de un directorio
    for(auto arch: dir.archivos) { //No definir el tipo de dato
        if(arch.name == target){
            path += "/" + dir.name;
            return true;
        }
    }
        

    for(auto subdir: dir.subdirectorio){
        string subdirpath = path + "/" + dir.name; //Modificar cada que entre a un subdirectorio
        if(findFile(subdirpath, target, subdir)){
            path = subdirpath;
            return true;
        }
    }
    return false;

}

int main(){
    Directorio sistemaDeArchivos = {
   "root",
   {
           {"archivo1.txt"},
           {"archivo2.txt"}
   },
   {
           {
               "subdir1",
               {
                   {"archivo3.txt"},
               },
               {
                   {
                       "subdir2",
                       {
                           {"target.txt"},
                           {"archivo4.txt"}
                       },
                       {}
                   }
               }
           },
           {"archivo5.txt"}
   }
};

    string target = "archivo3.txt";
    string path = ""; //Regresa la dirección de memoria

    //cout << &sistemaDeArchivos <<endl;

    if(findFile(path, target, sistemaDeArchivos)){
        cout << "Archivo encontrado en: " << path << "/" << target;
    }else{
        cout << "Archivo no encontrado :c";
    }

}

