/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software 								  *
* NOMBRES: Erick Santamaria- Alexis Altamirano                    *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
* Programa:Resuelve el cubo magico                                *
******************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
template<typename tipo>
class CuboMagico{
private:
  tipo **cuadrado;
public:
    CuboMagico(tipo **);
    void llenar(tipo,tipo);
    void mostrar(tipo, tipo);
    tipo **getCuboMagicoCuadrado();
    void setCuboMagicoCuadrado(tipo **);

};
/** @name contructor
	@param tipo **_cuadrado 
	@brief constructor de la calse CuboMagico
*/
template<typename tipo>
CuboMagico::CuboMagico(tipo **_cuadrado){
    cuadrado=_cuadrado;
}
/** @name getCuboMagicoCuadrado
	@param 
	@return cuadrado
*/
template<typename tipo>
tipo **CuboMagico::getCuboMagicoCuadrado(){
    return cuadrado;
}
/** @name setCuboMagicoCuadrado
	@param tipo **_cuadrado 
	@return 
*/
template<typename tipo>
void CuboMagico::setCuboMagicoCuadrado(tipo **_cuadrado){
    cuadrado=_cuadrado;
}
/** @name llenar
	@param tipo a,tipo b 
	@return
	@brief llena la matriz 
*/

template<typename tipo>
void CuboMagico::llenar(tipo a,tipo b){
    int x=0,k=0,p=1,j=0,t=0,s=0,d=0;
        x=(b-1)/2;
        t=((a+1)/2);
        s=(a-x-1)/2;
        d=x;

         for(int g=0; g<((a+1)/2);g++){
            j=g;
            k=g;
        for( int i=x;i>=j;i--){
            *(*(cuadrado+i)+k)=p;
             if( k<(d-s) ){
                *(*(cuadrado+i)+(k+t))=p;
			}
            if(k>(d+s)){
                *(*(cuadrado+i)+(k-t))=p;
            }
            if(i>(d+s)){
                *(*(cuadrado+(i-t))+k)=p;
            }
            if(i<(d-s)){
                *(*(cuadrado+(i+t))+k)=p;
            }

            k++;
            p++;
        }
        x++;
    }
}
/** @name mostrar
	@param tipo a,tipo b 
	@return 
	@brief muestra la matriz resuelta
*/
template<typename tipo>
void CuboMagico::mostrar(tipo a,tipo b){
   system("cls");
    int x=0,t=0,s=0;
        t=((a+1)/2);
        x=(b-1)/2;
        s=(a-x-1)/2;

        for(int l=0;l<a;l++){
                cout<<"\n\t";
            for(int h=0;h<b;h++){
                if(h>=(x-s) && h<=(x+s) && l<=(x+s) && l>=(x-s)){
                    cout<<"\t"<<*(*(cuadrado+l)+h);
                }
        	}
		}
}
