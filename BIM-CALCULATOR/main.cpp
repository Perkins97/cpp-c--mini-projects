#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

void weightCategories(double bodyMassIndex) {
            if (bodyMassIndex < 18.5) {
                cout << "# You're underweight" << endl;
                cout << "== POSSIBLE HEALTH RISKS ==" << endl;
                cout << ". Nutritional deficiencies (e.g iron, calcium)" << endl;
                cout << ". Weakened immune system" << endl;
                cout << ". Fertility issues" << endl;
                cout << ". Osteoporosis" << endl;
                cout << ". Anemia" << endl;
                cout << ". Fatigue and low energy" << endl;
            }
            else if (bodyMassIndex < 25) {
                cout << "# You have a normal weight" << endl;
                cout << "== GENERALLY LOWER RISK ==" << endl;
                cout << ". Lowest risk for weight-related chronic diseases" << endl;
                cout << ". Ideal range for most people" << endl;
                cout << ". Fertility issues" << endl;
                cout << ". Osteoporosis" << endl;
                cout << ". Anemia" << endl;
                cout << ". Fatigue and low energy" << endl;
            }
            else if (bodyMassIndex < 30) {
                cout << "OVERWEIGHT " << endl;
                cout << "== POSSIBLE HEALTH RISKS ==" << endl;
                cout << "# Increased risk of :" << endl;
                cout << ". High blood pressure" << endl;
                cout << ". Type 2 diabetes" << endl;
                cout << ". Heart disease" << endl;
                cout << ". Joint pain or osteoarthritis" << endl;
                cout << ". Sleep apnea" << endl;
            }
            else {
                cout << "You fall into the obese category" << endl;
                cout << "== Major Health Risks ==" << endl;
                cout << ". Cardiovascular diseases" << endl;
                cout << ". Type 2 diabetes" << endl;
                cout << ". Stroke" << endl;
                cout << ". Certain Cancers (e.g. colon, breast, uterine)" << endl;
                cout << ". Liver disease (fatty Liver)" << endl;
                cout << ". Infertility " << endl;
                cout << ". Respiratory issues (e.g. sleep apnea) " << endl;
                cout << ". Depression or low self-esteem " << endl;
            }


}

int main() {
// BIM CALCULATOR
    // Navigation Menu for User
int choice;
    double height, weight;
    vector <double> bodyMassIndexes;


    do {
        cout << "====== MAIN MENU ======" << endl;
        cout <<"1. Calculate your B.M.I today " << endl;
        cout <<"2. View your past B.M.I results or History " << endl;
        cout <<"3. Exit " << endl;

        cin >> choice;
 // calculating the bmi of the user inputs
        if (choice ==1 ) {
            cout << "Enter your weight ( kg ) :"  ;
            cin >> weight;

            cout << "Enter your height ( m ) :" ;
            cin >> height;
            double bodyMassIndex = weight / pow (height, 2);

             cout << "Your Body Mass Index is :" << " "<< bodyMassIndex << endl;
             bodyMassIndexes.push_back(bodyMassIndex);

            weightCategories(bodyMassIndex);

        }
        else if (choice == 2) {
                cout << "== B.M.I. HISTORY ==" << endl;
            for (int i = 0; i < bodyMassIndexes.size(); i++) {
                cout << i + 1 << ". "<< bodyMassIndexes[i] << endl;
            }
        }


    }while (choice != 3);






    return 0;
}