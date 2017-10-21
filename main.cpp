//Header and Libraries
#include <iostream>
#include <cmath>

using namespace std;

/*
        This projects the approximate value of e^x with the value x as the
        user's input. It uses the taylor series to run the estimations from
        1 to 100.
*/

double process(int, int&, double);
//Pre-condition: sum, x, and n to be intialized
//Post-condition: return value sum for n 1 to 100
double fact(int);
//Pre-condition: n to be initialized
//Post-condition: return factorial of n
void value(int, double);
//Pre-condition: x and ex to be initialized
//Post-condition: print value of e^x
void loop(char&);
//Pre-condition: ans to be declared
//Post-condition: Prompt user for input and read input for ans
void input(int&);
//Pre-condition: x to be declared
//Post-condition: Prompt user for input and read input for x
void output(int);
//Pre-condition: x
//Post-condition: Output value x for e^x

int main()
{
        //Declarations
        char ans;
        double ex, sum = 1;
        int n, x;

        do
        {
                //Input
                input(x);

                //Function for calculating value of e^x
                ex = exp(x);

                //Actual value of e^x
                value(x , ex);

                //Start output
                output(x);

                //Processing & output
                sum = process(x, n, sum);

                //Input for loop answer
                loop(ans);

        } while (toupper(ans) == 'Y'); //loop conditions that make all input uppercase
}

void loop(char& a)
{
        cout << "\nDo you wish to repeat calculations for different values? (y/n): ";
        cin >> a;

}

void output(int x)
{
        cout << "Using the equation, e^" << x << " from n = 1 to 100 is: ";
}

void value(int x, double ex)
{
        cout << "e^" << x << " = " << ex << endl;
}

void input(int& x)
{
        cout << "Enter a value x to calculate for e^x: ";
        cin >> x;
}

double process(int x, int& n, double sum)
{
        //Computer e^x with x^n/n!
        for (n = 1; n <= 100; n++)
        {
                sum += (pow(x, n)) / (fact(n));

                //Fancy formatting
                if (n % 10 == 1)
                        cout << endl;

                cout << sum << " ";
        }

        return (sum);
}

double fact(int n)
{
        double product = 1;

        //Computer the factorial of n
        for (int i = 1; i <= n; i++)
                product *= i;

        return (product);
}