#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib> 
#include <ctime>
#include<cstring> //Atalig: Might not need this
using namespace std; 

//global variables
const vector<string> specializations {"Cardiology", "Gastroenterology", "Internal medicine",
                                      "Neurology", "Psychiatry"};




//

/*
*****IMPORTANT******: A possible solution for correctly distributing the students equally across the Countries. Create temporary vectors to filter
the participants and countries by a language. Create a Nested Loop:
While the filtered student vector is nonempty
    for every country
      add one student

Since these vectors are temporary and are already filtered, we can use pop_back() funciton

*/

/*

Filteration Loop is working. However, we are having issues with referencing Country and Student vector. Our function only gets a copy of a Country object, instead of referencing it. Our provisional solution is to use additional collecting vector. We need find a proper way to reference the Countries vectors such that we can edit the Country objects.

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
  

  public:
  vector<string> languages;
  vector<Student> students;

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

  vector<Student> getCopyOfStudent(){
    return this->students;
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

  void addStudent(vector<Student> s)
  {
    this->students.push_back(s.back());
  }

  void addStudent(Student s)
  {
    this->students.push_back(s);
  }

  double pLang(string l){
    double acc = 0;
    
    for (auto stu : this->students)
      if (stu.getLanguage() == l)
        acc += 1;
    
    return (acc / this->students.size())*100;
  }

  double pSpecial(string s){
     double acc = 0;
    
    for (auto stu : this->students)
      if (stu.getSpecialization() == s)
        acc += 1;
    
    return (acc / this->students.size())*100;
  }

  void printInfo(){

    cout << "\n\nCountry Name: " << this->getName() << endl << endl;
    cout << "Percentage of Students by Language: \n\n";

    for (auto l: this->languages)
      cout << l << ": " << setprecision(3) << this->pLang(l) << "%" << endl;

    cout << "\nPercentage of Students by Specialization\n\n";

    for (auto sp : specializations)
      cout << sp << ": " << this->pSpecial(sp)  << "%" << endl;

    cout << endl;
    return;
  }

  void printName(){
    cout << endl << this->name << endl;
  }

};

//NOTE (Atalig): Rearrange class objects into separate files. Move this global vector back to beginning afterwards.
//Atalig: Adding languges to countries requires vector be accessible and not constant.
/*
vector<Country> Countries {Country("India"), Country("South Korea"), Country("Brazil"), Country("Namibia"), Country("China"), Country("TestCountry") } ;
*/

vector<Country> Countries {Country("India"), Country("South Korea"), Country("Brazil"), Country("Namibia"), Country("China"), Country("France"), Country("USA"), Country("Spain"), Country("TestCountry")};



/*{{"France", "French"}, {"Hong Kong", "Cantonese", "English"},                                                              {"India", "Hindi"}, {"United States","English", "Spanish"},                                                               {"Brazil","Portugese"}, {"Spain","Spanish"}, {"Argentina",                                                                 "Spanish"}, {"South Korea", "Korean"}, {"Czech Republic",
                                      "Czech"}, {"Mexico", "Spanish"}, {"Spain", "Spanish"}}; */


int main() {
  srand(time(0));
  Countries[0].addLanguage(languages[3]); //India: Hindi
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
  

  //Test Language
  

  /*
  
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

*/


  

  int testStudentTotal = 0; //Temporary, Make sure students add to 100

  int filterTotal = 0;


  vector<Student> participants (10000); //vector of Students initialized w 100 elements
  







/*
create filtered country vector
create filtered student vector

for each language in laguage vector
  clear country vector
  clear student vector

  for each country
    if country match language, add to filtered country vector
  for each student
    if student match language, add to filted student vector
    fill "null" for main student vector


    until student vector is empty
      for each country in filtered country vector
        add 1 student
        pop student from filtered student vector

  



*/

vector<Country> filteredCountry;
vector<Student> filteredStudent;



for(int l = 0; l < languages.size(); l++){                    //loops thru languages
  filteredCountry.clear();
  filteredStudent.clear();

  for(int c = 0; c < Countries.size(); c++){                  //loops thru countries to add to filtered Country list if 
                                                              // countries match the current language
    //Make sure that this vector gets deleted in memory.
    
    for(int i = 0; i < Countries[c].languages.size(); i++){
      if(Countries[c].languages[i] == languages[l]){
        Country tempC = Countries[c];
        tempC.students.clear();
        filteredCountry.push_back(tempC);
        }
      } 
    }

    
      
  for (int i = 0; i < participants.size(); i++)           //adds participants to filtered Student list if student 
    {                                                     //matches current language  
      if (participants[i].getLanguage() == languages[l]){
        filteredStudent.push_back(participants[i]);
        participants[i].clearStudent();
      }
    }

   
   cout << "No. of filtered Countries: " << filteredCountry.size() << endl;

   int acc = 0;
   for(int i = 0; i < filteredCountry.size(); i++)
  {
    acc += filteredCountry[i].students.size();
  }

  cout << "Student size before distribution: " << acc << endl;

 
  int currentSize = filteredStudent.size();
  bool flagCheck = false;
  while(currentSize != 0)
  {
    //cout << "\n In while loop\n";
    for(int i = 0; i < filteredCountry.size(); i++){
      //cout << "\n In for loop\n";
       if (filteredStudent.size() == 0){
         flagCheck = true;
         goto breakwhile;
       }
      filteredCountry[i].students.push_back(filteredStudent.back());
      cout << "Filtered Country Size: " << filteredCountry[i].students.size() << endl;
      filteredStudent.pop_back();
      
    }

    if (flagCheck == true){
      breakwhile: break;
    }
  }

  for(int i = 0; i < filteredCountry.size(); i++)
  {
    filterTotal += filteredCountry[i].students.size();
  }
 





  
  
  for (int k = 0 ; k < filteredCountry.size() ; k++)
  {
    for (int c = 0; c < Countries.size(); c++)
    {



      
      if (filteredCountry[k].getName() == Countries[c].getName())
        {
          //temp vector; 
          for (int j = 0; j < filteredCountry[k].students.size(); j++)
          {
            //vector.push_back(filteredCountry[k].students[j]))
            Countries[c].students.push_back(filteredCountry[k].students[j]);
            
          }

          cout << filteredCountry[k].getName() << " added " << filteredCountry[k].students.size() << " Students" << endl << endl;
          
        }
         


     
    }
  }
  
  for(int i = 0; i < filteredCountry.size(); i++)
  {
    filteredCountry[i].students.clear();
  }

  filteredCountry.clear();
  filteredStudent.clear();
  
}

cout << "\n\n ************BREAK****************** \n\n" ;




for(int c = 0; c < Countries.size(); c++)
  {
    Countries[c].printInfo();
    cout << Countries[c].getStudentSize() << endl << endl;
    testStudentTotal += Countries[c].getStudentSize();
    
  
  }

  

  
  


//Atalig: I'm pretty sure there's a word for console messages for programmers during development, though I've completely forgotten it. So for now
//dev message will do.
  cout << "\n\nDev Message - Size of participants: " << participants.size();
  cout << "\n\nDev Message - total students (sum from each country): " << testStudentTotal;
  cout << "\n\nDev Message - total students (sum from filters): " << filterTotal;
  

}