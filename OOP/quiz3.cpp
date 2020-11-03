#include <iostream>
using namespace std;

class Rectangle{
public:
    double length;
    double width;
    void getInformation(){
        cin >> width;
        cin >> length;
    }
    void display(){
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
    double getArea(){
        return width*length;
    }
    double getPerimeter(){
        return (length + width)*2;
    }
};


int main(){
    Rectangle R1;
    R1.getInformation();
    R1.display();
    return 0;
}