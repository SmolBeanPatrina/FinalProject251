#include "student.hpp"
#include "list.hpp"
#include <iostream>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi

int main()
{
    DSLinkedList domestic_students;    
    string line;
    ifstream domesticFile("domestic-stu.txt");
    if (!domesticFile.is_open())
    {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(domesticFile, line);

    int stu_count = 1;
    while (getline(domesticFile, line))
    {
        istringstream ss(line);

        string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;

        //get firstName separated by comma
        getline(ss, firstName, ',');

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get province separated by comma
        getline(ss, province, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        int temp_id = 20210000 + stu_count;

        DomesticStudent temp_student(firstName, lastName, cgpa, researchScore, temp_id, province);

        domestic_students.AddNode(temp_student);

        stu_count++;
    }

    domesticFile.close();

    MergeSort(&domestic_students.head);

    domestic_students.print();

    return 0;
}