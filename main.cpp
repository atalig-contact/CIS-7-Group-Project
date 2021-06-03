#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include<cstring>
using namespace std; 

//List of specializations. Referenced by student class
const vector<string> specializations {"Cardiology", "Gastroenterology", "Internal medicine",
                                      "Neurology", "Psychiatry"};

//List of languages. Referenced by student and country classes
const vector<string> languages {"French", "Cantonese", "English", "Hindi", "Spanish", "Portugese",
                                "Korean", "Afrikaans", "Oshiwambo", "Mandarin"}; 

class Student{
  public:
      Student()   //Atalig: make sure to always have srand(time(0)) in main when using this class
      {
        unsigned short index;

        index = rand() % specializations.size();   //randomly sets a specialization
        specialization = specializations[index];

        index = rand() % languages.size();  //randomly sets a language
        language = languages[index];
      }

      //Sets values to null value. This is to assist in comparisons in later instructions
      void clearStudent(){
        language = "null";
        specialization = "null";
      }

      //Get functions
      string getLanguage()
      { return language; }

      string getSpecialization()
      { return specialization; }

  private:
      string language, specialization;
};





class Country{
  private:
  string name;
  

  public:
  vector<string> languages;   //List of languages supported in the country
  vector<Student> students;   //Students that will be sent to this country

  //Intiialize country with name
  Country(string n){
    name = n;
    return;
  }

  //Set and get functions
  string getName(){
    return name;
  }

  void addLanguage(string l){
    this->languages.push_back(l);
  }

  
  //Compute percentage of country's students for a given language
  double pLang(string l){
    double acc = 0; //total number of students speaking a given language

    // if students speaks a given language, increment acc
    for (auto stu : this->students)
      if (stu.getLanguage() == l)
        acc += 1;
    
    //return ratio of selected students versus total students (multiplied by 100 for a percentage)
    return (acc / this->students.size())*100;
  }

  //Compute percentage of country's students for a given specialization
  double pSpecial(string s){
     double acc = 0; //total number of students of a given specialization
    
    //if student matches specialization, increment
    for (auto stu : this->students)
      if (stu.getSpecialization() == s)
        acc += 1;
    
    return (acc / this->students.size())*100;
  }

  //Print statistics on Country
  void printInfo(){

    cout << "\n\nCountry Name: " << this->getName() << endl << endl;

    cout << "Number of Students: " << this->students.size() << endl << endl;

    cout << "Percentage of Students by Language: \n\n";

    //Calculate percentage for each language
    for (auto l: this->languages)
      cout << l << ": " << setprecision(3) << this->pLang(l) << "%" << endl;

    cout << "\nPercentage of Students by Specialization\n\n";

    //Calculate percentage for each specialization
    for (auto sp : specializations)
      cout << sp << ": " << this->pSpecial(sp)  << "%" << endl;

    cout << endl;
    return;
  }
};


//List of countries
vector<Country> Countries {Country("India"), Country("South Korea"), Country("Brazil"), Country("Namibia"), Country("China"), Country("France"), Country("USA"), Country("Spain"), Country("TestCountry")};



int main() {
  srand(time(0)); //set seed for rand() functions
  //Set languages for each country
  Countries[0].addLanguage(languages[3]); //India: Hindi
  Countries[0].addLanguage(languages[2]); //English
  Countries[1].addLanguage(languages[6]); //South Korea: Korean
  Countries[2].addLanguage(languages[5]); //Brazil: Portugese
  Countries[3].addLanguage(languages[7]); //Namibia: Afrikaans, Oshiwambo
  Countries[3].addLanguage(languages[8]); 
  Countries[4].addLanguage(languages[9]); //China: Mandarin, Cantonese
  Countries[4].addLanguage(languages[1]);
  Countries[5].addLanguage(languages[0]); //France: French
  Countries[6].addLanguage(languages[2]);  //USA: English
  Countries[7].addLanguage(languages[4]);

  
for (auto i : languages)
  {
    Countries[8].addLanguage(i);
  }
  

  int testStudentTotal = 0; //Temporary, Make sure students add to 100

  int filterTotal = 0;


  vector<Student> participants (100); //vector of Students initialized w 100 elements
  


//These vectors will filtere
vector<Country> filteredCountry;
vector<Student> filteredStudent;


// for each language
for(int l = 0; l < languages.size(); l++){                   
  filteredCountry.clear(); //clear filters
  filteredStudent.clear();

//If country matches filtering language, add country to filteredCountry list
  for(int c = 0; c < Countries.size(); c++){    
    for(int i = 0; i < Countries[c].languages.size(); i++){
      if(Countries[c].languages[i] == languages[l]){
        Country tempC = Countries[c];
        tempC.students.clear(); //Clear vector to prevent duplication of students
        filteredCountry.push_back(tempC);
        }
      } 
    }

    
  //If student matches filtering language, add student to filteredStudent list
  for (int i = 0; i < participants.size(); i++)           
    {                                                       
      if (participants[i].getLanguage() == languages[l])
      {
        filteredStudent.push_back(participants[i]);
        participants[i].clearStudent(); //Set student variables to null to prevent duplicate students
      }
    }

   
   
  //Test to make sure there are no duplicate students
   int acc = 0;
   for(int i = 0; i < filteredCountry.size(); i++)
  {
    acc += filteredCountry[i].students.size();
  }

  

 
  
  //While filteredStudent list has students
  while(filteredStudent.size() != 0)
  {
    //for each filtered country, add one student at a time
    for(int i = 0; i < filteredCountry.size(); i++){
       if (filteredStudent.size() == 0)
         goto breakwhile; //if list is empty, break while loop
       
      filteredCountry[i].students.push_back(filteredStudent.back());
      filteredStudent.pop_back();
      
    }

    if (false)
      breakwhile: break;
    
  }

//Check for no duplicates
  for(int i = 0; i < filteredCountry.size(); i++)
  {
    filterTotal += filteredCountry[i].students.size();
  }
 
  
//For each filtered country, match back to the original country from Countries list, and dump students into the original country
  for (int k = 0 ; k < filteredCountry.size() ; k++)
  {
    for (int c = 0; c < Countries.size(); c++)
    {
      if (filteredCountry[k].getName() == Countries[c].getName())
        { 
          for (int j = 0; j < filteredCountry[k].students.size(); j++)
          {
            Countries[c].students.push_back(filteredCountry[k].students[j]);
          }
        }
    }
  }
  
}

//Print Information for each Country
for(int c = 0; c < Countries.size(); c++)
  {
    Countries[c].printInfo();
    testStudentTotal += Countries[c].students.size();
  }

  

}