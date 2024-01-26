#include <iostream>
using namespace std;

struct Poly
{
    float coeff;
    int pow;
};

void firstPolynomial(Poly firstPoly[],int n){
    Poly poly;
    cout << "Enter the first Equation : " << endl;
    for(int i = 0;i < n;i++){
        cout << "Enter coefficient of the " << i << " th element :" << endl;
        cin >> poly.coeff;
        cout << "Enter power of the " << i << " th element :" << endl;
        cin >> poly.pow;
        firstPoly[i] = poly;
    }
}

void secondPolynomial(Poly secondPoly[],int m){
    Poly poly;
    cout << "Enter the second Equation : " << endl;
    for(int i = 0;i < m;i++){
        cout << "Enter coefficient of the " << i << " th element :" << endl;
        cin >> poly.coeff;
        cout << "Enter power of the " << i << " th element :" << endl;
        cin >> poly.pow;
        secondPoly[i] = poly;
    }
}

void printFirstPolynomial(Poly firstPoly[],int n){
    cout << "The first equation is :" << endl;
    for(int j = 0;j < n;j++){
        cout << "The " << j << " th coeffient is : " << firstPoly[j].coeff << endl;
        cout << "The " << j << " th power is : " << firstPoly[j].pow << endl;
    }
}

void printsecondPolynomial(Poly secondPoly[],int m){
    cout << "The second equation is :" << endl;
    for(int j = 0;j < m;j++){
        cout << "The " << j << " th coeffient is : " << secondPoly[j].coeff << endl;
        cout << "The " << j << " th power is : " << secondPoly[j].pow << endl;
    }
}

void addPolynomial(Poly resultAddPolynomial[],Poly firstPoly[],Poly secondPoly[],int n,int m,int &c){
    int s = 0,k = 0,l = 0;
    while(s < n && k < m){
        if(firstPoly[s].pow < secondPoly[k].pow){
            resultAddPolynomial[l].coeff = firstPoly[s].coeff;
            resultAddPolynomial[l].pow = firstPoly[s].pow;
            s++;
            l++;
        }else if(firstPoly[s].pow > secondPoly[k].pow){
            resultAddPolynomial[l].coeff = secondPoly[k].coeff;
            resultAddPolynomial[l].pow = secondPoly[k].pow;
            k++;
            l++;
        }else{
            resultAddPolynomial[l].coeff = firstPoly[s].coeff + secondPoly[k].coeff;
            resultAddPolynomial[l].pow = firstPoly[s].pow;
            k++;
            s++;
            l++;
        }
    }
    for(int i = s;i < n;i++){
        resultAddPolynomial[l].coeff = firstPoly[i].coeff;
        resultAddPolynomial[l].pow = firstPoly[i].pow;
        l++;
    }
    for(int j = k;j < m;j++){
        resultAddPolynomial[l].coeff = secondPoly[j].coeff;
        resultAddPolynomial[l].pow = secondPoly[j].pow;
        l++;
    }
    c = l;
}

void integralPolynomial(Poly integralPolynomial[], Poly resultIntegralPolynomial[],int c)
{
    for(int i = 0;i < c;i++){
        resultIntegralPolynomial[i].pow = integralPolynomial[i].pow + 1;
        resultIntegralPolynomial[i].coeff = integralPolynomial[i].coeff / (integralPolynomial[i].pow + 1);
    }
}

void diffrentialPolynomial(Poly diffrentialPolynomial[],Poly resultdiffrentialPolynomial[],int c,int &k)
{
    for (int i = 0;i < c;i++)
    {
        if (diffrentialPolynomial[i].pow != 0 )
        {
            resultdiffrentialPolynomial[i].coeff = diffrentialPolynomial[i].pow * diffrentialPolynomial[i].coeff;
            resultdiffrentialPolynomial[i].pow = diffrentialPolynomial[i].pow - 1;
            k++;
        }
        else {
            resultdiffrentialPolynomial[i].coeff = 0;
            resultdiffrentialPolynomial[i].pow = 0;
            k++;
        }
    }
}

void printPolynomial(Poly resultAddPolynomial[],int n)
{

    for (int i = 0;i < n;i++)
    {
    if (resultAddPolynomial[i].coeff != 0){
        if (resultAddPolynomial[i].pow != 1 && resultAddPolynomial[i].pow != 0){
            cout << resultAddPolynomial[i].coeff << "X^" << resultAddPolynomial[i].pow;
            if (i != n-1)
            cout << " + ";
        }
        else if (resultAddPolynomial[i].pow == 1)
        {
            cout << resultAddPolynomial[i].coeff << "X";
            if (i != n-1)
            cout << " + ";
        }
        else if (resultAddPolynomial[i].pow == 0)
        {
        cout << resultAddPolynomial[i].coeff;
            if(i != n-1)
            cout << " + ";
        }
    }
    }
    cout << endl;
}

int main(){
    int n,m;
    cout << "Enter the number of coeff for the first eq : ";
    cin >> n;
    cout << "Enter the number of coeff for the second eq : ";
    cin >> m;
    int c;
    c = n + m;
    Poly firstPoly[n], secondPoly[m], resultAddPolynomial[c];

    firstPolynomial(firstPoly ,n);
    secondPolynomial(secondPoly ,m);

    printFirstPolynomial(firstPoly ,n);
    printsecondPolynomial(secondPoly ,m);

    addPolynomial(resultAddPolynomial, firstPoly, secondPoly, n, m, c);

    printPolynomial(resultAddPolynomial, c);
    Poly IntegralPolynomial[c];
    integralPolynomial(resultAddPolynomial, IntegralPolynomial, c);
    printPolynomial(IntegralPolynomial, c);
    int k = 0;
    Poly diffPolynomial[k];
    diffrentialPolynomial(IntegralPolynomial, diffPolynomial, c, k);
    printPolynomial(diffPolynomial, k);
} 