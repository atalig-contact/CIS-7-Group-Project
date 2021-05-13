#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
using namespace std; //ik some people are picky about this so idk if u wanna use or not but prof doesnt care

//global variables
const vector<string> specializations {"Cardiology", "Gastroenterology", "Internal medicine",
                                      "Neurology", "Psychiatry"};

                                      //multidimensional vector so, Hong Kong, English would be location[2,3]
const vector<vector<string>> location {{"France", "French"}, {"Hong Kong", "Cantonese", "English"},                                                              {"India", "Hindi"}, {"United States","English", "Spanish"},                                                               {"Brazil","Portugese"}, {"Spain","Spanish"}, {"Argentina",                                                                 "Spanish"}, {"South Korea", "Korean"}, {"Czech Republic",
                                      "Czech"}, {"Mexico", "Spanish"}, {"Spain", "Spanish"}}; 

const vector<string> languages {"French", "Cantonese", "English", "Hindi", "Spanish", "Portugese",
                                "Korean"}; 

class Student{
  public:
      void randomizeStudent()
      {
        srand(time(NULL));
        unsigned short index;

        index = rand() % 5;   //randomly sets a specialization
        setSpecialization(index);

        index = rand() % 7;  //randomly sets a language
        setLanguage(index);
      }

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


int main() {
  
  vector<Student> participants (3); //vector of Students initialized w 100 elements
  
  for(int i=0;i<participants.size();++i) //test loop
    {
        for(int k=0;k<participants.size();++k)
          { participants[k].randomizeStudent(); }
      cout << "Student " << i << " " << participants[i].getSpecialization() 
           << " " << participants[i].getLanguage() << endl  ;
    }
  

}