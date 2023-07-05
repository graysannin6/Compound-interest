#include <cmath>
#include <iostream>

using std::cout, std::cin, std::endl;

int main()
{
    //-------------------------------------------------
    cout << "Enter the initial amount to invest: " << endl;
    double C_0{};
    cin >> C_0;

    if (C_0 <= 0.0)
    {
        cout << "Wrong value,exiting..." << endl;
        return -1;
    }
    //--------------------------------------------------
    cout << "Enter the annual rate [% per 12 months]: " << endl;
    double r{};
    cin >> r;
    if (r <= 0.0 || r >= 100.0)
    {
        cout << "Wrong value, exiting..." << endl;
        return -1;
    }

    // ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
    cout << "Compound frequency is a period in months between computing interest" << endl;
    cout << "Ex: if 2 times a year, enter 6" << endl;
    cout << "if you dont know,enter 12 for a year compound frequecy." << endl;
    cout << "enter the compound frequency [months 1-72]: " << endl;
    double t{};
    cin >> t;
    if (t <= 0.0 || t > 72.0)
    {
        cout << "Wrong value,exiting..." << endl;
        return -1;
    }
    //-------------------------------------------------------
    cout << "Enter investment time [months 1-100]: " << endl;
    double m{};
    cin >> m;
    if (m <= 0.0 || m >= 100)
    {
        cout << "wrong value, exiting..." << endl;
        return -1;
    }
    //----------------------------------------------------
    // do computations

    const double kMontsPerYear = 12.0;
    const double kPercentageDiv = 100.0;

    double i = m / t;

    double C_i = C_0 * std::pow((1.0 + (r / kPercentageDiv) / kMontsPerYear * t), i);

    cout<<"Your balance before tax, after "<<m;
    cout<<" months of investiment is: "<<C_i<<endl;

    //compute the net income
    double income = C_i - C_0;

    cout<<"Your income is "<<income<<endl;
    const double kIncomeTax = 19.0;
    cout<<"After "<<kIncomeTax<<"% tax deduction you get: ";
    cout<<(1.0-kIncomeTax/kPercentageDiv) * income<<endl;
    system("pause");
    return 0;
}