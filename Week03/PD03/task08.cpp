#include<iostream>
using namespace std;
main(){
    float vg_per_kg,fruit_per_kg;
    int vg,fruits;
    cout<<"Enter vegetables prive per kilogram (in coins)";
    cin>>vg_per_kg;
    cout<<"Enter fruits prive per kilogram (in coins)";
    cin>>fruit_per_kg;
    cout<<"Enter vegetables kilos";
    cin>>vg;
    cout<<"Enter fruit kilos";
    cin>>fruits;

    int ttl = vg_per_kg*vg/1.94 + fruit_per_kg*fruits/1.94;

    cout<<"Total earning in Rupees Rs."<<ttl;
}