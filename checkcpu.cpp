#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool loop= true;

int main () {

    while (loop = true) {
    ifstream myfile("/sys/class/thermal/thermal_zone0/temp");
    string temp_str;
    getline (myfile, temp_str);

    stringstream conv(temp_str);
    int temp_int;
    conv >> temp_int;
    int temperature = temp_int/1000;
    
    cout << temperature << endl;

    if(temperature >= 80){
        system("shutdown -P now");
    }
    }
    return 0;
}