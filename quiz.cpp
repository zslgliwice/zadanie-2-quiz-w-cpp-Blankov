#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <string>

int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //

    
    std::fstream file;  //Declare the variable
    file.open("pytania.exe", std::ios::in); //Connetc with the file

    SetConsoleTextAttribute(handle, 15);
    if(file.good() == true){
        //Check if this file exists
        //If file exists, continue

        SetConsoleTextAttribute(handle, 14);
        std::cout <<"Plik z quizme istnieje :D"<<std::endl;
        Sleep(2000);
        
        SetConsoleTextAttribute(handle, 15);


        //variable
        std::string name;
        std::string line;
        int line_number=1;
        int question_number=0;
        std::string content[8], answerpA[8], answerB[8], answerC[8], correct[8];
        std::string answer;
        int points =0; 


        while(getline(file, line)){
            switch(line_number){
                    case 1: content[question_number] = line;      break;
                    case 2: answerpA[question_number] = line;       break;
                    case 3: answerB[question_number] = line;       break;
                    case 4: answerC[question_number] = line;       break;
                    case 5: correct[question_number] = line;   break;
            }if (line_number==5)
                {
                    line_number=0;
                    question_number++;
                }
                line_number++;
        }
        std::cout <<"Za chwile zaladuje quiz :D"<<std::endl;
        Sleep(2000);
        system("cls");

        SetConsoleTextAttribute(handle, 10);
        std::cout<<"Podaj swoje imie"<<"\n";
        SetConsoleTextAttribute(handle, 14);
        std::cin>>name;
        SetConsoleTextAttribute(handle, 15);
        

        Sleep(1000);
        for(int i=0;i <8; i++){
            SetConsoleTextAttribute(handle, 14);
            std::cout<<std::endl<<content[i]<<std::endl;
            SetConsoleTextAttribute(handle, 15);
            std::cout<<"<===============================================================================>"<<std::endl;
            std::cout<<"A. "<<answerpA[i]<<std::endl;
            std::cout<<"B. "<<answerB[i]<<std::endl;
            std::cout<<"C. "<<answerC[i]<<std::endl;
            std::cout<<"<===============================================================================>"<<std::endl;
            SetConsoleTextAttribute(handle, 14);
            std::cout<<"Twoja odpowiedz (a,b,c): ";
            std::cin>>answer;


            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower); //
            
            Sleep(1000);
            if (answer==correct[i])
                {
                    SetConsoleTextAttribute(handle, 10);
                    std::cout<<std::endl<<"Poprawna odpowiedz!"<<std::endl;
                    points++;
                }
                else
                {
                    SetConsoleTextAttribute(handle, 12);
                    std::cout<<std::endl<<"Zla odpwoiedz, prawidlowa odpowiedzia jest: "<<correct[i]<<std::endl;
                }
                SetConsoleTextAttribute(handle, 15);
        }
        if(points == 8){
            std::cout<<name<<" masz "<<points<<"/8 punktow!"<<std::endl;
            std::cout<<"Najlepszy wynik! :D"<<std::endl;

        }else if(points > 5 && points < 7){
            std::cout<<name<<" masz "<<points<<"/8 punktow!"<<std::endl;
            std::cout<<"Jest dobrze, znawsz w wiekszosci ksiazke"<<std::endl;

        }else if(points < 5 && points > 2){
            std::cout<<name<<" masz "<<points<<"/8 punktow!"<<std::endl;
            std::cout<<"Nie jest zle, ale polecam ponownie przeczytac ksiazke"<<std::endl;

        }else{
            std::cout<<name<<" masz "<<points<<"/8 punktow!"<<std::endl;
            std::cout<<"Chyba nie znasz ksiazki"<<std::endl;
        }
        
   
        SetConsoleTextAttribute(handle, 15);
        file.close();
    }else{
        SetConsoleTextAttribute(handle, 12);
        std::cout<<"Plikz z quziem nie istnieje :c"<<std::endl;
        //If file does not exists, print information
    }
	
}


