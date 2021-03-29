#include <unistd.h>
#include <sstream>
using namespace std;
static const string NEGRO="Black";
static const string GRIS="Gray";
static const string VERDE="Green";
static const string CAFE="Brown";
static const string NARANJA="Orange";
static const string ROJO="Red";
static const string AMARILLO="Yellow";
static const int INT_NEGRO=1;
static const int INT_GRIS=2;
static const int INT_VERDE=3;
static const int INT_CAFE=4;
static const int INT_NARANJA=5;
static const int INT_ROJO=6;
static const int INT_AMARILLO=7;


static string getRgbTronco(string lastRgb){
    if(lastRgb==NEGRO)return GRIS;
    return NEGRO;
}
static string getRgbRama(string lastRgb){
    if(lastRgb==VERDE)return CAFE;
    return VERDE;
}
static string getRgbHoja(string lastRgb){

    if(lastRgb==VERDE)return NARANJA;
    if(lastRgb==NARANJA)return ROJO;
    if(lastRgb==ROJO)return AMARILLO;
    return VERDE;
}
static string convertint(int lastRgb){

    if(lastRgb==INT_VERDE)return VERDE;
    if(lastRgb==INT_NEGRO)return NEGRO;
    if(lastRgb==INT_GRIS)return GRIS;
    if(lastRgb==INT_CAFE)return CAFE;
    if(lastRgb==INT_NARANJA)return NARANJA;
    if(lastRgb==INT_ROJO)return ROJO;
    if(lastRgb==INT_AMARILLO)return AMARILLO;

    return NEGRO;
}



static int getRgbTronco(int lastRgb){
    if(lastRgb==INT_NEGRO)return INT_GRIS;
    return INT_NEGRO;
}
static int getRgbRama(int lastRgb){
    if(lastRgb==INT_VERDE)return INT_CAFE;
    return INT_VERDE;
}
static int getRgbHoja(int lastRgb){

    if(lastRgb==INT_VERDE)return INT_NARANJA;
    if(lastRgb==INT_NARANJA)return INT_ROJO;
    if(lastRgb==INT_ROJO)return INT_AMARILLO;
    return INT_VERDE;
}

class ManejadorDeColores {

private:

public:





};
