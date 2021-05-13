#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include<cstring> //Atalig: Might not need this
#include <cstdarg> //Atalig: Necessary for country class
using namespace std; //ik some people are picky about this so idk if u wanna use or not but prof doesnt care

//global variables
const vector<string> specializations {"Cardiology", "Gastroenterology", "Internal medicine",
                                      "Neurology", "Psychiatry"};

                                      //multidimensional vector so, Hong Kong, English would be location[2,3]


//

//Atalig: Might need to change this. It makes mores sense for countries to have multiple languages.
const vector<vector<string>> location {{"France", "French"}, {"Hong Kong", "Cantonese", "English"},                                                              {"India", "Hindi"}, {"United States","English", "Spanish"},                                                               {"Brazil","Portugese"}, {"Spain","Spanish"}, {"Argentina",                                                                 "Spanish"}, {"South Korea", "Korean"}, {"Czech Republic",
                                      "Czech"}, {"Mexico", "Spanish"}, {"Spain", "Spanish"}}; 

//Atalig: Make sure to use this vector when inputing languages
const vector<string> languages {"French", "Cantonese", "English", "Hindi", "Spanish", "Portugese",
                                "Korean"}; 

class Student{
  public:
      Student()   //Atalig: make sure to always have srand(time(0)) in main when using this class
      {
        unsigned short index;

        index = rand() % 5;   //randomly sets a specialization
        setSpecialization(index);

        index = rand() % 7;  //randomly sets a language
        setLanguage(index);
      }

    //Atalig : Keep these, dumby.

      void setLanguage(int langIndex)
      {
        language = languages[langIndex];
      }

      void setSpecialization(int specialIndex)
      {
        specialization = specializations[specialIndex];
      }

      string getLanguage()
      { return language; }

      string getSpecialization()
      { return specialization; }

  private:
      string language, specialization;
};

/*Atalig: functions to work on

Constructor: set Name and languages
addStudent: add student to students vector.
specializationProbability: Find distribution of students in country based on specialization
languageProbability: Find distribution of students in country based on language


**WORK IN PROGRESS**
*/
class Country{
  private:
  string name;
  vector<string> languages;
  vector<Student> students;

  public:
  Country(string n, const string format, ... ){
    name = n;
    va_list valist;
    va_start(valist, format);

    for(int i = 0; i < 3; i++)
    this->languages[i] = va_arg(valist, int);//Atalig: Change later


  }


}


int main() {
  srand(time(0));
  vector<Student> participants (100); //vector of Students initialized w 100 elements
  
  for(int i = 0; i < participants.size(); ++i) //test loop
    {
      cout << "Student " << i << " " << participants[i].getSpecialization() 
           << " " << participants[i].getLanguage() << endl  ;
    }
  

}