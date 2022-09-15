#include<iostream>
using namespace std;

class Punto{
    double x, y;
    public:
        Punto(){
            x = y = 0;
        }
        Punto(double x, double y){
            this->x = x;
            this->y = y;
        }
        void setCoordenada(double x, double y){
            this->x = x;
            this->y = y;
        }
        double getX(){return x;}
        double getY(){return y;}
};

class Forma{
    protected:
        string color;
        Punto * centro;
        char nombre;
    public:
        Forma(){
            centro = new Punto;
        }
        Forma(string color, double x, double y, char nombre){
            this->color = color;
            centro = new Punto(x,y);
            this->nombre = nombre;
        }
        ~Forma(){
            delete centro;
        }

        virtual void imprimir(){
            cout<<"Esto es una forma: "<<endl;
            cout<<"De color: "<<color<<endl;
            cout<<"Su centro se encuentra en x:"<<centro->getX()<<" y: "<<centro->getY()<<endl;
            cout<<"Su nombre es: "<<nombre<<endl;
        }

        string getColor(){return color;}
        void setColor(string color){this->color = color;}
        void moverCentro(double x, double y){centro->setCoordenada(x,y);}
};

class Rectangulo : public Forma{
    float ladoMayor, ladoMenor;
    public:
        Rectangulo():Forma(){}
        Rectangulo(string color, double x, double y, char nombre, float ladoMayor, float ladoMenor):
        Forma(color,x,y,nombre){
            this->ladoMayor = ladoMayor;
            this->ladoMenor = ladoMenor;
        }

        ~Rectangulo(){
            delete centro;
        }
        void imprimir(){
            cout<<"Es un rectangulo"<<endl;
            Forma::imprimir();           
            cout<<"Lado mayor: "<<ladoMayor<<endl;
            cout<<"Lado menor: "<<ladoMenor<<endl;
        }
        float getArea(){
            return ladoMayor * ladoMenor;
        }
        float getPerimetro(){
            return (ladoMayor*2) + (ladoMenor*2);
        }
        void escala(float factor){
            ladoMayor *= factor;
            ladoMenor *= factor;
        }
};

int main(){

    Rectangulo *rect = new Rectangulo("Rojo",12.4,12.1,'A',14.6,1.1);
    rect->imprimir();
    cout<<"El area es: "<<rect->getArea()<<endl;
    cout<<"El perimetro es: "<<rect->getPerimetro()<<endl;

    rect->escala(0.5);
    rect->imprimir();
    
    delete rect;

    return 0;
}