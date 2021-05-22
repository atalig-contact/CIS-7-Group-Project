#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include<cstring> //Atalig: Might not need this
using namespace std; //ik some people are picky about this so idk if u wanna use or not but prof doesnt care

//global variables
const vector<string> specializations {"Cardiology", "Gastroenterology", "Internal medicine",
                                      "Neurology", "Psychiatry"};

                                      //multidimensional vector so, Hong Kong, English would be location[2,3]


//

/*
*****IMPORTANT******: A possible solution for correctly distributing the students equally across the Countries. Create temporary vectors to filter
the participants and countries by a language. Create a Nested Loop:
While the filtered student vector is nonempty
    for every country
      add one student

Since these vectors are temporary and are already filtered, we can use pop_back() funciton

*/




//Atalig: Make sure to use this vector when inputing languages
//Do not change order of languages, just add new ones
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

      //Atalig: Guys I promise I didn't break the class again.
      //Atalig: Guys I broke it.
      void clearStudent(){
        language = "null";
        specialization = "null";
      }


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
  vector<string> languages;
  vector<Student> students;

  public:
  Country(string n){
    name = n;
    return;
  }

  string getName(){
    return name;
  }

  //Atalig: A pass by copy isn't ideal. We may want to change this
  vector<string> getCopyOfLang(){
    return this->languages;
  }

  //Atalig: Get size of student vector
  int getStudentSize(){
    return this->students.size();
  }

  void addLanguage(string l){
    this->languages.push_back(l);
    return;
  }

  void addStudent(vector<Student> &s, int i){
    this->students.push_back(s[i]);
    //s.erase(s.begin() + i);
    s[i].clearStudent();
    return;
  }

  double pLang(string l){
    double acc = 0;
    
    for (auto stu : this->students)
      if (stu.getLanguage() == l)
        acc += 1;
    
    return acc / this->students.size();
  }

  double pSpecial(string s){
     double acc = 0;
    
    for (auto stu : this->students)
      if (stu.getSpecialization() == s)
        acc += 1;
    
    return acc / this->students.size();
  }

  void printInfo(){

    cout << "\n\nCountry Name: " << this->getName() << endl << endl;
    cout << "Percentage of Students by Language: \n\n";

    for (auto l: this->languages)
      cout << l << ": " << this->pLang(l) << endl;

    cout << "\nPercentage of Students by Specialization\n\n";

    for (auto sp : specializations)
      cout << sp << ": " << this->pSpecial(sp) << endl;

    cout << endl;
    return;
  }

};

//NOTE (Atalig): Rearrange class objects into separate files. Move this global vector back to beginning afterwards.
//Atalig: Adding languges to countries requires vector be accessible and not constant.

vector<Country> Countries {Country("India"), Country("South Korea"), Country("Brazil"), Country("Namibia"), Country("China"), Country("TestCountry") } ;



/*{{"France", "French"}, {"Hong Kong", "Cantonese", "English"},                                                              {"India", "Hindi"}, {"United States","English", "Spanish"},                                                               {"Brazil","Portugese"}, {"Spain","Spanish"}, {"Argentina",                                                                 "Spanish"}, {"South Korea", "Korean"}, {"Czech Republic",
                                      "Czech"}, {"Mexico", "Spanish"}, {"Spain", "Spanish"}}; */


int main() {
  srand(time(0));
  Countries[0].addLanguage(languages[3]); //India: Hindi
  Countries[1].addLanguage(languages[6]); //South Korea: Korean
  Countries[2].addLanguage(languages[5]); //Brazil: Portugese
  Countries[3].addLanguage(languages[7]); //Namibia: Afrikaans, Oshiwambo
  Countries[3].addLanguage(languages[8]); 
  Countries[4].addLanguage(languages[9]); //China: Mandarin

  //Test Language
  Countries[5].addLanguage(languages[0]);
  Countries[5].addLanguage(languages[1]);
  Countries[5].addLanguage(languages[2]);
  Countries[5].addLanguage(languages[3]);
  Countries[5].addLanguage(languages[4]);
  Countries[5].addLanguage(languages[5]);
  Countries[5].addLanguage(languages[6]);
  Countries[5].addLanguage(languages[7]);
  Countries[5].addLanguage(languages[8]);
  Countries[5].addLanguage(languages[9]);

  

  int testStudentTotal = 0; //Temporary, Make sure students add to 100


  vector<Student> participants (100000); //vector of Students initialized w 100 elements
  
  /*
  for(int i = 0; i < participants.size(); ++i) //test loop
    {
      cout << "Student " << i << " " << participants[i].getSpecialization() 
           << " " << participants[i].getLanguage() << endl  ;
    }
    */

    
  for(auto c : Countries)
  {
    for (auto l : c.getCopyOfLang())
     {

      
      for (int i = 0; i < participants.size(); i++)
      {
       
        if (participants[i].getLanguage() == l)
          c.addStudent(participants, i);
      }
        
     }
    
    c.printInfo();
    cout << c.getStudentSize() << endl << endl;
    testStudentTotal += c.getStudentSize();
  }

//Atalig: I'm pretty sure there's a word for console messages for programmers during development, though I've completely forgotten it. So for now
//dev message will do.
  cout << "\n\nDev Message - Size of participants: " << participants.size();
  cout << "\n\nDev Message - total students (sum from each country: " << testStudentTotal;
  

}