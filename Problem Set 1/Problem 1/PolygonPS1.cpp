#include "Polygon.h"
float Polygon::getSignedArea() const{
    float result = 0.0;
    if(fNumberOfVertices > 2){
        
        for(size_t i=0;i<fNumberOfVertices;i++){
            size_t next = (i+1) % fNumberOfVertices;

            result += fVertices[i].getX() * fVertices[next].getY();
            result -= fVertices[i].getY() * fVertices[next].getX();
        }

        result *= 0.5;
    }

    return result;
}