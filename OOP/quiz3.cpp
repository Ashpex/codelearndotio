#include <iostream>
using namespace std;

class Rectangle{
public:
    double length;
    double width;
    void getInformation(){
        cin >> length;
        cin >> width;
    }
    void display(){
        cout << getArea() << endl;
        cout << getPerimeter() << endl;
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